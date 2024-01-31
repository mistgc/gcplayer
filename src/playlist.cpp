#include <gcplayer/log.h>
#include <gcplayer/playlist.h>
#include <ui_playlist.h>

#include <QContextMenuEvent>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QMenu>
#include <QVBoxLayout>

Playlist::Playlist(QWidget *parent)
    : QWidget(parent),
      m_inner(new __PlaylistInner(this)),
      m_layout(new QVBoxLayout(this)),
      ui(new Ui::Playlist) {
  ui->setupUi(this);
  init();
}

Playlist::~Playlist() { delete ui; }

void Playlist::init() {
  // __PlaylistInner
  m_layout->addWidget(m_inner);
  m_layout->setContentsMargins(2, 2, 2, 2);

  connect(m_inner, &__PlaylistInner::itemActivated, this,
          &Playlist::do_itemActivated);
}

void Playlist::do_itemActivated(QListWidgetItem *item) {
  QString path = item->data(Qt::UserRole).toString();
  m_currListItemIndex = m_inner->row(item);

  linfo("Selected %s", path.constData());

  emit sig_mediaSelected(path);
}

__PlaylistInner::__PlaylistInner(QWidget *parent)
    : QListWidget(parent),
      m_menu(new QMenu(this)),
      m_actAddFile(new QAction("Add File", this)),
      m_actClearList(new QAction("Clear List", this)) {
  init();
}

void __PlaylistInner::init() {
  // Context Menu
  m_menu->addAction(m_actAddFile);
  m_menu->addAction(m_actClearList);

  connect(m_actAddFile, SIGNAL(triggered()), this,
          SLOT(on_actAddFile_triggered()));
  connect(m_actClearList, SIGNAL(triggered()), this,
          SLOT(on_actClearList_triggered()));
}

void __PlaylistInner::contextMenuEvent(QContextMenuEvent *ev) {
  m_menu->exec(ev->globalPos());
}

void __PlaylistInner::on_actAddFile_triggered() {
  QStringList fileNames = QFileDialog::getOpenFileNames(
      this, "Select Files", QDir::homePath(),
      "Media Files(*.mkv *.wmv *.mp3 *.mp4 *.flv)");
  for (auto &i : fileNames) {
    auto *item = new QListWidgetItem();
    QFileInfo fileInfo(i);
    item->setData(Qt::UserRole, QVariant(fileInfo.filePath()));
    item->setText(fileInfo.fileName());
    this->addItem(item);
  }
}

void __PlaylistInner::on_actClearList_triggered() { this->clear(); }
