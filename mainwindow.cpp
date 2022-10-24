#include "mainwindow.h"
#include "mainwindow.h"
#include "page_login.h"
#include "ui_mainwindow.h"
#include "stusql.h"
#include "qsqlquery.h"


#include <QRandomGenerator>
#include <QFile>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStuSql(nullptr)
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

    m_ptrStuSql = stusql::getinstance();
    m_ptrStuSql->init();

    m_lNames<<"伍凌凡";
    m_lNames<<"汤采薇";
    m_lNames<<"平宛丹";
    m_lNames<<"发山兰";
    m_lNames<<"愚绍钧";
    m_lNames<<"阴宜人";
    m_lNames<<"区安莲";
    m_lNames<<"狐睿诚";
    m_lNames<<"班冬易";
    m_lNames<<"班乐珞";
    m_lNames<<"年锦宇";
    m_lNames<<"佟半梦";
    m_lNames<<"成访松";
    m_lNames<<"佟白莲";
    m_lNames<<"卞如山";
    m_lNames<<"汉睿凌";
    m_lNames<<"裘宇书";
    m_lNames<<"连半双";
    m_lNames<<"义雪春";
    m_lNames<<"完南笙";
    m_lNames<<"万俟迎";
    m_lNames<<"夏连晨";
    m_lNames<<"风仑安";
    m_lNames<<"亦东寻";
    m_lNames<<"冬兰巧";
    m_lNames<<"芹零山";
    m_lNames<<"云东若";
    m_lNames<<"旋区弘";
    m_lNames<<"业熙雅";
    m_lNames<<"叶佟盼";
    m_lNames<<"山万俟";
    m_lNames<<"云梦连";
    m_lNames<<"俊楚东";
    m_lNames<<"怀南李";
    m_lNames<<"觅枫裘";
    m_lNames<<"夏之费";
    m_lNames<<"采波汉";
    m_lNames<<"依冬司";
    m_lNames<<"马明煦";
    m_lNames<<"司马商";
    m_lNames<<"博袜新";
    m_lNames<<"兰完飞";
    m_lNames<<"玉裘冰";
    m_lNames<<"琴火冬";
    m_lNames<<"山奈成";
    m_lNames<<"业弘乐";
    m_lNames<<"槐回七";
    m_lNames<<"七费思";
    m_lNames<<"菱薇正";
    m_lNames<<"青连盼";
    m_lNames<<"秋公良";
    m_lNames<<"俊侠公";
    m_lNames<<"良问兰";
    m_lNames<<"愚碧秋";
    m_lNames<<"连弘阔";
    m_lNames<<"仑妙山";
    m_lNames<<"费初风";
    m_lNames<<"司马清";
    m_lNames<<"栀遥水";
    m_lNames<<"彤支晴";
    m_lNames<<"君轩灵";
    m_lNames<<"兰撒曼";
    m_lNames<<"玉公良";
    m_lNames<<"高澹仄";
    m_lNames<<"慕柳阴";
    m_lNames<<"从之东";
    m_lNames<<"容鸣酆";
    m_lNames<<"白真金";
    m_lNames<<"雁岚支";
    m_lNames<<"依巧佟";
    m_lNames<<"盼南千";
    m_lNames<<"秋灵公";
    m_lNames<<"良昕依";
    m_lNames<<"司马浩";
    m_lNames<<"阔巴晨";
    m_lNames<<"轩裘昕";
    m_lNames<<"若弘轻";
    m_lNames<<"月裘安";
    m_lNames<<"春东绿";
    m_lNames<<"荷弘翠";
    m_lNames<<"安平冷";
    m_lNames<<"丹佟谷";
    m_lNames<<"青愚玥";
    m_lNames<<"昕平恨";
    m_lNames<<"蓉佟新";
    m_lNames<<"竹万俟";
    m_lNames<<"问风媛";
    m_lNames<<"碧萱愚";
    m_lNames<<"乐天懂";
    m_lNames<<"司夜区";
    m_lNames<<"新翰伍";
    m_lNames<<"春风奈";
    m_lNames<<"若薇年";
    m_lNames<<"少轩区";
    m_lNames<<"若云平";
    m_lNames<<"海秋东";
    m_lNames<<"怀莲兰";
    m_lNames<<"云海袜";
    m_lNames<<"珊芷阴";
    m_lNames<<"之柳回";
    m_lNames<<"嘉佑兰";
    m_lNames<<"沫楹成";
    m_lNames<<"语云千";
    m_lNames<<"南翠兰";
    m_lNames<<"才良班";
    m_lNames<<"咏志回";
    m_lNames<<"采春成";
    m_lNames<<"以彤撒";
    m_lNames<<"乐圣裘";
    m_lNames<<"友竹懂";
    m_lNames<<"笑萱公";
    m_lNames<<"良绮灵";
    m_lNames<<"愚诗夏";
    m_lNames<<"汉南阳";
    m_lNames<<"愚代晴";
    m_lNames<<"佟含阳";
    m_lNames<<"区雪晴";
    m_lNames<<"成靖蕊";
    m_lNames<<"阴安青";
    m_lNames<<"懂沛芹";
    m_lNames<<"义曼萍";
    m_lNames<<"兰枫剑";
    m_lNames<<"公良之";
    m_lNames<<"南裘修";
    m_lNames<<"德阴念";
    m_lNames<<"之阴绿";
    m_lNames<<"薇愚笑";
    m_lNames<<"晴奈绿";
    m_lNames<<"撒夏蓉";


    auto cnt = m_ptrStuSql->getStuCnt();
    QList<StuInfo> lStudents =  m_ptrStuSql->getPageStu(0,cnt);

    ui->tableWidget->setRowCount(cnt);

    for(int i = 0; i<lStudents.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lStudents[i].uiclass)));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(lStudents[i].wechat));
    }


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

void MainWindow::on_btn_simulation_clicked()
{
    QStringList l;

    QRandomGenerator g,c;
    g.seed(0);
    c.seed(0);


    //1000 num
    for(int i = 0;i<m_lNames.size();i++)
    {

        auto grade = g.bounded(7,10);
        auto uiclass = g.bounded(1,8);

        StuInfo info;
        info.name = m_lNames[i];
        if(i%3){
             info.age = 15;
        }
        if(i%7){
             info.age = 16;
        }
        if(i%2){
             info.age = 17;
        }
        info.grade = grade;
        info.uiclass = uiclass;
        info.studentid = 1;
        info.phone = "13883566666";
        info.wechat = "13883566666";

        m_ptrStuSql->addStu(info);
    }

}
