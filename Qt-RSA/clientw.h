#ifndef CLIENTW_H
#define CLIENTW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class client; }
QT_END_NAMESPACE

class client : public QWidget
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();

private:
    Ui::client *ui;
};
#endif // CLIENTW_H
