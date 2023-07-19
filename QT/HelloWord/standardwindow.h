
#ifndef STANDARDWINDOW_H
#define STANDARDWINDOW_H


#include <QMainWindow>
#include <QWidget>


class StandardWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StandardWindow(QWidget *parent = nullptr);

signals:

};

#endif // STANDARDWINDOW_H
