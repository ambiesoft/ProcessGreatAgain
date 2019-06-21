#include <QFileSystemModel>
#include <QSet>

#include "../../lsMisc/stdQt/stdQt.h"

#include "systemprocessmodel.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace AmbiesoftQt;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QFileSystemModel *model = new QFileSystemModel;
//    model->setRootPath(QDir::currentPath());

    ui->treeMain->setModel(&model_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Test_triggered()
{
    QSet<int> all = GetAllProcessIDs();
    model_.setRawData(all);
}
