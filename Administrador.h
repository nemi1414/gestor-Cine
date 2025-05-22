#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED
#include "Usuario.h"
#include "Cliente.h"
#include "Pelicula.h"
#include "Sala.h"

class Administrador : public Usuario {
public:
    void registrarNuevoAdministrador();
    void iniciarSesionAdministrador();
    void menuAdministrador();
    void menuPeliculasAdministrador();
    void menuSalasAdministrador();
    void menuEntradasAdministrador();
    void menuAdministradores();
    void menuClientes();
    void menuReportes();

    void agregarPelicula();
    void listarPeliculas();
    void modificarPelicula();
    void modificarDatos(Pelicula &pelicula);
    void eliminarPelicula();

    void agregarSala();
    void listarSalas();
    void modificarSala();
    void modificarDatosSala(Sala &sala);
    void eliminarSala();

    void agregarAdministrador();
    void listarAdministradores();
    void eliminarAdministrador();
    void modificarAdministrador();
    void modificarDatosAdministrador(Administrador &administrador);
    void cargarAdministrador();
    void mostrarAdministrador();

    void listarClientes();
    void agregarClientes();
    void modificarClientes();
    void modificarDatosCliente(Cliente &cliente);
    void eliminarClientes();

};


#endif // ADMINISTRADOR_H_INCLUDED
