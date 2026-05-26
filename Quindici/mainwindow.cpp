#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  int indice{0};
  for (auto &b : ui->centralwidget->findChildren<QPushButton *>()) {
    connect(b, SIGNAL(clicked()), this, SLOT(casellaClick()));
    if (indice == 0) {
      b->setText("");
    } else {
      b->setText(QString::number(indice));
    }
    ++indice;
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::casellaClick() {
  // qDebug() << "Click";
  auto sorgente = dynamic_cast<QPushButton *>(sender());
  if (sorgente) {
    sorgente->setText("OK");
  }
  auto indice =
      ui->centralwidget->findChildren<QPushButton *>().indexOf(sorgente);
  int row, column, rowSpan, columnSpan;
  ui->gridLayout->getItemPosition(indice, &row, &column, &rowSpan, &columnSpan);
  auto widgetSopra = ui->gridLayout->itemAtPosition(row - 1, column);
  if (widgetSopra) {
    QWidget *widget = widgetSopra->widget();
    auto btn = dynamic_cast<QPushButton *>(widget);
    if (btn) {
      // TODO: se btn contiene la stringa vuota
      // scambia i valori dei due pulsanti
    }
  }
}
