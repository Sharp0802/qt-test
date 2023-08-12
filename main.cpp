#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w0;
    Widget w1;
    w0.show();
    w1.show();
    return a.exec();
}
