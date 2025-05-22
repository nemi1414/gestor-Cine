#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED

class Sala {
private:
    int _numeroDeSala;
    char _nombreDeSala[50];
    int _tipoDeSala;
    bool _butacasDisponibles[100]; ///false es disponible y true es ocupado
    bool _estado;

public:
    Sala();
    Sala(int numeroDeSala, const char* nombreDeSala, int tipoDeSala, bool estado);

    void setNumeroDeSala(int numeroDeSala);
    void setNombreDeSala(const char* nombreDeSala);
    void setTipoDeSala(int tipoDeSala);
    void setButacasDisponibles(bool* butacasDisponibles); // opcional
    void setEstadoSala(bool estado);

    int getNumeroDeSala();
    const char* getNombreDeSala();
    int getTipoDeSala();
    bool* getButacasDisponibles();
    bool getEstadoSala();

    void inicializarButacas(); // pone todas en true
    void mostrarButacasDisponibles();
    void cargarSala();
    void mostrarSala();///PROBANDO GIT BUSH

    void imprimirTipoSala();
};

#endif // SALA_H_INCLUDED

