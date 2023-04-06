#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // 添加qss
    QFile file(":/main.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());

    ui->setupUi(this);
    this->init();
    this->cont();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    setWindowTitle("Tic-Tac-Toe");
    setFixedSize(630, 800);

    this->clear();

    QLabel *myinfo=new QLabel("   Powered By Lier-accuser | v1.0  ",this);
    ui->statusbar->addPermanentWidget(myinfo);

    if(!info::name1.isEmpty()) n1=info::name1;
    if(!info::name2.isEmpty()) n2=info::name2;

    ui->player1->setText(n1+"：");
    ui->player2->setText(n2+"：");

}

void MainWindow::cont()
{
    connect(ui->label_1, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_2, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_3, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_4, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_5, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_6, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_7, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_8, SIGNAL(click()), this, SLOT(onclick()));
    connect(ui->label_9, SIGNAL(click()), this, SLOT(onclick()));

    connect(ui->restart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->exit, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clear()));

}



void MainWindow::clear()
{
    QLabel* labels[]={ui->label_1,ui->label_2,ui->label_3,
                      ui->label_4,ui->label_5,ui->label_6,
                      ui->label_7,ui->label_8,ui->label_9};
    for(int i=0; i<9; ++i){
        labels[i]->setText("");
    }
    this->num=0;
    player_flag=true;
}


int MainWindow::is_over()
{   // 0--玩家1获胜， 1--玩家2获胜， 2--棋没下完没人获胜， 3--棋下完了平局
    QString stringArray[3][3]={
        {ui->label_1->text(),ui->label_2->text(),ui->label_3->text()},
        {ui->label_4->text(),ui->label_5->text(),ui->label_6->text()},
        {ui->label_7->text(),ui->label_8->text(),ui->label_9->text()}
    };
    // 横着判断
    for(int i=0;i<3;i++){
        if(stringArray[i][0]==stringArray[i][1] && stringArray[i][1]==stringArray[i][2]){
            if(stringArray[i][0]=="⭕" && stringArray[i][1]=="⭕") return 0;
            else if(stringArray[i][0]=="✖️" && stringArray[i][1]=="✖️") return 1;
        }
    }
    // 竖着判断
    for(int j=0;j<3;j++){
        if(stringArray[0][j]==stringArray[1][j] && stringArray[1][j]==stringArray[2][j]){
            if(stringArray[0][j]=="⭕" && stringArray[1][j]=="⭕") return 0;
            else if(stringArray[0][j]=="✖️" && stringArray[1][j]=="✖️") return 1;
        }
    }
    // 斜着判断
    if(stringArray[0][0]==stringArray[1][1] && stringArray[1][1]==stringArray[2][2]){
        if(stringArray[0][0]=="⭕" && stringArray[1][1]=="⭕") return 0;
        else if(stringArray[0][0]=="✖️" && stringArray[1][1]=="✖️") return 1;
    }
    if(stringArray[0][2]==stringArray[1][1] && stringArray[1][1]==stringArray[2][0]){
        if(stringArray[0][2]=="⭕" && stringArray[1][1]=="⭕") return 0;
        else if(stringArray[0][2]=="✖️" && stringArray[1][1]=="✖️") return 1;
    }
    // 没有分出胜负
    if(num==9) return 3;
    return 2;

}

void MainWindow::send_msg(int judge)
{
    if(judge==2) return;

    if(judge==0){
        QString cout = n1+" 获胜";
        QMessageBox::information(this, "获胜", cout);
        int value=ui->score1->text().toInt();
        ++value;
        ui->score1->setText(QString::number(value));
    }
    else if(judge==1){
        QString cout = n2+" 获胜";
        QMessageBox::information(this, "获胜", cout);
        int value=ui->score2->text().toInt();
        ++value;
        ui->score2->setText(QString::number(value));
    }
    else if(judge==3) QMessageBox::information(this, "平局", "平局");
    num=9;   // 快进到结尾
}

void MainWindow::onclick(){
    QLabel* label = qobject_cast<QLabel*>(sender());
    if(label && label->text() == "" && num!=9){
        if(player_flag) label->setText("⭕");
        else label->setText("✖️");
        player_flag=!player_flag;
        this->num++;
        this->send_msg(this->is_over());
    }
    if(num==9) this->clear();
}

void MainWindow::exit()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认退出", "是否确定要退出游戏？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        close();
    }
}

void MainWindow::restart()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认重新开始", "是否确定要重新开始游戏？",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        clear();
        ui->score1->setText(QString::number(0));
        ui->score2->setText(QString::number(0));
    }
}
