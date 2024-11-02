#include "jsonutils.h"

#include <cstdio>
#include <QDebug>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/schema.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/error/en.h>

bool JsonUtils::readFromFile(const QString &filePath, QVariant &data)
{
    return false;
}

bool JsonUtils::writeToFile(QVariant &data, const QString &filePath, int precision)
{
    return false;
}

bool JsonUtils::read(std::string &jsonData, QVariant &data)
{
    rapidjson::Document document;
    if(document.ParseInsitu(jsonData.data()).HasParseError()){
        qDebug() << errMsg(document.GetParseError());
        return false;
    }
    rapidJsonToQVariant(document, data);
    return data.isValid();
}

bool JsonUtils::write(const QVariant &variant, std::string& jsonData, int precision)
{
    rapidjson::Document document;
    QVariantToRapidJson(variant,document,document.GetAllocator());
    rapidjson::StringBuffer sb;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
    writer.SetFormatOptions(rapidjson::kFormatSingleLineArray);
    writer.SetMaxDecimalPlaces(precision);
    document.Accept(writer);

    jsonData = sb.GetString();

    return true;
}

bool JsonUtils::schema(std::string &schemaData, std::string &jsonData, std::string& result)
{
    // Read a JSON schema from file into Document
    rapidjson::Document d;
    char buffer[4096];

    {
        FILE *fp = fopen(schemaData.data(), "r");
        if (!fp) {
            printf("Schema file '%s' not found\n", schemaData.data());
            fflush(stdout);
            return -1;
        }
        rapidjson::FileReadStream fs(fp, buffer, sizeof(buffer));
        d.ParseStream(fs);
        if (d.HasParseError()) {
            fprintf(stderr, "Schema file '%s' is not a valid JSON\n", schemaData.data());
            fprintf(stderr, "Error(offset %u): %s\n",
                    static_cast<unsigned>(d.GetErrorOffset()),
                    GetParseError_En(d.GetParseError()));
            fclose(fp);
            fflush(stdout);

            result.append("Schema file is not a valid JSON\n")
                .append(GetParseError_En(d.GetParseError()));
            return false;
        }
        fclose(fp);
    }

    // Then convert the Document into SchemaDocument
    rapidjson::SchemaDocument sd(d);

    // Use reader to parse the JSON in stdin, and forward SAX events to validator
    rapidjson::SchemaValidator validator(sd);
    rapidjson::Reader reader;
    FILE* fpData = fopen(jsonData.data(), "r");
    rapidjson::FileReadStream is(fpData, buffer, sizeof(buffer));
    if (!reader.Parse(is, validator) && reader.GetParseErrorCode() != rapidjson::kParseErrorTermination) {
        // Schema validator error would cause kParseErrorTermination, which will handle it in next step.
        fprintf(stderr, "Input is not a valid JSON\n");
        fprintf(stderr, "Error(offset %u): %s\n",
                static_cast<unsigned>(reader.GetErrorOffset()),
                GetParseError_En(reader.GetParseErrorCode()));

        result.append("Input is not a valid JSON\n")
            .append(GetParseError_En(reader.GetParseErrorCode()));
    }

    // Check the validation result
    if (validator.IsValid()) {
        printf("Input JSON is valid.\n");
        fflush(stdout);
        result = "Input JSON is valid.\n";
        return true;
    }
    else {
        printf("Input JSON is invalid.\n");
        result = "Input JSON is Invalid.\n";
        rapidjson::StringBuffer sb;
        validator.GetInvalidSchemaPointer().StringifyUriFragment(sb);
        fprintf(stderr, "Invalid schema: %s\n", sb.GetString());
        result.append(std::string("Invalid schema:") + sb.GetString() + "\n");
        fprintf(stderr, "Invalid keyword: %s\n", validator.GetInvalidSchemaKeyword());
        result.append(std::string("Invalid keyword:") + validator.GetInvalidSchemaKeyword() + "\n");
        sb.Clear();
        validator.GetInvalidDocumentPointer().StringifyUriFragment(sb);
        fprintf(stderr, "Invalid document: %s\n", sb.GetString());
        fflush(stdout);
        return false;
    }

}

bool JsonUtils::rapidJsonToQVariant(const rapidjson::Value &value, QVariant &variant)
{
    if(value.IsTrue()){
        variant.setValue(true);
    }else if(value.IsFalse()){
        variant.setValue(false);
    }else if(value.IsInt()){
        variant.setValue(value.GetInt());
    }else if(value.IsFloat()){
        variant.setValue(value.GetFloat());
    }else if(value.IsString()){
        variant.setValue(QString(value.GetString()));
    }else if(value.IsObject()){
        QVariantMap varMap;
        auto iter = value.MemberBegin();
        for(; iter != value.MemberEnd(); ++iter){
            QVariant var;
            rapidJsonToQVariant(iter->value,var);
            varMap[iter->name.GetString()] = var;
        }
        variant.setValue(varMap);
    }else if(value.IsArray()){
        QVariantList varList;
        for(rapidjson::SizeType i = 0; i<value.Size();++i){
            const rapidjson::Value& subValue = value[i];
            QVariant var;
            rapidJsonToQVariant(subValue,var);
            varList.push_back(var);
        }
        variant.setValue(varList);
    }
    return true;
}

bool JsonUtils::QVariantToRapidJson(const QVariant &variant, rapidjson::Value &value,
                                    rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> &allcator)
{
    if(!variant.isValid()){
        value.SetNull();
    }else if(variant.type() == QVariant::Bool){
        value.SetBool(variant.toBool());
    }else if(variant.type() == QVariant::Int){
        value.SetInt(variant.toInt());
    }else if(variant.type() == QVariant::Double){
        value.SetDouble(variant.toDouble());
    }else if(variant.type() == QVariant::String){
        QString str = variant.toString();
        int len =str.toUtf8().size();
        value.SetString(str.toUtf8().data(),static_cast<rapidjson::SizeType>(len),allcator);//allcator是否必要？
    }else if(variant.canConvert<QVariantMap>()){
        QVariantMap map = variant.toMap();
        value.SetObject();
        for(auto iter = map.begin(); iter != map.end(); ++iter){
            rapidjson::Value newObject;
            QVariantToRapidJson(iter.value(),newObject,allcator);
            rapidjson::Value newKey;
            std::string keyString = iter.key().toStdString();
            int len = keyString.size();
            newKey.SetString(keyString.data(),static_cast<rapidjson::SizeType>(len),allcator);
            value[newKey] = newObject;
        }
    }else if(variant.canConvert<QVariantList>()){
        QVariantList list = variant.toList();
        value.SetArray();
        foreach (QVariant var, list) {
            rapidjson::Value newObject;
            QVariantToRapidJson(var,newObject,allcator);
            value.PushBack(newObject,allcator);
        }
    }
    return true;
}

QString JsonUtils::errMsg(rapidjson::ParseErrorCode code)
{
    return "error in rapidJson";
}
