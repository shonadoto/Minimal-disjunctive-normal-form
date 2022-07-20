#ifndef ENTER_NUMBER_H
#define ENTER_NUMBER_H

#include <QDialog>

namespace Ui {
  class enter_number;
}

class enter_number : public QDialog
{
  Q_OBJECT

public:
  explicit enter_number(QWidget *parent = nullptr);
  ~enter_number();

private slots:
  void on_enter_number_button_clicked();

private:
  Ui::enter_number *ui;
};

#endif // ENTER_NUMBER_H
