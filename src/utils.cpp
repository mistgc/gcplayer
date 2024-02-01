#include <gcplayer/log.h>
#include <gcplayer/utils.h>

#include <QFile>

QString Utils::getStringFromFile(QString path) {
  QString s;
  QFile file(path);

  if (file.open(QIODevice::ReadOnly)) {
    s = file.readAll();
    file.close();
  } else {
    ldebug("%s file doesn't exists.", path.toUtf8().constData());
  }

  return s;
}
