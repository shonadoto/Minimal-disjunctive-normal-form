#ifndef ENTER_BITS_H
#define ENTER_BITS_H

#include <QDialog>

namespace Ui {
  class enter_bits;
}

class enter_bits : public QDialog
{
  Q_OBJECT

public:
  explicit enter_bits(QWidget *parent = nullptr);
  ~enter_bits();

private slots:
  void on_enter_bits_button_clicked();

private:
  Ui::enter_bits *ui;
};

#endif // ENTER_BITS_H
