#include <iostream>
#include <cstring>
#include "Sala.h"
using namespace std;

Sala::Sala() {
    setNumeroDeSala(0);
    setNombreDeSala("");
    setTipoDeSala(0);
    //inicializarButacas();
    setEstadoSala(false);
}

Sala::Sala(int numeroDeSala, const char* nombreDeSala, int tipoDeSala, bool estado) {
    setNumeroDeSala(numeroDeSala);
    setNombreDeSala(nombreDeSala);
    setTipoDeSala(tipoDeSala);
    //inicializarButacas();
    setEstadoSala(estado);
}


void Sala::setNumeroDeSala(int numeroDeSala) {
    if (numeroDeSala >= 1) {
        _numeroDeSala = numeroDeSala;
    }
}
void Sala::setNombreDeSala(const char* nombreDeSala) {
    strcpy(_nombreDeSala, nombreDeSala);
}
void Sala::setTipoDeSala(int tipoDeSala) {
    _tipoDeSala = tipoDeSala;
}/*
void Sala::setButacasDisponibles(bool* butacasDisponibles) {
    for (int i = 0; i < 100; i++) {
        _butacasDisponibles[i] = butacasDisponibles[i];
    }
}*/
void Sala::setEstadoSala(bool estado) {
    _estado = estado;
}


int Sala::getNumeroDeSala() {
    return _numeroDeSala;
}
const char* Sala::getNombreDeSala() {
    return _nombreDeSala;
}
int Sala::getTipoDeSala() {
    return _tipoDeSala;
}/*
bool* Sala::getButacasDisponibles() {
    return _butacasDisponibles;
}*/
bool Sala::getEstadoSala() {
    return _estado;
}
/*
// Inicializar todas las butacas como disponibles
void Sala::inicializarButacas() {
    for (int i = 0; i < 100; i++) {
        _butacasDisponibles[i] = true;
    }
}*/
/*
// Mostrar estado de cada butaca
void Sala::mostrarButacasDisponibles(){
    for(int i=0; i<100; i++){
        cout << "BUTACA: " << i+1 << ": ";
        if(_butacasDisponibles[i] == true){
            cout << "DISPONIBLE" << endl;
        }else{
            cout << "OCUPADA" << endl;
        }
    }
}
*/
// Cargar datos de la sala
void Sala::cargarSala() {
    int numeroDeSala;
    int tipoDeSala;
    char nombreDeSala[50];
    bool estadoSala;
    cout << "INGRESE NUMERO DE SALA: ";
    cin >> numeroDeSala;
    setNumeroDeSala(numeroDeSala);
    cout << "INGRESE NOMBRE DE SALA: ";
    cin.ignore();
    cin.getline(nombreDeSala, 50);
    setNombreDeSala(nombreDeSala);
    cout << "INGRESE TIPO DE SALA (NUMERO): ";
    cin >> tipoDeSala;
    setTipoDeSala(tipoDeSala);
   // inicializarButacas(); // todas disponibles al principio

    cout << "INGRESE ESTADO DE LA SALA (1 ACTIVA, 0 INACTIVA): ";
    cin >> estadoSala;
    setEstadoSala(estadoSala);
}

// Mostrar datos de la sala
void Sala::mostrarSala() {
    cout << "NUMERO DE SALA: " << getNumeroDeSala() << endl;
    cout << "NOMBRE DE SALA: " << getNombreDeSala() << endl;
    cout << "TIPO DE SALA: ";
    imprimirTipoSala();
    cout << "ESTADO: ";
    if(_estado==true){
        cout << "ACTIVA" <<endl;
    }
    else{
        cout << "EN MANTENIMIENTO" << endl;
    }
    //cout << "BUTACAS DISPONIBLES: " << endl;
    //mostrarButacasDisponibles();
}

void Sala::imprimirTipoSala(){
    if(_tipoDeSala == 1){
        cout << "ESTANDAR" << endl;
    }else if(_tipoDeSala == 2){
        cout << "PREMIUM" << endl;
    }else{
        cout << "CONFORT PLUS" << endl;
    }
}
