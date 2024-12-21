#include "main/mainwindow.h"
#include "ui_mainwindow.h"
#include"file/file.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    File file(std::move(File("C:/qt_project/conwife/headers/bridge.h")));


    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

