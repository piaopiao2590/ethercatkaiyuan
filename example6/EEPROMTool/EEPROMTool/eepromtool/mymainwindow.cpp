#include "mymainwindow.h"
#include "ui_mymainwindow.h"

/* 解决窗口中文乱码 */
#pragma execution_character_set("utf-8")

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    QFile styleSheet(":/qss/myMainwindow.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
    {
        qWarning("Can't open the style sheet file.");
        return;
    }
    this->setStyleSheet(styleSheet.readAll());
    getEthInfo();
    QObject::connect(ui->pushButton_scan,&QPushButton::clicked,this,&MyMainWindow::pushButton_scan_clicked);
    QObject::connect(ui->pushButton_open,&QPushButton::clicked,this,&MyMainWindow::pushButton_open_clicked);
    QObject::connect(ui->pushButton_read,&QPushButton::clicked,this,&MyMainWindow::pushButton_read_clicked);
    QObject::connect(ui->pushButton_write,&QPushButton::clicked,this,&MyMainWindow::pushButton_write_clicked);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}


/**
 * @brief myMainWindow::getEthInfo
 * 获取网卡信息
 */
void MyMainWindow::getEthInfo(void)
{
    ec_adaptert * adapter = NULL;
    adapter = ec_find_adapters ();
    while(adapter != NULL)
    {
        ui->comboBox_eth->addItem(QString::fromUtf8(adapter->desc,-1));
        ethinfo.insert(adapter->desc,adapter->name);
        adapter = adapter->next;
    }
}

void MyMainWindow::pushButton_open_clicked(void)
{
    QFileDialog *dlg = new QFileDialog();
    QString filepath = dlg->getOpenFileName(this,"打开文件","/","file(*.bin)");
    ui->lineEdit_file->setText(filepath);
//    QFileInfo finfo  = QFileInfo(filepath);
//    QString filename = finfo.fileName();
//    ui->lineEdit_file->setText(filename);

//    file->setFileName(filepath);
//    filesize = finfo.size();
}

void MyMainWindow::pushButton_scan_clicked(void)
{
    int w, wkc = 0;
    char *eth0;
    /* 获取网卡 */
    /* 获取网卡 */
    ifname = ui->comboBox_eth->currentText();
    QByteArray ba = ethinfo[ifname].toLatin1();
    eth0 = ba.data();
    if (ec_init(eth0))
    {
       w = 0x0000;
        wkc = ec_BRD(0x0000, ECT_REG_TYPE, sizeof(w), &w, EC_TIMEOUTSAFE);      /* detect number of slaves */
        if (wkc > 0)
        {
          ec_slavecount = wkc;
          ui->textBrowser->append(QString::asprintf("%d slaves found.\n",ec_slavecount));

          for(w = 1; w<=ec_slavecount;w++)
          {
            ui->comboBox_slave->addItem(QString::number(w));
          }
        }else{
            ui->textBrowser->append("no slave find");
        }
     }
}

void MyMainWindow::pushButton_write_clicked(void)
{
    QString filepath = ui->lineEdit_file->text();
    QFileInfo finfo  = QFileInfo(filepath);
    int filesize = finfo.size();
    QFile *readfile = new QFile(filepath);
    readfile->open(QIODevice::ReadOnly);
    if(readfile == false)
    {
        ui->textBrowser->append("open file fail");
        return;
    }
    memset(ebuf,0,MAXBUF);
    readfile->read((char *)ebuf,filesize);
    uint16 *wbuf = (uint16 *)&ebuf[0];
    int slave = ui->comboBox_slave->currentText().toUInt();
    ui->textBrowser->append(QString::asprintf("Slave %d data\n", slave));
    ui->textBrowser->append(QString::asprintf(" PDI Control      : %4.4X\n",*(wbuf + 0x00)));
    ui->textBrowser->append(QString::asprintf(" PDI Config       : %4.4X\n",*(wbuf + 0x01)));
    ui->textBrowser->append(QString::asprintf("Config Alias     : %4.4X\n",*(wbuf + 0x04)));
    ui->textBrowser->append(QString::asprintf(" Checksum         : %4.4X\n",*(wbuf + 0x07)));
    ui->textBrowser->append(QString::asprintf(" Vendor ID        : %8.8X\n",*(uint32 *)(wbuf + 0x08)));
    ui->textBrowser->append(QString::asprintf(" Product Code     : %8.8X\n",*(uint32 *)(wbuf + 0x0A)));
    ui->textBrowser->append(QString::asprintf(" Revision Number  : %8.8X\n",*(uint32 *)(wbuf + 0x0C)));
    ui->textBrowser->append(QString::asprintf(" Serial Number    : %8.8X\n",*(uint32 *)(wbuf + 0x0E)));
    ui->textBrowser->append(QString::asprintf(" Mailbox Protocol : %4.4X\n",*(wbuf + 0x1C)));
    if((slave>0)&&(slave <= ec_slavecount))
        eeprom_write(slave,0, filesize);
}

void MyMainWindow::pushButton_read_clicked(void)
{
    int slave,esize;
    unsigned short *wbuf;
    /* 设置保存名字 */
    QFileDialog *dlg = new QFileDialog();
    QString filepath = dlg->getSaveFileName(this,"打开文件","/","file(*.bin)");
    QFileInfo finfo  = QFileInfo(filepath);
    QString filename = finfo.fileName();
    /* 读取前128字节EEPROM内容　*/
    slave = ui->comboBox_slave->currentText().toUInt();
    memset(ebuf,0,MAXBUF);

    if((slave>0)&&(slave <= ec_slavecount))
    {
        eeprom_read(slave, 0x0000, MINBUF);
        wbuf = (unsigned short *)&ebuf[0];
        ui->textBrowser->append(QString::asprintf("Slave %d data\n", slave));
        ui->textBrowser->append(QString::asprintf(" PDI Control      : %4.4X\n",*(wbuf + 0x00)));
        ui->textBrowser->append(QString::asprintf(" PDI Config       : %4.4X\n",*(wbuf + 0x01)));
        ui->textBrowser->append(QString::asprintf("Config Alias     : %4.4X\n",*(wbuf + 0x04)));
        ui->textBrowser->append(QString::asprintf(" Checksum         : %4.4X\n",*(wbuf + 0x07)));
        ui->textBrowser->append(QString::asprintf(" Vendor ID        : %8.8X\n",*(uint32 *)(wbuf + 0x08)));
        ui->textBrowser->append(QString::asprintf(" Product Code     : %8.8X\n",*(uint32 *)(wbuf + 0x0A)));
        ui->textBrowser->append(QString::asprintf(" Revision Number  : %8.8X\n",*(uint32 *)(wbuf + 0x0C)));
        ui->textBrowser->append(QString::asprintf(" Serial Number    : %8.8X\n",*(uint32 *)(wbuf + 0x0E)));
        ui->textBrowser->append(QString::asprintf(" Mailbox Protocol : %4.4X\n",*(wbuf + 0x1C)));
        esize = (*(wbuf + 0x3E) + 1) * 128;
        if (esize > MAXBUF) esize = MAXBUF;
        ui->textBrowser->append(QString::asprintf(" Size             : %4.4X = %d bytes\n",*(wbuf + 0x3E), esize));
        ui->textBrowser->append(QString::asprintf(" Version          : %4.4X\n",*(wbuf + 0x3F)));
        /* 读取剩下的字节 */
        if (esize > MINBUF) eeprom_read(slave, MINBUF, esize - MINBUF);
        /* 打开文件，准备保存 */
        QFile *savefile = new QFile(filepath);
        savefile->open(QIODevice::WriteOnly);
        if(savefile == false)
        {
            ui->textBrowser->append("open file fail");
            return;
        }
        savefile->write((char *)ebuf,esize);
        savefile->close();
    }

}

void MyMainWindow::eeprom_read(int slave, int start, int length)
{
    int i, wkc, ainc = 4;
    uint16 estat, aiadr;
    uint32 b4;
    uint64 b8;
    uint8 eepctl;

    if((ec_slavecount >= slave) && (slave > 0) && ((start + length) <= MAXBUF))
    {
       aiadr = 1 - slave;
       eepctl = 2;
       wkc = ec_APWR(aiadr, ECT_REG_EEPCFG, sizeof(eepctl), &eepctl , EC_TIMEOUTRET3); /* force Eeprom from PDI */
       eepctl = 0;
       wkc = ec_APWR(aiadr, ECT_REG_EEPCFG, sizeof(eepctl), &eepctl , EC_TIMEOUTRET3); /* set Eeprom to master */

       estat = 0x0000;
       aiadr = 1 - slave;
       wkc=ec_APRD(aiadr, ECT_REG_EEPSTAT, sizeof(estat), &estat, EC_TIMEOUTRET3); /* read eeprom status */
       estat = etohs(estat);
       /* 8字节读取 */
       if (estat & EC_ESTAT_R64)
       {
          ainc = 8;
          for (i = start ; i < (start + length) ; i+=ainc)
          {
             b8 = ec_readeepromAP(aiadr, i >> 1 , EC_TIMEOUTEEP);
             ebuf[i] = (uint8) b8;
             ebuf[i+1] = (uint8) (b8 >> 8);
             ebuf[i+2] = (uint8) (b8 >> 16);
             ebuf[i+3] = (uint8) (b8 >> 24);
             ebuf[i+4] = (uint8) (b8 >> 32);
             ebuf[i+5] = (uint8) (b8 >> 40);
             ebuf[i+6] = (uint8) (b8 >> 48);
             ebuf[i+7] = (uint8) (b8 >> 56);
          }
       }
       else
       {
          /* 4字节读取 */
          for (i = start ; i < (start + length) ; i+=ainc)
          {
             b4 = (uint32)ec_readeepromAP(aiadr, i >> 1 , EC_TIMEOUTEEP);
             ebuf[i] = (uint8) b4;
             ebuf[i+1] = (uint8) (b4 >> 8);
             ebuf[i+2] = (uint8) (b4 >> 16);
             ebuf[i+3] = (uint8) (b4 >> 24);
          }
       }
    }
}

void MyMainWindow::eeprom_write(int slave, int start, int length)
{
    int i, wkc;
    uint16 aiadr, *wbuf;
    uint8 eepctl;
    int ret;

    if((ec_slavecount >= slave) && (slave > 0) && ((start + length) <= MAXBUF))
    {
       aiadr = 1 - slave;
       eepctl = 2;
       wkc = ec_APWR(aiadr, ECT_REG_EEPCFG, sizeof(eepctl), &eepctl , EC_TIMEOUTRET3); /* force Eeprom from PDI */
       eepctl = 0;
       wkc = ec_APWR(aiadr, ECT_REG_EEPCFG, sizeof(eepctl), &eepctl , EC_TIMEOUTRET3); /* set Eeprom to master */

       aiadr = 1 - slave;
       wbuf = (uint16 *)&ebuf[0];
       for (i = start ; i < (start + length) ; i+=2)
       {
          ret = ec_writeeepromAP(aiadr, i >> 1 , *(wbuf + (i >> 1)), EC_TIMEOUTEEP);
          Sleep(1);
       }
    }
}


