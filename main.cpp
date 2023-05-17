#include "mainwindow.h"
#include "gamewindow.h"
#include <QApplication>
#include "ABB_thread.h"
#include "ARJ_thread.h"
#include "AVL_thread.h"
#include "Heap_Thread.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//main_window.show();

    int costo_abb = -1;
    int costo_heap= -1;
    int costo_arj= -1;
    int costo_avl= -1;

    int t_crecimien_abb= 5;
    int t_crecimien_heap= 4;
    int t_crecimien_avl= 3;
    int t_crecimien_arj= 4;

    int cosecha_abb= 1;
    int cosecha_heap= 1;
    int cosecha_arj= 1;
    int cosecha_avl= 1;

    int cosecha_cada_t_abb= 2;
    int cosecha_cada_t_avl= 2;
    int cosecha_cada_t_arj= 3;
    int cosecha_cada_t_heap= 4;

    double precio_frut_abb= -1;
    double precio_frut_arj= -1;
    double precio_frut_heap= -1;
    double precio_frut_avl= -1;

    MainWindow *main_window = new MainWindow(nullptr,
                                    costo_abb,costo_avl ,costo_arj  ,costo_heap,
                                    t_crecimien_abb, t_crecimien_avl, t_crecimien_arj, t_crecimien_heap,
                                    cosecha_abb, cosecha_avl, cosecha_arj,cosecha_heap,
                                    cosecha_cada_t_abb, cosecha_cada_t_avl, cosecha_cada_t_arj, cosecha_cada_t_heap,
                                    precio_frut_abb, precio_frut_avl, precio_frut_arj, precio_frut_heap);

    main_window->show();
    //Gamewindow *game_window = new Gamewindow(nullptr,main_window);

    Heap_Thread *heap_thread = new Heap_Thread(10,&t_crecimien_heap,&cosecha_cada_t_heap,&cosecha_heap,&costo_heap,&precio_frut_heap);
    heap_thread->start();
 /*
    AVL_Thread *avl_thread = new AVL_Thread(&t_crecimien_avl,&cosecha_cada_t_avl,&cosecha_avl,&costo_avl,&precio_frut_avl);
    avl_thread->start();

    ABB_Thread *abb_thread = new ABB_Thread(&t_crecimien_abb,&cosecha_cada_t_abb,&cosecha_abb,&costo_abb,&precio_frut_abb);
    abb_thread->start();
    ARJ_thread *arj_thread = new ARJ_thread(&t_crecimien_arj,&cosecha_cada_t_arj,&cosecha_arj,&costo_arj,&precio_frut_arj);
    arj_thread->start();


*/
    return a.exec();
}
