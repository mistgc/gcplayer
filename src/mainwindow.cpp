#include <gcplayer/mainwindow.h>
#include <gcplayer/playlist.h>
#include <gcplayer/titlebar.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  init();
}

void MainWindow::init() {
  // Title Bar
  m_titleBar = new TitleBar(this);
  ui->titleBar->setTitleBarWidget(m_titleBar);
  connect(m_titleBar, SIGNAL(sig_MainWindowClose()), this,
          SLOT(do_MainWindowClose()));
  connect(m_titleBar, SIGNAL(sig_MainWindowMax()), this,
          SLOT(do_MainWindowMax()));
  connect(m_titleBar, SIGNAL(sig_MainWindowMin()), this,
          SLOT(do_MainWindowMin()));

  // Playlist
  m_playlist = new Playlist(this);
  ui->playlist->setTitleBarWidget(new QWidget(this));
  ui->playlist->setWidget(m_playlist);
}

void MainWindow::do_MainWindowClose() { this->close(); }

void MainWindow::do_MainWindowMax() {
  if (this->isMaximized()) {
    this->showNormal();
  } else {
    this->showMaximized();
  }
}

void MainWindow::do_MainWindowMin() { this->showMinimized(); }

MainWindow::~MainWindow() { delete ui; }
