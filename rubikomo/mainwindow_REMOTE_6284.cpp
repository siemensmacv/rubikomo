#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_view2D = new View2D(ui->horizontalLayoutWidget_2, &controllerRubik.model);
    //m_view3D = new View3D(&controllerRubik.model);

    float tabWidth = (ui->tabWidget->width()*3-34);
    ui->tabWidget->setStyleSheet("QTabWidget QTabBar::tab{width:" + QString::number(tabWidth) + "px; }");
    ui->tabWidget->setCurrentIndex(2);

    ui->horizontalLayout->insertLayout(0, m_view2D->getLayout());
    //ui->gridLayout_3->addWidget(m_view3D->getContainer());

    connectFlatButtonsToSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectFlatButtonsToSlots()
{
    connect(ui->pushButton_BR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_B_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_DR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_D_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_FR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_F_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_LR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_L_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_RR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_R_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_UR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_U_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_XR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_X_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_YR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_Y_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_ZR_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(ui->pushButton_Z_2D, &QPushButton::clicked, this, &MainWindow::handleButton);
}

void MainWindow::handleButton()
{
    QString senderName = sender()->objectName();
    if(senderName == "pushButton_U_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Up);
    }
    else if(senderName == "pushButton_UR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Up);
    }
    else if(senderName == "pushButton_D_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Down);
    }
    else if(senderName == "pushButton_DR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Down);
    }
    else if(senderName == "pushButton_F_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Front);
    }
    else if(senderName == "pushButton_FR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Front);
    }
    else if(senderName == "pushButton_B_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Back);
    }
    else if(senderName == "pushButton_BR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Back);
    }
    else if(senderName == "pushButton_L_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Left);
    }
    else if(senderName == "pushButton_LR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Left);
    }
    else if(senderName == "pushButton_R_2D")
    {
        controllerRubik.rotateFaceClockwise(RubikFace::Right);
    }
    else if(senderName == "pushButton_RR_2D")
    {
        controllerRubik.rotateFaceCounterClockwise(RubikFace::Right);
    }
    else if(senderName == "pushButton_X_2D")
    {
        controllerRubik.rotateXAxisClockwise();
    }
    else if(senderName == "pushButton_XR_2D")
    {
        controllerRubik.rotateXAxisCounterClockwise();
    }
    else if(senderName == "pushButton_Y_2D")
    {
        controllerRubik.rotateYAxisClockwise();
    }
    else if(senderName == "pushButton_YR_2D")
    {
        controllerRubik.rotateYAxisCounterClockwise();
    }
    else if(senderName == "pushButton_Z_2D")
    {
        controllerRubik.rotateZAxisClockwise();
    }
    else if(senderName == "pushButton_ZR_2D")
    {
        controllerRubik.rotateZAxisCounterClockwise();
    }
}
