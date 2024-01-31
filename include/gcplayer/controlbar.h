#ifndef GCPLAYER_CONTROLBAR_H_
#define GCPLAYER_CONTROLBAR_H_

#include <QWidget>

namespace Ui {
class ControlBar;
}

class ControlBar : public QWidget {
  Q_OBJECT
 public:
  explicit ControlBar(QWidget *parent = nullptr);
  ~ControlBar();

  void setElapsedTime(qint64 ms);
  void setTotalTime(qint64 ms);

 private slots:
  void on_btnPlay_clicked();
  void on_btnForward_clicked();

 public slots:
  void do_mediaPlayed();
  void do_mediaPaused();

 private:
  void init();

 private:
  Ui::ControlBar *ui;
  qint64 m_totalDuration = 0;    // ms
  qint64 m_elapsedDuration = 0;  // ms
  QTimer *m_elapsedTimer;

 signals:
  void sig_btnPlay_clicked();
  void sig_btnForward_clicked();
  void sig_sliderMoved(int value_s);
};

#endif  // GCPLAYER_CONTROLBAR_H_
