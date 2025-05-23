#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        int getDia();
        int getMes();
        int getAnio();

        void cargarFecha();
        void mostrarFecha();
};

#endif // FECHA_H_INCLUDED
