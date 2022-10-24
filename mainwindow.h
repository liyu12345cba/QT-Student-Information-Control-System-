#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "page_login.h"
#include "stusql.h"

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     virtual void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_exit_clicked();


    void on_btn_simulation_clicked();

private:
    Ui::MainWindow *ui;
    Page_Login m_dlgLogin;
    stusql *m_ptrStuSql;
    QStringList m_lNames;
};
#endif // MAINWINDOW_H
