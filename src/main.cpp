#include <gcplayer/log.h>
#include <gcplayer/mainwindow.h>

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
  tttl_log_set_level(TTTL_LOG_DEBUG);
  tttl_log_set_mode(TTTL_LOG_MODE_ASYNC);

  int ret = 0;
  QApplication a(argc, argv);
  QFontDatabase::addApplicationFont(":/fonts/JetBrainsMonoNerd-Regular.ttf");
  MainWindow w;
  w.show();

  ret = a.exec();

  tttl_log_close();

  return ret;
}
