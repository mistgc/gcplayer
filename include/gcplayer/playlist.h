#ifndef GCPLAYER_PLAYLIST_H_
#define GCPLAYER_PLAYLIST_H_

#include <QListWidget>

namespace Ui {
class Playlist;
}

class QVBoxLayout;

class __PlaylistInner : public QListWidget {
 public:
  explicit __PlaylistInner(QWidget *parent = nullptr);

 protected:
  void contextMenuEvent(QContextMenuEvent *ev);

 private:
  void init();

 private:
  QMenu *m_menu;
  QAction *m_actAddFile;
  QAction *m_actClearList;
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
};

#endif  // GCPLAYER_PLAYLIST_H_
