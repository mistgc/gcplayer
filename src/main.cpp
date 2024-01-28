#include <gcplayer/mainwindow.h>

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QFontDatabase::addApplicationFont(":/fonts/JetBrainsMonoNerd-Regular.ttf");
  MainWindow w;
  w.show();

  return a.exec();
}
