#include "MainWindow.h"
#include <QLabel>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle ("Appointments Application");
    w.resize (800,500);
    w.show();
    return a.exec();
}
