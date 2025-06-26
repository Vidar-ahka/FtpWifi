#include "main/mainwindow.h"
#include "ui_mainwindow.h"
#include"file/file.h"
#include"iostream"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile file("C:\\zakazs\\thermal.c");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout<<file.readAll().toStdString();

    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

