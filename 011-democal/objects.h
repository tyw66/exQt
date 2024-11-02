#ifndef AREADIALOG_H
#define AREADIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QUuid>

#define PI 3.1415926

/**
 * @brief 属性编辑窗体基类
 */
class EditAttrWidget : public QWidget{
public:
    EditAttrWidget(QWidget* parent = NULL);
    virtual void setData(QObject* data) = 0;
    virtual void getData(QObject* data) = 0;
};


/**
 * @brief 形状基类
 */
class Shape : public QObject{
public:
    Shape();
    virtual ~Shape();
    ///返回对象唯一的ID
    QUuid uid() const;
    ///名称的取值设值
    QString name() const;
    void setName(const QString &name);

    ///计算形状面积
    virtual double calulateArea() = 0;
    ///计算形状周长
    virtual double calulatePerimeter() = 0;
    ///设置参数
    virtual void setParameters(const QStringList &parameters) = 0;
    ///参数输入窗体
    virtual QWidget* createPropertyWidget() = 0;


protected:
    QUuid m_uid;
    QString m_name;
};



/**
 * @brief 圆形类
 */
class Circle : public Shape{
public:
    Circle();
    double calulateArea();
    double calulatePerimeter();
    EditAttrWidget* createPropertyWidget();
    void setParameters(const QStringList &parameters);

private:
    double m_radius;
};


/**
 * @brief 矩形类
 */
class Rectangle : public Shape{
public:
    Rectangle();
    double calulateArea();
    double calulatePerimeter();
    QWidget* createPropertyWidget();
    void setParameters(const QStringList &parameters);


private:
    double m_width;
    double m_height;
};



/**
 * @brief 计算面积和周长
 */
class AreaDialog : public QDialog
{
    Q_OBJECT

public:
    AreaDialog(QWidget *parent = NULL);
    ~AreaDialog();


private:
    void initUI();

private slots:
    void onShapeTypeChanged(int index);
    void onCalculate();




private:
    QComboBox * m_combox_type;

    Circle m_circle;
    Rectangle m_rectangle;

    QWidget* m_circleWidget;
    QWidget* m_rectangleWidget;


};
#endif // AREADIALOG_H
