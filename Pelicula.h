#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include "Fecha.h"

class Pelicula{
    private:
        int _numeroIdPelicula;
        char _nombrePelicula[50];
        char _nombreAutor[50];
        char _generoPelicula[50];
        int _clasificacion;
        Fecha _fechaEstreno;
        bool _estado;
    public:
        Pelicula();
        Pelicula(int numeroIdPelicula, const char*nombrePelicula, const char*nombreAutor, const char*generoPelicula, int clasificacion, Fecha fechaEstreno, bool estadoPelicula);

        void setNumeroIdPelicula(int numeroIdPelicula);
        void setNombrePelicula(const char *nombrePelicula);
        void setNombreAutor(const char *nombreAutor);
        void setGeneroPelicula(const char *generoPelicula);
        void setClasificacion(int clasificacion);
        void setFechaEstreno(Fecha fechaEstreno);
        void setEstadoPelicula(bool estadoPelicula);

        int getNumeroIdPelicula();
        const char* getNombrePelicula();
        const char* getNombreAutor();
        const char* getGeneroPelicula();
        int getClasificacion();
        Fecha getFechaEstreno();
        bool getEstadoPelicula();

        void cargarPelicula();
        void mostrarPelicula();
};

#endif // PELICULA_H_INCLUDED
