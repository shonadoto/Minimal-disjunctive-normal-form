#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>

namespace Ui {
  class TableWindow;
}

class TableWindow : public QDialog
{
  Q_OBJECT

public:
  explicit TableWindow(QWidget *parent = nullptr);
  ~TableWindow();

private slots:
  void on_pushButton_clicked();

private:
  Ui::TableWindow *ui;
};

#endif // TABLEWINDOW_H
