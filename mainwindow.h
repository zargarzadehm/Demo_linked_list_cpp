#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QLineEdit* display;
    QPushButton* add;
    QPushButton* addend;
    QPushButton* addstart;
    QPushButton* addpos;
    QPushButton* delstart;
    QPushButton* delend;
    QPushButton* delpos;
    QSignalMapper* signalMapper;
public slots:
    void addnode();
    void addstartfunc();
    void addposition();
    void deletestart();
    void deleteend();
    void deletepos();
};
class node
{
public:
    int data;
    QPushButton *lable;
    QPushButton *lable_fake;
    QLabel *lable_fake1;
    node *next;
};
class list
{
private:
    node *head, *tail;

public:
    list();
    void createnode(int);
    void display();
    void insert_start(int);
    void insert_position(int, int);
    void delete_first();
    void delete_last();
    void delete_position(int);


};

#endif // MAINWINDOW_H
