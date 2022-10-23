#include "stusql.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlQuery>
#include <qdebug.h>
#include <QSqlError>

stusql::stusql(QObject *parent) : QObject(parent)
{
      init();

//      StuInfo s;
//      s.name = "steve";
//      for(int i =0;i<10;i++)
//      {
//          addStu(s);
//      }

//      getStuCnt();

//      getPageStu(2,3);

//      delStu(13);

//      StuInfo s;
//      s.id = 8;
//      s.name = "cha";
//      UpdateStuInfo(s);

      UserInfo info;
      info.username = "LEE";
      info.password = "123456";
      info.aut = "admin";

      AddUser(info);
      AddUser(info);
      auto l = getALLUser();
      qDebug()<<isExit("LEE");

      info.password = "666";
      updateUser(info);
      delUser("LEE");
}

void stusql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
#if 0
    auto str = QCoreApplication::applicationDirPath()+"data.db";
    qDebug()<<str;
#endif

    m_db.setDatabaseName("C:\\data.db");
    if(!m_db.open())
        qDebug()<<"db not open";
}

quint32 stusql::getStuCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 uiCnt = 0;
    while(sql.next())
    {
        uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

QList<StuInfo> stusql::getPageStu(quint32 page, quint32 uiCnt)
{
    QList<StuInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from student order by id limit %1 offset %2").
            arg(uiCnt).arg(page*uiCnt);
    sql.exec("strsql");

    StuInfo info;

    while(sql.next())
    {
        info.id = sql.value(0).toUInt();
        info.name = sql.value(1).toString();
        info.age = sql.value(2).toUInt();
        info.grade = sql.value(3).toUInt();
        info.uiclass = sql.value(4).toUInt();
        info.studentid = sql.value(5).toUInt();
        info.phone = sql.value(6).toString();
        info.wechat = sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

bool stusql::addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7')").
            arg(info.name).
            arg(info.age).
            arg(info.grade).
            arg(info.uiclass).
            arg(info.studentid).
            arg(info.phone).
            arg(info.wechat);
    return sql.exec(strSql);
}

bool stusql::delStu(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1").arg(id));;
}

bool stusql::clearStuTable()
{
    QSqlQuery sql(m_db);
    return sql.exec("delete from student");
}

bool stusql::UpdateStuInfo(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =
            QString("update student set name = '%1',age=%2,grade=%3,class=%4,studentid=%5,"
                    "phone='%6',wechat='%7' where id = %8").
            arg(info.name).
            arg(info.age).
            arg(info.grade).
            arg(info.uiclass).
            arg(info.studentid).
            arg(info.phone).
            arg(info.wechat).arg(info.id);

    bool ret = sql.exec(strSql);
    QSqlError e = sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

QList<UserInfo> stusql::getALLUser()
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from username");

    UserInfo info;
    while(sql.next())
    {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.aut = sql.value(2).toString();

        l.push_back(info);
    }
    return l;
}

bool stusql::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec (QString("select *from username where username = '%1'").arg(strUser));
    return sql.next();
}

bool stusql::updateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql =
            QString("update username set password='%1',auth='%2' where username = '%3'").

            arg(info.password).
            arg(info.aut).
            arg(info.username);

    bool ret = sql.exec(strSql);
    QSqlError e = sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

bool stusql::AddUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into username values ('%1', '%2','%3')").
            arg(info.username).
            arg(info.password).
            arg(info.aut);

    return sql.exec(strSql);
}

bool stusql::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
    return sql.exec (QString("delete from username where username ='%1'").arg(strUserName));

}
