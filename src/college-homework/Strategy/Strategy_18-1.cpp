#include <iostream>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;

class Estrategia {
public:
    virtual void executeAcao() = 0;
};

class Segunda : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Segunda, dia de por lixo na rua.." << endl;
    }
};

class Terca : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Terca, dia de ver uma condessa.." << endl;
    }
};

class Quarta : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Quarta, dia de lavar a barca.." << endl;
    }
};

class Quinta : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Quinta, dia de colocar pimenta.." << endl;
    }
};

class Sexta : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Sexta, dia de TRAVESSura.." << endl;
    }
};

class Sabado : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Sabado, dia de meditar sobre algo.." << endl;
    }
};

class Domingo : public Estrategia {
public:
    void executeAcao() override {
        cout << "Hoje eh Domingo, dia de fumar um caximbo.." << endl;
    }
};

class AcaoDoDia {
    Estrategia *acao;
public:
    AcaoDoDia(char day_week[]) {
        if (!strcmp(day_week, "Monday"))
            acao = new Segunda();
        else if (!strcmp(day_week, "Tuesday"))
            acao = new Terca();
        else if (!strcmp(day_week, "Wednesday"))
            acao = new Quarta();
        else if (!strcmp(day_week, "Thursday"))
            acao = new Quinta();
        else if (!strcmp(day_week, "Friday"))
            acao = new Sexta();
        else if (!strcmp(day_week, "Saturnday"))
            acao = new Sabado();
        else if (!strcmp(day_week, "Sunday"))
            acao = new Domingo();
    }

    void executar() {
        acao->executeAcao();
    }

};

int main() {
    char day_wknd[100];
    time_t t_start = time(nullptr);
    strftime(day_wknd, sizeof(day_wknd), "%A", localtime(&t_start));

    AcaoDoDia nova_acao(day_wknd);

    nova_acao.executar();

    return 0;
}