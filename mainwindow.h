#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_pbDecimal_released();
    void unary_operation_pressed();
    void on_pbClear_released();
    void digit_pressed();
    void on_pbEquals_released();
    void binary_operation_pressed();


};

#endif // MAINWINDOW_H
