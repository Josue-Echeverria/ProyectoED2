#include "gamewindow.h"
#include "ui_gamewindow.h"

Gamewindow::Gamewindow(QWidget *parent,MainWindow *m):
    QDialog(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);
   // this->mercado = new Mercado();
    this->granjero = new class granjero();
    this->main_window = m;
    this->setStyleSheet("background-color: lightgreen;");
    QPixmap granjero_imagen("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/agricultorFin.png");
    QPixmap plaga("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/Plaga.png");
    granjeroLab = findChild<QLabel*>("granjeroLabel");
    QPixmap oveja("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/oveja.png");
    QPixmap cuervo("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/cuervo.png");

    QPixmap abb_imagen("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/ABB_matriz.png");
    this->abb_ = abb_imagen;
    QPixmap avl_imagen("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/AVL_matriz.png");
    this->avl_ = avl_imagen;
    QPixmap arj_imagen("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/ARJ_matriz.png");
    this->arj_ = arj_imagen;
    QPixmap heap_imagen("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/Heap_matriz.png");
    this->heap_ = heap_imagen;
    this->table_pos = findChild<QComboBox*>("comboBox");
    tabla = findChild<QTableWidget*>("tabla");
//  tabla->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tabla->setFocusPolicy(Qt::NoFocus);
    tabla->setSelectionMode(QAbstractItemView::NoSelection);
    granjeroLab->setPixmap(granjero_imagen);
    granjeroLab->setVisible(false);
    plagaLab = findChild<QLabel*>("plagaLabel");
    plagaLab->setPixmap(plaga);
    plagaLab->setVisible(false);
    ovejaLab = findChild<QLabel*>("ovejaLabel");
    ovejaLab->setPixmap(oveja);
    ovejaLab->setVisible(false);
    cuervoLab = findChild<QLabel*>("cuervoLabel");
    cuervoLab->setPixmap(cuervo);
    cuervoLab->setVisible(false);
    recordLab = findChild<QLabel*>("recordLabel");
    this->counter_trees = 0;
    tab = new class tablero();
    granjero = new class granjero();
  //  granjero->cargaEspantajaros = true;
    plagahilo = new plagaThread(plagaLab, &this->main_window->probPlaga, 2, &this->main_window->tiempoSegPlaga, &this->main_window->frutosComenPlaga, &this->main_window->tiempoSegComenPlaga, 3, tab, granjero, mutexTablero);
    ovejahilo = new plagaThread(ovejaLab, &this->main_window->probOveja, 2, &this->main_window->tiempoSegOveja,  &this->main_window->frutosComenOveja, &this->main_window->tiempoSegComenOveja, 1, tab, granjero, mutexTablero);
    cuervohilo = new plagaThread(cuervoLab, &this->main_window->probCuervo, 2, &this->main_window->tiempoSegCuervo,  &this->main_window->frutosComenCuervo, &this->main_window->tiempoSegComenCuervo, 2, tab, granjero, mutexTablero);
//    plagaThread(QLabel *plagaLabel, int probabilidad, int cant, int tiempoSeg, int frutosComen, int tiempoSegComen, int tipo, tablero *tab, granjero *granj, QMutex *mutexTab)

    this->pos_trees = new QHash<int,QVector<int>>;
    mercado_thread = new class mercado_thread(this->main_window->t_mercado_abierto,this->main_window->t_mercado_abrir,findChild<QLabel*>("label_mercado"),&this->granjero->dinero,findChild<QLabel*>("label_plata"));
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);

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
            parcelas[x][y]->setStyleSheet("border: 1px solid black");
            layout->addWidget(parcelas[x][y], x, y);
        }
    }
}

QString Gamewindow::toStringRecords(){
    QString recordString = "";
    std::string nombreArchivo = "C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/records.txt";
    std::ifstream archivo(nombreArchivo.c_str());
    std::string linea;
    recordString +="Mejores records: \n";
    while (getline(archivo, linea)) {
        recordString += QString::fromStdString(linea);
        recordString += "\n";
    }
    return recordString;
};

void  Gamewindow::agregarRecord(string nombre, double dinero){
    std::string arregloRecords[22];
    int length = 0;
    char* char_array;
    std::string nombreArchivo = "C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/records.txt";
    std::ifstream archivo(nombreArchivo.c_str());
    std::string linea;
    std::string name;
    std::string score;
    bool flag = true;
    bool entro = false;
    int contador = 0;
    while (getline(archivo, linea)) {
        name = "";
        score = "";
        flag = true;
        length = linea.length();
        char_array = new char[length + 1];
        strcpy(char_array, linea.c_str());
        for (int i = 0; i < length; i++){
            if(char_array[i] == ' '){
                flag = false;
            }else{
                if(flag){
                    name += char_array[i];
                }else{
                    score+= char_array[i];
                }
            }
        }
        if( stod(score) <= dinero && entro == false){
            arregloRecords[contador] = nombre;
            contador += 1;
            arregloRecords[contador] = to_string(dinero);
            contador += 1;
            arregloRecords[contador] = name;
            contador += 1;
            arregloRecords[contador] = score;
            contador += 1;
            entro = true;
        }else{
            arregloRecords[contador] = name;
            contador += 1;
            arregloRecords[contador] = score;
            contador += 1;
        }
    }
    if(!entro){
        arregloRecords[contador] = nombre;
        contador += 1;
        arregloRecords[contador] = to_string(dinero);
    }
    archivo.close();
    ofstream myfile ("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/records.txt");
    string recordNuevo = "";
    for(int x = 0; x < 20; x+=2){
        if(x!=18)
            recordNuevo = arregloRecords[x] + " " + arregloRecords[x+1] +"\n";
        else
            recordNuevo = arregloRecords[x] + " " + arregloRecords[x+1];
        myfile<< recordNuevo;
    }
    myfile.close();
}

void Gamewindow::keyPressEvent(QKeyEvent * event)
{
    //tabla->setDisabled(true);
    int py = granjeroLab->y();
    int px = granjeroLab->x();
    if( event->key() == Qt::Key_S)
    {
        py += 77;
        if(py > 619)
            py = 80;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_W)
    {
        py -= 77;
        if(py < 80)
            py = 619;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_D)
    {
        px += 125;
        if(px > 935)
            px = 60;
        granjeroLab->setGeometry(px,py,50,50);
        verificarGranjero(px, py);
    }
    else if( event->key() == Qt::Key_A)
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
        if(this->mercado_thread->abierto){
            this->mercado = new Mercado(NULL,*this->main_window->costo_abb,*this->main_window->costo_avl,*this->main_window->costo_arj,*this->main_window->costo_heap,
                                        *this->main_window->t_crecimien_abb,*this->main_window->t_crecimien_avl,*this->main_window->t_crecimien_arj,*this->main_window->t_crecimien_heap,
                                        *this->main_window->cosecha_abb,*this->main_window->cosecha_avl,*this->main_window->cosecha_arj,*this->main_window->cosecha_heap,
                                        *this->main_window->cosecha_cada_t_abb,*this->main_window->cosecha_cada_t_avl,*this->main_window->cosecha_cada_t_arj,*this->main_window->cosecha_cada_t_heap,
                                        *this->main_window->precio_frut_abb,*this->main_window->precio_frut_avl,*this->main_window->precio_frut_arj,*this->main_window->precio_frut_heap,
                                        this->granjero,*this->main_window->costo_espantapajaros,1,10);//*this->main_window->mercado_rango1,*this->main_window->mercado_rango2);
            this->mercado->show();
        }
    }
    else if( event->key() == Qt::Key_F3){
        int posy_matriz = (py-80)/77;
        int posx_matriz = (px-60)/125;

        if(this->granjero->cargaArbolTipo == 1){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,1,this->main_window->t_crecimien_abb,
                                      this->main_window->cosecha_cada_t_abb,this->main_window->cosecha_abb,
                                      this->main_window->costo_abb,this->main_window->precio_frut_abb,tabla,
                                      &this->granjero->dinero);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->abb_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 2){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,2,this->main_window->t_crecimien_arj,
                                      this->main_window->cosecha_cada_t_arj,this->main_window->cosecha_arj,
                                      this->main_window->costo_arj,this->main_window->precio_frut_arj,tabla,
                                      &this->granjero->dinero);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->arj_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 3){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,3,this->main_window->t_crecimien_avl,
                                      this->main_window->cosecha_cada_t_avl,this->main_window->cosecha_avl,
                                      this->main_window->costo_avl,this->main_window->precio_frut_avl,tabla,
                                      &this->granjero->dinero);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->avl_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 4){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,4,this->main_window->t_crecimien_heap,
                                      this->main_window->cosecha_cada_t_heap,this->main_window->cosecha_heap,
                                      this->main_window->costo_heap,this->main_window->precio_frut_heap,tabla,
                                      &this->granjero->dinero);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->heap_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
    }
    else if(event->key() == Qt::Key_F4){
        if(granjero->cargaEspantajaros){
            QPixmap espantapajaro("C:/Users/hdani/OneDrive/Escritorio/Tec semestre 1/datos/proyecto2/QtGit/ProyectoED2/espantapajaros.png");
            int posy_matriz = (py-80)/77;
            int posx_matriz = (px-60)/125;
            tab->Tablero[posx_matriz][posy_matriz]->espantaPaj = true;
            tab->Tablero[posx_matriz+1][posy_matriz]->espantaPaj = true;
            tab->Tablero[posx_matriz-1][posy_matriz]->espantaPaj = true;
            tab->Tablero[posx_matriz][posy_matriz+1]->espantaPaj = true;
            tab->Tablero[posx_matriz][posy_matriz-1]->espantaPaj = true;
            tab->Tablero[posx_matriz+1][posy_matriz+1]->espantaPaj = true;
            tab->Tablero[posx_matriz-1][posy_matriz+1]->espantaPaj = true;
            tab->Tablero[posx_matriz-1][posy_matriz-1]->espantaPaj = true;
            tab->Tablero[posx_matriz+1][posy_matriz-1]->espantaPaj = true;
            parcelas[posy_matriz][posx_matriz]->setPixmap(espantapajaro);
            granjero->cargaEspantajaros = false;
        }
    }/*
    else if(event->key() == Qt::Key_W){
        std::cout<<"WWWW"<<std::endl;

    }
    else if(event->key() == Qt::Key_A){
        std::cout<<"AAAA"<<std::endl;

    }
    else if(event->key() == Qt::Key_S){
        std::cout<<"SSSS"<<std::endl;

    }
    else if(event->key() == Qt::Key_D){
        std::cout<<"DDDD"<<std::endl;

    }*/
}
   // tabla->setDisabled(false);

void Gamewindow::verificarGranjero(int x, int y){
    if((plagaLab->x() == x) && (plagaLab->y() == y)){
        //plagaLab->setVisible(false);
    }
    else if((ovejaLab->x() == x) & (ovejaLab->y() == y)){
    //    ovejaLab->setVisible(false);
    }
    else if((cuervoLab->x() == x) && (cuervoLab->y() == y)){
        cuervoLab->setVisible(false);
    }
}


void Gamewindow::on_pushButton_clicked()
{
    int t = this->table_pos->currentIndex();
    if(pos_trees->contains(t)){
        QVector<int> A = this->pos_trees->value(t);
        switch(this->tab->casillaEnPos(A[0],A[1])->arbol){// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        case 1:
            this->tab->casillaEnPos(A[0],A[1])->Abb->has_2_sell = true;
            break;
        case 2:
            this->tab->casillaEnPos(A[0],A[1])->Arj->has_2_sell = true;
            break;
        case 3:
            this->tab->casillaEnPos(A[0],A[1])->Avl->has_2_sell = true;
            break;
        case 4:
            this->tab->casillaEnPos(A[0],A[1])->Heap->has_2_sell = true;
            break;

        }
    }
}


void Gamewindow::on_pushButton_2_clicked()
{
    int t = this->table_pos->currentIndex();
    if(pos_trees->contains(t)){
        QVector<int> A = this->pos_trees->value(t);
        switch(this->tab->casillaEnPos(A[0],A[1])->arbol){// 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
        case 1:
            this->tab->casillaEnPos(A[0],A[1])->Abb->has_2_sell_all = true;
            break;
        case 2:
            this->tab->casillaEnPos(A[0],A[1])->Arj->has_2_sell_all = true;
            break;
        case 3:
            this->tab->casillaEnPos(A[0],A[1])->Avl->has_2_sell_all = true;
            break;
        case 4:
            this->tab->casillaEnPos(A[0],A[1])->Heap->has_2_sell_all = true;
            break;

        }
    }
}


void Gamewindow::on_pushButton_3_clicked()
{
    granjero->nombre = this->main_window->nombre;
    agregarRecord(granjero->nombre, granjero->dinero);
    recordLab->setText(toStringRecords());
}


void Gamewindow::on_iniciarButton_clicked()
{
    cuervohilo->start();
    plagahilo->start();
    ovejahilo->start();
    recordLab->setText(toStringRecords());
    mercado_thread->start();
    generarLabels();
    granjeroLab->setVisible(true);
}

