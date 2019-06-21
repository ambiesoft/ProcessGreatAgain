#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "systemprocessmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
     SystemProcessModel model_;

private slots:
    void on_action_Test_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
