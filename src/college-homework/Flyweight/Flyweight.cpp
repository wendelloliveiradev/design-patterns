#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

class Flyweight{
public:
    virtual void imprimirNumDezAlgarismos(){};
};

class FlyweightAlgarismos {
    //Classe concreta para criar objetos como numeros 1, 2, 3 etc..
private:
    int algarismo;

public:
    FlyweightAlgarismos(int n) {
        this->algarismo = n;
    }

    int getAlgarismo() {
        return this->algarismo;
    }
};

class FlyweightConcreto : public Flyweight{
private:
    list<unsigned short int> num_dez_algas;

public:
    FlyweightConcreto(FlyweightAlgarismos &algarismo, unsigned short int num_algarismos) {
        //Contrutor cria uma lista que recebe o algarismo desejado n vezes
        //formando um numero de n algarismos.
        for (unsigned short int i = 0; i < num_algarismos; i++)
            this->num_dez_algas.push_back(algarismo.getAlgarismo());
    }

    void imprimirNumDezAlgarismos() {
        //imprime a lista como se fosse um numero de n algarismos.
        list<unsigned short int>::iterator itr;
        for (itr = this->num_dez_algas.begin(); itr != this->num_dez_algas.end(); itr++) {
            cout << *itr;
        }
        cout << endl;
    }
};

class FlyweightFactory{
private:
    //Hashtables salvam objetos ja criados para serem reutilizados
    unordered_map<unsigned short int, FlyweightConcreto*> flyweights;
    unordered_map<unsigned short int, FlyweightAlgarismos*> algarisms_pool;
    unsigned short int num_elements;

    void createNewFlyweight(unsigned short int algarismo, unsigned short int qtd_algarismos) {
        FlyweightAlgarismos *aux = new FlyweightAlgarismos(algarismo);
        this->algarisms_pool.emplace(algarismo, aux);

        FlyweightConcreto *aux2 = new FlyweightConcreto(*this->algarisms_pool[algarismo], qtd_algarismos);
        flyweights.emplace(algarismo, aux2);
    }

    bool alreadyCreated(unsigned short int position) {
        //retorna true caaso o elemento ja tenha sido adicionado.
        if (this->algarisms_pool.find(position) != this->algarisms_pool.end())
            return true;

        return false;
    }

public:
    FlyweightFactory(unsigned short int num_elmts) {
        this->num_elements = num_elmts;
    }

    void printRandomAlgarisms(unsigned short int qtd_algarismos) {
        //gera 'aleatoriamente' valores de 0 a n-1 de acordo com o cliente
        //checa se o objeto correspondente aquele valor ja foi criado
        //caso nao tenha sido criado usa-o, se não cria-o.
        for (unsigned short int i = 0; i < this->num_elements; i++) {
            unsigned short int num = rand()%10;
            if (!alreadyCreated(num)) {
                createNewFlyweight(num, qtd_algarismos);
                this->flyweights[num]->imprimirNumDezAlgarismos();
            }
            else
                this->flyweights[num]->imprimirNumDezAlgarismos();
        }
    }
};

int main() {
    //Funcao 'srand' para padronizar a geracao de numeros 'aleatorios'
    srand(time(0));

    //Constroi um fabrica que abriga os objetos ja criados,
    //e que sao utilizados de forma recorrente.
    //o valor como parametro indica o numero de numeros a
    //serem impressos.
    FlyweightFactory *factory = new FlyweightFactory(10);

    //imprime numeros de 10 algarismos 10 vezes,
    //para alterar o numero de algarismos a serem impressos
    //basta alterar o valor do parametro
    factory->printRandomAlgarisms(10);

    delete factory;

    return 0;
}