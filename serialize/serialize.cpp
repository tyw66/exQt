#include <QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QDataStream>
#include <QBuffer>
#include <QFile>
#include <QList>

class Home
{
public:
  QString m_address;
  qint32 m_age;
};

class Person
{
public:
    int m_age;
    int m_wight;
    QString m_name;
    Home* p_home;

    bool serialize(QDataStream& data);

    bool parse(const QByteArray& data);
};

bool Person::serialize(QDataStream &ss)
{
//    QDataStream ss(data);
    ss << m_name << m_age << m_wight;
    return true;
}

bool Person::parse(const QByteArray &data)
{
    QDataStream ss(data);
    ss >> m_name >> m_age;
    return true;
}



int main(){
    //初始化
    Person p,np;
    p.m_age = 11;
    p.m_name = "tyw66";
    p.m_wight = 33;

    Home h;
    h.m_address = "chengdu-4th-street";
    h.m_age = 26;

    p.p_home = &h;

    //序列化输出到文件
    QByteArray data;
//    data.push_back('Q');
    //p.serialize(data);

    QFile file("./person.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream ds(&file);
     p.serialize(ds);
//    ds << data;
    file.close();

    //读入文件反序列化
    file.open(QIODevice::ReadOnly);
    ds.setDevice(&file);
    ds >> data;
    np.parse(data);

    qDebug()<<np.m_age;
    qDebug()<<np.m_wight;
    qDebug()<<np.m_name;




    return 0;
}










//QDataStream &operator<<(QDataStream &output, const Person &p)
//{
//    output << p.m_name << p.m_age;
//    return output;
//}

//QDataStream &operator>>(QDataStream &input, Person *p)
//{
//    input >> p->m_name >>p->m_age;
//    return input;
//}

//class Home
//{
//public:
//    QString m_address;
//    double m_area;
//    QList<Person*> m_persons;

//    void init();
//    QString serialize();
//    void parse(const QString& msg);

//    //    QDataStream& operator>>(QDataStream& , Home& );
//    //    QDataStream& operator<<(QDataStream& , const Home& );
//};

//QDataStream &operator<<(QDataStream &output, const Home &home)
//{
//    output << home.m_address << home.m_area;

//    foreach (Person* p, home.m_persons) {
//        output << p;
//    }
//    return output;
//}

//QDataStream &operator>>(QDataStream &input, Home &home)
//{
//    input >> home.m_address >>home.m_area;

//    for(int i =0; i < home.m_persons.size(); ++i){
//        input >> home.m_persons[i];
//    }
//    return input;
//}

//void Home::init()
//{
//    Person dad,mom,son;
//    dad.m_age = 60;
//    dad.m_name = "dad";

//    mom.m_age = 58;
//    mom.m_name = "mom";

//    son.m_age = 18;
//    son.m_name = "son";

//    m_address = "Road66-street2333";
//    m_area = 190;
//    m_persons.push_back(&dad);
//    m_persons.push_back(&mom);
//    m_persons.push_back(&son);
//}

//QString Home::serialize()
//{
//    QString s;
//    QByteArray byte;
//    QBuffer buffer(&byte);
//    buffer.open(QIODevice::WriteOnly);

//    QDataStream out(&buffer);
//    out << this;
//    s = byte;

//    buffer.close();
//    return s;
//}

//void Home::parse(const QString &msg)
//{
//    //    QByteArray byte = msg.toLatin1();
//    //    QBuffer buffer(&byte);
//    //    buffer.open(QIODevice::ReadOnly);

//    QFile file("test.txt");
//    file.open(QIODevice::ReadOnly);

//    //    QByteArray byte;



//    QDataStream in(&file);
//    //    Home home;
//    in >> *this;
//    //    return home;
//}



//int main(int argc, char *argv[])
//{
//    //    QCoreApplication a(argc, argv);

//    Person p, np;
//    p.m_age = 66;
//    p.m_name = "tyw666";
//    p.m_wight = 763;

//    QFile file("./persondata.dat");
//    file.open(QIODevice::WriteOnly);

//    QDataStream ds(&file);
//    ds << p.m_age << p.m_wight << p.m_name ;//用QDataStream时不需加分隔符

//    //    QTextStream ts(&file);
//    //    ts << p.m_age << p.m_wight << p.m_name ;//用QTextStream时需加分隔符，否则输入的时候区分不了

//    file.close();
//    qDebug()<<"out finish";


//    file.open(QIODevice::ReadOnly);


//    QDataStream ds2(&file);
//    ds2 >>  np.m_age >> np.m_wight >> np.m_name ;

//    //    QTextStream ts2(&file);
//    //    ts2 >> np.m_age >> np.m_wight >> np.m_name;

//    file.close();
//    qDebug()<<"in finish";

//    qDebug()<<np.m_age;
//    qDebug()<<np.m_wight;
//    qDebug()<<np.m_name;


//    /*
//    Home home;
//    home.init();

//    //    QByteArray byte;
//    //    QDataStream out(byte);
//    //    out << home;


//    //    QByteArray byte;

//    //    QBuffer buffer(&byte);
//    //    buffer.open(QIODevice::WriteOnly);

//    QFile file("test.db");
//    file.open(QIODevice::WriteOnly);

//    QDataStream out(&file);
//    out << home;
//    //    string = QString(byte);

//    //    buffer.close();
//    file.close();

//    QString string;
//    //    QString string = home.serialize();
//    Home home_new;
//    home_new.parse(string);

//    qDebug()<<home.m_persons.at(1)->m_age;
//    qDebug()<<home_new.m_persons.at(1)->m_age;
//*/

//    /*
//    QByteArray ba("汉Qt");
//    std::cout << ba.size() << std::endl;


//    QString str = "tyw66";
//    std::cout << str.size() << std::endl;
//    QChar *ch = str.data();
//    ch++;
//    QString newStr;
//    newStr.push_back(ch->unicode());
//    std::cout << newStr.toStdString() << std::endl;

//    QLatin1String latin("Qt");
//    QString string("Qt");
//    if(latin == string){
//        qDebug()<<"equal.";
//    }

//    if(latin.operator ==(string)){
//        qDebug()<<"equal.";
//    }
//    else {
//        qDebug()<<"not equal.";
//    }
//*/



//    //    return a.exec();
//}



