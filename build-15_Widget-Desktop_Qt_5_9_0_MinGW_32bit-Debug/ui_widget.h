/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextEdit *text_read;
    QTextEdit *text_write;
    QPushButton *btn_send;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_close;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(673, 497);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        text_read = new QTextEdit(Widget);
        text_read->setObjectName(QStringLiteral("text_read"));
        text_read->setReadOnly(true);

        gridLayout->addWidget(text_read, 0, 0, 1, 3);

        text_write = new QTextEdit(Widget);
        text_write->setObjectName(QStringLiteral("text_write"));

        gridLayout->addWidget(text_write, 1, 0, 1, 3);

        btn_send = new QPushButton(Widget);
        btn_send->setObjectName(QStringLiteral("btn_send"));

        gridLayout->addWidget(btn_send, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        btn_close = new QPushButton(Widget);
        btn_close->setObjectName(QStringLiteral("btn_close"));

        gridLayout->addWidget(btn_close, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        btn_send->setText(QApplication::translate("Widget", "send", Q_NULLPTR));
        btn_close->setText(QApplication::translate("Widget", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
