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
    this->pos_trees = new QHash<int,QVector<int>>;
    granjeroLab->setGeometry(60,80,50,50);
    plagaLab->setGeometry(60,80,50,50);
    generarLabels();
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
                                      &this->granjero->dinero,-1,parcelas[posy_matriz][posx_matriz]);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->abb_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 2){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,2,this->main_window->t_crecimien_arj,
                                      this->main_window->cosecha_cada_t_arj,this->main_window->cosecha_arj,
                                      this->main_window->costo_arj,this->main_window->precio_frut_arj,tabla,
                                      &this->granjero->dinero,-1,parcelas[posy_matriz][posx_matriz]);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->arj_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 3){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,3,this->main_window->t_crecimien_avl,
                                      this->main_window->cosecha_cada_t_avl,this->main_window->cosecha_avl,
                                      this->main_window->costo_avl,this->main_window->precio_frut_avl,tabla,
                                      &this->granjero->dinero,-1,parcelas[posy_matriz][posx_matriz]);
            parcelas[posy_matriz][posx_matriz]->setPixmap(this->avl_);
            this->granjero->cargaArbolTipo = 0;
            this->pos_trees->insert(counter_trees,{posx_matriz,posy_matriz});
            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
        }
        if(this->granjero->cargaArbolTipo == 4){ // 0 = vacio, 1 = ABB, 2 = ARJ, 3 = AVL, 4 = Heap.
            this->tab->modificarArbol(posx_matriz,posy_matriz,4,this->main_window->t_crecimien_heap,
                                      this->main_window->cosecha_cada_t_heap,this->main_window->cosecha_heap,
                                      this->main_window->costo_heap,this->main_window->precio_frut_heap,tabla,
                                      &this->granjero->dinero,-1,parcelas[posy_matriz][posx_matriz]);
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
    }
}

void Gamewindow::verificarGranjero(int x, int y){
    if((plagaLab->x() == x) && (plagaLab->y() == y)){
     //   plagaLab->setVisible(false);
    }
    else if((ovejaLab->x() == x) & (ovejaLab->y() == y)){
        ovejaLab->setVisible(false);
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
    plagahilo = new plagaThread(plagaLab, &this->main_window->probPlaga, 2, &this->main_window->tiempoSegPlaga, &this->main_window->frutosComenPlaga, &this->main_window->tiempoSegComenPlaga, 3, tab, granjero, mutexTablero);
    ovejahilo = new plagaThread(ovejaLab, &this->main_window->probOveja, 2, &this->main_window->tiempoSegOveja,  &this->main_window->frutosComenOveja, &this->main_window->tiempoSegComenOveja, 1, tab, granjero, mutexTablero);
    cuervohilo = new plagaThread(cuervoLab, &this->main_window->probCuervo, 2, &this->main_window->tiempoSegCuervo,  &this->main_window->frutosComenCuervo, &this->main_window->tiempoSegComenCuervo, 2, tab, granjero, mutexTablero);
    mercado_thread = new class mercado_thread(this->main_window->t_mercado_abierto,this->main_window->t_mercado_abrir,findChild<QLabel*>("label_mercado"),&this->granjero->dinero,findChild<QLabel*>("label_plata"));

    cuervohilo->start();
    plagahilo->start();
    ovejahilo->start();
    recordLab->setText(toStringRecords());
    mercado_thread->start();

    granjeroLab->setVisible(true);
}


void Gamewindow::on_pushButton_5_clicked()
{
    QString filePath = "C:/Users/Asus/Repositories/ProyectoED2/"+QString::fromStdString(this->main_window->nombre)+".json";
    qDebug() << "C:/Users/Asus/Repositories/ProyectoED2/"+QString::fromStdString(this->main_window->nombre)+".json";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        // Read the JSON data from the file
        QByteArray jsonData = file.readAll();

        // Parse the JSON document
        QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
        if (!jsonDocument.isNull()) {
            if (jsonDocument.isObject()) {
                QJsonObject jsonObject = jsonDocument.object();
                this->granjero->dinero = jsonObject["Plata"].toDouble();
                QJsonArray jsonArray = jsonObject["config"].toArray();

                *this->main_window->costo_abb = jsonArray[0].toDouble();
                *this->main_window->cosecha_abb = jsonArray[1].toInt();
                *this->main_window->cosecha_cada_t_abb = jsonArray[2].toInt();
                *this->main_window->precio_frut_abb = jsonArray[3].toDouble();
                *this->main_window->t_crecimien_abb = jsonArray[4].toInt();

                *this->main_window->costo_arj = jsonArray[5].toDouble();
                *this->main_window->cosecha_arj = jsonArray[6].toInt();
                *this->main_window->cosecha_cada_t_arj = jsonArray[7].toInt();
                *this->main_window->precio_frut_arj = jsonArray[8].toDouble();
                *this->main_window->t_crecimien_arj = jsonArray[9].toInt();

                *this->main_window->costo_avl = jsonArray[10].toDouble();
                *this->main_window->cosecha_avl = jsonArray[11].toInt();
                *this->main_window->cosecha_cada_t_avl = jsonArray[12].toInt();
                *this->main_window->precio_frut_avl = jsonArray[13].toDouble();
                *this->main_window->t_crecimien_avl = jsonArray[14].toInt();


                *this->main_window->costo_heap = jsonArray[15].toDouble();
                *this->main_window->cosecha_heap = jsonArray[16].toInt();
                *this->main_window->cosecha_cada_t_heap = jsonArray[17].toInt();
                *this->main_window->precio_frut_heap = jsonArray[18].toDouble();
                *this->main_window->t_crecimien_heap = jsonArray[19].toInt();

                this->main_window->probOveja = jsonArray[20].toInt();
                this->main_window->tiempoSegOveja = jsonArray[21].toInt();
                this->main_window->frutosComenOveja = jsonArray[22].toInt();
                this->main_window->tiempoSegComenOveja = jsonArray[23].toInt();

                this->main_window->probCuervo = jsonArray[24].toInt();
                this->main_window->tiempoSegCuervo = jsonArray[25].toInt();
                this->main_window->frutosComenCuervo = jsonArray[26].toInt();
                this->main_window->tiempoSegComenCuervo = jsonArray[27].toInt();

                this->main_window->probPlaga = jsonArray[28].toInt();
                this->main_window->tiempoSegPlaga = jsonArray[29].toInt();
                this->main_window->frutosComenPlaga = jsonArray[30].toInt();
                this->main_window->tiempoSegComenPlaga = jsonArray[31].toInt();

                qDebug()<< jsonArray[32].toInt();
                qDebug()<< jsonArray[33].toInt();
                *this->main_window->t_mercado_abierto= jsonArray[32].toInt();
               *this->main_window->t_mercado_abrir = jsonArray[33].toInt();
                qDebug()<< *this->main_window->t_mercado_abrir;
                qDebug()<< *this->main_window->t_mercado_abierto;
                for (const QJsonValue& itemValue : jsonArray) {
                    QJsonObject itemObject = itemValue.toObject();
                    int key = itemObject["key"].toInt();
                    QJsonArray valuesArray = itemObject["values"].toArray();
                }
                int n = 0;
                while(true){
                    if(jsonObject.contains(QString::number(n))){
                        QJsonArray jsonArray = jsonObject[QString::number(n)].toArray();
                        int tipo = jsonArray[0].toInt();
                        switch(tipo){
                        case 1:
                            this->tab->modificarArbol(jsonArray[4].toInt(),jsonArray[5].toInt(),1,this->main_window->t_crecimien_abb,
                                                      this->main_window->cosecha_cada_t_abb,this->main_window->cosecha_abb,
                                                      this->main_window->costo_abb,this->main_window->precio_frut_abb,tabla,
                                                      &this->granjero->dinero,jsonArray[1].toInt(),parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]);
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->perdidos = jsonArray[2].toInt();
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->vendidos = jsonArray[3].toInt();

                            parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]->setPixmap(this->abb_);
                            this->pos_trees->insert(counter_trees,{jsonArray[4].toInt(),jsonArray[5].toInt()});
                            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
                            break;
                        case 2:
                            this->tab->modificarArbol(jsonArray[4].toInt(),jsonArray[5].toInt(),2,this->main_window->t_crecimien_arj,
                                                      this->main_window->cosecha_cada_t_arj,this->main_window->cosecha_arj,
                                                      this->main_window->costo_arj,this->main_window->precio_frut_arj,tabla,
                                                      &this->granjero->dinero,jsonArray[1].toInt(),parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]);
                            parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]->setPixmap(this->arj_);
                            this->pos_trees->insert(counter_trees,{jsonArray[4].toInt(),jsonArray[5].toInt()});
                            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->perdidos = jsonArray[2].toInt();
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->vendidos = jsonArray[3].toInt();

                            break;

                        case 3:
                            this->tab->modificarArbol(jsonArray[4].toInt(),jsonArray[5].toInt(),3,this->main_window->t_crecimien_avl,
                                                      this->main_window->cosecha_cada_t_avl,this->main_window->cosecha_avl,
                                                      this->main_window->costo_avl,this->main_window->precio_frut_avl,tabla,
                                                      &this->granjero->dinero,jsonArray[1].toInt(),parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]);
                            parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]->setPixmap(this->avl_);
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->perdidos = jsonArray[2].toInt();
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->vendidos = jsonArray[3].toInt();

                            this->pos_trees->insert(counter_trees,{jsonArray[4].toInt(),jsonArray[5].toInt()});
                            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
                            break;

                        case 4:
                            this->tab->modificarArbol(jsonArray[4].toInt(),jsonArray[5].toInt(),4,this->main_window->t_crecimien_heap,
                                                      this->main_window->cosecha_cada_t_heap,this->main_window->cosecha_heap,
                                                      this->main_window->costo_heap,this->main_window->precio_frut_heap,tabla,
                                                      &this->granjero->dinero,jsonArray[1].toInt(),parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]);
                            parcelas[jsonArray[5].toInt()][jsonArray[4].toInt()]->setPixmap(this->heap_);
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->perdidos = jsonArray[2].toInt();
                            this->tab->casillaEnPos(jsonArray[4].toInt(),jsonArray[5].toInt())->vendidos = jsonArray[3].toInt();
                            this->pos_trees->insert(counter_trees,{jsonArray[4].toInt(),jsonArray[5].toInt()});
                            this->table_pos->insertItem(counter_trees,QString::number(++counter_trees));
                            break;
                        }

                        n++;
                    }else
                        break;
                    QThread::sleep(1);
                }
            }
        }
    }
}

void Gamewindow::on_guardarButton_clicked()
{
    {
        QHash<int, QVector<int>> hash = *this->pos_trees;

        QJsonObject jsonObject;
        jsonObject["Plata"] = this->granjero->dinero;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            int key = it.key();
            QVector<int> value = it.value();
            QJsonArray jsonArray;

            jsonArray.append(this->tab->casillaEnPos(it.value()[0],it.value()[1])->arbol);
            jsonArray.append(this->tab->casillaEnPos(it.value()[0],it.value()[1])->n_elementos);
            jsonArray.append(this->tab->casillaEnPos(it.value()[0],it.value()[1])->perdidos);
            jsonArray.append(this->tab->casillaEnPos(it.value()[0],it.value()[1])->vendidos);


            for (int item : value) {
                jsonArray.append(item);
            }

            jsonObject[QString::number(key)] = jsonArray;

        }
        QJsonArray jsonArray;
        jsonArray.append(*this->main_window->costo_abb);
        jsonArray.append(*this->main_window->cosecha_abb);
        jsonArray.append(*this->main_window->cosecha_cada_t_abb);
        jsonArray.append(*this->main_window->precio_frut_abb);
        jsonArray.append(*this->main_window->t_crecimien_abb);

        jsonArray.append(*this->main_window->costo_arj);
        jsonArray.append(*this->main_window->cosecha_arj);
        jsonArray.append(*this->main_window->cosecha_cada_t_arj);
        jsonArray.append(*this->main_window->precio_frut_arj);
        jsonArray.append(*this->main_window->t_crecimien_arj);

        jsonArray.append(*this->main_window->costo_avl);
        jsonArray.append(*this->main_window->cosecha_avl);
        jsonArray.append(*this->main_window->cosecha_cada_t_avl);
        jsonArray.append(*this->main_window->precio_frut_avl);
        jsonArray.append(*this->main_window->t_crecimien_avl);

        jsonArray.append(*this->main_window->costo_heap);
        jsonArray.append(*this->main_window->cosecha_heap);
        jsonArray.append(*this->main_window->cosecha_cada_t_heap);
        jsonArray.append(*this->main_window->precio_frut_heap);
        jsonArray.append(*this->main_window->t_crecimien_heap);

        jsonArray.append(this->main_window->probOveja);
        jsonArray.append(this->main_window->tiempoSegOveja);
        jsonArray.append(this->main_window->frutosComenOveja);
        jsonArray.append(this->main_window->tiempoSegComenOveja);

        jsonArray.append(this->main_window->probCuervo);
        jsonArray.append(this->main_window->tiempoSegCuervo);
        jsonArray.append(this->main_window->frutosComenCuervo);
        jsonArray.append(this->main_window->tiempoSegComenCuervo);

        jsonArray.append(this->main_window->probPlaga);
        jsonArray.append(this->main_window->tiempoSegPlaga);
        jsonArray.append(this->main_window->frutosComenPlaga);
        jsonArray.append(this->main_window->tiempoSegComenPlaga);

        jsonArray.append(*this->main_window->t_mercado_abierto);
        jsonArray.append(*this->main_window->t_mercado_abrir);

        jsonObject["config"] = jsonArray;
        // Creating a JSON document from the JSON object
        QJsonDocument jsonDocument(jsonObject);

        // Saving the JSON document to a file
        QString filePath = "C:/Users/Asus/Repositories/ProyectoED2/"+QString::fromStdString(this->main_window->nombre)+".json";
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(jsonDocument.toJson());
            file.close();
            qDebug() << "JSON data saved to" << filePath;
        } else {
            qDebug() << "Failed to open file for writing:" << file.errorString();
        }


    }
}

