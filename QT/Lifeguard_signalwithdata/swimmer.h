
#ifndef SWIMMER_H
#define SWIMMER_H


#include <QObject>


class Swimmer : public QObject
{
    Q_OBJECT
private:
    std::string sw_name;
    int sw_id;

public:
    explicit Swimmer(std::string name, int id, QObject *parent = nullptr);
    void raise_threat();

signals:
    void threat(std::string name, int id);
};

#endif // SWIMMER_H
