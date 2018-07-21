#include "add_start.h"
#include "ui_add_start.h"

Add_start::Add_start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_start)
{
    ui->setupUi(this);
}

Add_start::~Add_start()
{
    delete ui;
}
