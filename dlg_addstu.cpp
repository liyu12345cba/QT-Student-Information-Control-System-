#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"

#include <QMessageBox>

Dlg_AddStu::Dlg_AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddStu)
{
    ui->setupUi(this);
}

Dlg_AddStu::~Dlg_AddStu()
{
    delete ui;
}

void Dlg_AddStu::setType(bool isAdd, StuInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->le_name->setText(info.name);
    ui->sb_age->setValue(info.age);
    ui->le_class->setText(QString::number(info.uiclass));
    ui->le_grade->setText(QString::number(info.grade));
    ui->le_phone->setText(info.phone);
    ui->le_weichat->setText(info.wechat);
}


void Dlg_AddStu::on_btn_save_clicked()
{
    StuInfo info;
    auto ptr = stusql::getinstance();
    info.name = ui->le_name->text();
    info.age = ui->sb_age->text().toUInt();
    info.uiclass = ui->le_class->text().toUInt();
    info.grade = ui->le_grade->text().toUInt();
    info.phone = ui->le_phone->text();
    info.wechat = ui->le_weichat->text();

    if(m_isAdd)
    {
        ptr->addStu(info);
    }
    else
    {
        ptr->UpdateStuInfo(info);
    }

    QMessageBox::information(nullptr,"HEY","save success!");
    this->hide();
}

void Dlg_AddStu::on_btn_cancle_clicked()
{
    this->hide();
}
