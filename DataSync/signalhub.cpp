#include "signalhub.h"
SignalHub *SignalHub::m_self = NULL;
SignalHub *SignalHub::inst()
{
    if(!m_self){
        m_self = new SignalHub();
    }
    return m_self;
}
SignalHub::SignalHub(QObject *parent) : QObject(parent)
{

}

void SignalHub::emitCurrentSelectIDChanged(const QString& msg)
{
    emit currentSelectIDChanged(msg);
}

