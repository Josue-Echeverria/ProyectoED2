#include "mercado.h"
#include "ui_mercado.h"

Mercado::Mercado(QWidget *parent,int cost_abb, int cost_avl, int cost_arj, int cost_heap,
                 int t_cres_abb, int  t_cres_avl, int t_cres_arj, int t_cres_heap,
                 int cos_abb, int cos_avl, int cos_arj,int  cos_heap,
                 int tcos_abb   ,int tcos_avl,int tcos_arj, int tcos_heap,
                 double prec_fru_abb, double prec_fru_avl,double prec_fru_arj, double prec_fru_heap,
                 class granjero *granjero, int cost_espantapajaros) :
    QDialog(parent),
    ui(new Ui::Mercado)
{

    ui->setupUi(this);
    this->granjero = granjero;
//    this->cargaArbolTipo = cargaarboltipo;
//    this->plata = plata;
    this->costo_espantapajaros = cost_espantapajaros;

    QPixmap abb("C:/Users/Asus/Repositories/ProyectoED2/ABB.jpg");
    QLabel *imagen_ABB = findChild<QLabel*>("label_imagen_ABB");
    imagen_ABB->setPixmap(abb);
    QPixmap avl("C:/Users/Asus/Repositories/ProyectoED2/AVL.png");
    QLabel *imagen_AVL = findChild<QLabel*>("label_imagen_AVL");
    imagen_AVL->setPixmap(avl);
    QPixmap arj("C:/Users/Asus/Repositories/ProyectoED2/ARJ.jpg");
    QLabel *imagen_ARJ = findChild<QLabel*>("label_imagen_ARJ");
    imagen_ARJ->setPixmap(arj);
    QPixmap heap("C:/Users/Asus/Repositories/ProyectoED2/Heap.png");
    QLabel *imagen_Heap = findChild<QLabel*>("label_imagen_Heap");
    imagen_Heap->setPixmap(heap);

    QPixmap espantapajaros("C:/Users/Asus/Repositories/ProyectoED2/espantapajaros_mercado.png");
    QLabel *imagen_espantapajaros = findChild<QLabel*>("label_imagen_espantapajaros");
    imagen_espantapajaros->setPixmap(espantapajaros);
    QLabel *cos_espantapajaros = findChild<QLabel*>("label_costo_espantapajaros");
    cos_espantapajaros->setText(QString::number(this->costo_espantapajaros));
    QLabel *caracteristicas_ABB = findChild<QLabel*>("label_caracteristicas_ABB");
    caracteristicas_ABB->setText("Costo: "+QString::number(cost_abb)+"\nTiempo para crecer: "+QString::number(t_cres_abb)+"\nCosecha "+QString::number(cos_abb)+" frutos cada "+QString::number(tcos_abb)+"s\nPrecio por fruta:"+QString::number(prec_fru_abb));
    QLabel *caracteristicas_AVL = findChild<QLabel*>("label_caracteristicas_AVL");
    caracteristicas_AVL->setText("Costo: "+QString::number(cost_avl)+"\nTiempo para crecer: "+QString::number(t_cres_avl)+"\nCosecha "+QString::number(cos_avl)+" frutos cada "+QString::number(tcos_avl)+"s\nPrecio por fruta:"+QString::number(prec_fru_avl));
    QLabel *caracteristicas_ARJ = findChild<QLabel*>("label_caracteristicas_ARJ");
    caracteristicas_ARJ->setText("Costo: "+QString::number(cost_arj)+"\nTiempo para crecer: "+QString::number(t_cres_arj)+"\nCosecha "+QString::number(cos_arj)+" frutos cada "+QString::number(tcos_arj)+"s\nPrecio por fruta:"+QString::number(prec_fru_arj));
    QLabel *caracteristicas_Heap = findChild<QLabel*>("label_caracteristicas_Heap");
    caracteristicas_Heap->setText("Costo: "+QString::number(cost_heap)+"\nTiempo para crecer: "+QString::number(t_cres_heap)+"\nCosecha "+QString::number(cos_heap)+" frutos cada "+QString::number(tcos_heap)+"s\nPrecio por fruta:"+QString::number(prec_fru_heap));

    labelplata = findChild<QLabel*>("label_plata");
    labelplata->setText(QString::number(this->granjero->dinero));
    this->costo_abb = cost_abb;
    this->costo_avl = cost_avl;
    this->costo_arj = cost_arj;
    this->costo_heap = cost_heap;
}

Mercado::~Mercado()
{
    delete ui;
}

void Mercado::on_pushButton_comprar_ABB_clicked()
{
    if(this->costo_abb < this->granjero->dinero){
        this->granjero->cargaArbolTipo = 1;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_abb;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }

}


void Mercado::on_pushButton_comprar_AVL_clicked()
{
    if(this->costo_avl < this->granjero->dinero){
        this->granjero->cargaArbolTipo = 3;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_avl;
        this->labelplata->setText(QString::number( this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_ARJ_clicked()
{
    if(this->costo_arj < this->granjero->dinero){
        this->granjero->cargaArbolTipo = 2;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_arj;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_Heap_clicked()
{
    if(this->costo_heap < this->granjero->dinero){
        this->granjero->cargaArbolTipo = 4;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_heap;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_espantapajaros_clicked()
{
    if(this->costo_espantapajaros < this->granjero->dinero){
        this->granjero->cargaEspantajaros = true;
        this->granjero->dinero -= this->costo_espantapajaros;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}

