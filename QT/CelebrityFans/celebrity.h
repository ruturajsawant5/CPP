
#ifndef CELEBRITY_H
#define CELEBRITY_H


#include <QObject>


class Celebrity : public QObject
{
    Q_OBJECT
public:
    explicit Celebrity(QObject *parent = nullptr);
    void broadcast_ready();
signals:
    void ready_for_signing();
};

#endif // CELEBRITY_H
