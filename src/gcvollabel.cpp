#include <gcplayer/gcvollabel.h>
#include <gcplayer/log.h>

#include <QBrush>
#include <QEvent>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QSlider>
#include <QTimer>

GCVolLabel::GCVolLabel(QWidget *parent)
    : QWidget(parent),
      m_popupSlider(new __GCVolLabel_innerSlider(this)),
      m_textLabel(new __GCVolLabel_innerLabel(this)) {
  setPopupFixedSize(15, 70);
  m_popupSlider->setRange(0, 100);
  m_popupSlider->setValue(50);  // default volume value is 0.5
                                // (0 is silence, 1 is full volume)
  m_popupSlider->setWindowFlag(Qt::ToolTip);
  m_popupSlider->hide();

  connect(m_popupSlider, &__GCVolLabel_innerSlider::hoveredIn, [&] {
    m_isSliberHovered = true;
    showPopupSlider();
  });
  connect(m_popupSlider, &__GCVolLabel_innerSlider::hoveredOut, [&] {
    m_isSliberHovered = false;
    hidePopupSlider();
  });
  connect(m_textLabel, &__GCVolLabel_innerLabel::hoveredIn, [&] {
    m_isSliberHovered = true;
    showPopupSlider();
  });
  connect(m_textLabel, &__GCVolLabel_innerLabel::hoveredOut, [&] {
    m_isSliberHovered = false;
    hidePopupSlider();
  });
  connect(m_popupSlider, SIGNAL(valueChanged(int)), this,
          SIGNAL(sliderValueChanged(int)));
  connect(m_popupSlider, SIGNAL(sliderMoved(int)), this,
          SIGNAL(sliderMoved(int)));
  connect(m_popupSlider, SIGNAL(sliderPressed()), this,
          SIGNAL(sliderPressed()));
  connect(m_popupSlider, SIGNAL(sliderReleased()), this,
          SIGNAL(sliderReleased()));
}

void GCVolLabel::showPopupSlider() {
  if (m_isSliberHovered || m_isLabelHovered) {
    QPoint pos = getGlobalPos();
    pos = QPoint(pos.x(), pos.y() - m_popupSlider->height() - 5);
    m_popupSlider->move(pos);
    m_popupSlider->show();
  }
}

void GCVolLabel::hidePopupSlider() {
  QTimer::singleShot(600, [&] {
    if (!m_isSliberHovered && !m_isSliberHovered) {
      m_popupSlider->hide();
    }
  });
}

QPoint GCVolLabel::getGlobalPos() {
  QPoint pos = mapToGlobal(QPoint(0, 0));
  ldebug("GCVolLabel pos: (%d, %d)", pos.x(), pos.y());
  return pos;
}

void GCVolLabel::setPopupFixedSize(const QSize &size) {
  m_popupSlider->setFixedSize(size);
}

void GCVolLabel::setPopupFixedSize(const int w, const int h) {
  m_popupSlider->setFixedSize(w, h);
}

void GCVolLabel::setText(const QString &text) { m_textLabel->setText(text); }

// __GCVolLabel_innerLabel

__GCVolLabel_innerLabel::__GCVolLabel_innerLabel(QWidget *parent)
    : QLabel(parent) {}

void __GCVolLabel_innerLabel::enterEvent(QEnterEvent *ev) { emit hoveredIn(); }

void __GCVolLabel_innerLabel::leaveEvent(QEvent *ev) { emit hoveredOut(); }

// __GCVolLabel_innerSlider

__GCVolLabel_innerSlider::__GCVolLabel_innerSlider(QWidget *parent)
    : QSlider(parent) {}

void __GCVolLabel_innerSlider::enterEvent(QEnterEvent *ev) { emit hoveredIn(); }

void __GCVolLabel_innerSlider::leaveEvent(QEvent *ev) { emit hoveredOut(); }
