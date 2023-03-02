#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QObject>

class WidgetManager : public QObject
{
    Q_OBJECT
public:
    explicit WidgetManager(QObject *parent = nullptr);

signals:

};

#endif // WIDGETMANAGER_H
