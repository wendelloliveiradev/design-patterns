#include <iostream>

using namespace std;

class CriarClass {
public:
    virtual void templateMethod() final {
        operacaoUm();
        operacaoDois();
    }

    virtual void operacaoUm () = 0;
    virtual void operacaoDois () = 0;
};

class ClasseGenericaUm : public CriarClass {
public:
    void operacaoUm() override {
        cout << "trecho de codigo x.." << endl;
    }

    void operacaoDois() override { };
};

class ClasseGenericaDois : public CriarClass {
public:
    void operacaoUm() override { };

    void operacaoDois() override {
        cout << "trecho de codigo y.." << endl;
    }
};

int main() {
    ClasseGenericaUm um;
    ClasseGenericaDois dois;

    um.templateMethod();
    dois.templateMethod();

    return 0;
}