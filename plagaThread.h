#ifndef PLAGATHREAD_H
#define PLAGATHREAD_H
#include <QThread>
#include "gamewindow.h"
class plagaThread : public QThread{
public:
    plagaThread(){

    }
    bool ocupado;
    QLabel *plagaLabel;
    void run();
};
#endif // PLAGATHREAD_H
