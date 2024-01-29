#include <gcplayer/playlist.h>
#include <ui_playlist.h>

#include <QContextMenuEvent>
#include <QMenu>
#include <QVBoxLayout>

Playlist::Playlist(QWidget *parent)
    : QWidget(parent),
      m_inner(new __PlaylistInner(this)),
      ui(new Ui::Playlist) {
  ui->setupUi(this);
  init();
}

Playlist::~Playlist() { delete ui; }

void Playlist::init() {
  m_layout = new QVBoxLayout(this);
  m_layout->addWidget(m_inner);
  m_layout->setContentsMargins(2, 2, 2, 2);
}

__PlaylistInner::__PlaylistInner(QWidget *parent)
    : QListWidget(parent),
      m_menu(new QMenu(this)),
      m_actAddFile(new QAction("Add File", this)),
      m_actClearList(new QAction("Clear List", this)) {
  init();
}

void __PlaylistInner::init() {
  m_menu->addAction(m_actAddFile);
  m_menu->addAction(m_actClearList);
}

void __PlaylistInner::contextMenuEvent(QContextMenuEvent *ev) {
  m_menu->exec(ev->globalPos());
}
