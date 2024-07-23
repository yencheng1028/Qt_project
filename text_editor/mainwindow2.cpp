#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
    ui->plainTextEdit->setPlainText("Switched to second screen!");
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
