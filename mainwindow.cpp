#include "mainwindow.h"
#include "mainwindow.h"
#include "page_login.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_dlgLogin.show();
    auto f = [&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);

    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"Stuent Control System";
    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);

    l.clear();
    l<<"Student Control";
    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);

    l.clear();
    l<<"Admin Control";
    QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

    pf->addChild(p1);
    pf->addChild(p2);

    ui->treeWidget->expandAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F6)
    {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        this->setStyleSheet(strQss);
        m_dlgLogin.setStyleSheet(strQss);
    }
}


void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}
