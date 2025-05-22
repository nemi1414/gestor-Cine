#include <iostream>
#include <cstring>
#include "Entrada.h"
#include "Fecha.h"
using namespace std;

Entrada::Entrada(){
    setIdPelicula(0);
    setSala(0);
    setFechaProyeccion(Fecha());
    setDniComprador("0");
    setCantidadEntradasCompradas(0);
    setEstadoEntrada(false);
}

Entrada::Entrada(int idPelicula, int sala, Fecha fechaProyeccion, const char*dniComprador, int cantidadEntradasCompradas, bool estado){
    setIdPelicula(idPelicula);
    setSala(sala);
    setFechaProyeccion(fechaProyeccion);
    setDniComprador(dniComprador);
    setCantidadEntradasCompradas(cantidadEntradasCompradas);
    setEstadoEntrada(estado);
}


void Entrada::setIdPelicula(int idPelicula){
    _idPelicula = idPelicula;
}
void Entrada::setSala(int sala){
    _sala = sala;
}
void Entrada::setFechaProyeccion(Fecha fechaProyeccion){
    _fechaProyeccion = fechaProyeccion;
}
void Entrada::setDniComprador(const char* dniComprador){
    strcpy(_dniComprador, dniComprador);
}
void Entrada::setCantidadEntradasCompradas(int cantidadEntradasCompradas){
    _cantidadEntradasCompradas = cantidadEntradasCompradas;
}
void Entrada::setEstadoEntrada(bool estado){
    _estado = estado;
}

int Entrada::getIdPelicula(){
    return _idPelicula;
}
int Entrada::getSala(){
    return _sala;
}
Fecha Entrada::getFechaProyeccion(){
    return _fechaProyeccion;
}
const char*Entrada::getDniComprador(){
    return _dniComprador;
}
int Entrada::getCantidadEntradasCompradas(){
    return _cantidadEntradasCompradas;
}
bool Entrada::getEstado(){
    return _estado;
}

void Entrada::cargarEntrada(){
    int idPelicula;
    int sala;
    Fecha fechaProyeccion;
    char dniComprador[12];
    int cantidadEntradasCompradas;
    bool estado;
    cout << "INGRESE ID DE PELICULA: ";
    cin >> idPelicula;
    setIdPelicula(idPelicula);
    cout << "INGRESE NUMERO DE SALA: ";
    cin >> sala;
    setSala(sala);
    cout << "INGRESE FECHA DE PROYECCION: ";
    fechaProyeccion.cargarFecha();
    setFechaProyeccion(fechaProyeccion);
    cout << endl;
    cout << "INGRESE DNI DEL COMPRADOR: ";
    cin >> dniComprador;
    setDniComprador(dniComprador);
    cout << "INGRESE CANTIDAD DE ENTRADAS COMPRADAS: ";
    cin >> cantidadEntradasCompradas;
    setCantidadEntradasCompradas(cantidadEntradasCompradas);
    cout << "INGRESE ESTADO DE ENTRADA (1 ACTIVA, 0 INACTIVA): ";
    cin >> estado;
    while(estado!=0 && estado!=1){
        cout << "ESTADO INVALIDO. INGRESE DE NUEVO: ";
        cin >> estado;
    }
    setEstadoEntrada(estado);
}

void Entrada::mostrarEntrada(){
    cout << "ID DE PELICULA: " << _idPelicula << endl;
    cout << "NUMERO DE SALA: " << _sala << endl;
    cout << "FECHA DE PROYECCION: ";
    _fechaProyeccion.mostrarFecha();
    cout << endl;
    cout << "DNI DEL COMPRADOR: " << _dniComprador << endl;
    cout << "CANTIDAD DE ENTRADAS COMPRADAS: " << _cantidadEntradasCompradas << endl;
    cout << "ESTADO: ";
    if(_estado==true){
        cout << "ACTIVO" << endl;
    }else{
        cout << "INACTIVO" << endl;
    }
}
