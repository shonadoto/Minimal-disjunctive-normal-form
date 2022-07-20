#include "mdnf_window.h"
#include "ui_mdnf_window.h"
#include "backend.h"
Mdnf_window::Mdnf_window(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Mdnf_window)
{
  ui->setupUi(this);
  QString s = "Lenght: ";
  s = s + QString::fromStdString(std::to_string(min_len)) + "\n";
  for (int64_t i = 0; i < mdnf.size(); ++i)
      if (min_len == mdnf_lens[i])
          for (int64_t j = 0; j < mdnf[i].size(); ++j) {
              s = s + QString::fromStdString(mdnf[i][j]);
              if (j != mdnf[i].size() - 1)
                s = s + " v ";
              else
                s += "\n";
            }
  ui->textEdit->setText(s);
}

Mdnf_window::~Mdnf_window()
{
  delete ui;
}

