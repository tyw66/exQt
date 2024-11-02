#include "objects.h"

EditAttrWidget::EditAttrWidget(QWidget* parent):QWidget(parent)
{

}


///////////////////////////////////////////////////////////////
Shape::Shape()
{
   m_uid = QUuid::createUuid();
   m_name = "Undefined";

}

Shape::~Shape()
{
}

QUuid Shape::uid() const
{
    return m_uid;
}

QString Shape::name() const
{
    return m_name;
}

void Shape::setName(const QString &name)
{
    m_name = name;
}



//////////////////////////////////////////////////////////////
Circle::Circle()
{
    m_radius = 1.0;
    m_name = tr("Circle");

}

double Circle::calulateArea()
{
    if(m_radius < 0){
        return -1;
    }else{
        return PI * m_radius * m_radius;
    }
}

double Circle::calulatePerimeter()
{
    if(m_radius < 0){
        return -1;
    }else{
        return PI * m_radius * 2;
    }
}

EditAttrWidget *Circle::createPropertyWidget()
{
    EditAttrWidget* widget = new EditAttrWidget();

    QGridLayout* cicleLayout = new QGridLayout(0);
    QLabel* label_radius = new QLabel(tr("Radius"));
    cicleLayout->addWidget(label_radius,0,0);
    QLineEdit* lineEdit_radius = new QLineEdit();
    cicleLayout->addWidget(lineEdit_radius,0,1);

    widget->setLayout(cicleLayout);
    return widget;
}

void Circle::setParameters(const QStringList &parameters)
{
    if(!parameters.empty()){
        m_radius = parameters[0].toDouble();
    }
}


///////////////////////////////////////////////////////////////
Rectangle::Rectangle()
{
    m_width = 1.0;
    m_height = 1.0;
    m_name = tr("Rectangle");


    m_propertyWidget = createPropertyWidget();
}

double Rectangle::calulateArea()
{
    if(m_width < 0 || m_height < 0){
        return -1;
    }
    else{
        return m_width * m_height;
    }
}

double Rectangle::calulatePerimeter()
{
    if(m_width < 0 || m_height < 0){
        return -1;
    }
    else{
        return 2*(m_width + m_height);
    }
}

QWidget *Rectangle::createPropertyWidget()
{
    QWidget* widget = new QWidget();

    //
    QGridLayout *rectLayout = new QGridLayout(0);
    QLabel* label_width = new QLabel(tr("Width"));
    rectLayout->addWidget(label_width,0,0);
    QLineEdit* lineEdit_width = new QLineEdit();
    rectLayout->addWidget(lineEdit_width,0,1);

    QLabel* label_height = new QLabel(tr("Height"));
    rectLayout->addWidget(label_height,1,0);
    QLineEdit* lineEdit_height = new QLineEdit();
    rectLayout->addWidget(lineEdit_height,1,1);

    widget->setLayout(rectLayout);
    return widget;
}

void Rectangle::setParameters(const QStringList &parameters)
{
    if(parameters.size() > 1){
        m_width = parameters[0].toDouble();
        m_height = parameters[1].toDouble();
    }
    else if(parameters.size() == 1){
        m_width = m_height = parameters[0].toDouble();
    }
    else{
        m_width = m_height = 1.0;
    }
}


////////////////////////////////////////////////////////////

AreaDialog::AreaDialog(QWidget *parent)
    : QDialog(parent)
    ,m_combox_type(NULL)
    ,m_circleWidget(NULL)
    ,m_rectangleWidget(NULL)
{
    initUI();
}

AreaDialog::~AreaDialog()
{
}

void AreaDialog::initUI()
{
    //
    QGridLayout* mainLayout = new QGridLayout(0);
    QLabel* label_shape = new QLabel(tr("Shape"),this);
    m_combox_type = new QComboBox(this);
    m_combox_type->addItem(tr("Circle"),"Circle");
    m_combox_type->addItem(tr("Rectangle"),"Rectangle");
    connect(m_combox_type, SIGNAL(currentIndexChanged(int)),
            this,SLOT(onShapeTypeChanged(int)));


    mainLayout->addWidget(label_shape,0,0);
    mainLayout->addWidget(m_combox_type,0,1);

    m_circleWidget = m_circle.createPropertyWidget();
    m_rectangleWidget = m_rectangle.createPropertyWidget();

    mainLayout->addWidget(m_circleWidget,1,0,1,2);
    mainLayout->addWidget(m_rectangleWidget,2,0,1,2);

    QLabel* label_out = new QLabel(tr("Output"),this);
    label_out->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(label_out,3,0,1,2);

    QLabel* label_area = new QLabel(tr("Area"),this);
    mainLayout->addWidget(label_area,4,0);
    QLineEdit* lineEdit_area = new QLineEdit(this);
    mainLayout->addWidget(lineEdit_area,4,1);

    QLabel* label_perimeter = new QLabel(tr("Perimeter"),this);
    mainLayout->addWidget(label_perimeter,5,0);
    QLineEdit* lineEdit_perimeter = new QLineEdit(this);
    mainLayout->addWidget(lineEdit_perimeter,5,1);


    QPushButton* button_cal = new QPushButton(tr("Calculate"), this);
    connect(button_cal, SIGNAL(clicked()),
            this,SLOT(onCalculate()));
    mainLayout->addWidget(button_cal,6,0,1,2);

    setLayout(mainLayout);

}



void AreaDialog::onShapeTypeChanged(int index)
{
    QString type = m_combox_type->currentData().toString();
    if(type.toLower() == "circle"){
        m_circleWidget->setHidden(false);
        m_rectangleWidget->setHidden(true);
    }else{
        m_circleWidget->setHidden(true);
        m_rectangleWidget->setHidden(false);
    }
}

void AreaDialog::onCalculate()
{
    QString type = m_combox_type->currentData().toString();
    if(type.toLower() == "circle"){

    }else{

    }
}














