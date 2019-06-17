#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->input_0,SIGNAL(released()),this,SLOT(input_0()));
    connect(ui->input_1,SIGNAL(released()),this,SLOT(input_1()));
    connect(ui->input_2,SIGNAL(released()),this,SLOT(input_2()));
    connect(ui->input_3,SIGNAL(released()),this,SLOT(input_3()));
    connect(ui->input_4,SIGNAL(released()),this,SLOT(input_4()));
    connect(ui->input_5,SIGNAL(released()),this,SLOT(input_5()));
    connect(ui->input_6,SIGNAL(released()),this,SLOT(input_6()));
    connect(ui->input_7,SIGNAL(released()),this,SLOT(input_7()));
    connect(ui->input_8,SIGNAL(released()),this,SLOT(input_8()));
    connect(ui->input_9,SIGNAL(released()),this,SLOT(input_9()));
    connect(ui->left_bracket,SIGNAL(released()),this,SLOT(input_left_bracket()));
    connect(ui->right_bracket,SIGNAL(released()),this,SLOT(input_right_bracket()));
    connect(ui->input_dot,SIGNAL(released()),this,SLOT(input_dot()));
    connect(ui->addButton,SIGNAL(released()),this,SLOT(input_add()));
    connect(ui->minusButton,SIGNAL(released()),this,SLOT(input_min()));
    connect(ui->mulButton,SIGNAL(released()),this,SLOT(input_mul()));
    connect(ui->divButton,SIGNAL(released()),this,SLOT(input_div()));
    connect(ui->sinButton,SIGNAL(released()),this,SLOT(input_sin()));
    connect(ui->cosButton,SIGNAL(released()),this,SLOT(input_cos()));
    connect(ui->tanButton,SIGNAL(released()),this,SLOT(input_tan()));
    connect(ui->powButton,SIGNAL(released()),this,SLOT(input_pow()));
    connect(ui->logButton,SIGNAL(released()),this,SLOT(input_log()));
    connect(ui->clearButton,SIGNAL(released()),this,SLOT(clear()));
    connect(ui->backButton,SIGNAL(released()),this,SLOT(back()));
    connect(ui->calcButton,SIGNAL(released()),this,SLOT(calc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_0()
{
    append("0");
}

void MainWindow::input_1()
{
    append("1");
}
void MainWindow::input_2()
{
    append("2");
}
void MainWindow::input_3()
{
    append("3");
}
void MainWindow::input_4()
{
    append("4");
}
void MainWindow::input_5()
{
    append("5");
}
void MainWindow::input_6()
{
    append("6");
}
void MainWindow::input_7()
{
    append("7");
}
void MainWindow::input_8()
{
    append("8");
}
void MainWindow::input_9()
{
    append("9");
}
void MainWindow::input_add()
{
    append("+");
}
void MainWindow::input_min()
{
    append("-");
}
void MainWindow::input_mul()
{
    append("*");
}
void MainWindow::input_div()
{
    append("/");
}
void MainWindow::input_pow()
{
    append("^");
}
void MainWindow::input_dot()
{
    append(".");
}
void MainWindow::input_left_bracket()
{
    append("(");
}
void MainWindow::input_right_bracket()
{
    append(")");
}
void MainWindow::input_sin()
{
    append("sin(");
}
void MainWindow::input_cos()
{
    append("cos(");
}
void MainWindow::input_tan()
{
    append("tan(");
}
void MainWindow::input_log()
{
    append("log(");
}
void MainWindow::clear()
{
    expression.clear();
    ui->show->setText(expression);
}
void MainWindow::back()
{
    if(expression == "wrong")
        expression.clear();
    else
        expression.resize(expression.size()-1);
    ui->show->setText(expression);
}
void MainWindow::append(QString c)
{
    if(expression == "wrong")
        clear();
    expression += c;
    ui->show->setText(expression);
}
void MainWindow::calc()
{
    char temp[256];
    sprintf(temp, "%lf", anl.calc(expression.toStdString()));
    expression = QString::fromStdString(temp);
    bool islegal = anl.getFlag();
    if(islegal)
        ui->show->setText(expression);
    else
    {
        expression = "wrong";
        ui->show->setText("表达式不合法，请重新输入!");
    }
    anl.resetFlag();
}
