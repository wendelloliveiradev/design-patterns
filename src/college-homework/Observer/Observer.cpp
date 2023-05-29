#include <iostream>
#include <vector>

using namespace std;

class Observer {
public:
    virtual ~Observer(){};
    virtual void update(const string &msg) = 0;
};

class Subject {
public:
    virtual ~Subject(){};
    virtual void addObserver(Observer *new_observer) = 0;
    virtual void removeObserver(Observer *old_observer) = 0;
    virtual void notifyObservers() = 0;
};

class ConcreteSubject : public Subject {
private:
    vector<Observer*> all_observers;
    string fresh_message;

public:
    virtual ~ConcreteSubject() {
        cout << "Adios!" << endl;
    }

    void addObserver(Observer *new_observer) override {
        this->all_observers.push_back(new_observer);
    }

    void removeObserver(Observer *old_observer) override {
        for (int i = 0; i < this->all_observers.size(); ++i)
            if (this->all_observers[i] == old_observer)
                this->all_observers.erase(this->all_observers.begin()+i);

    }

    void notifyObservers() override {
        for (int i = 0; i < this->all_observers.size(); ++i) {
            this->all_observers[i]->update(this->fresh_message);
        }
    }

    void newMessage (string message = "Nenhuma msg added!\n") {
        this->fresh_message = message;
        notifyObservers();
    }

    int getNumObservers () {
        return this->all_observers.size();
    }
};

class ConcreteObserver : public Observer{
private:
    string subject_message;
    Subject &subjecta;
    int number;
    static int non_edtble_num;

public:
    ConcreteObserver(Subject &subject) : subjecta(subject) {
        this->subjecta.addObserver(this);
    }

    virtual ~ConcreteObserver() {
        cout << "Adios!" << endl;
    }

    void update(const string &msg) override {
        this->subject_message = msg;
        callToAction();
    }

    void callToAction() {
        cout << "Vc tem uma nova notificacao" << endl;
    }

};



int main () {
    ConcreteSubject *subject = new ConcreteSubject;
    ConcreteObserver *concrete_um = new ConcreteObserver(*subject);
    ConcreteObserver *concrete_dois = new ConcreteObserver(*subject);
    ConcreteObserver *concrete_tres = new ConcreteObserver(*subject);

    subject->newMessage("Criar nova lista de produtos a serem vendidos!\n");

    subject->newMessage("Nova linha de produtos atualizada, entre em contato!\n");

    return 0;
}