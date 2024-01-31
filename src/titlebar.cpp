#include <gcplayer/titlebar.h>
#include <gcplayer/utils.h>
#include <ui_titlebar.h>

#include <QFileInfo>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent), ui(new Ui::TitleBar) {
  ui->setupUi(this);
  init();
}

void TitleBar::init() {
  Utils::setTextIcon(ui->btnMin, 15, QChar(0xf2d1));
  Utils::setTextIcon(ui->btnMax, 15, QChar(0xf2d0));
  Utils::setTextIcon(ui->btnClose, 15, QChar(0xf2d3));
}

void TitleBar::on_btnClose_clicked() { emit sig_MainWindowClose(); }
void TitleBar::on_btnMax_clicked() { emit sig_MainWindowMax(); }

TitleBar::~TitleBar() { delete ui; }

void TitleBar::setTitle(QString &s) {
  auto fileInfo = QFileInfo(s);
  ui->labelVideoName->setText(fileInfo.fileName());
}
