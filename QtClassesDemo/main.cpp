#include <QCoreApplication>
#include <QDate>
#include <QTime>
#include <QDateTime>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    QCoreApplication a(argc, argv);

    /*
        *******
        QString
        *******
    */
    qInfo() << "QString demo";

    QString s1 {"Hello World"};
    qInfo() << s1.mid(1, 3);
    qInfo() << s1.insert(1, 'E');
    qInfo() << s1.split(" ");

    QString s2 {"Mr. Akkas Ali Khan"};

    qsizetype dotIndex = s2.indexOf('.');
    if(dotIndex > -1)
    {
        qInfo() << s2.remove(0, dotIndex + 1).trimmed();
    }

    qInfo() << "";

    /*
        *************************************************************
        QStringList: Based on QList with extra string functionalities
        *************************************************************
    */
    qInfo() << "QStringList Demo";

    QString s3 {"Apple"};
    QString s4 {"Orange"};
    QString s5 {"Pear"};

    QStringList strList;

    strList << s3 << s4 << s5;
    qInfo() << strList;

    QString s345 = strList.join(" ") + "!";
    qInfo() << s345;

    qInfo() << "";

    /*
        *****************************************************
        QByteArray: It gives us more control over string data
        *****************************************************
    */
    qInfo() << "QByteArray Demo";

    QByteArray s3ByteArray {s3.toUtf8()};
    qInfo() << s3ByteArray.rightJustified(20, '.');
    // Changing to different encoding system
    qInfo() << s3ByteArray.toBase64();

    qInfo() << "";

    /*
        ******************************************************
        QVariant: It adds dynamic typing functionality in C++
        ******************************************************
    */
    qInfo() << "QVariant Demo";

    QVariant varA {5};
    QVariant varB {"Hello World!"};

    // Converting them back to regular types
    int integerA;
    bool conversionASucceded;
    integerA = varA.toInt(&conversionASucceded);

    if(conversionASucceded)
    {
        qInfo() << integerA;
    }
    else
    {
        qInfo() << "The QVariant cannot be converted to an int";
    }

    int integerB;
    bool conversionBSucceded;
    integerB = varB.toInt(&conversionBSucceded);

    if(conversionBSucceded)
    {
        qInfo() << integerB;
    }
    else
    {
        qInfo() << "The QVariant cannot be converted to an int";
    }

    qInfo() << "";

    /*
        *****
        QList
        *****
    */
    qInfo() << "QList Demo";

    QList<QString> fruits {"Apple", "Banana", "Pear"};

    QListIterator<QString> fruitsIterator {fruits};
    while(fruitsIterator.hasNext())
    {
        qInfo() << fruitsIterator.next();
    }

    qInfo() << "";

    /*
        *****
        QMap
        *****
    */

    qInfo() << "QMap Demo";

    QMap<int, QString> fruitMap;
    fruitMap.insert(1, "Apple");
    fruitMap.insert(2, "Orange");
    fruitMap.insert(3, "Pear");

    for(auto &key : fruitMap.keys())
    {
        qInfo() << key << fruitMap.value(key);
    }

    qInfo() << "";

    /*
        *************
        Date and Time
        *************
    */

    // QDate
    qInfo() << "QDate Demo";

    QDate today {QDate::currentDate()};
    qInfo() << today;

    // Outputting date in different formats
    qInfo() << "Different Formats";
    qInfo() << today.toString(Qt::DateFormat::ISODate);
    qInfo() << today.toString(Qt::DateFormat::ISODateWithMs);
    qInfo() << today.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << today.toString(Qt::DateFormat::TextDate);

    qInfo() << "";

    // Manipulating Date
    qInfo() << "Manipulaitng date";
    qInfo() << today.addDays(1);
    qInfo() << today.addDays(-5);
    qInfo() << today.addYears(20);

    qInfo() << "";

    //  QTime
    qInfo() << "QTime Demo";

    QTime now {QTime::currentTime()};
    qInfo() << now;

    // Outputting time in different formats
    qInfo() << "Different Formats";
    qInfo() << now.toString(Qt::DateFormat::ISODate);
    qInfo() << now.toString(Qt::DateFormat::ISODateWithMs);
    qInfo() << now.toString(Qt::DateFormat::RFC2822Date);
    qInfo() << now.toString(Qt::DateFormat::TextDate);

    qInfo() << "";

    // Manipulaitng time
    qInfo() << now.addSecs(120);

    qInfo() << "";

    // QDateTime
    qInfo() << "QDateTime Demo";

    QDateTime nowDateTime {QDateTime::currentDateTime()};
    qInfo() << nowDateTime;

    return a.exec();
}
