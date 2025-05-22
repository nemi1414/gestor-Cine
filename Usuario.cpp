#include <iostream>
#include <cstring>
#include "Usuario.h"
using namespace std;

void Usuario::setNombreUsuario(const char* nombreUsuario){
    strcpy(_nombreUsuario, nombreUsuario);
}
void Usuario::setContrasenia(const char* contrasenia){
    strcpy(_contrasenia, contrasenia);
}
void Usuario::setEstado(bool estado){
    _estado = estado;
}
void Usuario::setDniUsuario(const char* dniUsuario){
    strcpy(_dniUsuario, dniUsuario);
}

const char* Usuario::getNombreUsuario(){
    return _nombreUsuario;
}
const char* Usuario::getContrasenia(){
    return _contrasenia;
}
bool Usuario::getEstado(){
    return _estado;
}
const char* Usuario::getDniUsuario(){
    return _dniUsuario;
}

void Usuario::cargarUsuario(){
    char nombreUsuario[50];
    char contrasenia[50];
    char dniUsuario[12];
    cout << "INGRESE NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    setNombreUsuario(nombreUsuario);
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;
    setContrasenia(contrasenia);
    cout << "INGRESE DNI: ";
    cin >> dniUsuario;
    setDniUsuario(dniUsuario);
}
void Usuario::mostrarUsuario(){
    cout << "NOMBRE DE USUARIO: " << _nombreUsuario << endl;
}
