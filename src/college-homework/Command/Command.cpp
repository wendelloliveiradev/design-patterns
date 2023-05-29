#include <iostream>
#include <unordered_map>

using namespace std;

//Using Singleton
class DataBaseReceiver {
    static DataBaseReceiver *instacia;
    unordered_map<int, string> db;

    DataBaseReceiver();

public:
    static DataBaseReceiver *getInstacia();

    void newInsert(int id, string name) {
        this->db[id] = name;
    }

    void deleteRow(int id) {
        this->db.erase(id);
    }

    void printAllData() {
        for (auto itr : this->db)
            cout << "Pessoa de ID: " << itr.first << ". Tem nome: " << itr.second << endl;
    }

    void printPersonInfo(int id) {
        cout << "A pessoa consultada se chama: " << this->db[id] << endl;
    }

};

//Singleton requirements
DataBaseReceiver *DataBaseReceiver::instacia = nullptr;

//Singleton requirements
DataBaseReceiver *DataBaseReceiver::getInstacia() {
    if (instacia == nullptr)
        instacia = new DataBaseReceiver();

    return instacia;
}

//Singleton requirements
DataBaseReceiver::DataBaseReceiver() {}


class Command {
public:
    virtual void executar(int id, string name) = 0;
};

class NewCommand : public Command{
    DataBaseReceiver *db_receiver = DataBaseReceiver::getInstacia();
public:
    void executar(int id, string name) override {
        db_receiver->newInsert(id, name);
    }
};

class DeleteCommand : public Command {
    DataBaseReceiver *db_receiver = DataBaseReceiver::getInstacia();
public:
    void executar(int id, string name) override {
        db_receiver->deleteRow(id);
    }
};

class ListAllCommand : public Command {
    DataBaseReceiver *db_receiver = DataBaseReceiver::getInstacia();
public:
    void executar(int id, string name) override {
        db_receiver->printAllData();
    }
};

class GetInfoCommand : public Command {
    DataBaseReceiver *db_receiver = DataBaseReceiver::getInstacia();
public:
    void executar(int id, string name) override {
        db_receiver->printPersonInfo(id);
    }
};

class DataBaseInvoker {
    unordered_map<string, Command*> commands;

public:
    DataBaseInvoker() {
        commands["new"] = new NewCommand();
        commands["delete"] = new DeleteCommand();
        commands["all"] = new ListAllCommand();
        commands["get"] = new GetInfoCommand();
    }

    void newOperation(string command, int id, string name) {
        Command *c = commands[command];

        c->executar(id, name);
    }

};

int main() {
    DataBaseInvoker *db_invoker_commands = new DataBaseInvoker();

    db_invoker_commands->newOperation("new", 222, "Joao");
    db_invoker_commands->newOperation("new", 333, "Maria");
    db_invoker_commands->newOperation("new", 555, "Pedro");
    db_invoker_commands->newOperation("new", 777, "Fernanda");
    db_invoker_commands->newOperation("new", 111111, "Paulo");
    db_invoker_commands->newOperation("new", 131313, "Clara");
    db_invoker_commands->newOperation("new", 171717, "Ricardo");

    db_invoker_commands->newOperation("get", 333, "");

    cout << endl;

    db_invoker_commands->newOperation("all", 0, "");

    db_invoker_commands->newOperation("delete", 171717, "");
    db_invoker_commands->newOperation("delete", 111111, "");
    db_invoker_commands->newOperation("delete", 222, "");

    cout << endl;

    db_invoker_commands->newOperation("all", 0, "");

    return 0;
}