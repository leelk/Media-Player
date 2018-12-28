#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <string>
#include <QKeyEvent>
#include <QMediaPlaylist>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    player = new QMediaPlayer(this);


    vw = new QVideoWidget(this);

    vw->setFixedSize(545,250);
    vw->setStyleSheet("margin");


    player->setVideoOutput(vw);





   // this->setCentralWidget(vw);
  // vw->setStyleSheet(" border: 2px solid green;border-radius: 4px;padding: 2px;");
    //ui->statusBar->setStyleSheet(color:black);
   // qApp->setStyleSheet("QLineEdit { background-color: yellow }");
  ui->statusBar->setStyleSheet(" background-color: black; color:white; border-radius: 4px");

  ui->mainToolBar->setStyleSheet(" background-color: blue; color: red; height:70px; align:center");


    slider = new QSlider(this);

//    bar = new QProgressBar(this);
//    bar->setVisible(0);

    slider->setOrientation(Qt::Horizontal);
//    slider->setStyleSheet("max-width: 154px; height:15px"); THIS IS CORRECT

    ui->actionPause->setVisible(0);
    ui->mainToolBar->setMovable(0);
   // ui->statusBar->addPermanentWidget(slider);
   // ui->statusBar->addPermanentWidget(bar);
    //ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(slider);
    ui->mainToolBar->adjustSize();
    //ui->mainToolBar->addWidget(bar);






    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);


//    connect(player,&QMediaPlayer::volumeChanged,sliderVol,&QSlider::setValue);

//    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
//    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent (QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q){


    }
}

//void MainWindow::keyPressEvent(QKeyEvent *event)
//{
//    switch (event->key()) {
//    case Qt::Key_E:
//        ui->statusBar->showMessage("E pressed");
//        break;

//    }

//}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.*)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->actionPlay->setVisible(0);
    ui->actionPause->setVisible(1);
    ui->statusBar->showMessage("Playing..");

}

void MainWindow::on_actionNext_triggered()
{
    playlist->next();
    on_actionPlay_triggered();
    ui->statusBar->showMessage("Playing Next file..");
}

void MainWindow::on_actionBack_triggered()
{
    playlist->previous();
    on_actionPlay_triggered();
    ui->statusBar->showMessage("Playing Previous file..");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusBar->showMessage("Stoped");
    ui->actionPlay->setVisible(1);
    ui->actionPause->setVisible(0);
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusBar->showMessage("Paused");
    ui->actionPlay->setVisible(1);
    ui->actionPause->setVisible(0);

}



void MainWindow::on_actionPlayList_triggered()
{
//    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File(*.*)");
//    on_actionStop_triggered();

//    player->setMedia(QUrl::fromLocalFile(filename));

//    on_actionPlay_triggered();

// 555555555555
//    QStringList filenames = QFileDialog::getOpenFileNames(this,tr("BMP files"),QDir::currentPath(),tr("Bitmap files (*.bmp);;All files (*.*)") );
//    if( !filenames.isEmpty() )
//    {
//        for (int i =0;i<filenames.count();i++)
//            ui->lstFiles->addItem(filenames.at(i));

//    }
//    QStringList flienames = QFileDialog::getOpenFileNames(this,"Open files","","Video Files(*.*)");
//    if( !flienames.isEmpty() )
//    {
//        for(int i =0; i<flienames.count();i++)
//        {
//            player->setMedia(QUrl::fromLocalFile(flienames.at(i)));



//        }


//    }

   // ui->listView.

  //vw->setFullScreen(1);

//    playlist = new QMediaPlaylist(this);
//    contents = new QMediaContent()

//   playlist->addMedia(QFileDialog::getOpenFileNames(this,"Open files","","Video Files(*.*)"));
//   on_actionPlay_triggered();

//    QVariant PlaylistModel::data(const QModelIndex &index, int role) const
//    {
//        if (index.isValid() && role == Qt::DisplayRole) {
//            QVariant value = m_data[index];
//            if (!value.isValid() && index.column() == Title) {
//                QUrl location = m_playlist->media(index.row()).canonicalUrl();
//                return QFileInfo(location.path()).fileName();
//            }

//            return value;
//        }
//        return QVariant();
//    }
// qDebug()<<filenames;





//    playlist = new QMediaPlaylist(player);
//    QStringList filenames = QFileDialog::getOpenFileNames(this,"Open a File","","Video File(*.*)");
//    playlist->addMedia(filenames);
//    player->setPlaylist(playlist);
//    on_actionPlay_triggered();


    playlist = new QMediaPlaylist(player);
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open a File","","Video File(*.*)");
    for(const QString & filename: filenames){
        playlist->addMedia(QMediaContent(QUrl::fromLocalFile(filename)));
    }

    player->setPlaylist(playlist);


player->setPlaylist(playlist);
on_actionPlay_triggered();














}


