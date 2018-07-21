#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent, int value1, int value) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton;
    QPushButton *butclose = new QPushButton("Close");
    QLabel *label = new QLabel;
    QLabel *label1 = new QLabel;
    QLabel *label2 = new QLabel;
    QLabel *label3 = new QLabel;
    QLabel *label4 = new QLabel;
    QLabel *label5 = new QLabel;
    QLabel *label6 = new QLabel;
    QGridLayout *layout1 = new QGridLayout;
    connect(butclose,SIGNAL(clicked(bool)),this,SLOT(close()));

    layout1->addWidget(button,2,1,Qt::AlignTop);
    layout1->addWidget(butclose,0,0,Qt::AlignLeft);
    layout1->addWidget(label,2,0,Qt::AlignTop);
    layout1->addWidget(label1,2,2,Qt::AlignTop);
    layout1->addWidget(label2,2,3,Qt::AlignTop);
    layout1->addWidget(label3,0,1,Qt::AlignBottom);
    layout1->addWidget(label4,1,1,Qt::AlignCenter);
    layout1->addWidget(label5,0,3,Qt::AlignBottom);
    layout1->addWidget(label6,1,3,Qt::AlignCenter);


    if(value1 == -253)
    {
        label->setText("Create First Node in head list :");
        button->setText(QString::number(value));
        label1->setText("-->");
        label2->setText("NULL");
        label2->setFrameStyle(QFrame::Box | QFrame::Plain);
        label4->setText(" |\n |\nV");
        label3->setFrameStyle(QFrame::Box | QFrame::Plain);
        label3->setText("Head & Tail");
        label6->setText(" |\n |\nV");
        label5->setFrameStyle(QFrame::Box | QFrame::Plain);
        label5->setText("Next");
    }
    setLayout(layout1);

}

Form::~Form()
{
    delete ui;
}
