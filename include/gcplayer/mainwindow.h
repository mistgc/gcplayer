#ifndef GCPLAYER_MAINWINDOW_H_
#define GCPLAYER_MAINWINDOW_H_

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class TitleBar;
class Playlist;

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  void init();

 private:
  Ui::MainWindow *ui;

  TitleBar *m_titleBar;
  Playlist *m_playlist;

 private slots:
  void do_MainWindowClose();
  void do_MainWindowMax();
  void do_MainWindowMin();
};

#endif  // GCPLAYER_MAINWINDOW_H_
