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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *navigation_widget;
    QComboBox *eth_comboBox;
    QPushButton *con_pushButton;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QString::fromUtf8("myMainWindow"));
        myMainWindow->resize(800, 600);
        centralwidget = new QWidget(myMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        navigation_widget = new QWidget(centralwidget);
        navigation_widget->setObjectName(QString::fromUtf8("navigation_widget"));
        navigation_widget->setMinimumSize(QSize(200, 0));
        navigation_widget->setMaximumSize(QSize(200, 16777215));
        eth_comboBox = new QComboBox(navigation_widget);
        eth_comboBox->setObjectName(QString::fromUtf8("eth_comboBox"));
        eth_comboBox->setGeometry(QRect(0, 10, 200, 40));
        eth_comboBox->setMinimumSize(QSize(200, 40));
        eth_comboBox->setMaximumSize(QSize(200, 40));
        con_pushButton = new QPushButton(navigation_widget);
        con_pushButton->setObjectName(QString::fromUtf8("con_pushButton"));
        con_pushButton->setGeometry(QRect(120, 60, 81, 31));

        horizontalLayout->addWidget(navigation_widget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        myMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        myMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(myMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myMainWindow->setStatusBar(statusbar);

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QCoreApplication::translate("myMainWindow", "myMainWindow", nullptr));
        con_pushButton->setText(QCoreApplication::translate("myMainWindow", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
