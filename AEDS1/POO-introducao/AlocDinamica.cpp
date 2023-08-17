#include <iostream>

using namespace std;


class Pessoa {
private:
    string *nome;
    int *idade;

public:
    Pessoa(string nome, int idade) {
        this->nome = new string(nome);
        this->idade = new int(idade);
    }

    ~Pessoa(){
        delete nome;
        delete idade;
    }

    string getNome (){
        return *nome;
    }

    int getIdade (){
        return *idade;
    }

    void setPessoa (string nome, int idade){
        *this->nome=nome;
        *this->idade=idade;

    }

};

int main()
{
    Pessoa *p1 = new Pessoa("ana", 19);

    cout << "idade:" << p1->getIdade();
    cout << "nome:" <<p1->getNome();

    p1->setPessoa("Ana F", 20);

    cout << "\nnova:" << p1->getIdade() << p1->getNome();

    return 0;
}
