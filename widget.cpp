#include <QMessageBox>
#include <sstream>
#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    updateState();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateState()
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    updateState();
}

#define decl_CLICKED_cap(name, diff) void Widget::on_##name##_clicked() { changeMoney( diff ); }

decl_CLICKED_cap(pb10, 10);
decl_CLICKED_cap(pb50, 50);
decl_CLICKED_cap(pb100, 100);
decl_CLICKED_cap(pb500, 500);

decl_CLICKED_cap(pbCoffee, -100);
decl_CLICKED_cap(pbTea, -150);
decl_CLICKED_cap(pbMilk, -200);

void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    std::stringstream buf;
    buf << "500 * " << (money / 500)
        << " + 100*" << (money % 500 / 100)
        << " + 50*" << (money % 100 / 50)
        << " + 10*" << (money % 50 / 10)
        << " = " << money;
    mb.information(nullptr, "T1tl3", buf.str().data());

    changeMoney(-money);
}

