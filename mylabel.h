#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

signals:
    void click();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // MYLABEL_H
