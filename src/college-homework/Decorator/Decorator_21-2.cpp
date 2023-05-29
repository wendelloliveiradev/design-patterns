#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Reader {
public:
    virtual vector<string> read() = 0;
    virtual string getText() = 0;
};

class ConcreteReader : public Reader {
    string text, aux;
    vector<string> splitted_str;

public:
    ConcreteReader(string str) {
        this->text = str;

        stringstream str_stream(str);

        while (str_stream >> aux)
            splitted_str.emplace_back(aux);
    }

    vector<string> read() override {
        return this->splitted_str;
    }

    string getText() override {
        return this->text;
    }

    void newCommandString(string str) {
        this->text = str;
        splitted_str.clear();

        stringstream str_stream(str);

        while (str_stream >> aux)
            splitted_str.emplace_back(aux);
    }

};

class Command {
public:
    virtual void operacao() = 0;
};

class NullCommand : public Command {
    Reader *component;
public:
    NullCommand(Reader *new_dec) {
        this->component = new_dec;
    }

    void operacao() override {
        cout << "O objeto retornado foi um NullObject.." << endl;
        cout << "Portanto o comando digitado eh invalido: " << endl;
        cout << component->getText() << endl;
    }
};

class NewCommand : public Command {
    Reader *component;
public:
    NewCommand(Reader *new_dec) {
        this->component = new_dec;
    }

    void operacao() override {
        vector<string> aux;
        aux = component->read();

        cout << "O objeto retornado foi um NewObject.." << endl;
        cout << "Os dados sao: " << endl;
        cout << "ID: " << aux[1] << endl;
        cout << "NAME: " << aux[2] << endl;
    }
};

class DeleteCommand : public Command {
    Reader *component;
public:
    DeleteCommand(Reader *new_dec) {
        this->component = new_dec;
    }

    void operacao() override {
        vector<string> aux;
        aux = component->read();

        cout << "O objeto retornado foi um DeleteObject.." << endl;
        cout << "Os dados sao: " << endl;
        cout << "ID: " << aux[1];
    }
};

class GetCommand : public Command {
    Reader *component;
public:
    GetCommand(Reader *new_dec) {
        this->component = new_dec;
    }

    void operacao() override {
        vector<string> aux;
        aux = component->read();

        cout << "O objeto retornado foi um GetObject.." << endl;
        cout << "Os dados sao: " << endl;
        cout << "ID: " << aux[1];
    }
};

class GetAllCommand : public Command {
    Reader *component;
public:
    GetAllCommand(Reader *new_dec) {
        this->component = new_dec;
    }

    void operacao() override {
        vector<string> aux;
        aux = component->read();

        cout << "O objeto retornado foi um GetAllObject.." << endl;
        cout << "Os dados sao: " << endl;
        cout << "ID: " << aux[0];
    }
};

class ComandoReader : public Reader {
    Reader *component;
    vector<string> aux;

public:
    ComandoReader() {}

    ComandoReader(Reader *new_dec) {
        this->component = new_dec;

        readComando();
    }

    void setNewCommand(Reader *new_dec) {
        this->component = new_dec;

        readComando();
    }

    virtual Command* readComando() {
        aux = component->read();

        if (aux[0] == "new" && aux.size() == 3)
            return new NewCommand(this->component);
        else if (aux[0] == "delete" && aux.size() == 2)
            return new DeleteCommand(this->component);
        else if (aux[0] == "get" && aux.size() == 2)
            return new GetCommand(this->component);
        else if (aux[0] == "all" && aux.size() == 1)
            return new GetAllCommand(this->component);
        else
            return new NullCommand(this->component);
    }

    vector<string> read() override {
        return component->read();
    }

    string getText() override {
        return component->getText();
    }

    ~ComandoReader(){}
};

int main() {
    //Test New Command
    ConcreteReader new_text = ConcreteReader("new 123 joao");
    ComandoReader command_reader = ComandoReader(&new_text);
    Command* command_return = command_reader.readComando();
    command_return->operacao();

    cout << endl;
    cout << endl;

    //Test Delete Command
    new_text.newCommandString("delete 345");
    command_reader.setNewCommand(&new_text);
    command_return = command_reader.readComando();
    command_return->operacao();

    cout << endl;
    cout << endl;

    //Test Get Command
    new_text.newCommandString("get 777");
    command_reader.setNewCommand(&new_text);
    command_return = command_reader.readComando();
    command_return->operacao();

    cout << endl;
    cout << endl;

    //Test GetAll Command
    new_text.newCommandString("all");
    command_reader.setNewCommand(&new_text);
    command_return = command_reader.readComando();
    command_return->operacao();

    return 0;
}