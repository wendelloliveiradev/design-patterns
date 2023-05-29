#include <iostream>

using namespace std;

class Estado {
public:
    virtual void miar() = 0;
};

class EstadoVivo : public Estado {
public:
    void miar() override {
        cout << "Meaaaooww!!" << endl;
    }
};

class EstadoMorto : public Estado {
public:
    void miar() override {
        cout << "Buu!" << endl;
    }
};

class EstadoQuantico : public Estado {
public:
    void miar() override {
        cout << "Hello Arnold!" << endl;
    }
};

class GatoQuantico {
    Estado *estado;

public:
    Estado *VIVO = new EstadoVivo();
    Estado *MORTO = new EstadoMorto();
    Estado *QUANTICO = new EstadoQuantico();

    void setEstado(Estado *estado) {
        this->estado = estado;
    }

    void miar() {
        this->estado->miar();
    }
};

int main() {
    GatoQuantico gato;

    //seta o estado do gato como VIVO
    gato.setEstado(gato.VIVO);
    gato.miar();

    //seta o estado do gato como MORTO
    gato.setEstado(gato.MORTO);
    gato.miar();

    //seta o estado do gato como QUANTICO
    gato.setEstado(gato.QUANTICO);
    gato.miar();

    return 0;
}