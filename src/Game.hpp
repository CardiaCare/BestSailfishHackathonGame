
#include <QtQuick>
#ifndef GAME_HPP
#define GAME_HPP
class MyClass : public QObject
{
    Q_OBJECT
public slots:
    void cppSlot(const QString &msg);
};
#endif // GAME_HPP

