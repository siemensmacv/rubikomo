#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rubik2dhandler.h"
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Rubik2DHandler *handler;
};

#endif // MAINWINDOW_H
