#include "audioplay.h"
#include "ui_audioplay.h"
#include <QDesktopWidget>

AudioPlay::AudioPlay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AudioPlay)
{
    ui->setupUi(this);

    player      = new QMediaPlayer;
    playerList  = new QMediaPlaylist;
    videoPlayWidget = new videowidget;
    // �ڵ�ǰ·������һ���ļ����ļ���PlayList.ini���Ѷ����ĸ�����������棬������һ�β���
    configIniWrite = new QSettings("D:/PlayList.ini", QSettings::IniFormat);

    playerIndex = 0;
    playerPrevious = 0;
    playerMode = 0;

    player->setVolume(50);             // ���ó�ʼ����
    ui->Slider_Volume->setValue(50);
    ui->label_Volume->setText("50%");
    playerList->setPlaybackMode(QMediaPlaylist::Loop);                       // ѭ������ģʽ


    // �����ļ���ק�����ڲ���
    this->setAcceptDrops(true);
    mLocation = this->geometry();
    mIsMax = false;
    mDrag = false;
    //


    // �ֶ���Ӵ��ڶ���������
    this->installEventFilter(this); // �¼����������ǽ������б����͵����������¼��Ķ���

    ui->pushButton_WindowMin->setIcon(QIcon(":/image/jianhao.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));

    ui->pushButton_WindowMax->setIcon(QIcon(":/image/fangkuang.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));

    ui->pushButton_WindowExit->setIcon(QIcon(":/image/guanbi.png"));
    ui->pushButton_WindowMin->setIconSize(QSize(16,16));



    ui->pushButton_WindowMin->setFlat(true);
    ui->pushButton_WindowMin->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->pushButton_WindowMax->setFlat(true);
    ui->pushButton_WindowMax->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->pushButton_WindowExit->setFlat(true);
    ui->pushButton_WindowExit->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->tableWidget->setShowGrid(false);//���ر����
       setStyleSheet("QMainWindow{color:#E8E8E8;background:#43CD80;}");
//       //������������ڲ鿴widgetTitle��ʽ�����б����������ӿؼ�����ʽ����



//    // ���ô������ƣ�ͼ��
    this->setWindowTitle(QTextCodec::codecForName("GBK")->toUnicode("��Ƶ������"));
    this->setWindowIcon(QIcon(":/image/icon.png"));

       QPixmap *pixmap = new QPixmap(":/image/icon.png");
       pixmap->scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
       ui->logo->setScaledContents(true);
       ui->logo->setPixmap(*pixmap);
       ui->label_Title->setText(QTextCodec::codecForName("GBK")->toUnicode("��Ƶ������"));


    // ���ñ���ͼƬΪbj.jpg
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/image/bj.png);}");

    this->setWindowFlags(Qt::FramelessWindowHint);//�ޱ߿�
//    this->setAttribute(Qt::WA_TranslucentBackground);//����͸��

//    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    // ���ð���ͼ��
    ui->PushButton_PlayStop->setIcon(QIcon(":/image/bofang.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));

    ui->PushButton_PlayMode->setIcon(QIcon(":/image/yinlebofangye-xunhuanbofang.png"));
    ui->PushButton_PlayMode->setIconSize(QSize(48,48));

    ui->PushButton_Previous->setIcon(QIcon(":/image/shangyishou.png"));
    ui->PushButton_Previous->setIconSize(QSize(48,48));

    ui->PushButton_Next->setIcon(QIcon(":/image/xiayishou.png"));
    ui->PushButton_Next->setIconSize(QSize(48,48));

    ui->PushButton_OpenFile->setIcon(QIcon(":/image/tianjiagequ.png"));
    ui->PushButton_OpenFile->setIconSize(QSize(48,48));

    ui->PushButton_DeleteMusic->setIcon(QIcon(":/image/shanchu.png"));
    ui->PushButton_DeleteMusic->setIconSize(QSize(48,48));


    QPixmap *pixmap1 = new QPixmap(":/image/jurassic.png");
    pixmap->scaled(QSize(16,16), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_Volume_2->setScaledContents(true);
    ui->label_Volume_2->setPixmap(*pixmap1);

    // ����ͼ��Ϊ͸��

    ui->PushButton_PlayStop->setFlat(true);
    ui->PushButton_PlayStop->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_PlayMode->setFlat(true);
    ui->PushButton_PlayMode->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_Previous->setFlat(true);
    ui->PushButton_Previous->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_Next->setFlat(true);
    ui->PushButton_Next->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_OpenFile->setFlat(true);
    ui->PushButton_OpenFile->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->PushButton_DeleteMusic->setFlat(true);
    ui->PushButton_DeleteMusic->setStyleSheet("QPushButton{border:none;background:transparent;}");

    ui->label_Volume->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->label_MusicTime->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->label_PlayTime->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->Slider_Volume->setStyleSheet("QSlider{border:none;background:transparent;}");

    ui->Slider_ProgressBar->setStyleSheet("QSlider{border:none;background:transparent;}");

    ui->label_Volume_2->setStyleSheet("QLabel{border:none;background:transparent;}");

    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->setStyleSheet("QTableView::item:selected{color:black;background:black;}");
    ui->tableWidget->setStyleSheet("QTableWidget{border:none;background:transparent;}");


     //���ø����б�ؼ���͸����
 //     ui->label_Volume->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,150)"));
       //���ø���б�ؼ���͸����
 //     ui->tableWidget->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,200)"));


//    setWindowFlags(Qt::FramelessWindowHint);  // �ޱ߿�


//    ���Ų���
//    player->setMedia(QUrl::fromLocalFile("C:\\Users\\71780\\Desktop\\MUSIC\\���»� - ��������.wav"));
//    player->setPlaylist();
//    player->setVolume(50);
//    player->play();

//     searchMusic("C:\\Users\\71780\\Desktop\\MUSIC");

    // ��ȡ�����ļ������ݣ������� ��ǰһ��д��ĸ���������
    configIniRead = new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    for(int i=0; ; ++i) //  �����еĲ����б���ʾ���б�ؼ���
    {
        if(configIniRead->value("/song/"+QString::number(i),100).toInt()!=100)
        {
            QString path = configIniRead->value("/song/"+QString::number(i)).toString();


            playerList->addMedia(QUrl::fromLocalFile(path));

            QFileInfo fileInfo;
            fileInfo = QFileInfo(path);
            QString fileName = fileInfo.completeBaseName(); //  �ļ���������׺
            QString fileSuffix = fileInfo.suffix(); //  �ļ���׺

            int rownum=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));
        }
        else
        {
            break;
        }
    }
    player->setPlaylist(playerList); // �Ѳ����б���ӵ�������
    playerList->setCurrentIndex(0);
}

AudioPlay::~AudioPlay()
{
    delete ui;
}


void AudioPlay::searchMusic(QString dirPath)
{
    QList<QString>  findedFilePath;
    QStringList list;

    bool status = false;

//    playerList->clear();     //��������б�
    list << "*.mp3" << "*.wav" << "*.wma" << "*.flac" << "*.wmv" << "*.mp4" << "*.mov" << "*.avi" ;
    findFormat(dirPath, list, findedFilePath);

    foreach(QString music, findedFilePath)
    {
        QFileInfo fileInfo;
        fileInfo = QFileInfo(music);   
        QString fileName = fileInfo.completeBaseName();  // �ļ���������׺
        QString fileSuffix = fileInfo.suffix();  // �ļ���׺

        qDebug() << fileInfo;

        if(playerList->mediaCount() > 0)
        {
            for (int i = 0;i < playerList->mediaCount() ; i++)
            {
                QString songName = ui->tableWidget->item(i,0)->text();         //  ȡ���ַ���
                if(songName == fileName + "." + fileSuffix)              // �ж��Ƿ����ظ���Ӹ���
                {
                    status = true;
                    break;
                }
            }

        }

        if(status == false)
        {
            playerList->addMedia(QUrl(music));       // ��ɨ��õ��ĸ�����ӵ������б��ϡ���·����

            int rownum = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));
            configIniWrite->setValue("/song/"+QString::number(rownum), music); // ��������б�
        }
       status = false;


    }
    player->setPlaylist(playerList); // �Ѳ����б���ӵ�������
}

// ���ļ�
void AudioPlay::on_PushButton_OpenFile_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     "./",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    searchMusic(dir);
}

void AudioPlay::findFormat(QString &path, QStringList format, QList<QString>& receiveFilePath)
{

    // �ж�·���Ƿ����
    QDir dir(path);
    if(!dir.exists())   return;


    // ��������������ù�����
    QDirIterator dirIterator(path, format, QDir::Files | QDir::NoSymLinks,QDirIterator::Subdirectories);
    while(dirIterator.hasNext())
    {
        dirIterator.next();
        receiveFilePath.append(dirIterator.fileInfo().absoluteFilePath());
    }
}

// ��������
void AudioPlay::playMusic(int index)
{

    if(playerList->mediaCount() == 0)
    {
        QMessageBox QmgBox;
        QMessageBox::warning(this,QTextCodec::codecForName("GBK")->toUnicode("����"),QTextCodec::codecForName("GBK")->toUnicode("�����б�Ϊ�գ����������Ƶ"));
        return;
    }
    videoPlayWidget->close();

    if(index < 0)
    {
       index =  playerList->mediaCount() - 1; //  ���㲥���б��ļ���
    }

    if(index > playerList->mediaCount() - 1)
    {
       index =  0;
    }

    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(do_getduration_slots(qint64)));      // ��ȡ����ʱ���ܳ����ź����
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(do_updatePosition_slots(qint64)));   // ��ȡ��ǰ���Ž��ȣ��ź����

    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));


    if(playerPrevious != index) // �ж��Ƿ�����һ�׸���
    {
        playerList->setCurrentIndex(index);
    }
    else   // ����������һ�׸���
    {
        do_getduration_slots(0);
    }

    // �ж��Ƿ�����Ƶ //"*.mp4" << "*.mov" << "*.avi
    if(ui->tableWidget->item(index,0)->text().right(3) == "wmv" ||
       ui->tableWidget->item(index,0)->text().right(3) == "mp4" ||
       ui->tableWidget->item(index,0)->text().right(3) == "mov" ||
       ui->tableWidget->item(index,0)->text().right(3) == "avi"    )
    {
        ui->horizontalLayout_4->addWidget(videoPlayWidget);
        player->setVideoOutput(videoPlayWidget);
        videoPlayWidget->show();
        player->play();
    }

    player->play();
}


// ˫�������ۺ���
void AudioPlay::on_tableWidget_cellDoubleClicked(int row, int column)
{
    qDebug()<<"row:"<<row << "col:"<<column;
    ui->tableWidget->clearFocus();
    playMusic(row);
}


// ���ź�ֹͣ�ۺ���
void AudioPlay::on_PushButton_PlayStop_clicked()
{

    if(player->state() == QMediaPlayer::PlayingState) // �жϵ�ǰ����״̬
    {
        player->pause();
        ui->PushButton_PlayStop->setIcon(QIcon(":/image/bofang.png"));
        ui->PushButton_PlayStop->setIconSize(QSize(48,48));
    }
    else
    {
        playMusic(playerList->currentIndex());
    }
}

// ��һ��
void AudioPlay::on_PushButton_Previous_clicked()
{
    playerIndex = playerList->currentIndex() - 1;
    playMusic(playerIndex);
}

// ��һ��
void AudioPlay::on_PushButton_Next_clicked()
{
    playerIndex = playerList->currentIndex() + 1;
    playMusic(playerIndex);
}

// ��������
void AudioPlay::on_Slider_Volume_valueChanged(int value)
{
    player->setVolume(value);
    ui->label_Volume->setText(QString::number(value)+"%");
}


// ��ȡ����ʱ��,�����ı�ʱ�Ż�ִ������ۺ���
void AudioPlay::do_getduration_slots(qint64 playtime)
{
    qDebug() << __FUNCTION__;

    playtime = player->duration();  // ��ȡʱ��
    GetTime(playtime);

    ui->Slider_ProgressBar->setRange(0,playtime); // ���ݲ���ʱ�������û���ķ�Χ
    ui->Slider_ProgressBar->setEnabled(playtime > 0);
    ui->Slider_ProgressBar->setPageStep(playtime / 10); // �Լ�ÿһ���Ĳ���

    // ǰһ������Ϊ��ɫ
    QTableWidgetItem *FileName1 = new QTableWidgetItem(ui->tableWidget->item(playerPrevious,0)->text());
    FileName1->setTextColor(QColor(Qt::black));
    ui->tableWidget->setItem(playerPrevious,0,FileName1);

    // ��ǰ����Ϊ����ɫ
    QTableWidgetItem *FileName = new QTableWidgetItem(ui->tableWidget->item(playerList->currentIndex(),0)->text());
    FileName->setTextColor(QColor(Qt::cyan));
    ui->tableWidget->setItem(playerList->currentIndex(),0,FileName);

    playerPrevious = playerList->currentIndex();
}

// ����ʱ��
void AudioPlay::GetTime(qint64 playtime)
{
    int h,m,s;
    playtime /= 1000;  //��õ�ʱ�����Ժ���Ϊ��λ��
    h = playtime/3600;
    m = (playtime-h*3600)/60;
    s = playtime-h*3600-m*60;

    ui->label_MusicTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // ��int��ת��Ϊstring���ͺ�������Ϊlabel��text
/*    ui->label_MusicTime->setStyleSheet("color:white");    */               // ����������ɫΪ��ɫ

    }


// ���ո���λ�øı䣬�ı������
void AudioPlay::do_updatePosition_slots(qint64 position)
{
    int h,m,s;

    ui->Slider_ProgressBar->setValue(position);//���û���λ��

    position /= 1000;  //��õ�ʱ�����Ժ���Ϊ��λ��
    h = position/3600;
    m = (position-h*3600)/60;
    s = position-h*3600-m*60;
    //     arg(��������,��λ��,����,��λ�ַ�);
    ui->label_PlayTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // ��int��ת��Ϊstring���ͺ�������Ϊlabel��text
}

// �϶��������ֲۺ���
void AudioPlay::on_Slider_ProgressBar_sliderReleased()
{
//    qDebug() << __FUNCTION__;
    player->setPosition(ui->Slider_ProgressBar->value());
}

// ���ò���ģʽ�ۺ���
void AudioPlay::on_PushButton_PlayMode_clicked()
{
//   qDebug() << __FUNCTION__;

   switch(playerMode++)
   {
        case 0:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/danquxunhuan.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);          // ����ѭ��
        break;

        case 1:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/suijibofang.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::Random);                     // �������
        break;

        case 2:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/yinlebofangye-xunhuanbofang.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::Loop);                       // ѭ������
        break;

   }

   if(playerMode == 3)  playerMode = 0;
}

// ɾ������
void AudioPlay::on_PushButton_DeleteMusic_clicked()
{
//    qDebug() << __FUNCTION__;
    if(playerList->mediaCount() == 0) return;

    configIniDelete = new QSettings("PlayList.ini",QSettings::IniFormat);
    int curPlayIndex = ui->tableWidget->currentRow();
    if( curPlayIndex >= 0)
    {
        for (int i = curPlayIndex; ; i++)
        {
            if(configIniDelete->value("/song/"+QString::number(i+1),100).toInt() != 100) //
            {
                configIniDelete->setValue("/song/"+QString::number(i),configIniDelete->value("/song/"+QString::number(i+1)).toString());
            }
            else
            {
                configIniDelete->remove("/song/"+QString::number(i));
                break;
            }
        }
       playerList->removeMedia(curPlayIndex);
       ui->tableWidget->removeRow(curPlayIndex);
    }
}




bool AudioPlay::eventFilter(QObject *obj, QEvent *e)
{
//    qDebug() << __FUNCTION__;
    if (obj == ui->centralWidget)
    {
        if(e->type() == QEvent::MouseButtonDblClick)
        {
            on_pushButton_WindowMax_clicked();
            return true;
        }
    }
    return QObject::eventFilter(obj, e);
}

void AudioPlay::mousePressEvent(QMouseEvent *e)//��갴���¼�
{
    qDebug() << __FUNCTION__;
    if (e->button() == Qt::LeftButton)
    {
        mDrag = true;
        mDragPos = e->globalPos() - pos();
        e->accept();
    }
}

void AudioPlay::mouseMoveEvent(QMouseEvent *e)//����ƶ��¼�
{
    qDebug() << __FUNCTION__;
    if (mDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - mDragPos);
        e->accept();
    }
}

void AudioPlay::mouseReleaseEvent(QMouseEvent *e)//����ͷ��¼�
{
    qDebug() << __FUNCTION__;
    mDrag = false;
}


void AudioPlay::on_pushButton_WindowMin_clicked()
{
    showMinimized();
}

void AudioPlay::on_pushButton_WindowMax_clicked()
{
    if (mIsMax)
       {
           setGeometry(mLocation);
//           ui->pushButton_WindowMax->setIcon(QIcon(":/image/max1.png"));
//           ui->pushButton_WindowMax->setToolTip(QStringLiteral("���"));
       }
       else
       {
           mLocation = geometry();
           setGeometry(qApp->desktop()->availableGeometry());
//           ui->pushButton_WindowMax->setIcon(QIcon(":/image/max2.png"));
//           ui->pushButton_WindowMax->setToolTip(QStringLiteral("��ԭ"));
       }
       mIsMax = !mIsMax;

}

void AudioPlay::on_pushButton_WindowExit_clicked()
{
    qApp->exit();
}


//������ק���ļ�
void AudioPlay::dragEnterEvent(QDragEnterEvent * event)
{
    qDebug()<<__FUNCTION__;
    event->acceptProposedAction();    //������ק���ļ�
}

// ��ȡ��ק���ļ���
void AudioPlay::dropEvent(QDropEvent * event)
{
    qDebug()<<__FUNCTION__;

    QString fileInfo;
    QFileInfo  Info;
    bool status = false;

    auto urls = event->mimeData()->urls();
    for(auto it = urls.begin();it != urls.end();++it)    //��ȡ��ק���ļ���
    {
        fileInfo = it->toLocalFile();
        Info = QFileInfo(it->toLocalFile());

        qDebug()<<it->toLocalFile();
    }

    QString fileName = Info.completeBaseName(); //  �ļ���������׺
    QString fileSuffix = Info.suffix(); //  �ļ���׺

    // list << "*.mp3" << "*.wav" << "*.wma" << "*.flac" << "*.wmv" << "*.mp4" << "*.mov" << "*.avi" ;
    if(fileSuffix != "mp3" &&
       fileSuffix != "wav"  &&
       fileSuffix != "wma"  &&
       fileSuffix != "flac" &&
       fileSuffix != "wmv"  &&
       fileSuffix != "mp4"  &&
       fileSuffix != "mov"  &&
       fileSuffix != "avi"
       ) return;

    if(playerList->mediaCount() > 0)
    {
        for (int i = 0;i < playerList->mediaCount() ; i++)
        {
            QString songName = ui->tableWidget->item(i,0)->text();         //  ȡ���ַ���
            if(songName == fileName + "." + fileSuffix)              // �ж��Ƿ����ظ���Ӹ���
            {
                status = true;
                break;
            }
        }

    }

    if(status == false)
    {

        playerList->addMedia(QUrl(fileInfo));       // ��ɨ��õ��ĸ�����ӵ������б��ϡ���·����

        int rownum = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rownum);
        ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));

        configIniWrite->setValue("/song/"+QString::number(rownum), fileInfo); // ��������б�
        player->setPlaylist(playerList); // �Ѳ����б���ӵ�������
        playMusic(rownum);
    }

}

void AudioPlay::on_commandLinkButton_clicked()
{
    QUrl url("https://blog.csdn.net/maomaochong666?spm=1001.2101.3001.5343");           // ��Ҫ�򿪵���ҳ����
    QDesktopServices::openUrl(url);      // ����ҳ
}
