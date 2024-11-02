#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <rapidjson/document.h>
#include <QVariant>

class JsonUtils
{
public:
    static bool readFromFile(const QString& filePath, QVariant& data);
    static bool writeToFile(QVariant& data,const QString& filePath, int precision);

    static bool read(std::string& jsonData, QVariant & data);
    static bool write(const QVariant & variant, std::string& jsonData,int precision);

    static bool schema(std::string& schemaData, std::string& jsonData, std::string &result);

private:
    static bool rapidJsonToQVariant(const rapidjson::Value& value, QVariant& data);
    static bool QVariantToRapidJson(const QVariant& variant, rapidjson::Value& value,
                                    rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>& allcator);

    static QString errMsg(rapidjson::ParseErrorCode code);

};

#endif // JSONUTILS_H
