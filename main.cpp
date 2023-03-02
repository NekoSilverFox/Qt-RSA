#include "widgetmanager.h"
#include "rsa.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetManager widgetManger;

    return a.exec();
}

