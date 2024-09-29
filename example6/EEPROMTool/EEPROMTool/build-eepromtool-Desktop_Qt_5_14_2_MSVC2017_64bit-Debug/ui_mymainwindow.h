/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyMainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_write;
    QComboBox *comboBox_slave;
    QPushButton *pushButton_open;
    QComboBox *comboBox_eth;
    QPushButton *pushButton_scan;
    QLineEdit *lineEdit_file;
    QPushButton *pushButton_read;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MyMainWindow)
    {
        if (MyMainWindow->objectName().isEmpty())
            MyMainWindow->setObjectName(QString::fromUtf8("MyMainWindow"));
        MyMainWindow->resize(500, 550);
        MyMainWindow->setMinimumSize(QSize(500, 550));
        MyMainWindow->setMaximumSize(QSize(500, 550));
        centralwidget = new QWidget(MyMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_write = new QPushButton(centralwidget);
        pushButton_write->setObjectName(QString::fromUtf8("pushButton_write"));
        pushButton_write->setMinimumSize(QSize(0, 32));
        pushButton_write->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(pushButton_write, 3, 0, 1, 1);

        comboBox_slave = new QComboBox(centralwidget);
        comboBox_slave->setObjectName(QString::fromUtf8("comboBox_slave"));
        comboBox_slave->setMinimumSize(QSize(0, 32));
        comboBox_slave->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(comboBox_slave, 1, 0, 1, 3);

        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setMinimumSize(QSize(0, 32));
        pushButton_open->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(pushButton_open, 2, 3, 1, 1);

        comboBox_eth = new QComboBox(centralwidget);
        comboBox_eth->setObjectName(QString::fromUtf8("comboBox_eth"));
        comboBox_eth->setMinimumSize(QSize(0, 32));
        comboBox_eth->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(comboBox_eth, 0, 0, 1, 3);

        pushButton_scan = new QPushButton(centralwidget);
        pushButton_scan->setObjectName(QString::fromUtf8("pushButton_scan"));
        pushButton_scan->setMinimumSize(QSize(0, 32));
        pushButton_scan->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(pushButton_scan, 1, 3, 1, 1);

        lineEdit_file = new QLineEdit(centralwidget);
        lineEdit_file->setObjectName(QString::fromUtf8("lineEdit_file"));
        lineEdit_file->setMinimumSize(QSize(0, 32));
        lineEdit_file->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(lineEdit_file, 2, 0, 1, 3);

        pushButton_read = new QPushButton(centralwidget);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));
        pushButton_read->setMinimumSize(QSize(0, 32));
        pushButton_read->setMaximumSize(QSize(16777215, 32));

        gridLayout->addWidget(pushButton_read, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        MyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MyMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 26));
        MyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MyMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MyMainWindow->setStatusBar(statusbar);

        retranslateUi(MyMainWindow);

        QMetaObject::connectSlotsByName(MyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyMainWindow)
    {
        MyMainWindow->setWindowTitle(QCoreApplication::translate("MyMainWindow", "EEPROMTool", nullptr));
        pushButton_write->setText(QCoreApplication::translate("MyMainWindow", "\345\206\231\345\205\245", nullptr));
        pushButton_open->setText(QCoreApplication::translate("MyMainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_scan->setText(QCoreApplication::translate("MyMainWindow", "\346\211\253\346\217\217", nullptr));
        pushButton_read->setText(QCoreApplication::translate("MyMainWindow", "\350\257\273\345\217\226", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyMainWindow: public Ui_MyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
