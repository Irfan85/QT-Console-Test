#include "reciever.h"

Reciever::Reciever(QObject *parent)
    : QObject{parent}
{

}

void Reciever::recieveMessage(QString &message)
{
    qDebug() << "The message is: " << message << '\n';
}
