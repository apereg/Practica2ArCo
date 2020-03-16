#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->vehiculosCreadosTextViewer->setText("0");

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_generarMatriculaButton_clicked(){
    srand(time(NULL));
    string numeros="0123456789";
    string letras="BCFGHJKLMNPRSTVWXYZ";

    char matricula[8];
    for(int i=0;i<4;i++)
        matricula[i]=numeros[rand()%numeros.length()];
    for(int i=4;i<7;i++)
        matricula[i]=letras[rand()%letras.length()];
    matricula[7] = '\0';

    ui->matriculaTextViewer->setText(matricula);
}

int MainWindow::convertirRuedas(int index){
    switch(index){
        case 0:
            return 2;
            break;
        case 1:
            return 3;
            break;
        case 2:
            return 4;
            break;
        case 3:
            return 6;
            break;
        case 4:
            return 40;
            break;
        default:
            return -1;
    }
}

string MainWindow::convertirColor(int index){
    switch(index){
        case 0:
            return "Blanco";
        break;
        case 1:
            return "Negro";
        break;
        case 2:
            return "Rojo";
        break;
        case 3:
            return "Azul";
        break;
        case 4:
            return "Amarillo";
        break;
        case 5:
            return "Verde";
        break;
        default:
            return "";
    }
}

string MainWindow::convertirCombustible(int index){
    switch(index){
        case 0:
            return "";
            break;
        case 1:
            return "Electrico";
            break;
        case 2:
            return "Diesel";
            break;
        case 3:
            return "Gasolina";
            break;
        case 4:
            return "Hibrido";
            break;
        case 5:
            return "Queroseno";
            break;
        default:
            return "";
    }
}

void MainWindow::on_motorCheckBox_clicked(bool checked){
    ui->motorSlider->setEnabled(checked);
    ui->motorLabel->setEnabled(checked);
    ui->motorSpinBox->setEnabled(checked);
    this->motor = checked;
    if(!checked){
        ui->motorSlider->setValue(80);
        ui->motorSpinBox->setValue(80);
    }
}

void MainWindow::restablecerValores(){
    ui->nombreVehiculoLineEdit->setText("");
    this->nombre = "";
    ui->ruedasComboBox->setCurrentIndex(0);
    this->ruedas = 2;
    ui->combustibleComboBox->setCurrentIndex(0);
    this->combustible = "";
    ui->colorComboBox->setCurrentIndex(0);
    this->color = "blanco";
    ui->motorCheckBox->setChecked(false);
    this->motor = false;
    ui->motorLabel->setEnabled(false);
    ui->motorSlider->setValue(80);
    ui->motorSlider->setEnabled(false);
    ui->motorSpinBox->setValue(80);
    ui->motorSpinBox->setEnabled(false);
    this->potencia = 80;
    ui->kitDePinchazosButton->setCheckable(false);
    ui->kitDePinchazosButton->setCheckable(true);
    this->kitPinchazos = false;
    ui->ruedaDeRepuestoButton->setCheckable(false);
    ui->ruedaDeRepuestoButton->setCheckable(true);
    this->ruedaRepuesto = false;
    ui->alasCheckBox->setChecked(false);
    this->alas = false;
    ui->locomotoraCheckBox->setChecked(false);
    this->locomotora = false;
    ui->reactoresCheckBox->setChecked(false);
    this->reactores = false;
    ui->trenDeAterrizajeCheckBox->setChecked(false);
    this->trenAterrizaje = false;
    ui->vagonesSpinBox->setValue(0);
    this->vagones = 0;
    ui->matriculaTextViewer->setText("");
    this->matricula = "";
}

void MainWindow::on_motorSpinBox_valueChanged(int arg1){
    ui->motorSlider->setValue(arg1);
}

void MainWindow::on_motorSlider_valueChanged(int value){
    ui->motorSpinBox->setValue(value);
}

void MainWindow::on_crearButton_clicked(){
    this->nombre = ui->nombreVehiculoLineEdit->text().toStdString();
    this->matricula = ui->matriculaTextViewer->text().toStdString();

    this->color = this->convertirColor(ui->colorComboBox->currentIndex());
    this->combustible = this->convertirCombustible(ui->combustibleComboBox->currentIndex());
    this->ruedas = this->convertirRuedas(ui->ruedasComboBox->currentIndex());

    if(this->motor)
        this->potencia = ui->motorSlider->value();
    else
        this->potencia = -1;

    this->alas = ui->alasCheckBox->isChecked();
    this->locomotora = ui->locomotoraCheckBox->isChecked();
    this->reactores = ui->reactoresCheckBox->isChecked();
    this->trenAterrizaje = ui->trenDeAterrizajeCheckBox->isChecked();

    this->vagones = ui->vagonesSpinBox->value();

    if(ui->kitDePinchazosButton->isChecked())
        this->kitPinchazos = true;
    else
        this->ruedaRepuesto = true;

    int valido = this->esUnVehiculoValido();
    QMessageBox mensaje;

    if(matricula == ""){
        this->on_generarMatriculaButton_clicked();
        this->matricula = ui->matriculaTextViewer->text().toStdString();
    }
    if(valido == -1 || this->nombre == ""){
        mensaje.setText("El vehiculo marcado no es valido");
        mensaje.exec();
    } else {
        string tipo;
        switch(valido){
            case 1:
                tipo = "Bicicleta";
            break;
            case 2:
                tipo = "Triciclo";
            break;
            case 3:
                tipo = "Motocicleta";
            break;
            case 4:
                tipo = "Coche";
            break;
            case 5:
                tipo = "Coche deportivo";
            break;
            case 6:
                tipo = "Avion";
            break;
            case 7:
                tipo = "Tren";
            break;
        }
        if(this->color == "")
            this->color = this->convertirColor(rand()%5);

        string creado = "Se ha creado un/una " +tipo+ " " +color;
        QString qstr = QString::fromStdString(creado);
        mensaje.setText(qstr);
        mensaje.exec();
        Vehiculo *vehiculo = new Vehiculo(this->nombre, this->matricula, this->color, this->combustible, this->ruedas, this->potencia
                                , this->vagones, this->motor, this->ruedaRepuesto, this->kitPinchazos, this->reactores, this->locomotora, this->alas, this->trenAterrizaje, tipo);
        this->vehiculos[numVehiculos] = *vehiculo;
        this->numVehiculos++;
        string s = to_string(numVehiculos);
        qstr = QString::fromStdString(s);
        ui->vehiculosCreadosTextViewer->setText(qstr);

        string vehiculoParaLista = this->nombre + " -> "  + tipo + " " + this->color + " (" + this->matricula + ")";
        QString str = QString::fromUtf8(vehiculoParaLista.c_str());

        QStringList list=(QStringList()<<str);
        ui->vehiculosCreadosListWidget->addItems(list);

        this->restablecerValores();
    }
}

int MainWindow::esUnVehiculoValido(){
    // 1 -> Bicicleta // 2 -> Triciclo // 3 -> Motocicleta // 4 -> Coche // 5 -> Coche deportivo // 6 -> Avion // 7 -> Tren
    if(this->ruedas == 2 && !this->motor && this->combustible == "" && !this->alas && !this->reactores && !this->locomotora && this->vagones == 0 && this->kitPinchazos)
        return 1;

    if(this->ruedas == 3 && !motor && this->combustible == "" && !this->alas && !this->reactores && !this->trenAterrizaje && !this->locomotora && this->vagones == 0 && this->kitPinchazos)
        return 2;

    if(this->ruedas == 2 && this->motor && (this->combustible == "Electrico" || this->combustible == "Gasolina" || this->combustible == "Diesel" || this->combustible == "Hibrido" ) && !this->alas && !this->reactores && !this->trenAterrizaje && !this->locomotora && this->vagones == 0 && this->kitPinchazos)
        return 3;

    if(this->ruedas == 4 && this->motor && this->potencia <= 250 && (this->combustible == "Electrico" || this->combustible == "Gasolina" || this->combustible == "Diesel" || this->combustible == "Hibrido" ) && !this->alas && !this->reactores && !this->trenAterrizaje && !this->locomotora && this->vagones == 0 && this->ruedaRepuesto)
        return 4;

    if(this->ruedas == 4 && this->motor && this->potencia >= 250 && (this->combustible == "Electrico" || this->combustible == "Gasolina") && !this->alas && !this->reactores && !this->trenAterrizaje && !this->locomotora && this->vagones == 0 && this->kitPinchazos)
        return 5;

    if(this->ruedas == 6 && this->motor && this->potencia == 450 && this->combustible == "Queroseno" && this->color == "Blanco" && this->alas && this->reactores && this->trenAterrizaje && !this->locomotora && !this->locomotora && this->vagones == 0 && this->ruedaRepuesto)
        return 6;

    if(this->ruedas == 40 && this->motor && this->potencia == 450 && (this->combustible == "Electrico" || this->combustible == "Gasolina") && this->color == "Negro" && !this->alas && !this->reactores && !this->trenAterrizaje && this->locomotora && this->vagones >= 5 && this->ruedaRepuesto)
        return 7;

    return -1;
}


void MainWindow::on_vehiculosCreadosListWidget_currentRowChanged(int currentRow){
    this->vehiculos[currentRow].toGraphicString(currentRow+1);
}
