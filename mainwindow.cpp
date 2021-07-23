#include "mainwindow.h"
#include <myvideosurface.h>

#include <QVideoSurfaceFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //bar.resize(16384);
    start_button.setParent(this);
    start_button.setGeometry(0,0,120,120);
    start_button.setText("record");

    shit_into_ears_button.setParent(this);
    shit_into_ears_button.setGeometry(120,120,120,120);
    shit_into_ears_button.setText("listen");

    label.setParent(this);
    label.setGeometry(120,0,300,120);
    label.setText("NO messages");


    //QCameraInfo camInfo = QCameraInfo::defaultCamera();
    //QCamera *cam = new QCamera(camInfo, this);
    //cam->unload();
    //cam->load();

    //cam->setCaptureMode(QCamera::CaptureMode::CaptureVideo);


    //MyVideoSurface *surf = new MyVideoSurface(&netman, this);

    //surf->start(QVideoSurfaceFormat(QSize(800, 600), QVideoFrame::PixelFormat::Format_RGB32));
    //cam->setViewfinder(surf);
    //cam->start();

    this->resize(800, 600);

    QVideoWidget *videoWidget = new QVideoWidget(this);
    videoWidget->setGeometry(240, 240, 300, 300);
    videoWidget->show();

    sender = new QMediaPlayer(this);
    //sender->setMedia(QUrl("gst-pipeline: v4l2src ! video/x-raw, format=YUY2, width=160, height=120 ! videoconvert ! x264enc ! video/x-h264 ! rtph264pay pt=96 ! udpsink host=239.13.69.228 port=42069 sync=false")); //, surf->buffer);

    //sender->play();
    mediaReceiver = new QMediaPlayer;//(this, QMediaPlayer::Flag::StreamPlayback);

    mediaReceiver->setVideoOutput(videoWidget);
    //mediaReceiver->setMedia(QUrl("gst-pipeline: udpsrc port=42069 ! application/x-rtp,media=video,encoding-name=H264,clock-rate=90000,payload=96 ! rtph264depay ! h264parse ! decodebin ! xvimagesink name=\"qtvideosink\""));//avdec_h264 ! xvimagesink name=\"qtvideosink\" sync=false"));
    //mediaReceiver->setMedia(QUrl("gst-pipeline: udpsrc port=42069 ! h264parse ! avdec_h264 ! videoconvert ! autovideosink name=qtvideosink sync=false")); //rtph264depay ! decodebin ! x264enc ! filesink location=\"/home/max/a.mp4\"
    //mediaReceiver->play();

    connect(&start_button, &QPushButton::pressed, this,  &MainWindow::record);
    connect(&shit_into_ears_button, &QPushButton::pressed, this,  &MainWindow::listen);

    mic = new microphone();
    speak = new speaker();
}

MainWindow::~MainWindow()
{
    delete speak;
    delete mic;
}

void MainWindow::record()
{
    //mic->startRecording(&netman);

    sender->setMedia(QUrl("gst-pipeline: v4l2src ! video/x-raw, format=YUY2, width=160, height=120 ! videoconvert ! x264enc ! video/x-h264 ! rtph264pay pt=96 ! udpsink host=239.13.69.228 port=42069 sync=false")); //, surf->buffer);
    sender->play();

    mediaReceiver->setMedia(QUrl("gst-pipeline: udpsrc port=42069 ! application/x-rtp,media=video,encoding-name=H264,clock-rate=90000,payload=96 ! rtph264depay ! h264parse ! decodebin ! xvimagesink name=\"qwidgetvideosink\""));//avdec_h264 ! xvimagesink name=\"qtvideosink\" sync=false"));
    mediaReceiver->play();
}

void MainWindow::listen()
{
    //speak->start(&netman);
    sender->stop();
    mediaReceiver->stop();
}
