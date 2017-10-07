#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    face = new FaceCube2D(ui->gridLayoutWidget);
    ui->gridLayout->addWidget(face, 0, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
