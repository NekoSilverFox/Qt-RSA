/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_13;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLabel *lb_p;
    QLabel *label_2;
    QLabel *lb_q;
    QLabel *label_3;
    QLabel *lb_n;
    QLabel *label_4;
    QLabel *lb_fn;
    QLabel *label_5;
    QLabel *lb_e;
    QLabel *label_6;
    QLabel *lb_d;
    QPushButton *btnGenerateNewRSAParameters;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLineEdit *le_privete_n;
    QLabel *label_15;
    QLineEdit *le_privete_d;
    QLabel *label_14;
    QPushButton *btnReset;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *le_public_n;
    QLineEdit *le_public_e;
    QPushButton *btnSendPublicKey;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_22;
    QTextBrowser *tbCodedText;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_23;
    QTextBrowser *tbExplicitText;
    QPushButton *btnDecrypt;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(434, 779);
        verticalLayout_3 = new QVBoxLayout(Client);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_13 = new QLabel(Client);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font;
        font.setPointSize(32);
        font.setBold(true);
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_13);

        groupBox = new QGroupBox(Client);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(widget_5);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(15, 16777215));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        lb_p = new QLabel(widget_5);
        lb_p->setObjectName(QString::fromUtf8("lb_p"));

        gridLayout_4->addWidget(lb_p, 0, 1, 1, 1);

        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        lb_q = new QLabel(widget_5);
        lb_q->setObjectName(QString::fromUtf8("lb_q"));

        gridLayout_4->addWidget(lb_q, 0, 3, 1, 1);

        label_3 = new QLabel(widget_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(15, 16777215));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        lb_n = new QLabel(widget_5);
        lb_n->setObjectName(QString::fromUtf8("lb_n"));

        gridLayout_4->addWidget(lb_n, 1, 1, 1, 1);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(30, 16777215));

        gridLayout_4->addWidget(label_4, 1, 2, 1, 1);

        lb_fn = new QLabel(widget_5);
        lb_fn->setObjectName(QString::fromUtf8("lb_fn"));

        gridLayout_4->addWidget(lb_fn, 1, 3, 1, 1);

        label_5 = new QLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(15, 16777215));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        lb_e = new QLabel(widget_5);
        lb_e->setObjectName(QString::fromUtf8("lb_e"));

        gridLayout_4->addWidget(lb_e, 2, 1, 1, 1);

        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 2, 2, 1, 1);

        lb_d = new QLabel(widget_5);
        lb_d->setObjectName(QString::fromUtf8("lb_d"));

        gridLayout_4->addWidget(lb_d, 2, 3, 1, 1);


        verticalLayout_4->addWidget(widget_5);

        btnGenerateNewRSAParameters = new QPushButton(groupBox);
        btnGenerateNewRSAParameters->setObjectName(QString::fromUtf8("btnGenerateNewRSAParameters"));

        verticalLayout_4->addWidget(btnGenerateNewRSAParameters);


        verticalLayout_3->addWidget(groupBox);

        widget = new QWidget(Client);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        le_privete_n = new QLineEdit(groupBox_2);
        le_privete_n->setObjectName(QString::fromUtf8("le_privete_n"));

        gridLayout_2->addWidget(le_privete_n, 2, 1, 1, 1);

        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 1, 0, 1, 1);

        le_privete_d = new QLineEdit(groupBox_2);
        le_privete_d->setObjectName(QString::fromUtf8("le_privete_d"));

        gridLayout_2->addWidget(le_privete_d, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMaximumSize(QSize(15, 16777215));

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

        btnReset = new QPushButton(groupBox_2);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));

        gridLayout_2->addWidget(btnReset, 3, 0, 1, 2);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMaximumSize(QSize(15, 16777215));

        gridLayout_3->addWidget(label_19, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMaximumSize(QSize(15, 16777215));

        gridLayout_3->addWidget(label_20, 1, 0, 1, 1);

        le_public_n = new QLineEdit(groupBox_3);
        le_public_n->setObjectName(QString::fromUtf8("le_public_n"));

        gridLayout_3->addWidget(le_public_n, 1, 1, 1, 1);

        le_public_e = new QLineEdit(groupBox_3);
        le_public_e->setObjectName(QString::fromUtf8("le_public_e"));

        gridLayout_3->addWidget(le_public_e, 0, 1, 1, 1);

        btnSendPublicKey = new QPushButton(groupBox_3);
        btnSendPublicKey->setObjectName(QString::fromUtf8("btnSendPublicKey"));

        gridLayout_3->addWidget(btnSendPublicKey, 2, 0, 1, 2);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_3->addWidget(widget);

        widget_3 = new QWidget(Client);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_22 = new QLabel(widget_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout->addWidget(label_22);

        tbCodedText = new QTextBrowser(widget_3);
        tbCodedText->setObjectName(QString::fromUtf8("tbCodedText"));

        verticalLayout->addWidget(tbCodedText);


        verticalLayout_3->addWidget(widget_3);

        widget_4 = new QWidget(Client);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_2 = new QVBoxLayout(widget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_23 = new QLabel(widget_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_2->addWidget(label_23);

        tbExplicitText = new QTextBrowser(widget_4);
        tbExplicitText->setObjectName(QString::fromUtf8("tbExplicitText"));

        verticalLayout_2->addWidget(tbExplicitText);

        btnDecrypt = new QPushButton(widget_4);
        btnDecrypt->setObjectName(QString::fromUtf8("btnDecrypt"));

        verticalLayout_2->addWidget(btnDecrypt);


        verticalLayout_3->addWidget(widget_4);

        QWidget::setTabOrder(btnGenerateNewRSAParameters, le_privete_d);
        QWidget::setTabOrder(le_privete_d, le_privete_n);
        QWidget::setTabOrder(le_privete_n, btnReset);
        QWidget::setTabOrder(btnReset, le_public_e);
        QWidget::setTabOrder(le_public_e, le_public_n);
        QWidget::setTabOrder(le_public_n, btnSendPublicKey);
        QWidget::setTabOrder(btnSendPublicKey, tbCodedText);
        QWidget::setTabOrder(tbCodedText, tbExplicitText);
        QWidget::setTabOrder(tbExplicitText, btnDecrypt);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Form", nullptr));
        label_13->setText(QCoreApplication::translate("Client", "Client", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Client", "RSA Parameter Information", nullptr));
        label->setText(QCoreApplication::translate("Client", "p:", nullptr));
        lb_p->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "q:", nullptr));
        lb_q->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        label_3->setText(QCoreApplication::translate("Client", "n:", nullptr));
        lb_n->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        label_4->setText(QCoreApplication::translate("Client", "\317\206(n):", nullptr));
        lb_fn->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        label_5->setText(QCoreApplication::translate("Client", "e:", nullptr));
        lb_e->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        label_6->setText(QCoreApplication::translate("Client", "d:", nullptr));
        lb_d->setText(QCoreApplication::translate("Client", "NONE", nullptr));
        btnGenerateNewRSAParameters->setText(QCoreApplication::translate("Client", "Generate new RSA parameter", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Client", "Private Key", nullptr));
        label_15->setText(QCoreApplication::translate("Client", "d:", nullptr));
        label_14->setText(QCoreApplication::translate("Client", "n:", nullptr));
        btnReset->setText(QCoreApplication::translate("Client", "Reset", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Client", "Public Key", nullptr));
        label_19->setText(QCoreApplication::translate("Client", "e:", nullptr));
        label_20->setText(QCoreApplication::translate("Client", "n:", nullptr));
        btnSendPublicKey->setText(QCoreApplication::translate("Client", "Send Public key", nullptr));
        label_22->setText(QCoreApplication::translate("Client", "Coded text", nullptr));
        label_23->setText(QCoreApplication::translate("Client", "Explicit text", nullptr));
        btnDecrypt->setText(QCoreApplication::translate("Client", "\360\237\224\223Decrypted text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
