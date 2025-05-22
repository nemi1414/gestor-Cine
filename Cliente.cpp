#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "Usuario.h"
#include "Pelicula.h"
#include "Entrada.h"
using namespace std;

void Cliente::iniciarSesionCliente(){
    Usuario usuario;
    char nombreUsuario[50];
    char contrasenia[50];
    bool accede = false;

    cout << "*****INICIAR SESION*****" << endl;
    cout << "INGRESE NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;

    FILE*archivo = fopen("clientes.dat", "rb");
    if(archivo==nullptr){
        cout << "NO HAY NINGUN CLIENTE REGISTRADO.";
        exit(-1);
    }
    fseek(archivo, 0, SEEK_END);
    int tam = ftell(archivo);
    if(tam==0){
        cout << "NO HAY NINGUN CLIENTE REGISTRADO." << endl;
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
        cout << "BIENVENIDO " << nombreUsuario << endl;
        menuCliente();
    }else{
        cout << "NOMBRE O CONTRASENIA INCORRECTOS" << endl;
    }
}

void Cliente::registrarNuevoCliente(){
    Usuario usuario;
    char nombreUsuario[50];
    char contrasenia[50];

    cout << "*****REGISTRAR CLIENTE*****" << endl;
    cout << "INGRESE NUEVO NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    usuario.setNombreUsuario(nombreUsuario);
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;
    usuario.setContrasenia(contrasenia);

    FILE*archivo = fopen("clientes.dat", "ab");
    if(archivo==nullptr){
        cout << "error de archivo";
        exit(-1);
    }
    int escribio = fwrite(&usuario, sizeof(Usuario), 1, archivo);
    fclose(archivo);
    if(escribio==1){
        cout << "NUEVO CLIENTE REGISTRADO CON EXITO" << endl;
    }else{
        cout << "ERROR AL REGISTRAR CLIENTE" << endl;
    }
}

void Cliente::menuCliente(){
    int opcion;
    while(true){
        cout << "*****CLIENTE*****" << endl;
        cout << "1.MENU PELICULAS" << endl;
        cout << "2.HISTORIAL" << endl;
        cout << "3.USUARIO" << endl;
        cout << "0.CERRAR SESION" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            menuPeliculasCliente();
            break;
        case 2:
            system("cls");
            historial();
            break;
        case 3:
            system("cls");
            menuModificarUsuario();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Cliente::menuPeliculasCliente(){
    int opcion;
    while(true){
        cout << "*****MENU PELICULAS*****" << endl;
        cout << "1.BUSCAR PELICULA" << endl;
        cout << "2.VER CARTELERA" << endl;
        cout << "0.VOLVER" << endl;
        cout << "INGRESE OPCION";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            buscarPeliculaPorTeclado();
            ///buscar pelicula ingresando nombre de pelicula por teclado
            break;
        case 2:
            system("cls");
            cout << "CARTELERA: " << endl;
            verCartelera();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Cliente::historial(){
    int opcion;
    while(true){
        cout << "*****HISTORIAL*****" << endl;
        cout << "PELICULAS VISTAS: " << endl;
        ///ac  debo mostrar los nombres de las peliculas vistas por este usuario (si se puede, tambien mostrar la fecha de cada una)
        cout << "ENTRADAS COMPRADAS: " << endl;
        ///aca debo mostrar la cantidad de entradas compradas por este usuario
        cout << "0.VOLVER" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        if(opcion==0){
            system("cls");
            return;
        }
    }
}

void Cliente::menuModificarUsuario(){
    int opcion;
    while(true){
        cout << "*****MODIFICAR USUARIO*****" << endl;
        cout << "1.MODIFICAR NOMBRE" << endl;
        cout << "2.MODIFICAR CONTRASENIA" << endl;
        cout << "3.DARME DE BAJA" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            modificarNombre();
            break;
        case 2:
            system("cls");
            modificarContrasenia();
            break;
        case 3:
            system("cls");
            darmeDeBaja();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Cliente::modificarNombre(){
    Usuario usuario;
    char nombreActual[50];
    char nuevoNombre[50];
    cout << "*****MODIFICAR NOMBRE*****" << endl;
    cout << "INGRESE NOMBRE ACTUAL: ";
    cin >> nombreActual;
    ///si nombreActual coincide con usuario.getNombre(), entonces hago la modificacion y todo ese codigo...

    int opcion;
    cout << "0.VOLVER" <<endl;
    cout << "INGRESE OPCION: ";
    cin >> opcion;
    if(opcion==0){
        system("cls");
        return;
    }
}

void Cliente::modificarContrasenia(){
    Usuario usuario;
    char contraseniaActual[50];
    char nuevaContrasenia[50];
    cout << "*****MODIFICAR CONTRASENIA*****" << endl;
    cout << "INGRESE CONTRASENIA ACTUAL: ";
    cin >> contraseniaActual;
    ///si la contraseniaActual coincide con usuario.getContrasenia(), entonces hago la modificacion y todo ese codigo...

    int opcion;
    cout << "0.VOLVER" << endl;
    cout << "INGRESE OPCION: ";
    cin >> opcion;
    if(opcion==0){
        system("cls");
        return;
    }
}

void Cliente::darmeDeBaja(){
    Usuario usuario;
    char nombreUsuario[50];
    char contrasenia[50];
    bool coincidenAmbos = false;
    cout << "INGRESE NOMBRE DE USUARIO: ";
    cin >> nombreUsuario;
    cout << "INGRESE CONTRASENIA: ";
    cin >> contrasenia;
    if( strcmp(usuario.getNombreUsuario(), nombreUsuario)==0 && strcmp(usuario.getContrasenia(), contrasenia)==0){
        ///entonces deber¡a poner que el estado de ese usuario pasa a false (desactivado)
        coincidenAmbos = true;
        if(coincidenAmbos==true){
            cout << "USUARIO DE BAJA." << endl;
        }
    }
    int opcion;
    cout << "0.CERRAR PROGRAMA" << endl;
    cout << "INGRESE OPCION: ";
    cin >> opcion;
    if(opcion==0){
        system("cls");
        exit(-1);
    }
}

void Cliente::buscarPeliculaPorTeclado(){
    Pelicula pelicula;
    bool peliculaEncontrada = false;
    FILE*archivo = fopen("peliculas.dat", "rb");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    char nombreDePeliculaBuscada[50];
    cout << "INGRESE EL NOMBRE DE LA PELICULA BUSCADA: ";
    cin.ignore();
    cin.getline(nombreDePeliculaBuscada, 50);
    while(fread(&pelicula, sizeof(Pelicula), 1, archivo)==1){
        if(pelicula.getEstadoPelicula() == true && strcmp(pelicula.getNombrePelicula(), nombreDePeliculaBuscada)==0){
            cout <<"PELICULA ENCONTRADA" << endl;
            peliculaEncontrada = true;
            pelicula.mostrarPelicula();
            cout << endl;
            cout << "DESEA SACAR ENTRADAS? (1 SI, 0 NO)";
            int respuesta;
            cin >> respuesta;
            if(respuesta==1){
                Entrada entrada;
                entrada.setIdPelicula(pelicula.getNumeroIdPelicula());
               // entrada.setSala(pelicula.getNumeroDeSala()) ///no tengo esto
                entrada.setEstadoEntrada(true);

                Fecha fecha;
                cout << "INGRESE LA FECHA DE LA FUNCION: " << endl;
                fecha.cargarFecha();
                entrada.setFechaProyeccion(fecha);
                entrada.setDniComprador(Cliente::getDniUsuario());
                int cantidad;
                cout << "INGRESE CANTIDAD DE ENTRADAS A SACAR: ";
                cin >> cantidad;
                entrada.setCantidadEntradasCompradas(cantidad);
                FILE*archivoEntrada = fopen("entradas.dat", "ab");
                if(archivoEntrada==nullptr){
                    cout << "error de archivo";
                    exit(-1);
                }
                fwrite(&entrada, sizeof(Entrada), 1, archivoEntrada);
                fclose(archivoEntrada);
                cout << "ENTRADA COMPRADA CON EXITO" << endl;
            }

            break;
        }
    }
    if(peliculaEncontrada==false){
        cout << "NO HAY REGISTROS DE ESA PELICULA" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
/*
void Cliente::buscarPeliculaPorTeclado(){
    int opcion;
    char peliculaBuscada[50];
    while(true){
        cout << "*****BUSCAR PELICULA*****" << endl;
        cout << "INGRESE EL NOMBRE DE LA PELICULA QUE BUSCA: ";
        cin >> peliculaBuscada;
        ///ac  debo hacer que busque en el archivo "peliculas.dat" si hay una pelicula activa con ese nombre,
        ///si la hay, mostrarla, mostrar fechas disponibles y permitir sacar entrada
        ///si no la hay, entonces imprimir "NO HAY REGISTROS DE ESA PELICULA"
        cout << "1.SACAR ENTRADAS" << endl;
        cout << "0.VOLVER" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            sacarEntradas(peliculaBuscada); //recibe el nombre de la pelicula y debe buscar en su achivo las fechas de esa pelicula
        break;
        case 0:
            system("cls");
            return;
        }
    }
}
*/
void Cliente::sacarEntradas(char* nombrePelicula){
    int eleccionFecha;
    int cantidadEntradasDeseadas;
    cout << "*****FECHAS DISPONIBLES*****" << endl;
    ///se muestran todas las fechas de esa pelicula ENUMERADAS
    cout << "INGRESE LA ENUMERACION CORRESPONDIENTE A LA FECHA SELECCIONADA: ";
    cin >> eleccionFecha;
    cout << "INGRESE LA CANTIDAD DE ENTRADAS QUE QUIERE: ";
    cin >>cantidadEntradasDeseadas;
    ///ac  deber¡a fijarme en el archivo de Peliculas, si esa pelicula tiene X cantidad de entradas disponibles (true o false)
    ///si las tiene, entonces deber¡a poner X cantidad en true, e imprimir en pantalla "X cantidad compradas"
    ///si no las tiene, deber¡a poner "LO SENTIMOS. NO HAY SUFICIENTES ENTRADAS DISPONIBLES"
    cout << "OPRIMA UNA TECLA PARA VOLVER AL MENU: ";
    system("pause");
    menuCliente();
}

void Cliente::listarPeliculas(){
    int opcion;
    int eleccionPelicula;
    char peliculaBuscada[50];
    while(true){
        cout << "*****TODAS LAS PELICULAS*****" << endl;
        ///se muestran todas las peliculas ENUMERADAS

        cout << "1.SACAR ENTRADAS" << endl;
        cout << "0.VOLVER" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cout << "INGRESE LA ENUMERACION CORRESPONDIENTE A LA PELICULA SELECCIONADA: ";
            cin >> eleccionPelicula;
            ///ac  deber¡a hacer algo que segun el numero ingresado, me devuelva el nombre de la pelicula
            ///peliculaBuscada = nombre devuelto de la pelicula
            sacarEntradas(peliculaBuscada);
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

void Cliente::cargarCliente(){
    Usuario::cargarUsuario();
}
void Cliente::mostrarCliente(){
    Usuario::mostrarUsuario();
}

void Cliente::verCartelera(){
    Pelicula pelicula;
    bool encontrada = false;
    FILE*archivo = fopen("peliculas.dat", "rb");
    if(archivo==nullptr){
        cout << "error de archivo" << endl;
        exit(-1);
    }
    while(fread(&pelicula, sizeof(Pelicula), 1, archivo)==1){
        if(pelicula.getEstadoPelicula()==true){
            encontrada = true;
            cout << "PELICULA ENCONTRADA: " << endl;
            pelicula.mostrarPelicula();
            cout << endl;
        }
    }
    if(encontrada==false){
        cout << "NO HAY PELICULAS EN CARTELERA ACTUALMENTE" << endl;
    }
    fclose(archivo);
    int opcion;
    cout << "INGRESE 0 PARA VOLVER AL MENU: ";
    cin >> opcion;
    if(opcion==0){
        return;
    }
}
