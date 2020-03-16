#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "vehiculo.h"

QT_BEGIN_NAMESPACE
namespace Ui{
    class MainWindow;
}
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    int convertirRuedas(int index);

    string convertirColor(int index);

    string convertirCombustible(int index);

    void on_crearButton_clicked();

    void on_motorCheckBox_clicked(bool checked);

    void on_motorSlider_valueChanged(int value);

    void on_motorSpinBox_valueChanged(int arg1);

    void on_generarMatriculaButton_clicked();

    void restablecerValores();

    int esUnVehiculoValido();

    void on_vehiculosCreadosListWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow*ui;

    Vehiculo vehiculos[50];
    int numVehiculos = 0;

    string nombre = "", combustible = "", color = "Blanco", matricula = "";
    int ruedas = 2, potencia = 80, vagones = 0;
    bool motor = false;
    bool ruedaRepuesto = false, kitPinchazos = false;
    bool reactores = false, locomotora = false , alas = false, trenAterrizaje = false;
};
#endif // MAINWINDOW_H
