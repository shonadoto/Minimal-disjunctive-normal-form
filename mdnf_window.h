#ifndef MDNF_WINDOW_H
#define MDNF_WINDOW_H

#include <QDialog>

namespace Ui {
  class Mdnf_window;
}

class Mdnf_window : public QDialog
{
  Q_OBJECT

public:
  explicit Mdnf_window(QWidget *parent = nullptr);
  ~Mdnf_window();

private:
  Ui::Mdnf_window *ui;
};

#endif // MDNF_WINDOW_H
