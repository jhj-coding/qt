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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_port;
    QLabel *label_2;
    QLineEdit *lineEdit_ip;
    QTextEdit *textEdit_read;
    QTextEdit *textEdit_2;
    QPushButton *send;
    QSpacerItem *horizontalSpacer;
    QPushButton *close;
    QPushButton *connect;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(622, 438);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ClientWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_port = new QLineEdit(ClientWidget);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        gridLayout->addWidget(lineEdit_port, 0, 1, 1, 2);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_ip = new QLineEdit(ClientWidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 1, 1, 1, 2);

        textEdit_read = new QTextEdit(ClientWidget);
        textEdit_read->setObjectName(QStringLiteral("textEdit_read"));
        textEdit_read->setReadOnly(true);

        gridLayout->addWidget(textEdit_read, 2, 0, 1, 4);

        textEdit_2 = new QTextEdit(ClientWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        gridLayout->addWidget(textEdit_2, 3, 0, 1, 4);

        send = new QPushButton(ClientWidget);
        send->setObjectName(QStringLiteral("send"));

        gridLayout->addWidget(send, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(397, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        close = new QPushButton(ClientWidget);
        close->setObjectName(QStringLiteral("close"));

        gridLayout->addWidget(close, 4, 3, 1, 1);

        connect = new QPushButton(ClientWidget);
        connect->setObjectName(QStringLiteral("connect"));

        gridLayout->addWidget(connect, 0, 3, 2, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", Q_NULLPTR));
        lineEdit_port->setText(QApplication::translate("ClientWidget", "8888", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250ip", Q_NULLPTR));
        lineEdit_ip->setText(QApplication::translate("ClientWidget", "127.0.0.1", Q_NULLPTR));
        send->setText(QApplication::translate("ClientWidget", "send", Q_NULLPTR));
        close->setText(QApplication::translate("ClientWidget", "close", Q_NULLPTR));
        connect->setText(QApplication::translate("ClientWidget", "connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
