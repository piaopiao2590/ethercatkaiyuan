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

class Ui_myMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *pushButton_write;
    QPushButton *pushButton_read;
    QLineEdit *lineEdit_file;
    QComboBox *comboBox_eth;
    QPushButton *pushButton_open;
    QPushButton *pushButton_connect;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QString::fromUtf8("myMainWindow"));
        myMainWindow->resize(500, 550);
        myMainWindow->setMinimumSize(QSize(500, 550));
        myMainWindow->setMaximumSize(QSize(500, 550));
        centralwidget = new QWidget(myMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_write = new QPushButton(centralwidget);
        pushButton_write->setObjectName(QString::fromUtf8("pushButton_write"));
        pushButton_write->setMinimumSize(QSize(0, 30));
        pushButton_write->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(pushButton_write, 2, 0, 1, 1);

        pushButton_read = new QPushButton(centralwidget);
        pushButton_read->setObjectName(QString::fromUtf8("pushButton_read"));
        pushButton_read->setMinimumSize(QSize(0, 30));
        pushButton_read->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(pushButton_read, 2, 1, 1, 1);

        lineEdit_file = new QLineEdit(centralwidget);
        lineEdit_file->setObjectName(QString::fromUtf8("lineEdit_file"));
        lineEdit_file->setMinimumSize(QSize(0, 30));
        lineEdit_file->setMaximumSize(QSize(16777215, 30));
        lineEdit_file->setReadOnly(true);

        gridLayout->addWidget(lineEdit_file, 1, 0, 1, 2);

        comboBox_eth = new QComboBox(centralwidget);
        comboBox_eth->setObjectName(QString::fromUtf8("comboBox_eth"));
        comboBox_eth->setMinimumSize(QSize(0, 30));
        comboBox_eth->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(comboBox_eth, 0, 0, 1, 2);

        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setMinimumSize(QSize(0, 30));
        pushButton_open->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(pushButton_open, 1, 2, 1, 1);

        pushButton_connect = new QPushButton(centralwidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setMinimumSize(QSize(0, 30));
        pushButton_connect->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(pushButton_connect, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        myMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 26));
        myMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(myMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myMainWindow->setStatusBar(statusbar);

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QCoreApplication::translate("myMainWindow", "FOETool", nullptr));
        pushButton_write->setText(QCoreApplication::translate("myMainWindow", "\345\206\231\345\205\245", nullptr));
        pushButton_read->setText(QCoreApplication::translate("myMainWindow", "\350\257\273\345\217\226", nullptr));
        pushButton_open->setText(QCoreApplication::translate("myMainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_connect->setText(QCoreApplication::translate("myMainWindow", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
