#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <iostream>

Gamewindow::Gamewindow(QWidget *parent,MainWindow *m):
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
        ui->setupUi(this);
   // this->mercado = new Mercado();
    this->granjero = new class granjero();
    this->main_window = m;
    this->setStyleSheet("background-color: lightgreen;");
    QPixmap granjero_imagen("C:/Users/Asus/Repositories/ProyectoED2/agricultorFin.png");
    QPixmap plaga("C:/Users/Asus/Repositories/ProyectoED2/Plaga.png");
    granjeroLab = findChild<QLabel*>("granjeroLabel");
    QPixmap oveja("C:/Users/Asus/Repositories/ProyectoED2/oveja.png");
    QPixmap cuervo("C:/Users/Asus/Repositories/ProyectoED2/cuervo.png");

    QPixmap abb_imagen("C:/Users/Asus/Repositories/ProyectoED2/ABB_matriz.png");
    this->abb_ = abb_imagen;
    QPixmap avl_imagen("C:/Users/Asus/Repositories/ProyectoED2/AVL_matriz.png");
    this->avl_ = avl_imagen;
    QPixmap arj_imagen("C:/Users/Asus/Repositories/ProyectoED2/ARJ_matriz.png");
    this->arj_ = arj_imagen;
    QPixmap heap_imagen("C:/Users/Asus/Repositories/ProyectoED2/Heap_matriz.png");
    this->heap_ = heap_imagen;

    tabla = findChild<QTableWidget*>("tabla");
//    tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabla->setFocusPolicy(Qt::NoFocus);
    tabla->setSelectionMode(QAbstractItemView::NoSelection);

    granjeroLab->setPixmap(granjero_imagen);
    plagaLab = findChild<QLabel*>("plagaLabel");
    plagaLab->setPixmap(plaga);
    plagaLab->setVisible(false);
    ovejaLab = findChild<QLabel*>("ovejaLabel");
    ovejaLab->setPixmap(oveja);
    ovejaLab->setVisible(false);
    cuervoLab = findChild<QLabel*>("cuervoLabel");
    cuervoLab->setPixmap(cuervo);
    cuervoLab->setVisible(false);
    tab = new class tablero();
    granjero = new class granjero();
  //  granjero->cargaEspantajaros = true;
    plagahilo = new plagaThread(plagaLab, 100, 1, 5, 0, 0, 3, tab, granjero, mutexTablero);
    ovejahilo = new plagaThread(ovejaLab, 100, 1, 5, 0, 0, 1, tab, granjero, mutexTablero);
    cuervohilo = new plagaThread(cuervoLab, 100, 1, 5, 0, 0, 1, tab, granjero, mutexTablero);
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);
    generarLabels();
    cuervohilo->start();
    plagahilo->start();
    ovejahilo->start();
}

Gamewindow::~Gamewindow()
{
    delete ui;
}

void Gamewindow::generarLabels(){
    QGridLayout *layout = ui->gridLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    for (int x = 0; x < 8; x++) {
        for(int y = 0; y<8; y++){
            parcelas[x][y] = new QLabel(this);
            //tablero[x][y]->setText("lola");
            parcelas[x][y]->setStyleSheet("border: 1px solid black");
            //tablero[x][y]->QLineEdit(border: 1px solid white);
            layout->addWidget(parcelas[x][y], x, y);
        }
    }
}




void Gamewindow::keyPressEvent(QKeyEvent * event)
{
    //tabla->setDisabled(true);
    int py = granjeroLab->y();
    int px = granjeroLab->x();
    if( event->key() == Qt::Key_Down)
    {
        py += 77;
        if(py > 619)
            py = 80;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Up)
    {
        py -= 77;
        if(py < 80)
            py = 619;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Right)
    {
        px += 125;
        if(px > 935)
            px = 60;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_Left)
    {
        px -= 125;
        if(px < 60)
            px = 935;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_F1){
        this->main_window->show();
    }
    else if( event->key() == Qt::Key_F2){
        this->mercado = new Mercado(NULL,*this->main_window->costo_abb,*this->main_window->costo_avl,*this->main_window->costo_arj,*this->main_window->costo_heap,
                                    *this->main_window->t_crecimien_abb,*this->main_window->t_crecimien_avl,*this->main_window->t_crecimien_arj,*this->main_window->t_crecimien_heap,
                                    *this->main_window->cosecha_abb,*this->main_window->cosecha_avl,*this->main_window->cosecha_arj,*this->main_window->cosecha_heap,
                                    *this->main_window->cosecha_cada_t_abb,*this->main_window->cosecha_cada_t_avl,*this->main_window->cosecha_cada_t_arj,*this->main_window->cosecha_cada_t_heap,
                                    *this->main_window->precio_frut_abb,*this->main_window->precio_frut_avl,*this->main_window->precio_frut_arj,*this->main_window->precio_frut_heap,
                                    this->granjero,*this->main_window->costo_espantapajaros);
        this->mercado->show();
    }
    else if( event->key() == Qt::Key_F3){

        int posy_matriz = (py-80)/77;
        int posx_matriz = (px-60)/125;

        if(this->granjero->cargaArbolTipo == 1){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,1,this->main_window->t_crecimien_abb,
                                      this->main_window->cosecha_cada_t_abb,this->main_window->cosecha_abb,
                                      this->main_window->costo_abb,this->main_window->precio_frut_abb,tabla);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->abb_);
            this->granjero->cargaArbolTipo = 0;
        }
        if(this->granjero->cargaArbolTipo == 2){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,2,this->main_window->t_crecimien_arj,
                                      this->main_window->cosecha_cada_t_arj,this->main_window->cosecha_arj,
                                      this->main_window->costo_arj,this->main_window->precio_frut_arj,tabla);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->arj_);
            this->granjero->cargaArbolTipo = 0;
        }
        if(this->granjero->cargaArbolTipo == 3){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,3,this->main_window->t_crecimien_avl,
                                      this->main_window->cosecha_cada_t_avl,this->main_window->cosecha_avl,
                                      this->main_window->costo_avl,this->main_window->precio_frut_avl,tabla);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->avl_);
            this->granjero->cargaArbolTipo = 0;
        }
        if(this->granjero->cargaArbolTipo == 4){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,4,this->main_window->t_crecimien_heap,
                                      this->main_window->cosecha_cada_t_heap,this->main_window->cosecha_heap,
                                      this->main_window->costo_heap,this->main_window->precio_frut_heap,tabla);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->heap_);
            this->granjero->cargaArbolTipo = 0;
        }
    }
    else if(event->key() == Qt::Key_F4){
        if(granjero->cargaEspantajaros){
            QPixmap espantapajaro("C:/Users/Asus/Repositories/ProyectoED2/espantapajaros.png");
            int posy_matriz = (py-80)/77;
            int posx_matriz = (px-60)/125;
            tab->Tablero[posx_matriz][posy_matriz]->espantaPaj = true;
            parcelas[posy_matriz][posx_matriz]->setPixmap(espantapajaro);
            granjero->cargaEspantajaros = false;
        }
    }
}
   // tabla->setDisabled(false);

void Gamewindow::verificarGranjero(int x, int y){
    if(plagaLab->x() == x && plagaLab->y() == y){
        plagaLab->setVisible(false);
    }
    else if(ovejaLab->x() == x && ovejaLab->y() == y){
        ovejaLab->setVisible(false);
    }
    else if(cuervoLab->x() == x && cuervoLab->y() == y){
        cuervoLab->setVisible(false);
    }
}


void Gamewindow::on_pushButton_clicked()
{

}


void Gamewindow::on_pushButton_2_clicked()
{

}

