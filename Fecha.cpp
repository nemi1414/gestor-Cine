#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha(){
    setDia(1);
    setMes(1);
    setAnio(2000);
}

Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::setDia(int dia){
    _dia = dia;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}

void Fecha::cargarFecha(){
    int dia;
    int mes;
    int anio;
    cout << "INGRESE DIA: ";
    cin >> dia;
    while(dia<=0 || dia>=32){
        cout << "DIA INVALIDO. INGRESE DE NUEVO: ";
        cin >> dia;
    }
    setDia(dia);
    cout << "INGRESE MES: ";
    cin >> mes;
    while(mes<=0 && mes>=13){
        cout << "MES INVALIDO. INGRESE DE NUEVO: ";
        cin >> mes;
    }
    setMes(mes);
    cout << "INGRESE ANIO: ";
    cin >> anio;
    while(anio<=1900){
        cout << "ANIO INVALIDO. INGRESE DE NUEVO: ";
        cin >> anio;
    }
    setAnio(anio);
}

void Fecha::mostrarFecha(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}
