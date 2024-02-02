#ifndef GCPLAYER_PLAYLIST_H_
#define GCPLAYER_PLAYLIST_H_

#include <QListWidget>

namespace Ui {
class Playlist;
}

class QVBoxLayout;

class __PlaylistInner : public QListWidget {
  Q_OBJECT
 public:
  explicit __PlaylistInner(QWidget *parent = nullptr);

 protected:
  void contextMenuEvent(QContextMenuEvent *ev) override;

 private:
  void init();

 private:
  QMenu *m_menu;
  QAction *m_actAddFile;
  QAction *m_actClearList;

 private slots:
  void on_actAddFile_triggered();
  void on_actClearList_triggered();
};

class Playlist : public QWidget {
  Q_OBJECT
 public:
  explicit Playlist(QWidget *parent = nullptr);
  ~Playlist();

 private:
  void init();

 private:
  Ui::Playlist *ui;
  __PlaylistInner *m_inner;
  QVBoxLayout *m_layout;
  quint32 m_currListItemIndex;

 public slots:
  void do_itemActivated(QListWidgetItem *item);
  void do_btnForward_clicked();

 signals:
  void sig_mediaSelected(QString &path);
  void sig_listCleared();
};

#endif  // GCPLAYER_PLAYLIST_H_
