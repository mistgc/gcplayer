#include <gcplayer/controlbar.h>
#include <gcplayer/mainwindow.h>
#include <gcplayer/playerwidget.h>
#include <gcplayer/playlist.h>
#include <gcplayer/titlebar.h>
#include <ui_mainwindow.h>

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_titleBar(new TitleBar(this)),
      m_playlist(new Playlist(this)),
      m_playerWidget(new PlayerWidget(this)),
      m_ctrlBar(new ControlBar(this)),
      m_centralWidgetLayout(new QVBoxLayout) {
  ui->setupUi(this);
  init();
}

void MainWindow::init() {
  // Central Widget
  ui->centralwidget->setLayout(m_centralWidgetLayout);

  // Title Bar
  ui->titleBar->setTitleBarWidget(m_titleBar);
  connect(m_titleBar, SIGNAL(sig_MainWindowClose()), this,
          SLOT(do_MainWindowClose()));
  connect(m_titleBar, SIGNAL(sig_MainWindowMax()), this,
          SLOT(do_MainWindowMax()));
  connect(m_titleBar, SIGNAL(sig_MainWindowMin()), this,
          SLOT(do_MainWindowMin()));

  // Playlist
  ui->playlist->setTitleBarWidget(new QWidget(this));
  ui->playlist->setWidget(m_playlist);
  connect(m_playlist, &Playlist::sig_mediaSelected, m_playerWidget,
          &PlayerWidget::setMediaSource);
  connect(m_playlist, &Playlist::sig_mediaSelected, m_titleBar,
          &TitleBar::setTitle);

  // Player Widget
  m_centralWidgetLayout->addWidget(m_playerWidget);
  connect(m_playerWidget, &PlayerWidget::sig_durationChanged, m_ctrlBar,
          &ControlBar::setTotalTime);
  connect(m_playerWidget, &PlayerWidget::sig_played, m_ctrlBar,
          &ControlBar::do_mediaPlayed);
  connect(m_playerWidget, &PlayerWidget::sig_paused, m_ctrlBar,
          &ControlBar::do_mediaPaused);

  // Control Bar
  m_centralWidgetLayout->addWidget(m_ctrlBar);
  connect(m_ctrlBar, SIGNAL(sig_btnPlay_clicked()), m_playerWidget,
          SLOT(playOrPause()));
  connect(m_ctrlBar, SIGNAL(sig_btnForward_clicked()), m_playlist,
          SLOT(do_btnForward_clicked()));
  connect(m_ctrlBar, &ControlBar::sig_sliderMoved,
          [&](int value_s) { m_playerWidget->seek(value_s * 1000); });
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
