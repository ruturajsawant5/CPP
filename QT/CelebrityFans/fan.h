
#ifndef FAN_H
#define FAN_H


#include <QObject>
#include <iostream>

class Fan : public QObject
{
    Q_OBJECT
private:
    std::string celeb_name;
    std::string fan_name;
public:
    explicit Fan(std::string _celeb_name, std::string _fan_name, QObject *parent = nullptr);

public slots:
    void get_sign();
};

#endif // FAN_H
