#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "backend.h"
#include "mdnf_window.h"
int cnt = 0;
std::vector<QColor> colors = {QColor(255,0,0),QColor(255,0,255), QColor(0,0,255), QColor(255,255,0)};
TableWindow::TableWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::TableWindow)
{
  ui->setupUi(this);

  bits_num = 1 << vars;
  fill_table();
  delete_zero_f();
  delete_bad_duplicats();
  delete_worse_cases();
  delete_good_duplicats();
  brute_force();


  ui->tableWidget->setRowCount(table.size() + 1);
  ui->tableWidget->setColumnCount(table[0].size() + 1);

  for (int64_t i = 1; i <= table.size(); ++i) {
      for (int64_t j = 1; j <= table[i-1].size(); ++j) {
          ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::fromStdString(table[i - 1][j - 1])));
        }
    }
  ui->tableWidget->setItem(0,0,new QTableWidgetItem("F"));
  for (int64_t i = 1; i <= table[0].size(); ++i)
    ui->tableWidget->setItem(0, i, new QTableWidgetItem(QString::fromStdString(combs[i-1])));
  for (int64_t i = 1; i <= table.size(); ++i)
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(func[i-1])));
}

TableWindow::~TableWindow()
{
  delete ui;
}

void TableWindow::on_pushButton_clicked()
{
  ++cnt;
  if (cnt == 5) {
      ui->pushButton->close();
      Mdnf_window w;
      w.setWindowTitle("MDNF");
      w.setModal(true);
      w.exec();
      close();
    }
  for (int i = 1; i <= table.size(); ++i)
    for (int j = 1; j <= table[i-1].size(); ++j)
      if (used[i-1][j-1] == -cnt)
        ui->tableWidget->item(i,j)->setBackground(QBrush(QColor(colors[cnt - 1])));

  if (cnt == 1)
    ui->pushButton->setText("Я карта");
  if (cnt == 2)
    ui->pushButton->setText("Я карта!");
  if (cnt == 3)
    ui->pushButton->setText("Я КАРТА");
  if (cnt == 4)
    ui->pushButton->setText("Я КАРТА Я КАРТА Я КАРТА!!!!!");
}
