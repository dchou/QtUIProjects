#include <QCoreApplication>
#include "httpdownloadresume.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HttpDownloadResume x;
    return a.exec();
}
