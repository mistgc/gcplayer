#include <gcplayer/controlbar.h>
#include <gcplayer/log.h>
#include <ui_controlbar.h>

#include <QTime>
#include <QTimer>

ControlBar::ControlBar(QWidget *parent)
    : QWidget(parent),
      m_elapsedTimer(new QTimer(this)),
      ui(new Ui::ControlBar) {
  ui->setupUi(this);
  init();
}

void ControlBar::init() {
  // Time Slider
  // set 3s per step for slider
  ui->sliderTime->setSingleStep(3);
  connect(ui->sliderTime, &QSlider::valueChanged, [&](int value_s) {
    m_elapsedDuration = value_s * 1000;
    this->setElapsedTime(value_s * 1000);
    emit sig_sliderValueChanged(value_s);
  });
  // Elapsed Timer
  connect(m_elapsedTimer, &QTimer::timeout, [&] {
    m_elapsedDuration += 1000;
    this->setElapsedTime(m_elapsedDuration);
  });
}

ControlBar::~ControlBar() { delete ui; }

void ControlBar::on_btnPlay_clicked() { emit sig_btnPlay_clicked(); }

void ControlBar::on_btnForward_clicked() { emit sig_btnForward_clicked(); }

void ControlBar::setElapsedTime(qint64 ms) {
  ui->sliderTime->setValue(ms / 1000);
  ui->timeEditElapsed->setTime(QTime::fromMSecsSinceStartOfDay(ms));
}

void ControlBar::setTotalTime(qint64 ms) {
  m_totalDuration = ms;
  m_elapsedDuration = 0;
  ui->sliderTime->setMinimum(0);
  ui->sliderTime->setMaximum(ms / 1000 + 1);
  ui->timeEditTotal->setTime(QTime::fromMSecsSinceStartOfDay(ms));
}

void ControlBar::do_mediaPlayed() { m_elapsedTimer->start(1000); }

void ControlBar::do_mediaPaused() { m_elapsedTimer->stop(); }
