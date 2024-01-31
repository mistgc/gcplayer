#ifndef GCPLAYER_TITLEBAR_H_
#define GCPLAYER_TITLEBAR_H_

#include <QWidget>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget {
  Q_OBJECT
 public:
  explicit TitleBar(QWidget *parent = nullptr);
  ~TitleBar();
  void setTitle(QString &s);

 private:
  void init();

 private:
  Ui::TitleBar *ui;

 signals:
  void sig_MainWindowMin();
  void sig_MainWindowMax();
  void sig_MainWindowClose();

 private slots:
  void on_btnClose_clicked();
  void on_btnMax_clicked();
};

#endif  // GCPLAYER_TITLEBAR_H_
