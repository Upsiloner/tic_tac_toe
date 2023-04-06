#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    // 添加qss
    QFile file(":/info.qss");
    file.open(QIODevice::ReadOnly);
    setStyleSheet(file.readAll());

    ui->setupUi(this);
    setWindowTitle("Before begin");
    connect(ui->start, SIGNAL(clicked()), this, SLOT(start()));
}

info::~info()
{
    delete ui;
}

QString info::name1;
QString info::name2;

void info::start()
{
    name1=ui->lineEdit->text();
    name2=ui->lineEdit_2->text();

    MainWindow* main=new MainWindow;
    main->show();

    close();
}
