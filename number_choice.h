#ifndef NUMBER_CHOICE_H
#define NUMBER_CHOICE_H

#include <QDialog>

namespace Ui {
  class number_choice;
}

class number_choice : public QDialog
{
  Q_OBJECT

public:
  explicit number_choice(QWidget *parent = nullptr);
  ~number_choice();

private slots:
  void on_number_choice_button_clicked();

private:
  Ui::number_choice *ui;
};

#endif // NUMBER_CHOICE_H
