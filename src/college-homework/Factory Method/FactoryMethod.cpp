#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

class Figura {
public:
    virtual double setgetArea(double x) = 0;
};

class Circulo : public Figura{
    double area;

public:
    double setgetArea(double x) override {
        this->area = 3.1415 * x * x;
        return this->area;
    }
};

class Quadrado : public Figura{
    double area;

public:
    double setgetArea(double x) override {
        this->area = x * x;
        return this->area;
    }
};

class TriEquilatero : public Figura{
    double area;

public:
    double setgetArea(double x) override {
        this->area = (x * x * sqrt(3))/4;
        return this->area;
    }
};

class Factory {
public:
    virtual Figura *getFigura(string tipo) = 0;
    virtual void operacao() = 0;
};

class FactoryConcreto : public Factory {
    unordered_map<string, Figura*> construtores;
    Figura *figTriangulo, *figQuadrado, *figCirculo;

public:
    FactoryConcreto() {
        construtores["Triangulo"] = new TriEquilatero();
        construtores["Quadrado"] = new Quadrado();
        construtores["Circulo"] = new Circulo();
    }

    Figura *getFigura(string tipo) override {
        Figura *f = construtores[tipo];
        return f;
    }

    void operacao() override {
        this->figTriangulo = getFigura("Triangulo");
        this->figQuadrado = getFigura("Quadrado");
        this->figCirculo = getFigura("Circulo");

        cout << "A area do triangulo é: " << this->figTriangulo->setgetArea(3.75) << endl;
        cout << "A area do Quadrado é: " << this->figQuadrado->setgetArea(5.34) << endl;
        cout << "A area do Circulo é: " << this->figCirculo->setgetArea(8.77) << endl;
    }
};

int main() {
    FactoryConcreto *factory_figuras = new FactoryConcreto();

    factory_figuras->operacao();

    delete factory_figuras;

    return 0;
}