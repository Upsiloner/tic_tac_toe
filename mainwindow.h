#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QThread>
#include <QString>
#include <QMessageBox>
#include "info.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void init();
    void cont();
    //void clear();    // 清空棋盘
    int is_over();   // 判断是否已经有一方胜利
    void send_msg(int judge);   // 根据判断出的结果，推送提示消息

    int num=0;       // 已经下了的棋子个数
    bool player_flag=true;

    QString n1="玩家1";
    QString n2="玩家2";


private slots:
    void onclick();
    void exit();
    void restart();
    void clear();
};
#endif // MAINWINDOW_H
