#ifndef GCPLAYER_MAINWINDOW_H_
#define GCPLAYER_MAINWINDOW_H_

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
};

#endif  // GCPLAYER_MAINWINDOW_H_
