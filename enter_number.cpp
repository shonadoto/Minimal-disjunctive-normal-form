#include "enter_number.h"
#include "ui_enter_number.h"
#include "backend.h"
#include "tablewindow.h"
#include "error.h"
enter_number::enter_number(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::enter_number)
{
  ui->setupUi(this);
}

enter_number::~enter_number()
{
  delete ui;
}

void enter_number::on_enter_number_button_clicked()
{
  QString s = ui->enter_number_2->text();
  bool check = true;
  for (auto& c : s)
    if (!(c>='0' && c <= '9'))
      check = false;
  if (!check) {
      error(QString("Enter only digits."));
      return;
    }
  QString check_s = "18446744073709551616";
  QString s_dupl=s;
  for (int64_t i = 0; i < check_s.size() - s.size(); ++i) {
      s_dupl = "0" + s_dupl;
    }
  if (s_dupl >= check_s && vars == 6) {
      error("Your number is too big!");
      return;
    } else if (vars != 6) {
      number = s.toULongLong();
      if (number >= 1ull << (1ull << vars)) {
          error("Your number is too big!");
          return;
        }
    } else {
      number = s.toULongLong();
    }
  if (number == 0) {
      error("Zero is forbidden!");
      return;
    }
  class TableWindow window;
  window.setWindowTitle("Table");
  window.setModal(true);
  window.exec();
}
