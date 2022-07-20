#include "error.h"
#include "ui_error.h"

Error::Error(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Error)
{
  ui->setupUi(this);
}

Error::~Error()
{
  delete ui;
}

void Error::setText(QString s) {
  ui->label->setText(s);
}

void error(QString s) {
  Error window;
  window.setWindowTitle("Error!");
  window.setText(s);
  window.setModal(true);
  window.exec();
}
