#ifndef KEYSHORTCURTS_H
#define KEYSHORTCURTS_H
#include <QGraphicsRectItem>

class KeyShortCurts: public QGraphicsRectItem{
public:
    void keyPressEvent (QKeyEvent * event);
};

#endif // KEYSHORTCURTS_H
