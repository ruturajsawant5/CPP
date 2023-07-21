
#ifndef LIFEGUARD_H
#define LIFEGUARD_H


#include <QObject>
#include <string>

class Lifeguard : public QObject
{
    Q_OBJECT
public:
    explicit Lifeguard(QObject *parent = nullptr);

public slots:
    void save_life(std::string name, int id);
};

#endif // LIFEGUARD_H
