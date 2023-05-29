#include <iostream>
#include <vector>

using namespace std;

struct adderBd {
    int cod_aluno;
    int cod_turma;
    string turma;
};

class Curso {
private:
    string curso;

public:
    string getNome () {
        return curso;
    };

    string setNome (string course_name) {
        curso = course_name;
    };

    bool getState () {
        if (curso == "")
            return false;
        else
            return true;
    }
};

class Turma {
private:
    vector<int> mat_alunos;
    Curso curso;

public:
    void setCurso (Curso curso_info) {
        curso = curso_info;
    }

    void addAluno (int cod_aluno) {
        mat_alunos.push_back(cod_aluno);
    }

    string getTurmaNome () {
        curso.getNome();
    }

    bool getState () {
        if (mat_alunos.empty() && curso.getState())
            return false;
        else
            return true;
    }
};

class Aluno {
private:
    string aluno;
    int matricula;

public:
    void setAluno (string aluno_nome) {
        aluno = aluno_nome;
    }

    void setMatricula (int matricula_num) {
        matricula = matricula_num;
    }

    string getNome() {
        return aluno;
    }

    int getMatricula() {
        return matricula;
    }
};

class Escola {
public:
    Curso getCurso(int num_curso) {
        return searchBdCurso(num_curso);
    }

    Aluno getAluno(int num_matricula) {
        return searchBdAluno(num_matricula);
    }

private:
    Curso searchBdCurso(int codigo_curso) {
        //Implementar a função abaixo que faz uma consulta no banco de dados por tal curso.
        //searchByIdCurso();
    };

    Aluno searchBdAluno(int codigo_matricula) {
        //Implementar Função abaixo que faz uma consulta no banco de dados por tal aluno.
        //searchByIdAluno();
    }
};

class MatriculaGUI {
public:
    void matricular(int cod_aluno, int cod_curso, Turma turma) {
        if (turma.getState()) {
            //Pseudo implementação de uma nova inserção de um novo aluno.
            Escola *escola;
            Curso c = escola->getCurso(cod_curso);

            Turma t;
            t.addAluno(cod_aluno);
            t.setCurso(c);

            turma = t;
        }

        matriculaAluno(cod_aluno, cod_curso, turma.getTurmaNome());
    }

    void exibirStatus(string turma);

private:
    bool matriculaAluno(int num_aluno, int num_curso, string turma_nome) {
        adderBd addBd;
        addBd.cod_aluno = num_aluno;
        addBd.cod_turma = num_curso;
        addBd.turma = turma_nome;
        adcionarBanco(addBd);
    }

    void adcionarBanco (adderBd newAdd) {
        vector<adderBd> pseudo_banco;

        pseudo_banco.push_back(newAdd);
    }
};

class Facade {

public:
    //Construtor chama função que carrega dados do Banco de Dados.
    Facade () {
        carregaDadosBd();
    }

    void matricularAluno (int cod_aluno, int cod_curso, Turma turma) {
        MatriculaGUI *matricula;
        matricula->matricular(cod_aluno, cod_curso, turma);
    };

    //Método a ser implementado, realiza busca por informações sobre o respectivo aluno no Banco de Dados.
    void pesquisarAluno (int cod_aluno) {};

    //Método a ser implementado, exclui um aluno do banco de dados em caso de desligamento da instituição.
    void excluirAluno (int cod_aluno) {};

private:
    //Função representa uma pesquisa no banco de dados. Não implementado
    void carregaDadosBd () {
        Escola *escola = new Escola;
        Turma *turma = new Turma;
    };


};

int main (void) {
    Facade f;
    Turma turma;

    //objeto turma a ser inicializado com os componentes corretos.

    f.matricularAluno(123, 112, turma);
    f.excluirAluno(123);
    f.pesquisarAluno(123);

    return 0;
}