#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent, int value1, int value) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QPushButton *butclose = new QPushButton("Close");

    QGridLayout *layout1 = new QGridLayout;
    connect(butclose,SIGNAL(clicked(bool)),this,SLOT(close()));
    layout1->addWidget(butclose,0,0,Qt::AlignLeft);



    if(value1 == -253)
    {
        QPushButton *button = new QPushButton(QString::number(value));
        QLabel *label = new QLabel("Create First Node in head list :");
        QLabel *label1 = new QLabel("-->");
        QLabel *label2 = new QLabel("NULL");
        QLabel *label3 = new QLabel("Head & Tail");
        QLabel *label4 = new QLabel(" |\n |\nV");
        QLabel *label5 = new QLabel("Next");
        QLabel *label6 = new QLabel(" |\n |\nV");
        layout1->addWidget(button,2,1,Qt::AlignTop);

        layout1->addWidget(label,2,0,Qt::AlignTop);
        layout1->addWidget(label1,2,2,Qt::AlignTop);
        layout1->addWidget(label2,2,3,Qt::AlignTop);
        layout1->addWidget(label3,0,1,Qt::AlignBottom);
        layout1->addWidget(label4,1,1,Qt::AlignCenter);
        layout1->addWidget(label5,0,3,Qt::AlignBottom);
        layout1->addWidget(label6,1,3,Qt::AlignCenter);

        label2->setFrameStyle(QFrame::Box | QFrame::Plain);
        label3->setFrameStyle(QFrame::Box | QFrame::Plain);
        label5->setFrameStyle(QFrame::Box | QFrame::Plain);
    }
    else
    {
        QPushButton *butlast = new QPushButton(QString::number(value1));
        QLabel *lastnode = new QLabel("Last Node");
        QLabel *arrow = new QLabel(" |\n |\nV");
        QLabel *step1 = new QLabel("Step 1 :");
        QLabel *Nul = new QLabel("NULL");
        QLabel *next= new QLabel("Next");
        QLabel *arrow1 = new QLabel("-->");
        QLabel *arrow2 = new QLabel("  |\n  |\n V");

        layout1->addWidget(step1,3,0);
        layout1->addWidget(butlast,3,1);
        layout1->addWidget(arrow,2,1,Qt::AlignCenter);
        layout1->addWidget(lastnode,1,1,Qt::AlignBottom);
        layout1->addWidget(arrow1,3,2,Qt::AlignCenter);
        layout1->addWidget(Nul,3,3);
        layout1->addWidget(arrow2,2,3,Qt::AlignCenter);
        layout1->addWidget(next,1,3,Qt::AlignBottom);

        Nul->setFrameStyle(QFrame::Box | QFrame::Plain);
        lastnode->setFrameStyle(QFrame::Box | QFrame::Plain);
        next->setFrameStyle(QFrame::Box | QFrame::Plain);

        QPushButton * butlastnew = new QPushButton(QString::number(value));
        QLabel *step2 = new QLabel("Step 2 :");
        QLabel *arrow3 = new QLabel(" |\n |\nV");
        QLabel *arrow4 = new QLabel("-->");
        QLabel *arrow5 = new QLabel("  |\n  |\n V");
        QLabel *Nul1 = new QLabel("NULL");
        QLabel *next1= new QLabel("Next");


        layout1->addWidget(step2,5,0);
        layout1->addWidget(arrow3,4,3,Qt::AlignCenter);
        layout1->addWidget(butlastnew,5,3);
        layout1->addWidget(arrow4,5,4,Qt::AlignCenter);
        layout1->addWidget(Nul1,5,5);
        layout1->addWidget(next1,3,5,Qt::AlignBottom);
        layout1->addWidget(arrow5,4,5,Qt::AlignCenter);

        Nul1->setFrameStyle(QFrame::Box | QFrame::Plain);
        next1->setFrameStyle(QFrame::Box | QFrame::Plain);

        QLabel *space = new QLabel;
        layout1->addWidget(space,6,0);

        QPushButton * node = new QPushButton(QString::number(value1));
        QPushButton * endnode = new QPushButton(QString::number(value));
        QLabel *step3 = new QLabel("Finall :");
        QLabel *arrow6 = new QLabel("-->");
        QLabel *arrow7 = new QLabel("-->");
        QLabel *Nul2 = new QLabel("NULL");

        layout1->addWidget(step3,7,0);
        layout1->addWidget(node,7,1);
        layout1->addWidget(arrow6,7,2,Qt::AlignCenter);
        layout1->addWidget(endnode,7,3);
        layout1->addWidget(arrow7,7,4,Qt::AlignCenter);
        layout1->addWidget(Nul2,7,5);

        Nul2->setFrameStyle(QFrame::Box | QFrame::Plain);
    }
    setLayout(layout1);

}

Form::~Form()
{
    delete ui;
}
