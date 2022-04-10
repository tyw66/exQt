#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>

/*----------------定义数据类Plot----------------------*/
class Plot {
public:
    Plot() {qDebug()<<"Plot()";m_value=0;}
    virtual ~Plot(){qDebug()<<"~Plot()";}

    int getValue() const;
    void setValue(int value);

protected:
    int m_value;
};

inline int Plot::getValue() const
{
    return m_value;
}

inline void Plot::setValue(int value)
{
    m_value = value;
}

/*------------------定义子类ColorPlot----------------------*/
class ColorPlot : public Plot {
public:
    void print(){qDebug() << "The Value is " << m_value;}
};


/*------------------测试例子----------------------*/
///裸指针
void case00(){
    Plot* f = new Plot;
    f->setValue(7);
    qDebug() << f->getValue();

    //对象f没有被析构，内存泄漏
    //所以需要调用一次：
    delete f;
}

///概述
void case01(){
    Plot* f = new Plot;
    QSharedPointer<Plot> f1 = QSharedPointer<Plot>(f);
    f1->setValue(7);
    qDebug() << f1->getValue();

    //退出作用域时，智能指针对象f1被析构，
    //它所“指向”的指针f已经没有任何其他智能指针“指向”它了，所以f的内存也自动析构了
    //不会发生内存泄漏
}

///初始化
void case02(){
    //最好在new的时候就用QSharedPointer封装，并管理起来，不要直接用裸指针
    QSharedPointer<Plot> f = QSharedPointer<Plot>(new Plot());
    f->setValue(7);
    qDebug() << f->getValue();

    //[tip] 1.使用智能指针包装后，不要直接去删除指针对象。
    //Qt会提示："shared QObject was deleted directly. The program is malformed and may crash."

    //[tip] 2.也不要多次使用同一裸指针构造QSharedPointer。
    //crashed: “pointer 0x1f0a8f0 already has reference counting”
}

///判空与删除
void case03(){
    QSharedPointer<Plot> s1;
    QSharedPointer<Plot> s2 = QSharedPointer<Plot>();
    QSharedPointer<Plot> s3 = QSharedPointer<Plot>(new Plot());
    qDebug() << s1.isNull();//true
    qDebug() << s2.isNull();//true
    qDebug() << s3.isNull();//false

    //用'.'来使用智能指针自身的方法；用'->'使用指向的对象的方法，调用前需要先判空。
    if(!s3.isNull()){
        s3->setValue(7);
        qDebug() << s3->getValue();
    }
    //用clear()清空s3的指向
    s3.clear();
    qDebug() << s3.isNull();//true

}

///引用计数(强)
void case04(){
    QSharedPointer<Plot> s1;
    QSharedPointer<Plot> s2 = QSharedPointer<Plot>(new Plot());
    s1 = s2; //让s1也指向s2所指向的内存区域
    QSharedPointer<Plot> s3 = QSharedPointer<Plot>(s2);//让s3也指向s2所指向的内存区域

    //通过调试能看到，一个QSharedPointer的内部保存有一个强引用计数和一个弱引用计数，即对指向的那一片内存的引用计数。
    //此时，s1 s2 s3的引用计数都一样：强引用为3，弱引用为3
    s1.clear();//s2 s3的引用计数都一样：强引用为2，弱引用为2
    s2.clear();//s3的引用计数：强引用为1，弱引用为1
    s3.clear();//内存释放

    //只有s1,s2,s3的指向都被清空，实际对象才会被析构，内存才会被释放
}

///引用计数(强&弱)
void case05(){
    QSharedPointer<Plot> s1;
    QSharedPointer<Plot> s2 = QSharedPointer<Plot>(new Plot());
    s1 = s2; //让s1也指向s2所指向的内存区域

    QWeakPointer<Plot> w1 = QWeakPointer<Plot>(s1);//初始化QWeakPointer
    QWeakPointer<Plot> w2;
    w1 = s1; //初始化QWeakPointer
    QWeakPointer<Plot> w3(s2);

    //s1 s2 w1 w2 w3都指向同一片内存，这片内存的引用计数：强引用为2，弱引用为4
    s1.clear();//引用计数：强引用为2，弱引用为4
    w1.clear();//引用计数：强引用为1，弱引用为3
    s2.clear();//引用计数：强引用为0，弱引用为0

    //无论w1 w2 w3怎么样，只有s1,s2的指向都被清空，
    //Foo的这个对象才会被析构，w1 w2 w3会被自动clear，内存才会被释放
    qDebug() << w3.isNull();//true
}

///弱指针
void case06(){
    QSharedPointer<Plot> s1 = QSharedPointer<Plot>(new Plot());
    QWeakPointer<Plot> w1 = QWeakPointer<Plot>(s1);
    s1->setValue(7);

    if(!s1.isNull()){
        qDebug() << s1->getValue();//7
    }
    if(!w1.toStrongRef().isNull()){
        //弱指针无法操纵数据，必须转为强指针
        //用toStrongRef()将弱引用转为强引用，来调用成员方法
        qDebug() << w1.toStrongRef()->getValue();//7
        w1.toStrongRef()->setValue(66);
        qDebug() << w1.toStrongRef()->getValue();//66
    }

    //[tip] 通常，要使用弱指针，必须将其转换为共享指针，因为这样的操作确保了只要您使用它就会生存。
    //这相当于“锁定”访问的对象，并且是使用弱指针指向的对象的唯一正确方法。并且转换后使用前需要判空。
}

///类型转换
void case07(){
    QSharedPointer<Plot> s1 = QSharedPointer<ColorPlot>(new ColorPlot());
    QSharedPointer<ColorPlot> s2 = s1.dynamicCast<ColorPlot>(); // dynamicCast<T>()
    if(!s2.isNull()){
        s2->setValue(7);
        s2->print();//调用子类方法
    }
}

///参数传递
void case08(){
    //TODO
}



/*------------------主程序----------------------*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    case08();
}


/*------------------Extra----------------------*/
//[tip] 1.让数据用智能指针管理；窗体控件用Qt父子层级(不用智能指针)。
//[tip] 2.不使用裸指针作为接口参数，代码里面最好没有用到QSharedPointer::data()或者QWeakPointer::data()
//[tip] 3.数据管理类持有强指针成员，其他类持有弱指针成员，强指针作为参数传递。






