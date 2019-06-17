#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QVector>
#include<QString>
#include "analyzer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString expression;
    Analyzer anl;
    void append(QString c);
private slots:
    void input_0();
    void input_1();
    void input_2();
    void input_3();
    void input_4();
    void input_5();
    void input_6();
    void input_7();
    void input_8();
    void input_9();
    void input_left_bracket();
    void input_right_bracket();
    void input_add();
    void input_min();
    void input_mul();
    void input_div();
    void input_pow();
    void input_sin();
    void input_cos();
    void input_tan();
    void input_log();
    void input_dot();
    void clear();
    void back();
    void calc();
};

#endif // MAINWINDOW_H
