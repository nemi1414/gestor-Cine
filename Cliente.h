#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Usuario.h"

class Cliente:public Usuario{
    public:
        void iniciarSesionCliente();
        void registrarNuevoCliente();
        void menuCliente();
        void menuPeliculasCliente();
        void historial();
        void menuModificarUsuario();
        void modificarNombre();
        void modificarContrasenia();
        void darmeDeBaja();
        void buscarPeliculaPorTeclado();
        void sacarEntradas(char* nombrePelicula);
        void listarPeliculas();

        void cargarCliente();
        void mostrarCliente();

        void verCartelera();
};

#endif // CLIENTE_H_INCLUDED
