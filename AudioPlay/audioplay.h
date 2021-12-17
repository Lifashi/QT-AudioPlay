#ifndef AUDIOPLAY_H
#define AUDIOPLAY_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFile>
#include <QFileInfo>
#include <QDirIterator>
#include <QDebug>
#include <QMediaPlaylist>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QMediaMetaData>
#include <QMediaRecorder>
#include <QSettings>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTextCodec>
#include "videowidget.h"
#include <QMouseEvent>
#include <QEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QPixmap>
#include <QSlider>
#include <QDesktopServices>
#include <QUrl>


namespace Ui {
class AudioPlay;
}

class AudioPlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit AudioPlay(QWidget *parent = 0);
    ~AudioPlay();
    void searchMusic(QString dirPath);
    void findFormat(QString &path, QStringList format, QList<QString>& receiveFilePath);
    void playMusic(int index);
    void GetTime(qint64 playtime);
private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_PushButton_OpenFile_clicked();

    void on_PushButton_PlayStop_clicked();

    void on_PushButton_Previous_clicked();

    void on_PushButton_Next_clicked();

    void on_Slider_Volume_valueChanged(int value);

    void do_getduration_slots(qint64 playtime);

    void do_updatePosition_slots(qint64 position);

    void on_Slider_ProgressBar_sliderReleased();

    void on_PushButton_PlayMode_clicked();

    void on_PushButton_DeleteMusic_clicked();

    void on_pushButton_WindowMin_clicked();

    void on_pushButton_WindowMax_clicked();

    void on_pushButton_WindowExit_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::AudioPlay *ui;
    QMediaPlayer *player;
    QMediaPlaylist *playerList;
    int  playerIndex;
    int  playerPrevious;
    int  playerMode;
    QSettings *configIniWrite; //�����ļ�дָ��
    QSettings *configIniRead; //�����ļ���ָ��
    QSettings *configIniDelete; //�����ļ�ɾ��ָ��
    videowidget *videoPlayWidget; //����һ����Ƶ���Ž���

    bool mDrag;             //�Ƿ����϶�
    QPoint mDragPos;        //�϶���ʼ��
    bool mIsMax;            //��ǰ�Ƿ����
    QRect mLocation;        //��󻯺�ָ�ʱ��λ��


protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);

};

#endif // AUDIOPLAY_H
