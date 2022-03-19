#include "sender.h"

Sender::Sender(QObject *parent)
    : QObject{parent}
{

}

void Sender::send(QString &message)
{
    emit sendMessage(message);
}
