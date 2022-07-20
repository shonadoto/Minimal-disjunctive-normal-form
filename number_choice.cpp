#include "number_choice.h"
#include "ui_number_choice.h"
#include "enter_bits.h"
#include "enter_number.h"
#include "error.h"
number_choice::number_choice(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::number_choice)
{
  ui->setupUi(this);
}

number_choice::~number_choice()
{
  delete ui;
}

void number_choice::on_number_choice_button_clicked()
{
  bool enter_number = ui->enter_number->isChecked();
  bool enter_bits = ui->enter_bits->isChecked();
  if (enter_number) {
      class enter_number window;
      window.setWindowTitle("Enter number");
      window.setModal(true);
      window.exec();
    } else if (enter_bits) {
      class enter_bits window;
      window.setWindowTitle("Enter bits");
      window.setModal(true);
      window.exec();

    } else {;
      error(QString("Choose on of the options"));
      return;
    }
}
