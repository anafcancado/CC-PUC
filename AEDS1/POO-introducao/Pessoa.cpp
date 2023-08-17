#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    float altura;

public:
    Pessoa(){}

    void setpessoa (string nome, int idade, float altura){
        this->nome=nome;
        this->idade=idade;
        this->altura=altura;
    }



    void setNome(string nome){
       this->nome=nome;
    }

    string getNome (){
        return nome;
    }

    void setIdade (int idade){
        this->idade=idade;
    }

    int getIdade (){
        return idade;
    }

    void setAltura (float altura){
        this->altura=altura;
    }

    float getAltura (){
        return altura;
    }


};

int main()
{
    Pessoa p1;
    Pessoa p2;

    p2.setpessoa("ana", 19, 1.66);

    p1.setNome("ana");
    p1.setIdade(19);
    p1.setAltura (1.66);

    cout << "nome: " << p1.getNome();
    cout << "\nidade: " << p1.getIdade ();
    cout << "\naltura: " << p1.getAltura();



    return 0;
}
