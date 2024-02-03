#ifndef GCPLAYER_GCVOLLABEL_H_
#define GCPLAYER_GCVOLLABEL_H_

#include <QLabel>
#include <QSlider>
#include <QWidget>

class __GCVolLabel_innerSlider;
class __GCVolLabel_innerLabel;

class GCVolLabel : public QWidget {
  Q_OBJECT
 public:
  explicit GCVolLabel(QWidget *parent = nullptr);

  void setPopupFixedSize(const QSize &size);
  void setPopupFixedSize(const int w, const int h);
  void setText(const QString &text);

 protected:
  virtual void showPopupSlider();
  virtual void hidePopupSlider();

 private:
  QPoint getGlobalPos();

 private:
  bool m_isLabelHovered = false;
  bool m_isSliberHovered = false;
  __GCVolLabel_innerLabel *m_textLabel = nullptr;
  __GCVolLabel_innerSlider *m_popupSlider = nullptr;

 signals:
  void sliderValueChanged(int value);
  void sliderMoved(int value);
  void sliderPressed();
  void sliderReleased();
};

class __GCVolLabel_innerLabel : public QLabel {
  Q_OBJECT
 public:
  __GCVolLabel_innerLabel(QWidget *parent = nullptr);

 protected:
  void enterEvent(QEnterEvent *ev);
  void leaveEvent(QEvent *ev);

 signals:
  void hoveredIn();
  void hoveredOut();
};

class __GCVolLabel_innerSlider : public QSlider {
  Q_OBJECT
 public:
  __GCVolLabel_innerSlider(QWidget *parent = nullptr);

 protected:
  void enterEvent(QEnterEvent *ev);
  void leaveEvent(QEvent *ev);

 signals:
  void hoveredIn();
  void hoveredOut();
};

#endif  // GCPLAYER_GCVOLLABEL_H_
