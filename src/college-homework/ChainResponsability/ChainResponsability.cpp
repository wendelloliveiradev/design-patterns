#include <iostream>

using namespace std;

class Processador {
public:
    virtual Processador *setNext(Processador *processador) = 0; 
    virtual int ProcessarRequisicao(string elemento) = 0;
}; 

class ProcessadorPrimario : public Processador {
private:
    Processador *proximo_processador;

public:
    ProcessadorPrimario() : proximo_processador(nullptr) {}

    Processador *setNext(Processador *processador) override {
        this->proximo_processador = processador;

        return processador;
    }

    int ProcessarRequisicao(string requisicao) override {
        if (this->proximo_processador) {
            return this->proximo_processador->ProcessarRequisicao(requisicao);
        }

        return {};        
    }
};

class ProcessadorEspacos : public ProcessadorPrimario {
private:
    const char espaco = 32;
    int num_espaco = 0;

public:
    int ProcessarRequisicao(string requisicao) override {
        for (int i = 0; i < requisicao.size(); i++) {
            if (requisicao[i] == espaco)
                this->num_espaco++;
        }

        cout << "numero de espacos eh: " << this->num_espaco << endl;

        return ProcessadorPrimario::ProcessarRequisicao(requisicao);
    }

    int getNumEspacos() {
        return this->num_espaco;
    }
};

class ProcessadorLetraA : public ProcessadorPrimario {
private:
    const char letra_a_min = 97;
    const char letra_a_mai = 65;
    int num_letras_a = 0;

public:
    int ProcessarRequisicao(string requisicao) override {
        for (int i = 0; i < requisicao.size(); i++) {
            if (requisicao[i] == this->letra_a_min)
                this->num_letras_a++;
            else if (requisicao[i] == this->letra_a_mai)
                this->num_letras_a++;
        }

        cout << "numero de letras 'a' eh: " << this->num_letras_a << endl;

        return ProcessadorPrimario::ProcessarRequisicao(requisicao);
    }

    int getNumLetraA() {
        return this->num_letras_a;
    }

};

class ProcessadorPonto : public ProcessadorPrimario {
private:
    const char ponto = 46;
    int num_pontos = 0;

public:
    int ProcessarRequisicao(string requisicao) override {
        for (int i = 0; i < requisicao.size(); i++) {
            if (requisicao[i] == this->ponto)
                this->num_pontos++;
        }

        cout << "numero de pontos eh: " << this->num_pontos << endl;

        return ProcessadorPrimario::ProcessarRequisicao(requisicao);
    }

    int getNumPontos() {
        return this->num_pontos;
    }
};

int main() {
    int soma_carac;
    char str[100000];
    ProcessadorEspacos *proc_espaco = new ProcessadorEspacos;
    ProcessadorLetraA *proc_a = new ProcessadorLetraA;
    ProcessadorPonto *proc_ponto = new ProcessadorPonto;

    proc_espaco->setNext(proc_a)->setNext(proc_ponto);

    cin.getline(str, 100000);

    proc_espaco->ProcessarRequisicao(str);


    soma_carac = proc_espaco->getNumEspacos() + proc_a->getNumLetraA() + proc_ponto->getNumPontos();

    cout << "O numero da soma de caracteres eh: " << soma_carac << endl;

    return 0;
}