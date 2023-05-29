#include <iostream>
#include <vector>

using namespace std;

class Mediador {
    public:
        virtual void enviarMensagem() {};
};

class Usuario {
    private:
        Mediador *mediador;
        string cor, mensagem;

    public:
        Usuario(Mediador *mediator = nullptr) : mediador(mediator) {
        }

        void setMediador(Mediador *m) {
            this->mediador = m;
        }

        void setCor(string nova_cor) {
            this->cor = nova_cor;
        }

        string getCor() {
            return this->cor;
        }

        void setMsg(string nova_msg) {
            this->mensagem = nova_msg;
            cout << "Mensagem recebida por um usuario " << this->cor << ": " << this->mensagem << endl;
        }

        void showMsg (){
            cout << this->mensagem << endl;
        }

};

class MediadorConcreto : public Mediador{
    private:
        string cor_msg, mensagem;
        vector<Usuario> usuarios;

    public:
        MediadorConcreto(vector<Usuario> users) {
            this->usuarios = users;
            for (unsigned short int i = 0; i < usuarios.size(); i++)
            {
                this->usuarios[i].setMediador(this);
            }
            
        };

        void enviarMensagem(string cor, string msg) {
            if (cor == "vermelho") {
                cout << "Usuarios vermelhos notificados..." << endl;
                for (unsigned short int i = 0; i < usuarios.size(); i++) {
                    if (usuarios[i].getCor() == "vermelho")
                        usuarios[i].setMsg(msg);
                }
                
            }
            else if (cor == "verde") {
                cout << "Usuarios verdes notificados..." << endl;
                for (unsigned short int i = 0; i < usuarios.size(); i++) {
                    if (usuarios[i].getCor() == "verde")
                        usuarios[i].setMsg(msg);
                }
            }
            else if (cor == "azul") {
                cout << "Usuarios azuis notificados..." << endl;
                for (unsigned short int i = 0; i < usuarios.size(); i++) {
                    if (usuarios[i].getCor() == "azul")
                        usuarios[i].setMsg(msg);
                }
            }
            else {
                cout << "Cor de entrada incorreta("<< cor <<").. Digite a cor corretamente: 'vermelho', 'verde' ou 'azul'!" << endl;
            }
        }

};


int main() {
    Usuario user_a, user_b, user_c, user_x;
    vector<Usuario> all_users;

    user_a.setCor("vermelho");
    user_b.setCor("azul");
    user_c.setCor("verde");
    user_x.setCor("roxo");

    all_users.push_back(user_a);
    all_users.push_back(user_b);
    all_users.push_back(user_c);
    all_users.push_back(user_x);

    MediadorConcreto mediador = MediadorConcreto(all_users);

    mediador.enviarMensagem("vermelho", "Ola usuarios da cor vermelha!");
    mediador.enviarMensagem("verde", "Ola usuarios da cor verde!");
    mediador.enviarMensagem("azul", "Ola usuarios da cor azul!");
    mediador.enviarMensagem("roxo", "Ola usuarios da cor roxa!");

    return 0;
}