#include <iostream>

using namespace std;

class abstractComponent {
public:
    virtual void inscreverParticipante();
    virtual void getAssento();
    virtual void getMembros();
    virtual void totalParticipantes();
    virtual void totalAssentos();
};

class Congresso : public abstractComponent {
    void inscreverParticipante() override {
        //Implementar o método que inscreve os participantes no evento.
    }

    void totalAssentos() override {
        //Implementar o método para conseguir o número total de assentos.
    }

    void totalParticipantes() override {
        //Implementar o método que obtem o total de participantes.
    }
};

class Individuo : public abstractComponent {
    void getAssento() override {
        //Implementar o método para conseguir um assento disponível.
    }
};

class Instituicao : public abstractComponent {
    void getMembros() override {
        //Implementar o método que obtem todos os membros de uma instituição.
    }
};

int main (void) {


    return 0;
}