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

 private:
  void init();

 private:
  Ui::ControlBar *ui;

 signals:
  void sig_btnPlay_clicked();
  void sig_btnForward_clicked();
};

#endif  // GCPLAYER_CONTROLBAR_H_
