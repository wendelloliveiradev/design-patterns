#include <iostream>
#include <sys/unistd.h>

using namespace std;

class Classe {
public:
    virtual void templateMethod() final {
        operacaoUm();
    }
    virtual void operacaoUm () = 0;
};

class ClasseGenerica : public Classe {
    string nome, mensagem;
public:
    void setNome(string str) {
        this->nome = str;
    }

    void setMensagem(string msg) {
        this->mensagem = msg;
    }

    void operacaoUm() override {
        cout << "O nome da classe eh: " << this->nome << endl;
        cout << "A mensagem eh: " << this->mensagem << endl;
    }
};

int main() {
    string str, msg;
    ClasseGenerica classe_generica;

    cout << "Escolha o nome da classe: " << endl;
    getline(cin, str);

    cout << "Escolha a mensagem a ser impressa: " << endl;
    getline(cin, msg);

    classe_generica.setNome(str);
    classe_generica.setMensagem(msg);

    classe_generica.templateMethod();

    return 0;
}