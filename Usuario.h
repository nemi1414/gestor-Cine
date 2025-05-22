#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario{
    private:
        char _nombreUsuario[50];
        char _contrasenia[50];
        bool _estado;
        char _dniUsuario[12];
    public:
        void setNombreUsuario(const char* nombreUsuario);
        void setContrasenia(const char* contrasenia);
        void setEstado(bool estado);
        void setDniUsuario(const char* dniUsuario);
        const char* getNombreUsuario();
        const char* getContrasenia();
        bool getEstado();
        const char* getDniUsuario();

        void cargarUsuario();
        void mostrarUsuario();
};

#endif // USUARIO_H_INCLUDED
