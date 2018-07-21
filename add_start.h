#ifndef ADD_START_H
#define ADD_START_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class Add_start;
}

class Add_start : public QWidget
{
    Q_OBJECT

public:
    explicit Add_start(QWidget *parent = 0, int value1=0, int value = 0);
    ~Add_start();

private:
    Ui::Add_start *ui;
};

#endif // ADD_START_H
