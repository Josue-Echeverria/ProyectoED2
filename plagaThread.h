#ifndef PLAGATHREAD_H
#define PLAGATHREAD_H
#include <QThread>
#include <QLabel>
#include <QRandomGenerator>
#include "tablero.h"
#include "granjero.h"
#include <QMutex>
class plagaThread : public QThread{
public:
    bool activas;
    bool running;
    QLabel *plagaLabel;
    int probabilidad;
    int cant;
    int tiempoSeg;
    int frutosComen;
    int tiempoSegComen;
    int tipo;
    tablero *tab;
    granjero *granj;
    QMutex *mutexTab;
    plagaThread(QLabel *plagaLabel, int probabilidad, int cant, int tiempoSeg, int frutosComen, int tiempoSegComen, int tipo, tablero *tab, granjero *granj, QMutex *mutexTab){
        activas = false;
        this->plagaLabel = plagaLabel;
        this->probabilidad = probabilidad;
        this->cant = cant;
        this->tiempoSeg = tiempoSeg;
        this->frutosComen = frutosComen;
        this->tiempoSegComen = tiempoSegComen;
        this->tab = tab;
        this->tipo = tipo; // 0 = vacio, 1 = oveja, 2 = cuervo, 3 = plaga.
        this->granj = granj;
        this->mutexTab = mutexTab;
    }
    bool pregunteProbabilidad();
    void aparecerPlaga();
    void esconderPlaga();
    void eliminarPlaga();
    void verificarGranjero();

    void run();
};
#endif // PLAGATHREAD_H

