#include "mymainwindow.h"
#include "ui_mymainwindow.h"

myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
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
    /* FOE 线程 */
    foethread = new QThread();
    foe = new foeApp();
    foe->moveToThread(foethread);
    foethread->start();

    QObject::connect(ui->pushButton_connect,&QPushButton::clicked,this,&myMainWindow::pushButton_connect_clicked);
    QObject::connect(ui->pushButton_open,&QPushButton::clicked,this,&myMainWindow::pushButton_open_clicked);
    QObject::connect(ui->pushButton_read,&QPushButton::clicked,this,&myMainWindow::pushButton_read_clicked);
    QObject::connect(ui->pushButton_write,&QPushButton::clicked,this,&myMainWindow::pushButton_write_clicked);
    QObject::connect(foe,&foeApp::foewrite,this,&myMainWindow::foe_write_hook);
    QObject::connect(foe,&foeApp::foeread,this,&myMainWindow::foe_read_hook);
}

myMainWindow::~myMainWindow()
{
    delete ui;
}


/**
 * @brief myMainWindow::getEthInfo
 * 获取网卡信息
 */
void myMainWindow::getEthInfo(void)
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

void myMainWindow::pushButton_open_clicked(void)
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



void myMainWindow::pushButton_write_clicked(void)
{
    int pswd = 123456;
    QString name = "app.bin";
    QString filepath = ui->lineEdit_file->text();
    QFileInfo finfo  = QFileInfo(filepath);
    int filesize = finfo.size();
    file = new QFile(filepath);
    file->open(QIODevice::ReadOnly);
    if(file == false)
    {
        ui->textBrowser->append("open file fail");
        return;
    }
    foewritesize = 0;
    foe->setFoeinfo(filesize,(char *)&name,pswd);
    foe->taskWrite();
}

void myMainWindow::pushButton_read_clicked(void)
{
    int pswd = 123456;
    QString name = "app.bin";
    /* 设置保存名字 */
    QFileDialog *dlg = new QFileDialog();
    QString filepath = dlg->getSaveFileName(this,"打开文件","/","file(*.bin)");
//    QFileInfo finfo  = QFileInfo(filepath);
//    QString filename = finfo.fileName();
    file = new QFile(filepath);
    file->open(QIODevice::WriteOnly);
    if(file == false)
    {
        ui->textBrowser->append("open file fail");
        return;
    }
    foe->setFoeinfo(0,(char *)&name,pswd);
    foereadsize = 0;
    /* 启动FOE */
    foe->taskRead();
}

/**
 * @brief ParameterWidget::foe_read_hook
 * FOE读信号槽函数
 * @param size 已经读取的总字节数
 */
void myMainWindow::foe_read_hook(unsigned int size)
{
    memcpy(buf,foe->filebuf,size-foereadsize);
    file->write((char *)buf,size-foereadsize);
    /* 如果新接收的数据长度小于最大的长度，说明是最后一包 */
    if((size-foereadsize)<foe->maxsize)
    {
        QMessageBox::information(this, tr("确认"),  tr("读取完成"));
        file->close();
    }
    foereadsize = size;
}

/**
 * @brief ParameterWidget::foe_write_hook
 * FOE写信号槽函数
 * @param size 剩余文件的总长度
 */
void myMainWindow::foe_write_hook(unsigned int size)
{

    memset(buf,0,foe->maxsize);
    memset(foe->filebuf,0,foe->maxsize);
    /* 剩余的文件长度大于单词发送最大文件长度 */
    if(size>=foe->maxsize)
    {
        file->read((char *)buf,foe->maxsize);
        memcpy(foe->filebuf,buf,foe->maxsize);
        foewritesize = foewritesize + foe->maxsize;
    }else{
        file->read((char *)buf,size);
        memcpy(foe->filebuf,buf,size);
        foewritesize = foewritesize + size;
        /* 弹出提示框 */
        QMessageBox::information(this, tr("确认"),  tr("写入完成"));
        file->close();
    }
}


void myMainWindow::pushButton_connect_clicked(void)
{
    char *eth0;
    /* 获取网卡 */
    /* 获取网卡 */
    ifname = ui->comboBox_eth->currentText();
    QByteArray ba = ethinfo[ifname].toLatin1();
    eth0 = ba.data();
    if (ec_init(eth0))
    {
        ui->textBrowser->append("init eth0 successed ");
        ui->textBrowser->append(QString::asprintf("ifname dese is %s",eth0));
        /* 扫描从站 */
        if ( ec_config_init(FALSE) > 0 )
        {
              setBootstrap();
        }
     }
}




/**
 * @brief myMainWindow::setBootstrap
 * 设置从机进入Bootstrap状态
 */
void myMainWindow::setBootstrap(void)
{
    unsigned int data;
    int chk;
     ui->textBrowser->append("set slave go to Bootstrap\n");
     if(ec_slavecount>0)
     {
         ec_slave[1].state = EC_STATE_INIT;
         ec_writestate(1);
         /* 等待从机进入初始化状态 超时检测 2s*/
         ec_statecheck(1, EC_STATE_INIT,  EC_TIMEOUTSTATE * 1);
         ui->textBrowser->append("go to Init\n");
         /* 读取EEPROM中从机的boot邮箱0参数 */
         data = ec_readeeprom(1, ECT_SII_BOOTRXMBX, EC_TIMEOUTEEP);
         ec_slave[1].SM[0].StartAddr = (uint16)LO_WORD(data);
         ec_slave[1].SM[0].SMlength = (uint16)HI_WORD(data);
         /* 保存邮箱地址 */
         ec_slave[1].mbx_wo = (uint16)LO_WORD(data);
         /* 保存邮箱大小 */
         ec_slave[1].mbx_l = (uint16)HI_WORD(data);

         /* 读取EEPROM中从机的boot邮箱1参数 */
         data = ec_readeeprom(1, ECT_SII_BOOTTXMBX, EC_TIMEOUTEEP);
         ec_slave[1].SM[1].StartAddr = (uint16)LO_WORD(data);
         ec_slave[1].SM[1].SMlength = (uint16)HI_WORD(data);
         /* 保存邮箱地址 */
         ec_slave[1].mbx_ro = (uint16)LO_WORD(data);
         /* 保存邮箱大小 */
         ec_slave[1].mbx_rl = (uint16)HI_WORD(data);
         ui->textBrowser->append(QString::asprintf(" SM0 A:%4.4x L:%4d F:%8.8x\n", ec_slave[1].SM[0].StartAddr, ec_slave[1].SM[0].SMlength,(int)ec_slave[1].SM[0].SMflags));
         ui->textBrowser->append(QString::asprintf(" SM1 A:%4.4x L:%4d F:%8.8x\n", ec_slave[1].SM[1].StartAddr, ec_slave[1].SM[1].SMlength,(int)ec_slave[1].SM[1].SMflags));
         /* 配置从机邮箱 */
         ec_FPWR (ec_slave[1].configadr, ECT_REG_SM0, sizeof(ec_smt), &ec_slave[1].SM[0], EC_TIMEOUTRET);
         /* 配置从机邮箱 */
         ec_FPWR (ec_slave[1].configadr, ECT_REG_SM1, sizeof(ec_smt), &ec_slave[1].SM[1], EC_TIMEOUTRET);
         /* 配置从机进入bootstrap模式 */
         ui->textBrowser->append("Request BOOT state for slave 1\n");
         ec_slave[1].state = EC_STATE_BOOT;
         ec_writestate(1);
         chk = 100;
         do
         {
            ec_statecheck(0, EC_STATE_BOOT, 10000);
         }
         while (chk-- && (ec_slave[1].state != EC_STATE_BOOT));
         ui->textBrowser->append(QString::asprintf("chk =%d,%d",chk,ec_slave[1].ALstatuscode));
         if(ec_slave[1].state == EC_STATE_BOOT)
         {
             ui->textBrowser->append("BootStrap state reached \n");
         }else{
             ui->textBrowser->append("BootStrap state fail!!! \n");
         }
     }else{
         ui->textBrowser->append("no slave find\n");
     }
}

