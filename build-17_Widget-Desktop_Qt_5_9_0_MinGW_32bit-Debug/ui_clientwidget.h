/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QLabel *label;
    QLineEdit *ip;
    QLabel *label_2;
    QLineEdit *port;
    QPushButton *btn_connect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(589, 442);
        label = new QLabel(ClientWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 40, 72, 15));
        ip = new QLineEdit(ClientWidget);
        ip->setObjectName(QStringLiteral("ip"));
        ip->setGeometry(QRect(210, 40, 113, 21));
        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 80, 72, 15));
        port = new QLineEdit(ClientWidget);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(220, 80, 113, 21));
        btn_connect = new QPushButton(ClientWidget);
        btn_connect->setObjectName(QStringLiteral("btn_connect"));
        btn_connect->setGeometry(QRect(350, 60, 93, 28));

        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250ip", Q_NULLPTR));
        ip->setText(QApplication::translate("ClientWidget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", Q_NULLPTR));
        port->setText(QApplication::translate("ClientWidget", "8888", Q_NULLPTR));
        btn_connect->setText(QApplication::translate("ClientWidget", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
