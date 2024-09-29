#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <inttypes.h>
#include "ethercat.h"


#define MAXBUF 32768
#define STDBUF 2048
#define MINBUF 128

QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void pushButton_scan_clicked(void);
    void pushButton_open_clicked(void);
    void pushButton_write_clicked(void);
    void pushButton_read_clicked(void);

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
    void getEthInfo(void);
    void eeprom_read(int slave, int start, int length);
    void eeprom_write(int slave, int start, int length);

private:
    Ui::MyMainWindow *ui;
    QMap<QString,QString> ethinfo;  /* 存放网卡信息 */
    QString ifname;                 /* 网卡名字 */
    QFile *file;
    unsigned char ebuf[MAXBUF];
};
#endif // MYMAINWINDOW_H
