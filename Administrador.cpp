#include <iostream>
#include <cstring>
#include "Administrador.h"
#include "Cliente.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Sala.h"
using namespace std;

void Administrador::registrarNuevoAdministrador(){
    Usuario usuario;
    char nombreUsuario[50];
    char contrasenia[50];

    cout << "*****REGISTRAR ADMINISTRADOR*****" << endl;
    cout << "INGRESE NUEVO NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    usuario.setNombreUsuario(nombreUsuario);
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;
    usuario.setContrasenia(contrasenia);

    FILE*archivo = fopen("administradores.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo";
        exit(-1);
    }
    int escribio = fwrite(&usuario, sizeof(Usuario), 1, archivo);
    fclose(archivo);
    if(escribio==1){
        cout << "NUEVO ADMINISTRADOR REGISTRADO CON EXITO" << endl;
    }else{
        cout << "ERROR AL REGISTRAR ADMINISTRADOR" << endl;
    }
}

void Administrador::iniciarSesionAdministrador(){
    Usuario usuario;
    char nombreUsuario[50];
    char contrasenia[50];
    bool accede = false;

    cout << "*****INICIAR SESION*****" << endl;
    cout << "INGRESE NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;

    FILE*archivo = fopen("administradores.dat", "rb");
    if(archivo==nullptr){
        cout << "NO HAY NINGUN ADMINISTRADOR REGISTRADO.";
        exit(-1);
    }
    fseek(archivo, 0, SEEK_END);
    int tam = ftell(archivo);
    if(tam==0){
        cout << "NO HAY NINGUN ADMINISTRADOR REGISTRADO." << endl;
        fclose(archivo);
        return;
    }
    fseek(archivo,0,SEEK_SET);

    while(fread(&usuario, sizeof(Usuario),1,archivo) == 1){
        if(strcmp(usuario.getNombreUsuario(), nombreUsuario)==0 && strcmp(usuario.getContrasenia(), contrasenia)==0 ){
            accede = true;
            break;
        }
    }
    fclose(archivo);

    if(accede==true){
        system("cls");
        cout << "BIENVENIDO " << nombreUsuario << endl;
        menuAdministrador();
    }else{
        cout << "NOMBRE O CONTRASENIA INCORRECTOS" << endl;
    }
}

void Administrador::menuAdministrador(){
    int opcion;
    while(true){
        cout << "*****ADMINISTRADOR*****" << endl;
        cout << "1.MENU PELICULAS" << endl;
        cout << "2.MENU SALAS" << endl;
        cout << "3.MENU ENTRADAS" << endl;
        cout << "4.MENU ADMINISTRADORES" << endl;
        cout << "5.MENU CLIENTES" << endl;
        cout << "6.MENU REPORTES" << endl;
        cout << "7.MENU MANTENIMIENTO" << endl;
        cout << "0.CERRAR SESION" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            menuPeliculasAdministrador();
            break;
        case 2:
            system("cls");
            menuSalasAdministrador();
            break;
        case 3:
            system("cls");
           // menuEntradasAdministrador();
            break;
        case 4:
            system("cls");
            menuAdministradores();
            break;
        case 5:
            system("cls");
            menuClientes();
            break;
        case 6:
            system("cls");
            menuReportes();
            break;
        case 7:
            system("cls");
            //menuMantenimiento();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Administrador::menuPeliculasAdministrador(){
    int opcion;
    while(true){
        cout << "*****MENU PELICULAS*****"<< endl;
        cout << "1.LISTAR PELICULAS" << endl;
        cout << "2.AGREGAR PELICULA" << endl;
        cout << "3.MODIFICAR PELICULA" << endl;
        cout << "4.ELIMINAR PELICULA" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            listarPeliculas();
            break;
        case 2:
            system("cls");
            agregarPelicula();
            break;
        case 3:
            system("cls");
            modificarPelicula();
            break;
        case 4:
            system("cls");
            eliminarPelicula();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Administrador::menuSalasAdministrador(){
    int opcion;
    while(true){
        cout << "*****MENU SALAS*****" << endl;
        cout << "1.LISTAR SALAS" << endl;
        cout << "2.AGREGAR SALA" << endl;
        cout << "3.MODIFICAR SALA" << endl;
        cout << "4.ELIMINAR SALA" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: " << endl;
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            listarSalas();
            break;
        case 2:
            system("cls");
            agregarSala();
            break;
        case 3:
            system("cls");
            modificarSala();
            break;
        case 4:
            system("cls");
            eliminarSala();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Administrador::menuAdministradores(){
    int opcion;
    while(true){
        cout << "*****MENU ADMINISTRADORES*****" << endl;
        cout << "1.LISTAR ADMINISTRADORES" << endl;
        cout << "2.AGREGAR ADMINISTRADOR" << endl;
        cout << "3.MODIFICAR ADMINISTRADOR" << endl;
        cout << "4.ELIMINAR ADMINISTRADOR" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            listarAdministradores();
            break;
        case 2:
            system("cls");
            agregarAdministrador();
            break;
        case 3:
            system("cls");
            modificarAdministrador();
            break;
        case 4:
            system("cls");
            eliminarAdministrador();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Administrador::menuClientes(){
    int opcion;
    while(true){
        cout << "*****MENU CLIENTES*****" << endl;
        cout << "1.LISTAR CLIENTES" << endl;
        cout << "2.AGREGAR CLIENTE" << endl;
        cout << "3.MODIFICAR CLIENTE" << endl;
        cout << "4.ELIMINAR CLIENTE" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            listarClientes();
            break;
        case 2:
            system("cls");
            agregarClientes();
            break;
        case 3:
            system("cls");
            modificarClientes();
            break;
        case 4:
            system("cls");
            eliminarClientes();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}


void Administrador::agregarPelicula(){
    Pelicula pelicula;
    pelicula.cargarPelicula();

    FILE*archivo = fopen("peliculas.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    int escribio = fwrite(&pelicula, sizeof(Pelicula), 1, archivo);
    if(escribio!=1){
        cout << "error al agregar pelicula" << endl;
    }else{
        cout << "PELICULA GUARDADA CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}

void Administrador::listarPeliculas(){
    Pelicula pelicula;
    FILE*archivo = fopen("peliculas.dat", "rb");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&pelicula, sizeof(Pelicula), 1, archivo)==1){
        if(pelicula.getEstadoPelicula()==true){
            cout << "PELICULA: " << endl;
            pelicula.mostrarPelicula();
            cout << endl;
        }

    }
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
/*
void Administrador::eliminarPelicula(){
    Pelicula pelicula;
    int idPeliculaAEliminar;
    bool peliculaDeBaja = false;
    FILE*archivo = fopen("peliculas.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    cout << "INGRESE EL ID DE PELICULA A ELIMINAR: ";
    cin >> idPeliculaAEliminar;
    while(fread(&pelicula, sizeof(Pelicula), 1, archivo)==1){
        if(pelicula.getNumeroIdPelicula() == idPeliculaAEliminar){
            pelicula.setEstadoPelicula(false);
            fseek(archivo, -sizeof(Pelicula), SEEK_CUR);
            fwrite(&pelicula, sizeof(Pelicula), 1, archivo);
            peliculaDeBaja = true;
            break;
        }
    }
    fclose(archivo);
    if(peliculaDeBaja==true){
        cout << "PELICULA DADA DE BAJA CON EXITO" << endl;
    }else{
        cout << "NO HAY REGISTROS DE ESA PELICULA" << endl;
    }
    int opcion;
    cout << "INGRESE 0 PARA VOLVER: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}*/
                                        ///CORREGIR ALGUNAS COSAS DE ESTE METODO

void Administrador::eliminarPelicula() { ///puedo usar este metodo o el que est  comentado arriba. este tiene ftell(), el otro no.
    Pelicula pelicula;
    int idPeliculaAEliminar;
    bool peliculaDeBaja = false;
    FILE* archivo = fopen("peliculas.dat", "rb+");
    if (archivo == nullptr) {
        cout << "error de archivo" << endl;
        exit(-1);
    }

    cout << "INGRESE EL ID DE PELICULA A ELIMINAR: ";
    cin >> idPeliculaAEliminar;

    while (true) {
        // Guardamos la posici¢n ANTES de leer
        int pos = ftell(archivo);

        // Leemos una pel¡cula
        if (fread(&pelicula, sizeof(Pelicula), 1, archivo) != 1) {
            break; // fin del archivo
        }

        if (pelicula.getNumeroIdPelicula() == idPeliculaAEliminar) {
            pelicula.setEstadoPelicula(false);

            // Volvemos a la posici¢n donde empez¢ el objeto
            fseek(archivo, pos, SEEK_SET);

            // Sobrescribimos
            fwrite(&pelicula, sizeof(Pelicula), 1, archivo);

            peliculaDeBaja = true;
            break;
        }
    }

    fclose(archivo);

    if (peliculaDeBaja) {
        cout << "PELICULA DADA DE BAJA CON EXITO" << endl;
    } else {
        cout << "NO HAY REGISTROS DE ESA PELICULA" << endl;
    }

    int opcion;
    cout << "INGRESE 0 PARA VOLVER: ";
    cin >> opcion;
    if (opcion == 0) {
        return;
    }
}

void Administrador::modificarPelicula(){
    Pelicula pelicula;
    FILE* archivo = fopen("peliculas.dat", "rb+");
    if(archivo == nullptr){
        cout << "error de archivo";
        exit(-1);
    }
    int idPeliculaAModificar;
    cout << "INGRESE EL ID DE LA PELICULA A MODIFICAR: ";
    cin >> idPeliculaAModificar;

    while(fread(&pelicula, sizeof(Pelicula), 1, archivo) == 1){
        if(pelicula.getNumeroIdPelicula() == idPeliculaAModificar){
            cout << "PELICULA ENCONTRADA: " << endl;
            pelicula.mostrarPelicula();
            cout << "MODIFICANDO DATOS..." << endl;

            modificarDatos(pelicula);  // PASAR OBJETO POR REFERENCIA

            fseek(archivo, -sizeof(Pelicula), SEEK_CUR);
            fwrite(&pelicula, sizeof(Pelicula), 1, archivo);
            cout << "DATOS DE LA PELICULA MODIFICADOS CON EXITO" << endl;
            fclose(archivo);
            return;
        }
    }
    cout << "NO SE ENCONTRO UNA PELICULA CON ESE ID" << endl;
    fclose(archivo);
}

void Administrador::modificarDatos(Pelicula &pelicula){
    char nombrePelicula[50];
    char nombreAutor[50];
    char generoPelicula[50];
    int clasificacion;
    int estado;
    Fecha fechaEstreno;
    cin.ignore();
    cout << "INGRESE NUEVO NOMBRE DE PELICULA: ";
    cin.getline(nombrePelicula, 50);
    pelicula.setNombrePelicula(nombrePelicula);
    cout << "INGRESE NUEVO NOMBRE DE AUTOR: ";
    cin.getline(nombreAutor, 50);
    pelicula.setNombreAutor(nombreAutor);
    cout << "INGRESE NUEVO GENERO DE PELICULA: ";
    cin.getline(generoPelicula, 50);
    pelicula.setGeneroPelicula(generoPelicula);
    cout << "INGRESE NUEVA CLASIFICACION: ";
    cin >> clasificacion;
    pelicula.setClasificacion(clasificacion);
    cout << "INGRESE NUEVA FECHA DE ESTRENO: " << endl;
    fechaEstreno.cargarFecha();
    pelicula.setFechaEstreno(fechaEstreno);
    cout << "INGRESE NUEVO ESTADO (1 ACTIVO, 0 INACTIVO): ";
    cin >> estado;
    while(estado != 0 && estado != 1){
        cout << "INVALIDO. INGRESE DE NUEVO: ";
        cin >> estado;
    }
    pelicula.setEstadoPelicula(estado == 1);
}



void Administrador::agregarSala(){
    Sala sala;
    sala.cargarSala();
    FILE*archivo = fopen("salas.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    int escribio = fwrite(&sala, sizeof(Sala), 1, archivo);
    if(escribio!=1){
        cout << "error al agregar sala" << endl;
    }else{
        cout << "SALA AGREGADA CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::listarSalas(){
    Sala sala;
    FILE*archivo = fopen("salas.dat", "rb");
    if(archivo == nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&sala, sizeof(Sala), 1, archivo)==1){
        if(sala.getEstadoSala() == true){
            cout << "SALA: " << endl;
            sala.mostrarSala();
            cout << endl;
        }
    }
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarSala(){
    Sala sala;
    FILE*archivo = fopen("salas.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    int numeroDeSalaAModificar;
    cout << "INGRESE EL NUMERO DE SALA A MODIFICAR: ";
    cin >> numeroDeSalaAModificar;
    while(fread(&sala, sizeof(Sala), 1, archivo)==1){
        if(sala.getNumeroDeSala() == numeroDeSalaAModificar){
            cout << "SALA ENCONTRADA: " << endl;
            sala.mostrarSala();
            cout << "MODIFICANDO DATOS: " << endl;
            modificarDatosSala(sala);
            fseek(archivo, -sizeof(Sala), SEEK_CUR);
            fwrite(&sala, sizeof(Sala), 1, archivo);
            cout << "DATOS DE LA SALA MODIFICADOS CON EXITO" << endl;
            fclose(archivo);
            return;
        }
    }
    cout << "NO SE ENCONTRO NINGUNA PELICULA CON ESE ID" << endl;
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarDatosSala(Sala &sala){
    char nombreDeSala[50];
    int tipoDeSala;
    bool butacasDisponibles[100];
    int estado;
    cin.ignore();
    cout << "INGRESE NUEVO NOMBRE DE SALA: ";
    cin.getline(nombreDeSala, 50);
    sala.setNombreDeSala(nombreDeSala);
    cout << "INGRESE NUEVO TIPO DE SALA: ";
    cin >> tipoDeSala;
    sala.setTipoDeSala(tipoDeSala);
    int valorInicial;
    cout << "¨DESEA PONER TODAS LAS BUTACAS COMO DISPONIBLES? (1 = SI, 0 = NO): ";
    cin >> valorInicial;
    while(valorInicial != 0 && valorInicial != 1){
        cout << "VALOR INVALIDO. INGRESE 1 O 0: ";
        cin >> valorInicial;
    }
    for(int i = 0; i < 100; i++){
        butacasDisponibles[i] = (valorInicial == 1);
    }
    //sala.setButacasDisponibles(butacasDisponibles);
    cout << "INGRESE NUEVO ESTADO (1 ACTIVO, 0 INACTIVO): ";
    cin >> estado;
    while(estado != 0 && estado != 1){
        cout << "INVALIDO. INGRESE DE NUEVO: ";
        cin >> estado;
    }
    sala.setEstadoSala(estado == 1);
}
void Administrador::eliminarSala(){
    Sala sala;
    int numeroDesalaAEliminar;
    bool salaDeBaja = false;
    FILE*archivo = fopen("salas.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    cout << "INGRESE EL NUMERO DE SALA A ELIMINAR: ";
    cin >> numeroDesalaAEliminar;
   // int pos = ftell(archivo);
    while(fread(&sala, sizeof(Sala), 1, archivo)==1){
        if(sala.getNumeroDeSala() == numeroDesalaAEliminar){
            sala.setEstadoSala(false);
            salaDeBaja=true;
            fseek(archivo, -sizeof(Sala), SEEK_CUR);
            fwrite(&sala, sizeof(Sala), 1, archivo);
            break;
        }
    }
    if(salaDeBaja){
        cout << "SALA DADA DE BAJA CON EXITO" << endl;
    }else{
        cout << "NO HAY REGISTROS DE ESA SALA" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER: ";
    cin >> opcion;
    if (opcion == 0) {
        return;
    }
}


void Administrador::agregarAdministrador(){
    Administrador administrador;
    administrador.cargarAdministrador();
    FILE*archivo = fopen("administradores.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    int escribio = fwrite(&administrador, sizeof(Administrador), 1, archivo);
    if(escribio!=1){
        cout << "NO SE PUDO AGREGAR EL ADMINISTRADOR" << endl;
    }else{
        cout << "ADMINISTRADOR AGREGADO CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: " << endl;
    cin >> opcion;
    if(opcion == 0){
        return;
    }
}

void Administrador::cargarAdministrador(){
    Usuario::cargarUsuario();
}
void Administrador::mostrarAdministrador(){
    Usuario::mostrarUsuario();
}

void Administrador::listarAdministradores(){
    Administrador administrador;
    bool encontrado=false;
    FILE*archivo = fopen("administradores.dat", "rb");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&administrador, sizeof(Administrador), 1, archivo)==1){
        if(administrador.getEstado()==true){
            administrador.mostrarAdministrador();
            encontrado = true;
        }
    }
    fclose(archivo);
    if(encontrado==false){
        cout << "NO SE ENCONTRARON ADMINISTRADORES ACTIVOS" << endl;
    }
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::eliminarAdministrador(){
    Administrador administrador;
    char nombreAdministradorAEliminar[50];
    bool administradorDeBaja = false;
    cout << "INGRESE EL NOMBRE DEL ADMINISTRADOR A ELIMINAR: ";
    cin >> nombreAdministradorAEliminar;
    FILE*archivo = fopen("administradores.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&administrador, sizeof(Administrador), 1, archivo)==1){
        if(administrador.getEstado() == true && strcmp(administrador.getNombreUsuario(), nombreAdministradorAEliminar)==0){
            cout << "ADMINISTRADOR ENCONTRADO: " << endl;
            administrador.mostrarAdministrador();
            administrador.setEstado(false);
            fseek(archivo, -sizeof(Administrador), SEEK_CUR);
            fwrite(&administrador, sizeof(Administrador), 1, archivo);
            administradorDeBaja = true;
            break;
        }
    }
    if(administradorDeBaja==false){
        cout << "NO SE ENCONTRARON REGISTROS ACTIVOS CON ESE NOMBRE DE USUARIO" << endl;
    }else{
        cout << "USUARIO DADO DE BAJA CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarAdministrador(){
    Administrador administrador;
    char nombreUsuarioAModificar[50];
    cout << "INGRESE NOMBRE DE USUARIO DEL ADMINISTRADOR A MODIFICAR: ";
    cin >> nombreUsuarioAModificar;
    FILE*archivo = fopen("administradores.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&administrador, sizeof(Administrador), 1, archivo) == 1){
        if(administrador.getEstado()== true && strcmp(administrador.getNombreUsuario(), nombreUsuarioAModificar)==0){
            cout << "ADMINISTRADOR ENCONTRADO:" << endl;
            administrador.mostrarAdministrador();
            cout << "MODIFICANDO ADMINISTRADOR..." << endl;
            administrador.modificarDatosAdministrador(administrador);
            fseek(archivo, -sizeof(Administrador) ,SEEK_CUR);
            fwrite(&administrador, sizeof(Administrador), 1, archivo);
            cout << "DATOS DEL ADMINISTRADOR MODIFICADOS CON EXITO" << endl;
            fclose(archivo);
            return;
        }
    }
    cout << "NO SE ENCONTRO NINFUN ADMINISTRADOR CON ESE NOMBRE" << endl;
    fclose(archivo);
    int opcion;
    cout << "OPRIMA 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarDatosAdministrador(Administrador &administrador){
    char nuevoNombreUsuario[50];
    char nuevaContrasenia[50];
    cin.ignore();
    cout << "INGRESE NUEVO NOMBRE DE USUARIO: ";
    cin >> nuevoNombreUsuario;
    setNombreUsuario(nuevoNombreUsuario);
    cout << "INGRESE NUEVA CONTRASENIA: ";
    cin >> nuevaContrasenia;
    setContrasenia(nuevaContrasenia);
}


void Administrador::agregarClientes(){
    Cliente cliente;
    FILE*archivo = fopen("clientes.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    cliente.cargarCliente();
    int escribio = fwrite(&cliente, sizeof(Cliente), 1, archivo);
    if(escribio!=1){
        cout << "NO SE PUDO AGREGAR EL CLIENTE" << endl;
    }else{
        cout << "CLIENTE AGREGADO CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::listarClientes(){
    Cliente cliente;
    bool encontrado = false;
    FILE*archivo = fopen("clientes.dat", "rb");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&cliente, sizeof(Cliente), 1, archivo)==1){
        if(cliente.getEstado()==true){
            encontrado = true;
            cliente.mostrarCliente();
        }
    }
    if(encontrado==false){
        cout << "NO HAY CLIENTES ACTIVOS" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::eliminarClientes(){
    Cliente cliente;
    char nombreClienteAEliminar[50];
    bool clienteDeBaja = false;
    cout << "INGRESE EL NOMBRE DEL CLIENTE A ELIMINAR: ";
    cin >> nombreClienteAEliminar;
    FILE*archivo = fopen("clientes.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&cliente, sizeof(Cliente), 1, archivo) == 1){
        if(cliente.getEstado()==true && strcmp(cliente.getNombreUsuario(), nombreClienteAEliminar) == 0){
            cliente.setEstado(false);
            fseek(archivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, archivo);
            clienteDeBaja = true;
            break;
        }
    }
    if(clienteDeBaja==false){
        cout << "NO SE ENCONTRO NINGUN CLIENTE CON ESE NOMBRE" << endl;
    }else{
        cout << "CLIENTE DADO DE BAJA CON EXITO" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarClientes(){
    Cliente cliente;
    char nombreClienteAModificar[50];
    bool encontrado = false;
    cout << "INGRESE NOMBRE DE USUARIO DE CLIENTE A MODIFICAR: ";
    cin >> nombreClienteAModificar;
    FILE*archivo = fopen("clientes.dat", "rb+");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&cliente, sizeof(Cliente), 1, archivo)==1){
        if(strcmp(cliente.getNombreUsuario(), nombreClienteAModificar) == 0){
            cout << "CLIENTE ENCONTRADO: " << endl;
            encontrado = true;
            cliente.mostrarCliente();
            cout << "MODIFICANDO CLIENTE..." << endl;
            modificarDatosCliente(cliente);
            fseek(archivo, -sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, archivo);
            cout << "DATOS DEL CLIENTE MODIFICADOS CON EXITO" << endl;
            break;
        }
    }
    if(encontrado==false){
        cout << "NO SE ENCONTRO CLIENTE ACTIVO CON ESE NOMBRE" << endl;
    }
    fclose(archivo);
    int opcion;
    cout <<"INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
void Administrador::modificarDatosCliente(Cliente &cliente){
    char nuevoNombreUsuario[50];
    char nuevaContrasenia[50];
    cin.ignore();
    cout << "INGRESE NUEVO NOMBRE DE USUARIO: ";
    cin >> nuevoNombreUsuario;
    cliente.setNombreUsuario(nuevoNombreUsuario);
    cout << "INGRESE NUEVA CONTRASENIA: ";
    cin >> nuevaContrasenia;
    cliente.setContrasenia(nuevaContrasenia);
}


void Administrador::menuReportes(){
    int opcion;
    while(true){
        cout << "*****REPORTES*****" << endl;
        cout << "1.LISTAR PELICULA MAS VISTA" << endl;
        cout << "2.LISTAR PELICULA MENOS VISTA" << endl;
        cout << "3.VER CANTIDAD DE ENTRADAS VENDIDAS POR PELICULA" << endl;
        cout << "4.VER SALA MAS ELEGIDA" << endl;
        cout << "5.VER SALA MENOS ELEGIDA" << endl;
        cout << "6.VER TIPO DE SALA MAS ELEGIDA" << endl;
        cout << "7.VER TOTAL DE ENTRADAS VENDIDAS" << endl;
        cout << "8.VER GENERO DE PELICULAS MAS VISTO" << endl;
        cout << "9.VER PELICULA MAS NUEVA" << endl;
        cout << "10.VER PELICULA MAS VIEJA" << endl;
        cout << "11.LISTAR PELICULAS ESTRENADAS EN 2025" << endl;
        cout << "12.LISTAR PELICULAS ESTRENADAS ANTES DE LOS 2000" << endl;
        cout << "0.VOLVER" <<endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            //listarPeliculaMasVista();
            break;
        case 2:
            system("cls");
            //listarPeliculaMenosVista();
            break;
        case 3:
            system("cls");
            //verCantidadDeEntradasVendidasPorPelicula();
            break;
        case 4:
            system("cls");
            //listarSalaMasElegida();
            break;
        case 5:
            system("cls");
            //listarSalaMenosElegida();
            break;
        case 6:
            system("cls");
            //listarTipoDeSalaMasElegida();
            break;
        case 7:
            system("cls");
            //verTotalDeEntradasVendidas();
            break;
        case 8:
            system("cls");
            //listarGeneroDePeliculaMasVisto();
            break;
        case 9:
            system("cls");
            //listarPeliculaMasNueva();
            break;
        case 10:
            system("cls");
            //listarPeliculaMasVieja();
            break;
        case 11:
            system("cls");
            //listarPeliculasEstrenadasEn2025();
            break;
        case 12:
            system("cls");
            //listarPeliculasEstrenadasAntesDeLos200();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}


void Administrador::menuEntradasAdministrador(){
    int opcion;
    while(true){
        cout << "*****ENTRADAS*****" << endl;
        cout << "1.VER ENTRADAS VENDIDAS POR PELICULA" << endl;
        cout << "2.VER FUNCIONES Y FECHAS DE UNA PELICULA" << endl;
        cout << "3.VER COMPRADORES DE UNA PELICULA" << endl;
        cout << "4.VER TOTAL DE ENTRADAS VENDIDAS POR PELICULA" << endl;
        cout << "0.VOLVER" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            //listarEntradasVendidasPorPelicula();
            break;
        case 2:
            system("cls");
            //listarFuncionesPorPelicula();
            break;
        case 3:
            system("cls");
            //listarCompradoresPorPelicula();
            break;
        case 4:
            system("cls");
            //verTotalDeEntradasVendidasPorPelicula();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
