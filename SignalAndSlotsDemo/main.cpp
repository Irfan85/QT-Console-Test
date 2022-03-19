#include <QCoreApplication>

#include "sender.h"
#include "reciever.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sender s;
    Reciever r;

    QObject::connect(&s, &Sender::sendMessage, &r, &Reciever::recieveMessage);

    QString str {"Hello World!"};
    s.send(str);

    return a.exec();
}
