#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.resize(320, 240);
    w.show();
    w.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return QCoreApplication::exec();
}
