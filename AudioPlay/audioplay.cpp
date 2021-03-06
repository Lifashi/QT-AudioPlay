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
    // 在当前路径创建一个文件（文件名PlayList.ini）把读到的歌曲输出到里面，方便下一次播放
    configIniWrite = new QSettings("D:/PlayList.ini", QSettings::IniFormat);

    playerIndex = 0;
    playerPrevious = 0;
    playerMode = 0;

    player->setVolume(50);             // 设置初始音量
    ui->Slider_Volume->setValue(50);
    ui->label_Volume->setText("50%");
    playerList->setPlaybackMode(QMediaPlaylist::Loop);                       // 循环播放模式


    // 允许文件拖拽到窗口部分
    this->setAcceptDrops(true);
    mLocation = this->geometry();
    mIsMax = false;
    mDrag = false;
    //


    // 手动添加窗口顶部处理部分
    this->installEventFilter(this); // 事件过滤器就是接收所有被发送到这个对象的事件的对象

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

    ui->tableWidget->setShowGrid(false);//隐藏表格线
       setStyleSheet("QMainWindow{color:#E8E8E8;background:#43CD80;}");
//       //另外在设计器内查看widgetTitle样式，内有标题栏各个子控件的样式设置



//    // 设置窗口名称，图标
    this->setWindowTitle(QTextCodec::codecForName("GBK")->toUnicode("音频播放器"));
    this->setWindowIcon(QIcon(":/image/icon.png"));

       QPixmap *pixmap = new QPixmap(":/image/icon.png");
       pixmap->scaled(ui->logo->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
       ui->logo->setScaledContents(true);
       ui->logo->setPixmap(*pixmap);
       ui->label_Title->setText(QTextCodec::codecForName("GBK")->toUnicode("音频播放器"));


    // 设置背景图片为bj.jpg
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/image/bj.png);}");

    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
//    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明

//    this->setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    // 设置按键图标
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

    // 设置图标为透明

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


     //设置歌曲列表控件的透明度
 //     ui->label_Volume->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,150)"));
       //设置歌词列表控件的透明度
 //     ui->tableWidget->setStyleSheet(QString("color:rgba(255,255,255,255);background-color:rgba(10,10,10,200)"));


//    setWindowFlags(Qt::FramelessWindowHint);  // 无边框


//    播放测试
//    player->setMedia(QUrl::fromLocalFile("C:\\Users\\71780\\Desktop\\MUSIC\\刘德华 - 暗里着迷.wav"));
//    player->setPlaylist();
//    player->setVolume(50);
//    player->play();

//     searchMusic("C:\\Users\\71780\\Desktop\\MUSIC");

    // 读取配置文件的内容：歌曲名 把前一次写入的歌曲读出来
    configIniRead = new QSettings("D:/PlayList.ini", QSettings::IniFormat);
    for(int i=0; ; ++i) //  将所有的播放列表显示在列表控件中
    {
        if(configIniRead->value("/song/"+QString::number(i),100).toInt()!=100)
        {
            QString path = configIniRead->value("/song/"+QString::number(i)).toString();


            playerList->addMedia(QUrl::fromLocalFile(path));

            QFileInfo fileInfo;
            fileInfo = QFileInfo(path);
            QString fileName = fileInfo.completeBaseName(); //  文件名不带后缀
            QString fileSuffix = fileInfo.suffix(); //  文件后缀

            int rownum=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));
        }
        else
        {
            break;
        }
    }
    player->setPlaylist(playerList); // 把播放列表添加到播放器
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

//    playerList->clear();     //清除播放列表
    list << "*.mp3" << "*.wav" << "*.wma" << "*.flac" << "*.wmv" << "*.mp4" << "*.mov" << "*.avi" ;
    findFormat(dirPath, list, findedFilePath);

    foreach(QString music, findedFilePath)
    {
        QFileInfo fileInfo;
        fileInfo = QFileInfo(music);   
        QString fileName = fileInfo.completeBaseName();  // 文件名不带后缀
        QString fileSuffix = fileInfo.suffix();  // 文件后缀

        qDebug() << fileInfo;

        if(playerList->mediaCount() > 0)
        {
            for (int i = 0;i < playerList->mediaCount() ; i++)
            {
                QString songName = ui->tableWidget->item(i,0)->text();         //  取出字符串
                if(songName == fileName + "." + fileSuffix)              // 判断是否是重复添加歌曲
                {
                    status = true;
                    break;
                }
            }

        }

        if(status == false)
        {
            playerList->addMedia(QUrl(music));       // 把扫描得到的歌曲添加到播放列表上。带路径的

            int rownum = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rownum);
            ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));
            configIniWrite->setValue("/song/"+QString::number(rownum), music); // 保存歌曲列表
        }
       status = false;


    }
    player->setPlaylist(playerList); // 把播放列表添加到播放器
}

// 打开文件
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

    // 判断路径是否存在
    QDir dir(path);
    if(!dir.exists())   return;


    // 定义迭代器并设置过滤器
    QDirIterator dirIterator(path, format, QDir::Files | QDir::NoSymLinks,QDirIterator::Subdirectories);
    while(dirIterator.hasNext())
    {
        dirIterator.next();
        receiveFilePath.append(dirIterator.fileInfo().absoluteFilePath());
    }
}

// 播放音乐
void AudioPlay::playMusic(int index)
{

    if(playerList->mediaCount() == 0)
    {
        QMessageBox QmgBox;
        QMessageBox::warning(this,QTextCodec::codecForName("GBK")->toUnicode("错误"),QTextCodec::codecForName("GBK")->toUnicode("播放列表为空，请先添加音频"));
        return;
    }
    videoPlayWidget->close();

    if(index < 0)
    {
       index =  playerList->mediaCount() - 1; //  计算播放列表文件数
    }

    if(index > playerList->mediaCount() - 1)
    {
       index =  0;
    }

    connect(player,SIGNAL(durationChanged(qint64)),this,SLOT(do_getduration_slots(qint64)));      // 获取歌曲时间总长，信号与槽
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(do_updatePosition_slots(qint64)));   // 获取当前播放进度，信号与槽

    ui->PushButton_PlayStop->setIcon(QIcon(":/image/zanting-xian.png"));
    ui->PushButton_PlayStop->setIconSize(QSize(48,48));


    if(playerPrevious != index) // 判断是否是上一首歌曲
    {
        playerList->setCurrentIndex(index);
    }
    else   // 继续播放上一首歌曲
    {
        do_getduration_slots(0);
    }

    // 判断是否是视频 //"*.mp4" << "*.mov" << "*.avi
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


// 双击触发槽函数
void AudioPlay::on_tableWidget_cellDoubleClicked(int row, int column)
{
    qDebug()<<"row:"<<row << "col:"<<column;
    ui->tableWidget->clearFocus();
    playMusic(row);
}


// 播放和停止槽函数
void AudioPlay::on_PushButton_PlayStop_clicked()
{

    if(player->state() == QMediaPlayer::PlayingState) // 判断当前播放状态
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

// 上一曲
void AudioPlay::on_PushButton_Previous_clicked()
{
    playerIndex = playerList->currentIndex() - 1;
    playMusic(playerIndex);
}

// 下一曲
void AudioPlay::on_PushButton_Next_clicked()
{
    playerIndex = playerList->currentIndex() + 1;
    playMusic(playerIndex);
}

// 设置音量
void AudioPlay::on_Slider_Volume_valueChanged(int value)
{
    player->setVolume(value);
    ui->label_Volume->setText(QString::number(value)+"%");
}


// 获取歌曲时长,歌曲改变时才会执行这个槽函数
void AudioPlay::do_getduration_slots(qint64 playtime)
{
    qDebug() << __FUNCTION__;

    playtime = player->duration();  // 获取时间
    GetTime(playtime);

    ui->Slider_ProgressBar->setRange(0,playtime); // 根据播放时长来设置滑块的范围
    ui->Slider_ProgressBar->setEnabled(playtime > 0);
    ui->Slider_ProgressBar->setPageStep(playtime / 10); // 以及每一步的步数

    // 前一首设置为黑色
    QTableWidgetItem *FileName1 = new QTableWidgetItem(ui->tableWidget->item(playerPrevious,0)->text());
    FileName1->setTextColor(QColor(Qt::black));
    ui->tableWidget->setItem(playerPrevious,0,FileName1);

    // 当前设置为蓝绿色
    QTableWidgetItem *FileName = new QTableWidgetItem(ui->tableWidget->item(playerList->currentIndex(),0)->text());
    FileName->setTextColor(QColor(Qt::cyan));
    ui->tableWidget->setItem(playerList->currentIndex(),0,FileName);

    playerPrevious = playerList->currentIndex();
}

// 计算时间
void AudioPlay::GetTime(qint64 playtime)
{
    int h,m,s;
    playtime /= 1000;  //获得的时间是以毫秒为单位的
    h = playtime/3600;
    m = (playtime-h*3600)/60;
    s = playtime-h*3600-m*60;

    ui->label_MusicTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // 把int型转化为string类型后再设置为label的text
/*    ui->label_MusicTime->setStyleSheet("color:white");    */               // 设置字体颜色为白色

    }


// 接收歌曲位置改变，改变进度条
void AudioPlay::do_updatePosition_slots(qint64 position)
{
    int h,m,s;

    ui->Slider_ProgressBar->setValue(position);//设置滑块位置

    position /= 1000;  //获得的时间是以毫秒为单位的
    h = position/3600;
    m = (position-h*3600)/60;
    s = position-h*3600-m*60;
    //     arg(整数类型,补位数,进制,补位字符);
    ui->label_PlayTime->setText(QString("%1:%2:%3").arg(h,2,10,QLatin1Char('0')).arg(m,2,10,QLatin1Char('0')).arg(s,2,10,QLatin1Char('0')));  // 把int型转化为string类型后再设置为label的text
}

// 拖动进度松手槽函数
void AudioPlay::on_Slider_ProgressBar_sliderReleased()
{
//    qDebug() << __FUNCTION__;
    player->setPosition(ui->Slider_ProgressBar->value());
}

// 设置播放模式槽函数
void AudioPlay::on_PushButton_PlayMode_clicked()
{
//   qDebug() << __FUNCTION__;

   switch(playerMode++)
   {
        case 0:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/danquxunhuan.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);          // 单曲循环
        break;

        case 1:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/suijibofang.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::Random);                     // 随机播放
        break;

        case 2:     ui->PushButton_PlayMode->setIcon(QIcon(":/image/yinlebofangye-xunhuanbofang.png"));
                    ui->PushButton_PlayMode->setIconSize(QSize(48,48));
                    playerList->setPlaybackMode(QMediaPlaylist::Loop);                       // 循环播放
        break;

   }

   if(playerMode == 3)  playerMode = 0;
}

// 删除歌曲
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

void AudioPlay::mousePressEvent(QMouseEvent *e)//鼠标按下事件
{
    qDebug() << __FUNCTION__;
    if (e->button() == Qt::LeftButton)
    {
        mDrag = true;
        mDragPos = e->globalPos() - pos();
        e->accept();
    }
}

void AudioPlay::mouseMoveEvent(QMouseEvent *e)//鼠标移动事件
{
    qDebug() << __FUNCTION__;
    if (mDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - mDragPos);
        e->accept();
    }
}

void AudioPlay::mouseReleaseEvent(QMouseEvent *e)//鼠标释放事件
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
//           ui->pushButton_WindowMax->setToolTip(QStringLiteral("最大化"));
       }
       else
       {
           mLocation = geometry();
           setGeometry(qApp->desktop()->availableGeometry());
//           ui->pushButton_WindowMax->setIcon(QIcon(":/image/max2.png"));
//           ui->pushButton_WindowMax->setToolTip(QStringLiteral("还原"));
       }
       mIsMax = !mIsMax;

}

void AudioPlay::on_pushButton_WindowExit_clicked()
{
    qApp->exit();
}


//接受拖拽的文件
void AudioPlay::dragEnterEvent(QDragEnterEvent * event)
{
    qDebug()<<__FUNCTION__;
    event->acceptProposedAction();    //接受拖拽的文件
}

// 获取拖拽的文件名
void AudioPlay::dropEvent(QDropEvent * event)
{
    qDebug()<<__FUNCTION__;

    QString fileInfo;
    QFileInfo  Info;
    bool status = false;

    auto urls = event->mimeData()->urls();
    for(auto it = urls.begin();it != urls.end();++it)    //获取拖拽的文件名
    {
        fileInfo = it->toLocalFile();
        Info = QFileInfo(it->toLocalFile());

        qDebug()<<it->toLocalFile();
    }

    QString fileName = Info.completeBaseName(); //  文件名不带后缀
    QString fileSuffix = Info.suffix(); //  文件后缀

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
            QString songName = ui->tableWidget->item(i,0)->text();         //  取出字符串
            if(songName == fileName + "." + fileSuffix)              // 判断是否是重复添加歌曲
            {
                status = true;
                break;
            }
        }

    }

    if(status == false)
    {

        playerList->addMedia(QUrl(fileInfo));       // 把扫描得到的歌曲添加到播放列表上。带路径的

        int rownum = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rownum);
        ui->tableWidget->setItem(rownum, 0, new QTableWidgetItem(fileName + "." + fileSuffix));

        configIniWrite->setValue("/song/"+QString::number(rownum), fileInfo); // 保存歌曲列表
        player->setPlaylist(playerList); // 把播放列表添加到播放器
        playMusic(rownum);
    }

}

void AudioPlay::on_commandLinkButton_clicked()
{
    QUrl url("https://blog.csdn.net/maomaochong666?spm=1001.2101.3001.5343");           // 需要打开的网页域名
    QDesktopServices::openUrl(url);      // 打开网页
}
