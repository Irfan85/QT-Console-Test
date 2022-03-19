#include <QCoreApplication>
#include <QFile>

// This this example, we will read data from a CSV file
int main(int argc, char *argv[])
{
    // QList will have the rows. Each row will have columns in QStringList format
    QVector<QStringList> data;

    // We have to specify absolute path as relative paths doesn't seem to work here.
    // If we use relative paths, it shows that the file content is empty
    QFile csvFile {"D:\\Projects\\C++_Projects\\QT-Console-Test\\QFileDemo\\SampleCSV.csv"};

    if(csvFile.open(QIODevice::ReadOnly)) {
        // We can pass the file in a QTextStream which gives us a convenient way
        // to read/write from file/strings using stream operators

        QTextStream inputStream {&csvFile};
//        qDebug() << inputStream.readAll();

        while(true) {
            QString line {inputStream.readLine()};

            if(line.isNull()) {
                break;
            } else if(line.isEmpty()) {
                continue;
            }

            QStringList row;

            for(const QString &column : line.split(",")) {
                row.append(column.trimmed());
            }

            data.append(row);
        }
    }

    csvFile.close();

    QTextStream cout {stdout, QIODevice::WriteOnly};

    for(const QStringList &row : data) {
        for(const QString &column : row) {
            cout << column << '\t';
        }

        cout << '\n';
    }

    return 0;
}
