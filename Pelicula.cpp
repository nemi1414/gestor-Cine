#include <iostream>
#include <cstring>
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula(){
    setNumeroIdPelicula(0);
    setNombrePelicula("");
    setNombreAutor("");
    setGeneroPelicula("");
    setClasificacion(0);
    setFechaEstreno(Fecha());
    setEstadoPelicula(false);
}

Pelicula::Pelicula(int numeroIdPelicula, const char*nombrePelicula, const char*nombreAutor, const char*generoPelicula, int clasificacion, Fecha fechaEstreno, bool estadoPelicula){
    setNumeroIdPelicula(numeroIdPelicula);
    setNombrePelicula(nombrePelicula);
    setNombreAutor(nombreAutor);
    setGeneroPelicula(generoPelicula);
    setClasificacion(clasificacion);
    setFechaEstreno(fechaEstreno);
    setEstadoPelicula(estadoPelicula);
}


void Pelicula::setNumeroIdPelicula(int numeroIdPelicula){
    _numeroIdPelicula = numeroIdPelicula;
}
void Pelicula::setNombrePelicula(const char* nombrePelicula){
    strcpy(_nombrePelicula, nombrePelicula);
}
void Pelicula::setNombreAutor(const char* nombreAutor){
    strcpy(_nombreAutor, nombreAutor);
}
void Pelicula::setGeneroPelicula(const char* generoPelicula){
    strcpy(_generoPelicula, generoPelicula);
}
void Pelicula::setClasificacion(int clasificacion){
    _clasificacion = clasificacion;
}
void Pelicula::setFechaEstreno(Fecha fechaEstreno){
    _fechaEstreno = fechaEstreno;
}
void Pelicula::setEstadoPelicula(bool estadoPelicula){
    _estado = estadoPelicula;
}

int Pelicula::getNumeroIdPelicula(){
    return _numeroIdPelicula;
}
const char* Pelicula::getNombrePelicula(){
    return _nombrePelicula;
}
const char* Pelicula::getNombreAutor(){
    return _nombreAutor;
}
const char* Pelicula::getGeneroPelicula(){
    return _generoPelicula;
}
int Pelicula::getClasificacion(){
    return _clasificacion;
}
Fecha Pelicula::getFechaEstreno(){
    return _fechaEstreno;
}
bool Pelicula::getEstadoPelicula(){
    return _estado;
}

void Pelicula::cargarPelicula(){
    int numeroIdPelicula;
    char nombrePelicula[50];
    char nombreAutor[50];
    char generoPelicula[50];
    int clasificacion;
    Fecha fechaEstreno;
    bool estado;
    cout << "INGRESE ID DE PELICULA: ";
    cin >> numeroIdPelicula;
    setNumeroIdPelicula(numeroIdPelicula);
    cout << "INGRESE NOMBRE DE PELICULA: ";
    cin >> nombrePelicula;
    setNombrePelicula(nombrePelicula);
    cout << "INGRESE NOMBRE DE AUTOR: ";
    cin >> nombreAutor;
    setNombreAutor(nombreAutor);
    cout << "INGRESE GENERO DE PELICULA: ";
    cin >> generoPelicula;
    setGeneroPelicula(generoPelicula);
    cout << "INGRESE CLASIFICACION: ";
    cin >> clasificacion;
    setClasificacion(clasificacion);
    cout << "INGRESE FECHA DE ESTRENO: " << endl;
    fechaEstreno.cargarFecha();
    setFechaEstreno(fechaEstreno);
    cout << "INGRESE ESTADO DE LA PELICULA (1 ACTIVA, 0 INACTIVA): " << endl;
    cin >> estado;
    while(estado !=0 && estado != 1){
        cout << "ESTADO INVALIDO. INGRESE DE NUEVO: ";
        cin >> estado;
    }
    setEstadoPelicula(estado);
}

void Pelicula::mostrarPelicula(){
    cout << "NUMERO ID PELICULA: " << _numeroIdPelicula << endl;
    cout << "NOMBRE DE PELICULA: " << _nombrePelicula << endl;
    cout << "NOMBRE DE AUTOR: " << _nombreAutor << endl;
    cout << "GENERO DE PELICULA: " << _generoPelicula << endl;
    cout << "CLASIFICACION: " << _clasificacion << endl;
    cout << "FECHA DE ESTRENO: " << endl;
    _fechaEstreno.mostrarFecha();
    cout << endl;
    cout << "ESTADO: ";
    if(_estado==true){
        cout << "ACTIVO" << endl;
    }else{
        cout << "INACTIVO" << endl;
    }
}
