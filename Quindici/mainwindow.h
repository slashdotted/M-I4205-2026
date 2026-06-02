#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void casellaClick();
  void nuovaPartita();

  // Dichiarazione di un segnale
signals:
  void inizioPartita(QString messaggio);

private:
  void randomizzaCelle();
  void handleClick(QPushButton *sorgente);
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
