#ifndef GCPLAYER_UTILS_H_
#define GCPLAYER_UTILS_H_

#include <QChar>
#include <QFont>

class Utils {
 public:
  template <class T>
  static void setTextIcon(T *widget, int pointSize, QChar icon) {
    QFont font;
    font.setFamily("JetBrainsMono Nerd Font");
    font.setPointSize(pointSize);
    widget->setFont(font);
    widget->setText(icon);
  }
};

#endif  // GCPLAYER_UTILS_H_
