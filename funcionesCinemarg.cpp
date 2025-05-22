#include <iostream>
#include <cstring>
#include "funcionesCinemarg.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Cliente.h"
using namespace std;

void menuIngresar(){// no hace falta que est‚ en ninguna clase
    int opcion;
    while(true){
        cout << "*****CINEMARG*****" << endl;
        cout << "1.INGRESAR COMO ADMINISTRADOR" << endl;
        cout << "2.INGRESAR COMO CLIENTE" << endl;
        cout << "0.ABANDONAR PROGRAMA" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            menuIngresarComoAdministrador();
            break;
        case 2:
            system("cls");
            menuIngresarComoCliente();
            break;
        case 0:
            return;
        }
    }
}

void menuIngresarComoAdministrador(){
    Administrador administrador;
    int opcion;
    while(true){
        cout << "*****ADMINISTRADOR*****" << endl;
        cout << "1.INICIAR SESION" << endl;
        cout << "2.REGISTRARSE" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            administrador.iniciarSesionAdministrador();
            break;
        case 2:
            system("cls");
            administrador.registrarNuevoAdministrador();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
/*
void registrarNuevoAdministrador(){
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
} */
/*
void iniciarSesionAdministrador(){
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
*/


void menuIngresarComoCliente(){
    Cliente cliente;
    int opcion;
    while(true){
        cout << "*****CLIENTES*****" << endl;
        cout << "1.INICIAR SESION" << endl;
        cout << "2.REGISTRARSE" << endl;
        cout << "0.VOLVER AL MENU" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            system("cls");
            cliente.iniciarSesionCliente();
            break;
        case 2:
            system("cls");
            cliente.registrarNuevoCliente();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}

/*
void iniciarSesionCliente(){ ///debe estar en clase cliente
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
} */
/*
void registrarNuevoCliente(){
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
} */


/*
void menuAdministrador(){ ///debe estar en clase Administrador
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
           // menuEntradas();
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
            //menuReportes();
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
*/

/*
void menuCliente(){
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
*/

/*
void menuPeliculasAdministrador(){ ///clase Admin
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
           // listarPeliculas();
            break;
        case 2:
            system("cls");
           // agregarPelicula();
            break;
        case 3:
            system("cls");
           // modificarPelicula();
            break;
        case 4:
            system("cls");
           // eliminarPelicula();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
*/
/*
void menuSalasAdministrador(){ ///clase admin
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
           // listarSalas();
            break;
        case 2:
            system("cls");
          //  agregarSala();
            break;
        case 3:
            system("cls");
           // modificarSala();
            break;
        case 4:
            system("cls");
           // eliminarSala();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}*/
/*
void menuAdministradores(){ ///clase admin
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
            //listarAdministradores();
            break;
        case 2:
            system("cls");
           // agregarAdministrador();
            break;
        case 3:
            system("cls");
            //modificarAdministrador();
            break;
        case 4:
            system("cls");
            //eliminarAdministrador();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
*/
/*
void menuClientes(){ ///clase Administrador
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
            //listarClientes();
            break;
        case 2:
            system("cls");
            //agregarClientes();
            break;
        case 3:
            system("cls");
            //modificarClientes();
            break;
        case 4:
            system("cls");
           // eliminarClientes();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
*/
/*
void menuPeliculasCliente(){ ///CLASE CLIENTE
    int opcion;
    while(true){
        cout << "*****MENU PELICULAS*****" << endl;
        cout << "1.BUSCAR PELICULA" << endl;
        cout << "2.LISTAR PELICULAS" << endl;
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
            cout << "TODAS LAS PELICULAS: " << endl;
           // listarPeliculas();
            break;
        case 0:
            system("cls");
            return;
        }
    }
}
*/
/*
void historial(){ ///CLASE CLIENTE
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
}*/
/*
void menuModificarUsuario(){ ///CLASE CLIENTE
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
}*/
/*
void modificarNombre(){ /// CLASE CLIENTE
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
}*/
/*
void modificarContrasenia(){ ///CLASE CLIENTE
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
}*/
/*
void darmeDeBaja(){ ///CLASE CLIENTE
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
*//*
void buscarPeliculaPorTeclado(){ ///CLASE CLIENTE
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
        case 2:
            system("cls");
            return;
        }
    }
}*/
/*
void sacarEntradas(char* nombrePelicula){ ///CLASE CLIENTE
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
}*/
/*
void listarPeliculas(){ ///CLASE CLIENTE
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
}*/
