#include "add_start.h"
#include "ui_add_start.h"

Add_start::Add_start(QWidget *parent, int value1, int value) :
    QWidget(parent),
    ui(new Ui::Add_start)
{
    ui->setupUi(this);
    QPushButton *butclose = new QPushButton("Close");

    QGridLayout *layout1 = new QGridLayout;
    connect(butclose,SIGNAL(clicked(bool)),this,SLOT(close()));
    layout1->addWidget(butclose,0,0,Qt::AlignLeft);

    QPushButton *pushnew = new QPushButton(QString::number(value));
    QPushButton *push = new QPushButton(QString::number(value1));
    QPushButton *pushnew1 = new QPushButton(QString::number(value));
    QPushButton *push1 = new QPushButton(QString::number(value1));

    QLabel * arrow = new QLabel(" |\n |\nV");
    QLabel * arrow1 = new QLabel("-->");
    QLabel * arrow2 = new QLabel(" |\n |\nV");
    QLabel * arrow3 = new QLabel(" |\n |\nV");
    QLabel * arrow4 = new QLabel("<--");
    QLabel * arrow5 = new QLabel("-->");
    QLabel * arrow6 = new QLabel(" |\n |\nV");
    QLabel * arrow7 = new QLabel("-->");
    QLabel * arrow8 = new QLabel("-->");
    QLabel * arrow9 = new QLabel(" |\n |\nV");

    QLabel * step1 = new QLabel("Step 1:");
    QLabel * step2 = new QLabel("Step 2:");
    QLabel * finall = new QLabel("Finall :");

    QLabel *newnode = new QLabel("New Node");
    QLabel *slabel = new QLabel("       ");
    QLabel *next = new QLabel("Next");
    QLabel *head1 = new QLabel("head");
    QPushButton *point = new QPushButton(" ... ");
    QLabel *spc = new QLabel("   ");
    QLabel *head2 = new QLabel("New head");
    QPushButton *point1 = new QPushButton(" ... ");
    QLabel *next1 = new QLabel("Next");


    layout1->addWidget(newnode,1,1);
    layout1->addWidget(arrow,2,1,Qt::AlignCenter);
    layout1->addWidget(step1,3,0);
    layout1->addWidget(pushnew,3,1);
    layout1->addWidget(arrow1,3,2,Qt::AlignCenter);
    layout1->addWidget(slabel,3,3);
    layout1->addWidget(next,3,5,Qt::AlignBottom);
    layout1->addWidget(arrow2,4,3,Qt::AlignCenter);
    layout1->addWidget(arrow3,4,5,Qt::AlignCenter);
    layout1->addWidget(step2,5,0);
    layout1->addWidget(head1,5,1,Qt::AlignBottom);
    layout1->addWidget(arrow4,5,2,Qt::AlignCenter);
    layout1->addWidget(push,5,3);
    layout1->addWidget(arrow5,5,4,Qt::AlignCenter);
    layout1->addWidget(point,5,5);
    layout1->addWidget(spc,6,0);
    layout1->addWidget(finall,9,0);
    layout1->addWidget(head2,7,1,Qt::AlignBottom);
    layout1->addWidget(arrow6,8,1,Qt::AlignCenter);
    layout1->addWidget(pushnew1,9,1);
    layout1->addWidget(arrow7,9,2,Qt::AlignCenter);
    layout1->addWidget(arrow8,9,4,Qt::AlignCenter);
    layout1->addWidget(push1,9,3);
    layout1->addWidget(point1,9,5);
    layout1->addWidget(arrow9,2,3,Qt::AlignCenter);
    layout1->addWidget(next1,1,3,Qt::AlignBottom);

    newnode->setFrameStyle(QFrame::Box | QFrame::Plain);
    next->setFrameStyle(QFrame::Box | QFrame::Plain);
    next1->setFrameStyle(QFrame::Box | QFrame::Plain);
    head1->setFrameStyle(QFrame::Box | QFrame::Plain);
    head2->setFrameStyle(QFrame::Box | QFrame::Plain);
    slabel->setFrameStyle(QFrame::Box | QFrame::Plain);

    setLayout(layout1);

}

Add_start::~Add_start()
{
    delete ui;
}
