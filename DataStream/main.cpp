#include <QCoreApplication>
#include <vector>
#include <QFile>
#include <QDataStream>
#include <QDebug>

struct Body
{
    double weight;
    double height;

    //因为二元运算符重载以某个类的成员函数形式实现时，左运算数必然为该类型
    //所以使用friend
    friend QDataStream &operator<<(QDataStream& input, const Body& body){
        input << body.weight << body.height;
        return input;
    }

    friend QDataStream& operator>>(QDataStream& output, Body& body){
        output >> body.weight>> body.height;
        return output;
    }


   //


};

//结构体
struct People
{
    int age;
    Body dBody;//结构体
    std::vector<QString> vecfamily;//vector

    //序列化
    friend QDataStream &operator<<(QDataStream& input,const People &iteam)
    {
        //vector 数据类型需要用vector<People>::fromStdVector 转一下
        //如果是QList则不需要直接插入
        QVector<QString> strvecfamily = QVector<QString>(iteam.vecfamily.begin(), iteam.vecfamily.end());
        input << iteam.age << iteam.dBody << strvecfamily;
        return input;
    }
    //反序列化
    friend QDataStream &operator>>(QDataStream& output,People& iteam)
    {
        QVector<QString> vecfamily;
        output >> iteam.age >> iteam.dBody >> vecfamily;
        iteam.vecfamily = std::vector<QString>(vecfamily.begin(), vecfamily.end());
        return output;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 0
    People p1;
    p1.age = 12;
    p1.dBody.height = 150.8;
    p1.dBody.weight = 50;
    p1.vecfamily.push_back("sister");
    p1.vecfamily.push_back("mother");
    p1.vecfamily.push_back("father");
    QFile file("./stream.bat");
    if(!file.open(QIODevice::WriteOnly))
    {
        return -1;
    }
    QDataStream input(&file);
    input << p1;
    file.close();
    People p2;
    QFile file1("./stream.bat");//.bat文件为二进制文件
    if(!file1.open(QIODevice::ReadOnly))
    {
        return -1;
    }
    QDataStream output(&file1);
    output << p2;
    file.close();

    output >> p2;
    //结果12 150.8 50 std::vector("sister", "mother", "father")
    qDebug()<<p2.age
           <<p2.dBody.height
          <<p2.dBody.weight
         <<p2.vecfamily;

#else
    Body b1;
    b1.height = 99;
    b1.weight = 66;

    QFile file("./body.dat");
    if(!file.open(QIODevice::WriteOnly)){
        return -1;
    }

    QDataStream outStream(&file);
    outStream << b1;
    file.close();

    Body b2;
    if(!file.open(QIODevice::ReadOnly)){
        return -1;
    }
    QDataStream inStream(&file);
    inStream >> b2;
    file.close();

    qDebug() << "height=" << b2.height << " "
             << "weight=" << b2.weight;

#endif




    return a.exec();
}



