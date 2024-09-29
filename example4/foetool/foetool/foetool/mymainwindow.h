#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <inttypes.h>
#include "ethercat.h"
#include "foeapp.h"

/* 解决MSVC编译器中 窗口名称乱码 */
#pragma execution_character_set("utf-8")

QT_BEGIN_NAMESPACE
namespace Ui { class myMainWindow; }
QT_END_NAMESPACE

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = nullptr);
    ~myMainWindow();
private slots:
    void pushButton_connect_clicked(void);
    void pushButton_open_clicked(void);
    void pushButton_write_clicked(void);
    void pushButton_read_clicked(void);
    void foe_read_hook(unsigned int size);
    void foe_write_hook(unsigned int size);
private:
    void getEthInfo(void);
    void setBootstrap(void);
private:
    Ui::myMainWindow *ui;
    QMap<QString,QString> ethinfo;  /* 存放网卡信息 */
    QString ifname;                 /* 网卡名字 */
    QThread *foethread;             /* FOE通信的线程 */
    foeApp *foe;
    unsigned int foereadsize;       /* 读取的文件的大小 */
    unsigned int foewritesize;      /* 已发送文件的大小 */
    unsigned char buf[200];         /* 收发数据缓存地址 */
    QFile *file;
};
#endif // MYMAINWINDOW_H
