#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QString>
#include "mainwindow.h"
#include <QFile>

namespace Ui {
class info;
}


class info : public QWidget
{
    Q_OBJECT

public:
    explicit info(QWidget *parent = nullptr);
    ~info();

    static QString name1;
    static QString name2;

private:
    Ui::info *ui;

private slots:
    void start();
};

#endif // INFO_H
