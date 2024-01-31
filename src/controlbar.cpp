#include <gcplayer/controlbar.h>
#include <ui_controlbar.h>

ControlBar::ControlBar(QWidget *parent)
    : QWidget(parent), ui(new Ui::ControlBar) {
  ui->setupUi(this);
  init();
}

void ControlBar::init() {}

ControlBar::~ControlBar() { delete ui; }

void ControlBar::on_btnPlay_clicked() { emit sig_btnPlay_clicked(); }

void ControlBar::on_btnForward_clicked() { emit sig_btnForward_clicked(); }
