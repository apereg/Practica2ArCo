#include "vehiculo.h"

//Vehiculo :: Vehiculo(){}

Vehiculo :: Vehiculo(string nombre, string matricula, string color, string combustible, int ruedas, int potencia
                     , int vagones, bool motor, bool ruedaRepuesto, bool antiPinchazos, bool reactores, bool locomotora, bool alas, bool trenAterrizaje, string tipo){
    this->nombre = nombre;
    this->matricula = matricula;
    this->color = color;
    this->combustible = combustible;
    this->ruedas = ruedas;
    this->potencia = potencia;
    this->vagones = vagones;
    this->motor = motor;
    this->ruedaRepuesto = ruedaRepuesto;
    this->antiPinchazos = antiPinchazos;
    this->reactores = reactores;
    this->locomotora = locomotora;
    this->alas = alas;
    this->trenAterrizaje = trenAterrizaje;
    this->tipo = tipo;

    if(this->combustible == "")
        this->combustible = "Sin combustible";

    if(this->motor)
        this->motorToString = "Si (" +to_string(this->potencia)+ ")";
    else
        this->motorToString = "No";

    if(this->ruedaRepuesto)
        this->complementoToString = "Rueda de repuesto";
    else
        this->complementoToString = "Kit anti pinchazos";


}

Vehiculo::Vehiculo(){}


void Vehiculo :: toGraphicString(int numVehiculo){
    QMessageBox mensaje;
    string vehiculoNombreVentana = "Informacion " + this->nombre;
    QString str = QString::fromUtf8(vehiculoNombreVentana.c_str());
    mensaje.setWindowTitle(str);

    string vehiculoParaLista = "Vehiculo " + to_string(numVehiculo) + " (" +this->tipo+ ")\nNombre: " + this->nombre + "\nColor: " + this->color + "\nCombustible: " +this->combustible+ "\nMotor: " + this->motorToString + "\nComplemento: " +this->complementoToString +
            "\nAlas: " + this->convertBoolean(this->alas) + "\nReactores: " + this->convertBoolean(this->reactores) + "\nTren de aterrizaje: " +this->convertBoolean(this->trenAterrizaje) + "\nReactores: " +this->convertBoolean(this->reactores) + "\nVagones: " +to_string(this->vagones) + "\0";
    str = QString::fromUtf8(vehiculoParaLista.c_str());
    mensaje.setText(str);

    mensaje.exec();
}

string Vehiculo :: convertBoolean(bool condicion){
    if(condicion)
        return "Si";
    return "No";
}
