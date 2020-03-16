#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <QMessageBox>

using namespace std;

class Vehiculo{

public:
    Vehiculo(string nombre, string matricula, string color, string combustible, int ruedas, int potencia
             , int vagones, bool motor, bool ruedaRepuesto, bool antiPinchazos, bool reactores, bool locomotora, bool alas, bool trenAterrizaje, string tipo);

    Vehiculo();

    void toGraphicString(int numVehiculo);
    string convertBoolean(bool condicion);

private :
    string tipo, nombre, combustible, color, matricula;
    int ruedas, potencia, vagones;
    bool motor, ruedaRepuesto, antiPinchazos, reactores, locomotora, alas, trenAterrizaje;
    string motorToString, complementoToString;
};
#endif // VEHICULO_H
