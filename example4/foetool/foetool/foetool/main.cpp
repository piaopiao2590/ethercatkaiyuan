#include "mymainwindow.h"

#include <QApplication>


#pragma comment( lib, "Winmm" )
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char *argv[])
{
    /* 解决高分辨率屏幕中应用显示问题 */
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    myMainWindow w;
    w.show();
    return a.exec();
}
