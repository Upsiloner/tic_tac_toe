#include "mylabel.h"

myLabel::myLabel(QWidget *parent)
{
    this->setParent(parent);
}

void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit click();
    }

}
