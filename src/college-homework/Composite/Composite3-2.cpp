#include <iostream>
#include <vector>

using namespace std;

class PubliLeaf;

//Interface que funciona como componete no padrão composite, é implementada pelo composite e pela folha.
class Publicacao {
public:
    string toString();
    vector<PubliLeaf> getPublicacoes();
    void addPublicacao(PubliLeaf nova_publi);
};

//Classe que representa a folha no padrão composite, e a ultima estrutura instanciavel.
class PubliLeaf : public Publicacao {
private:
    string autor, nome_publi, tipo_publi;

public:
    PubliLeaf(string autor, string nome_publi, string tipo_publi) {
        this->autor = autor;
        this->nome_publi = nome_publi;
        this->tipo_publi = tipo_publi;
    }

    string toString() {
        string to_str = "";
        if (this->tipo_publi == "artigo")
            to_str += "Autor: " + this->autor + "\nArtigo: " + this->nome_publi + "\nTipo: " + this->tipo_publi;
        else
            to_str += "Artigo: " + this->nome_publi + "\nTipo: " + this->tipo_publi;

        return to_str;
    }
};

//Classe coleção, extende o componente pai e funciona como o composite da nosso algoritmo.
class Colecao : public Publicacao {
private:
    vector<PubliLeaf> publis;

public:
    void addPublicacao(PubliLeaf nova_publi) {
        this->publis.push_back(nova_publi);
    }

    vector<PubliLeaf> getPublicacoes() {
        return this->publis;
    }

    string toString () {
        //Aqui poderia ser implementado uma função toString especifica da classe Colecoes.
    }
};

int main () {
    vector<PubliLeaf> getPublis;

    //São instanciadas os menores blocos da nossa estrutura, as folhas.
    PubliLeaf artigo("Joao Jose", "Usando composites com eficiencia em c++", "artigo");
    PubliLeaf caderno("", "Novo caderno velho", "caderno");
    PubliLeaf jornal("", "Jornal de ciência e tecnologia", "jornal");
    PubliLeaf revista("", "Nature", "revista");

    //Instancia um composite que servirá como caixa para nossos blocos.
    Colecao colecoes;

    colecoes.addPublicacao(artigo);
    colecoes.addPublicacao(caderno);
    colecoes.addPublicacao(jornal);
    colecoes.addPublicacao(revista);

    //Acessando os elementos do nosso composite por meio da função getPublicacoes.
    getPublis = colecoes.getPublicacoes();

    //Número de elementos no nosso composite.
    cout << getPublis.size() << endl;

    //Método toString para imprimir na tela os respectivos dados.
    for (int i = 0; i < getPublis.size(); ++i)
        cout << getPublis[i].toString() << "\n\n";

    return 0;
}