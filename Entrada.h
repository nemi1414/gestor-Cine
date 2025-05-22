#ifndef ENTRADA_H_INCLUDED
#define ENTRADA_H_INCLUDED
#include "Fecha.h"

class Entrada{
    private:
        int _idPelicula;
        int _sala;
        Fecha _fechaProyeccion;
        char _dniComprador[12];
        int _cantidadEntradasCompradas;
        bool _estado;
    public:
        Entrada();
        Entrada(int idPelicula, int sala, Fecha fechaProyeccion, const char*dniComprador, int cantidadEntradasCompradas, bool estado);

        void setIdPelicula(int idPelicula);
        void setSala(int sala);
        void setFechaProyeccion(Fecha fechaProyeccion);
        void setDniComprador(const char* dniComprador);
        void setCantidadEntradasCompradas(int cantidadEntradasCompradas);
        void setEstadoEntrada(bool estado);

        int getIdPelicula();
        int getSala();
        Fecha getFechaProyeccion();
        const char* getDniComprador();
        int getCantidadEntradasCompradas();
        bool getEstado();

        void cargarEntrada();
        void mostrarEntrada();
};

#endif // ENTRADA_H_INCLUDED
