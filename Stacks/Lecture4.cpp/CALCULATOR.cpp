
#include "calculator.h"
#include "ui_calculator.h"
#include <QString>
#include <QStack>
#include <cmath>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->btn0, &QPushButton::clicked, this, &Calculator::onDigitClicked);
    // ... repeat for btn1 to btn9, btnDot, btnPlus, btnMinus etc.
    connect(ui->btnEqual, &QPushButton::clicked, this, &Calculator::onEqualClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &Calculator::onClearClicked);
}

Calculator::~Calculator() {
    delete ui;
}

void Calculator::onDigitClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    ui->display->setText(ui->display->text() + button->text());
}

void Calculator::onClearClicked() {
    ui->display->clear();
}

void Calculator::onEqualClicked() {
    QString expr = ui->display->text();
    double result = evaluate(expr);  // you can reuse evaluate() from CLI
    ui->display->setText(QString::number(result));
}
