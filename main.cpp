#include "mainwindow.h"
#include "gamewindow.h"
#include <QApplication>
#include "ABB_thread.h"
#include "ARJ_thread.h"
#include "AVL_thread.h"
#include "Heap_Thread.h"
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//main_window.show();

    int t_abierto_mercado = 0;
    int t_para_abrir_mercado = 0;

    int mercado_rango1 = 0;
    int mercado_rango2 = 0;

    double costo_espantapajaros = 10;

    double costo_abb = 5;
    double costo_heap= 5;
    double costo_arj= 5;
    double costo_avl= 5;

    int t_crecimien_abb = 2;
    int t_crecimien_heap = 2;
    int t_crecimien_avl = 2;
    int t_crecimien_arj = 2;

    int cosecha_abb = 5;
    int cosecha_heap = 5;
    int cosecha_arj = 5;
    int cosecha_avl = 5;

    int cosecha_cada_t_abb = 2;
    int cosecha_cada_t_avl = 2;
    int cosecha_cada_t_arj = 2;
    int cosecha_cada_t_heap = 2;

    double precio_frut_abb = 4;
    double precio_frut_arj= 4;
    double precio_frut_heap= 4;
    double precio_frut_avl= 4;


    MainWindow *main_window = new MainWindow(NULL,
                                             &costo_abb,&costo_avl ,&costo_arj  ,&costo_heap,
                                             &t_crecimien_abb, &t_crecimien_avl, &t_crecimien_arj, &t_crecimien_heap,
                                             &cosecha_abb, &cosecha_avl, &cosecha_arj,&cosecha_heap,
                                             &cosecha_cada_t_abb, &cosecha_cada_t_avl, &cosecha_cada_t_arj, &cosecha_cada_t_heap,
                                             &precio_frut_abb, &precio_frut_avl, &precio_frut_arj, &precio_frut_heap,
                                             &costo_espantapajaros,&t_abierto_mercado,&t_para_abrir_mercado,
                                             &mercado_rango1,&mercado_rango2);
 //   main_window->show();
 //   main_window->show();
    Gamewindow *game_window = new Gamewindow(NULL, main_window);
    game_window->show();
    QTableWidget *tabla = game_window->findChild<QTableWidget*>("tabla");

    //AVL_Thread *avl_thread = new AVL_Thread(&t_crecimien_avl,&cosecha_cada_t_avl,&cosecha_avl,&costo_avl,&precio_frut_avl,tabla);
    //avl_thread->start();

/*     Heap_Thread *heap_thread = new Heap_Thread(10,&t_crecimien_heap,&cosecha_cada_t_heap,&cosecha_heap,&costo_heap,&precio_frut_heap,tabla);
    heap_thread->start();
  // Gamewindow *game_window = new Gamewindow(nullptr,main_window);



    ARJ_thread *arj_thread = new ARJ_thread(&t_crecimien_arj,&cosecha_cada_t_arj,&cosecha_arj,&costo_arj,&precio_frut_arj,tabla);
    arj_thread->start();
*/




    return a.exec();
}
