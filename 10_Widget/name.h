#ifndef NAME_H
#define NAME_H

#include <QLabel>
#include <QEvent>
class name : public QLabel
{
    Q_OBJECT
public:
    explicit name(QWidget *parent = nullptr);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *ev);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //通过event事件分发器 拦截鼠标按下事件
    bool event(QEvent *e);

signals:

public slots:
};

#endif // NAME_H
