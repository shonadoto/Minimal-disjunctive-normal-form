#ifndef ERROR_H
#define ERROR_H

#include <QDialog>

namespace Ui {
  class Error;
}

class Error : public QDialog
{
  Q_OBJECT



public:
  explicit Error(QWidget *parent = nullptr);
  void setText(QString s);
  ~Error();

private:
  Ui::Error *ui;
};

void error(QString s);

#endif // ERROR_H
