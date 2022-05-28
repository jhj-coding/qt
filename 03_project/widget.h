#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <mypushbutton.h>
#include <student.h>
#include <teacher.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Student *st;
    Teacher *tc;
    void classIsOver();
    void classIsOver(QString foodName);
};

#endif // WIDGET_H
