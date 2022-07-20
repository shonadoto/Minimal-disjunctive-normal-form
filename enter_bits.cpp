#include "enter_bits.h"
#include "ui_enter_bits.h"
#include "backend.h"
#include "tablewindow.h"
#include "error.h"
enter_bits::enter_bits(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::enter_bits)
{
  ui->setupUi(this);
  ui->tableWidget->setColumnCount(1 << vars);
  ui->tableWidget->setRowCount(1);
}

enter_bits::~enter_bits()
{
  delete ui;
}

void enter_bits::on_enter_bits_button_clicked()
{
  number = 0;
  for (int64_t i = 0; i < 1 << vars; ++i) {
      QString s = ui->tableWidget->item(0, i)->text();
      if (s != "0" && s != "1") {
          error(QString("Enter only \"1\" or \"0\""));
          return;
        } else {
          int64_t bit = s.toULongLong();
          number |= bit;
          if (i != (1 << vars) - 1)
            number <<= 1;
        }
    }
  class TableWindow window;
  window.setWindowTitle("Table");
  window.setModal(true);
  window.exec();
}
