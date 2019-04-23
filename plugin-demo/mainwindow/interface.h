#ifndef INTERFACE_H
#define INTERFACE_H

#include <QImage>
/**
 * @brief 接口类
 * @note 需要由插件来实现（提供）以下的这些虚函数
 */
class ImgInterface
{
public:
    virtual ~ImgInterface(){}
    virtual void paintImg(QImage& img) = 0;
};

//在QT元对象系统中注册该接口，第二个参数确保这个接口与其他接口不会相同
Q_DECLARE_INTERFACE(ImgInterface, "tyw66.ImgInterface/1.0")

#endif // INTERFACE_H
