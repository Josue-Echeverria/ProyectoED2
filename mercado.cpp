#include "mercado.h"
#include "ui_mercado.h"

Mercado::Mercado(QWidget *parent,double cost_abb, double cost_avl, double cost_arj, double cost_heap,
                 int t_cres_abb, int  t_cres_avl, int t_cres_arj, int t_cres_heap,
                 int cos_abb, int cos_avl, int cos_arj,int  cos_heap,
                 int tcos_abb   ,int tcos_avl,int tcos_arj, int tcos_heap,
                 double prec_fru_abb, double prec_fru_avl,double prec_fru_arj, double prec_fru_heap,
                 class granjero *granjero, double cost_espantapajaros, int rango1,int rango2) :
    QDialog(parent),
    ui(new Ui::Mercado)
{
    this->rango1 = rango1;
    this->rango2 = rango2;
    ui->setupUi(this);
    this->granjero = granjero;
  //  this->costo_espantapajaros = cost_espantapajaros;
    labelplata = findChild<QLabel*>("label_plata");
    this->label_variacion_precio = findChild<QLabel*>("label_variacion_precio");

    labelplata->setText(QString::number(this->granjero->dinero));
    this->variacion_precios = QRandomGenerator::global()->bounded(this->rango1,this->rango2);
 //   std::cout<<"WW "<<variacion_precios<<std::endl;
    this->precios_aumentan = QRandomGenerator::global()->bounded(2);
   // std::cout<<"WW "<<precios_aumentan<<std::endl;

    if(!precios_aumentan){
        this->costo_abb = cost_abb-(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_abb);
        this->costo_avl = cost_avl-(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_avl);
        this->costo_arj = cost_arj-(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_arj);
        this->costo_heap = cost_heap-(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_heap);
        this->costo_espantapajaros = cost_espantapajaros-(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_espantapajaros);
        this->label_variacion_precio->setText("El precio disminuyo en: "+QString::number(variacion_precios)+"%");
    } else {
        this->costo_abb = cost_abb+(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_abb);
        this->costo_avl = cost_avl+(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_avl);
        this->costo_arj = cost_arj+(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_arj);
        this->costo_heap = cost_heap+(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_heap);
        this->costo_espantapajaros = cost_espantapajaros+(static_cast<double>(variacion_precios)/100.0)*static_cast<double>(cost_espantapajaros);
        this->label_variacion_precio->setText("El precio aumento en: "+QString::number(variacion_precios)+"%");
    }
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
    caracteristicas_ABB->setText("Costo: "+QString::number(this->costo_abb)+"\nTiempo para crecer: "+QString::number(t_cres_abb)+"\nCosecha "+QString::number(cos_abb)+" frutos cada "+QString::number(tcos_abb)+"s\nPrecio por fruta:"+QString::number(prec_fru_abb));
    QLabel *caracteristicas_AVL = findChild<QLabel*>("label_caracteristicas_AVL");
    caracteristicas_AVL->setText("Costo: "+QString::number(this->costo_avl)+"\nTiempo para crecer: "+QString::number(t_cres_avl)+"\nCosecha "+QString::number(cos_avl)+" frutos cada "+QString::number(tcos_avl)+"s\nPrecio por fruta:"+QString::number(prec_fru_avl));
    QLabel *caracteristicas_ARJ = findChild<QLabel*>("label_caracteristicas_ARJ");
    caracteristicas_ARJ->setText("Costo: "+QString::number(this->costo_arj)+"\nTiempo para crecer: "+QString::number(t_cres_arj)+"\nCosecha "+QString::number(cos_arj)+" frutos cada "+QString::number(tcos_arj)+"s\nPrecio por fruta:"+QString::number(prec_fru_arj));
    QLabel *caracteristicas_Heap = findChild<QLabel*>("label_caracteristicas_Heap");
    caracteristicas_Heap->setText("Costo: "+QString::number(this->costo_heap)+"\nTiempo para crecer: "+QString::number(t_cres_heap)+"\nCosecha "+QString::number(cos_heap)+" frutos cada "+QString::number(tcos_heap)+"s\nPrecio por fruta:"+QString::number(prec_fru_heap));

}


Mercado::~Mercado()
{
    delete ui;
}

void Mercado::on_pushButton_comprar_ABB_clicked()
{
    if(this->costo_abb <= this->granjero->dinero){
        this->granjero->cargaArbolTipo = 1;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_abb;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }

}


void Mercado::on_pushButton_comprar_AVL_clicked()
{
    if(this->costo_avl <= this->granjero->dinero){
        this->granjero->cargaArbolTipo = 3;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_avl;
        this->labelplata->setText(QString::number( this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_ARJ_clicked()
{
    if(this->costo_arj <= this->granjero->dinero){
        this->granjero->cargaArbolTipo = 2;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_arj;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_Heap_clicked()
{
    if(this->costo_heap <= this->granjero->dinero){
        this->granjero->cargaArbolTipo = 4;// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        this->granjero->dinero -= this->costo_heap;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}


void Mercado::on_pushButton_comprar_espantapajaros_clicked()
{
    if(this->costo_espantapajaros <= this->granjero->dinero){
        this->granjero->cargaEspantajaros = true;
        this->granjero->dinero -= this->costo_espantapajaros;
        this->labelplata->setText(QString::number(this->granjero->dinero));
    }
}


void mercado_thread::run(){
    this->running = true;
    while(true){
        if(this->abierto){
            for(int i = *this->t_abierto; i>=0;i--){
                this->contador_interfaz->setText("El mercado cerrara en: "+QString::number(i));
                this->plata_interfaz->setText("Plata: "+QString::number(*this->plata));
                sleep(1);
            }
            this->abierto = false;
        }else{
            for(int i = *this->t_en_abrir; i>=0;i--){
                this->contador_interfaz->setText("El mercado abrira en: "+QString::number(i));
                this->plata_interfaz->setText("Plata: "+QString::number(*this->plata));
                sleep(1);
            }
            this->abierto = true;
        }
        sleep(1);
    }
}
