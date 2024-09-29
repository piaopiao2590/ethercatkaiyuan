#include "mymainwindow.h"

#include <QApplication>


#pragma comment( lib, "Winmm" )
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /* 解决高分辨率屏幕中应用显示问题 */
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    MyMainWindow w;
    w.show();
    return a.exec();
}
