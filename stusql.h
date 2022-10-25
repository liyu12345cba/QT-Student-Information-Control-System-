#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlDatabase>


struct StuInfo
{
    int id;
    QString name;
    quint8 age;
    quint16 grade;
    quint16 uiclass;
    quint32 studentid;
    QString phone;
    QString wechat;
};
struct UserInfo
{
    QString username;
    QString password;
    QString aut;
};

class stusql : public QObject
{
    Q_OBJECT
public:
    static stusql *ptrstuSql;
    static stusql *getinstance()
    {
        if(nullptr == ptrstuSql)
        {
            ptrstuSql = new stusql;
        }
        return ptrstuSql;

    }

    explicit stusql(QObject *parent = nullptr);

    void init();

    //search all student
    quint32 getStuCnt();

    //search the page of imformation of student
    QList<StuInfo> getPageStu(quint32 page, quint32 uiCnt);

    //add student
    bool addStu(StuInfo);

    //delete studetn
    bool delStu(int id);

    //clear the table of student
    bool clearStuTable();

    //edit imformation of student
    bool UpdateStuInfo(StuInfo info);

    //search all students
    QList<StuInfo> getALLStu();

    //search all User
    QList<UserInfo> getALLUser();

    //search if the user exit;
    bool isExit(QString strUser);

    //edit the imformation of user
    bool updateUser(UserInfo info);

    //add single user
    bool AddUser(UserInfo info);

    //delete user
    bool delUser(QString strUserName);
signals:
private:
    QSqlDatabase m_db;

};

#endif // STUSQL_H
