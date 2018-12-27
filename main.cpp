#include "mainwindow.h"
#include <QApplication>
#include "keyshortcurts.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    KeyShortCurts * shotcut = new KeyShortCurts();
    shotcut->setRect(0,0,100,100);

    shotcut->setFlag(QGraphicsItem::ItemIsFocusable);
    shotcut->setFocus();



    MainWindow w;
    w.show();

    return a.exec();
}
