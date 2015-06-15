

#include "QtSql/qsqldatabase.h"
#include <mctrl.h>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QLibrary>



QSqlDatabase db;
/**
 *函数介绍：创建数据库连接
 *输入参数：
 *返回值：无
 */
void MCtrl::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    // 对于express版本数据库,要加\\sqlexpress后缀 SERVER=58.67.161.109\\sqlexpress
    QString dsn = "DRIVER={SQL SERVER};SERVER=192.168.10.120;DATABASE=IVS_API;UID=sa;PWD=123456;";
    db.setHostName("192.168.10.120");   //数据库服务器
    db.setDatabaseName(dsn);   //数据库名
    if(!db.open ())
    {
        qDebug()<<"0";
    }
    else
    {
        qDebug()<<"1";
    }
}



void MCtrl::DataBind()
{
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");
    dataList.append("Item 4");

}


void MCtrl::selectAll()
{
//    AlarmModel->setColumnCount(6);
//    AlarmModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("1")));
//    AlarmModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("2")));
//    AlarmModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("3")));
//    AlarmModel->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("4")));
//    AlarmModel->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("5")));
//    AlarmModel->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("6")));



    QSqlQuery query;
    if(query.exec("select top 100 * from [tab_OriginalAlarmInfo] order by [int_Alarm_Index] DESC"))
    {
    int i=0;
    while(query.next())
        {
         qDebug()<<"0";
        AlarmModel->setItem(i,0,new QStandardItem(query.value(0).toString()));
        AlarmModel->setItem(i,1,new QStandardItem(query.value(1).toString()));
        AlarmModel->setItem(i,2,new QStandardItem(query.value(2).toString()));
        AlarmModel->setItem(i,3,new QStandardItem(query.value(3).toString()));
        AlarmModel->setItem(i,4,new QStandardItem(query.value(4).toString()));
        AlarmModel->setItem(i,5,new QStandardItem(query.value(5).toString()));
       //  AlarmModel->setItem(i,new QStandardItem(query.value(1).toString()));
        i++;
        }
    }




}
