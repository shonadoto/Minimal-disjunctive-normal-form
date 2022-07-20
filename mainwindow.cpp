#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "number_choice.h"
#include "backend.h"
#include "error.h"
#include "QKeyEvent"
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_number_var_button_clicked()
{
  QString str = ui->lineEdit->text();
  bool good = true;
  for (auto& c : str)
    if (c < '0' || c >'9') {
        good = false;
      }
  if (!good) {
      error("Enter only digits!");
      return;
    }
  vars = str.toInt();
  if (vars > 6) {
      error(QString("Number of variables is too big (max 6)."));
      return;
    } else if (vars < 1) {
      error(QString("Number of variables is too small (min 1)."));
      return;
    }
  close();
  number_choice window;
  window.setWindowTitle("Choose number input type");
  window.setModal(true);
  window.exec();
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
  if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
      MainWindow::on_number_var_button_clicked();
    }
}
