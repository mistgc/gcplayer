#include <gcplayer/log.h>
#include <gcplayer/mainwindow.h>

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {

  Logger logger;
  int ret = 0;
  QApplication a(argc, argv);
  QFontDatabase::addApplicationFont(":/fonts/JetBrainsMonoNerd-Regular.ttf");
  MainWindow w;
  w.show();

  ret = a.exec();

  return ret;
}
