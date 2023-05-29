#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class SaveText {
public:
    virtual string getText() = 0;
};

class ConcreteComponent : public SaveText {
    string text;

public:
    ConcreteComponent(string str) {
        text = str;
    }

    string getText() override {
        return text;
    }

};

class Decorator : public SaveText {
    SaveText *component;

public:
    Decorator() {}

    Decorator(SaveText *new_dec) {
        this->component = new_dec;
    }

    string getText() override {
        return component->getText();
    }
};

class DecoratorCaps : public Decorator {
    SaveText *component;
public:
    DecoratorCaps(SaveText *new_dec) {
        this->component = new_dec;
    }

    string getText() {
        string aux = this->component->getText();
        transform(aux.begin(), aux.end(), aux.begin(), ::toupper);
        return aux;
    }
};

class DecoratorInverse : public Decorator {
    SaveText *component;
public:
    DecoratorInverse(SaveText *new_dec) {
        this->component = new_dec;
    }

    string getText() {
        string aux = this->component->getText();

        reverse(aux.begin(), aux.end());

        return aux;
    }
};

class DecoratorTags : public Decorator {
    SaveText *component;
public:
    DecoratorTags(SaveText *new_dec) {
        this->component = new_dec;
    }

    string getText() {
        string aux = this->component->getText();

        return "<b>" + aux + "</b>";
    }
};

int main() {
    ConcreteComponent new_text = ConcreteComponent("Ola este eh um teste sobre decorators");

    cout << "This is the original string: " << new_text.getText() << endl;

    DecoratorCaps new_caps = DecoratorCaps(&new_text);

    cout << "After using upper case decorator: " << new_caps.getText() << endl;

    DecoratorInverse new_inv = DecoratorInverse(&new_caps);

    cout << "After using inverse decorator: " << new_inv.getText() << endl;
    
    DecoratorTags new_tags = DecoratorTags(&new_inv);

    cout << "After using tags decorator: " << new_tags.getText() << endl;

    cout << "Final results: " << endl;

    cout << new_tags.getText() << endl;

    return 0;
}