#ifndef GCPLAYER_PLAYERWIDGET_H_
#define GCPLAYER_PLAYERWIDGET_H_

#include <QWidget>

class QVideoWidget;
class QMediaPlayer;
class QVBoxLayout;
class QAudioOutput;

namespace Ui {
class PlayerWidget;
}

class PlayerWidget : public QWidget {
  Q_OBJECT
 public:
  explicit PlayerWidget(QWidget *parent = nullptr);
  ~PlayerWidget();

  bool setMediaSource(const QString &path);

 public slots:
  void playOrPause();
  void seek(quint64 ms);

 private:
  void init();

 private:
  Ui::PlayerWidget *ui;
  QVideoWidget *m_videoWidget;
  QAudioOutput *m_audioOutput;
  QMediaPlayer *m_mediaPlayer;
  QVBoxLayout *m_layout;

 signals:
  void sig_durationChanged(qint64 duration);
};

#endif  // GCPLAYER_PLAYERWIDGET_H_
