#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStringList flienames;



private slots:
    void on_actionOpen_triggered();

    void on_actionPlay_triggered();

    void on_actionNext_triggered();

    void on_actionBack_triggered();

    void on_actionStop_triggered();

    void on_actionPause_triggered();

    void on_actionPlayList_triggered();





private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *vw;
    QProgressBar *bar;
    QSlider *slider;

    QMediaPlaylist *playlist;
    QMediaContent *contents;
    void keyPressEvent (QKeyEvent *event);




};

#endif // MAINWINDOW_H
