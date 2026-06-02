#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>

static void setColor(QPushButton *btn) {
  QString rosso{"background-color: red; color: yellow;"};
  QString bianco{"background-color: white; color: black;"};
  QString nero{"background-color: black;"};
  if (btn->text().isEmpty()) {
    btn->setStyleSheet(nero);
  } else {
    bool conversioneOk;
    int valore = btn->text().toInt(&conversioneOk);
    if (conversioneOk && valore % 2 == 0) {
      btn->setStyleSheet(rosso);
    } else {
      btn->setStyleSheet(bianco);
    }
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->actionNuova_partita, SIGNAL(triggered()), this,
          SLOT(nuovaPartita()));
  // Connessione del segnale inizioPartita con lo slot
  // showMessage di QStatusBar
  connect(this, SIGNAL(inizioPartita(QString)), ui->statusbar,
          SLOT(showMessage(QString)));
  nuovaPartita();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::casellaClick() {
  // qDebug() << "Click";
  auto sorgente = dynamic_cast<QPushButton *>(sender());
  if (sorgente) {
    handleClick(sorgente);
  }
}

void MainWindow::nuovaPartita() {
  int indice{0};
  for (auto &b : ui->centralwidget->findChildren<QPushButton *>()) {
    connect(b, SIGNAL(clicked()), this, SLOT(casellaClick()));
    if (indice == 0) {
      b->setText("");
    } else {
      b->setText(QString::number(indice));
    }
    setColor(b);
    ++indice;
  }
  randomizzaCelle();
  // Viene emesso il segnale
  emit inizioPartita("Buona fortuna!");
}

void MainWindow::randomizzaCelle() {
  srand(time(NULL));
  // Assumiamo che la cella vuota all'inizio sia la prima
  int emptyRow{0}, emptyCol{0}, targetRow{0}, targetCol{0};
  for (auto i{0}; i < 1000;) {
    double r = (double)rand() / RAND_MAX;
    if (r < 0.33) {
      if (targetRow > 0) {
        targetRow = emptyRow - 1;
      }
    } else if (r < 0.66) {
      targetRow = emptyRow;
    } else {
      if (targetRow < 3) {
        targetRow = emptyRow + 1;
      }
    }
    double c = (double)rand() / RAND_MAX;
    if (c < 0.33) {
      if (emptyCol > 0) {
        targetCol = emptyCol - 1;
      }
    } else if (r < 0.66) {
      targetCol = emptyCol;
      if (targetRow == emptyRow) {
        continue;
      }
    } else {
      if (targetCol < 3) {
        targetCol = emptyCol + 1;
      }
    }
    // Determina il pulsante a targetCol, targetRow
    auto w = ui->gridLayout->itemAtPosition(targetRow, targetCol);
    if (w) {
      QWidget *widget = w->widget();
      auto btn = dynamic_cast<QPushButton *>(widget);
      handleClick(btn);
      if (btn->text().isEmpty()) {
        emptyCol = targetCol;
        emptyRow = targetRow;
        ++i;
      }
    }
  }
}

void MainWindow::handleClick(QPushButton *sorgente) {
  auto indice =
      ui->centralwidget->findChildren<QPushButton *>().indexOf(sorgente);
  int row, column, rowSpan, columnSpan;
  ui->gridLayout->getItemPosition(indice, &row, &column, &rowSpan, &columnSpan);
  auto widgetSopra = ui->gridLayout->itemAtPosition(row - 1, column);
  if (widgetSopra) {
    QWidget *widget = widgetSopra->widget();
    auto btn = dynamic_cast<QPushButton *>(widget);
    if (btn && btn->text().isEmpty()) {
      btn->setText(sorgente->text());
      sorgente->setText("");
      setColor(btn);
      setColor(sorgente);
      return;
    }
  }
  auto widgetSotto = ui->gridLayout->itemAtPosition(row + 1, column);
  if (widgetSotto) {
    QWidget *widget = widgetSotto->widget();
    auto btn = dynamic_cast<QPushButton *>(widget);
    if (btn && btn->text().isEmpty()) {
      btn->setText(sorgente->text());
      sorgente->setText("");
      setColor(btn);
      setColor(sorgente);
      return;
    }
  }
  auto widgetDestra = ui->gridLayout->itemAtPosition(row, column + 1);
  if (widgetDestra) {
    QWidget *widget = widgetDestra->widget();
    auto btn = dynamic_cast<QPushButton *>(widget);
    if (btn && btn->text().isEmpty()) {
      btn->setText(sorgente->text());
      sorgente->setText("");
      setColor(btn);
      setColor(sorgente);
      return;
    }
  }
  auto widgetSinistra = ui->gridLayout->itemAtPosition(row, column - 1);
  if (widgetSinistra) {
    QWidget *widget = widgetSinistra->widget();
    auto btn = dynamic_cast<QPushButton *>(widget);
    if (btn && btn->text().isEmpty()) {
      btn->setText(sorgente->text());
      sorgente->setText("");
      setColor(btn);
      setColor(sorgente);
      return;
    }
  }
}
