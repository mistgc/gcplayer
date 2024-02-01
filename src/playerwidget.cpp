#include <gcplayer/log.h>
#include <gcplayer/playerwidget.h>
#include <ui_playerwidget.h>

#include <QAudioOutput>
#include <QFile>
#include <QMediaPlayer>
#include <QVBoxLayout>
#include <QVideoWidget>

PlayerWidget::PlayerWidget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::PlayerWidget),
      m_videoWidget(new QVideoWidget(this)),
      m_mediaPlayer(new QMediaPlayer(this)),
      m_audioOutput(new QAudioOutput(this)),
      m_layout(new QVBoxLayout(this)) {
  ui->setupUi(this);
  init();
}

void PlayerWidget::init() {
  // Video Widget
  m_videoWidget->setMinimumSize(320, 180);

  // Media Player
  m_mediaPlayer->setVideoOutput(m_videoWidget);
  m_mediaPlayer->setAudioOutput(m_audioOutput);
  m_layout->addWidget(m_videoWidget);
  connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this,
          &PlayerWidget::sig_durationChanged);
}

PlayerWidget::~PlayerWidget() { delete ui; }

bool PlayerWidget::setMediaSource(const QString &path) {
  if (!QFile::exists(path)) {
    linfo("%s doesn't exists.", path.toUtf8().constData());
    return false;
  }

  ldebug("Set media source %s", path.toUtf8().constData());
  m_mediaPlayer->setSource(path);
  m_mediaPlayer->play();
  emit sig_played();

  return true;
}

void PlayerWidget::playOrPause() {
  if (m_mediaPlayer->isPlaying()) {
    m_mediaPlayer->pause();
    emit sig_paused();
  } else {
    m_mediaPlayer->play();
    emit sig_played();
  }
}

void PlayerWidget::seek(quint64 ms) {
  ldebug("Media seek to %lld ms", ms);
  m_mediaPlayer->setPosition(ms);
}
