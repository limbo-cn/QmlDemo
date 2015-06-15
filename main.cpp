#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <mctrl.h>
#include <qqml.h>
#include <QStandardItemModel>
#include <QStandardItem>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //建立数据库连接
    MCtrl mc;
    mc.createConnection();

    //绑定虚拟数据
    mc.DataBind();
    mc.selectAll();

    //注册方法
    qmlRegisterType<MCtrl>("Limbo.Test", 1, 0, "MCtrl");


    QQmlApplicationEngine engine;

    QQmlContext *ctx= engine.rootContext();

//    QStandardItemModel* cppmodel = new QStandardItemModel();
//    for (int i=0; i<100; i++) {
//        QStandardItem* item = new QStandardItem(QString("%1").arg(i,2,10,QChar('0')));
//        cppmodel->appendRow(item);
//    }
//    ctx->setContextProperty("cppModel",cppmodel);

    ctx->setContextProperty("ats",mc.AlarmModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
