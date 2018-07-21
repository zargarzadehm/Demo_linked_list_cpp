#include "mainwindow.h"
#include <QTime>
#include <QTimer>
#include <form.h>

list obj;

QGridLayout *layou = new QGridLayout;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    display = new QLineEdit;

    add = new QPushButton("Add Node");
    addend = new QPushButton("Add End");
    addstart = new QPushButton("Add Start");
    addpos = new QPushButton("Add Position");
    delstart = new QPushButton("Delete Start");
    delend = new QPushButton("Delete End");
    delpos = new QPushButton("Delete Position");

    QFont font = display->font();
    font.setPointSize(font.pointSize() + 16);
    display->setFont(font);

    layou->addWidget(display,0,0,2,2,Qt::AlignTop);

    layou->addWidget(add,0,2,0,1,Qt::AlignTop);
    layou->addWidget(addstart,1,2,1,1,Qt::AlignTop);
    layou->addWidget(addpos,0,3,0,1,Qt::AlignTop);
    layou->addWidget(addend,1,3,1,1,Qt::AlignTop);
    layou->addWidget(delstart,0,4,0,1,Qt::AlignTop);
    layou->addWidget(delpos,1,4,1,1,Qt::AlignTop);
    layou->addWidget(delend,0,5,0,1,Qt::AlignTop);
    connect (add, SIGNAL(clicked(bool)), this, SLOT(addnode())) ;
    connect (addend, SIGNAL(clicked(bool)), this, SLOT(addnode())) ;
    connect(addstart,SIGNAL(clicked(bool)),this,SLOT(addstartfunc()));
    connect(addpos,SIGNAL(clicked(bool)),this,SLOT(addposition()));
    connect(delstart,SIGNAL(clicked(bool)),this,SLOT(deletestart()));
    connect(delend,SIGNAL(clicked(bool)),this,SLOT(deleteend()));
    connect(delpos,SIGNAL(clicked(bool)),this,SLOT(deletepos()));

    QScrollArea *scrollArea=new QScrollArea;

    QWidget *containerWidget=new QWidget;

    containerWidget->setLayout(layou);
    scrollArea->setHorizontalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAsNeeded );
    scrollArea-> setBackgroundRole(QPalette::Dark);
    scrollArea->setAutoFillBackground(true);
    scrollArea->setWidgetResizable( true );
    scrollArea->setWidget(containerWidget);
    this->setCentralWidget(scrollArea);
}

void MainWindow::addnode()
{
    obj.createnode(display->text().toInt());
    display->clear();
    obj.display();
}
void MainWindow::addstartfunc()
{
    obj.insert_start(display->text().toInt());
    display->clear();
    obj.display();
}
void MainWindow::addposition()
{
    QString x = display->text();
    QStringList stringlist = x.split(',');
    obj.insert_position(stringlist[0].toInt(), stringlist[1].toInt());
    display->clear();
    obj.display();
}
void MainWindow::deletestart()
{
    obj.delete_first();
    display->clear();
    obj.display();
}
void MainWindow::deleteend()
{
    obj.delete_last();
    display->clear();
    obj.display();
}
void MainWindow::deletepos()
{
    obj.delete_position(display->text().toInt());
    display->clear();
    obj.display();
}

MainWindow::~MainWindow()
{

}

list::list()
{
    head = NULL;
    tail = NULL;
}

void list::createnode(int value)
{
    node *temp=new node;
    int value1 = 0;
    temp->data=value;
    temp->lable = new QPushButton;
    temp->lable->setText(QString::number(value));
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
        value1 = -253;
    }
    else
    {
        tail->lable_fake = new QPushButton("     ");
        tail->lable_fake1 = new QLabel(" |\n |\nV");
        tail->next=temp;
        value1 = tail->data;
        tail=temp;
    }

    Form *omg = new Form(0,value1,value);
    omg->show();
}
void list::display()
{
    node *temp=new node;
    temp=head;


    int i=2,j=0;
    while(temp!=NULL)
    {
            layou->addWidget(temp->lable,i,j,Qt::AlignCenter);
        if(temp->next != NULL)
        {
            layou->addWidget(temp->lable_fake,i,j+1,Qt::AlignCenter);
            layou->addWidget(temp->lable_fake1,i+1,j+1,Qt::AlignCenter);
        }
        temp=temp->next;
        i+=2;
        j++;
    }
}
void list::insert_start(int value)
{
    node *temp=new node;
    temp->lable = new QPushButton;
    temp->lable_fake = new QPushButton("     ");
    temp->lable_fake1 = new QLabel(" |\n |\nV");

    temp->data=value;
    temp->lable->setText(QString::number(value));
    temp->next=head;
    head=temp;
}
void list::insert_position(int pos, int value)
{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;

    temp->lable = new QPushButton;
    temp->lable_fake = new QPushButton("     ");
    temp->lable_fake1 = new QLabel(" |\n |\nV");

    cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    temp->lable->setText(QString::number(value));   
    pre->next=temp;
    temp->next=cur;
}
void list::delete_first()
{
    node *temp=new node;
    temp=head;
    delete head->lable;
    delete head->lable_fake;
    delete head->lable_fake1;
    head=head->next;
    delete temp;
}
void list::delete_last()
{
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    delete previous->lable_fake;
    delete previous->lable_fake1;
    tail=previous;
    previous->next=NULL;
    delete current->lable;
    delete current;
}
void list::delete_position(int pos)
{
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    delete current->lable;
    if(current->next!=NULL)
    {
        delete current->lable_fake;
        delete current->lable_fake1;
    }
    else
    {
        delete previous->lable_fake;
        delete previous->lable_fake1;
    }

}

