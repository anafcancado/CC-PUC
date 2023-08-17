#include <iostream>
#include <string>

using namespace std;

class AnimalEstimacao {
protected:
    string nome;
    string raca;

public:
    AnimalEstimacao(string n, string r): nome(n), raca(r) {}

    void imprimir (){
        cout << "nome: " << nome << endl;
        cout << "raca: " << raca << endl;
    }

    void caminha (){
        cout << "caminhando..." << endl;
    }
};

class cachorro : public AnimalEstimacao {
private:
    int ccf;
public:
    cachorro(string n, string r, int c): AnimalEstimacao(n, r), ccf(c) {}

    void imprimir (){
        AnimalEstimacao::imprimir();
        cout << "ccf: " << ccf << endl;

    }

    void late (){
        cout<< "au au" << endl;
    }

};

class gato : public AnimalEstimacao {
private:
    int cgf;

public:
    gato (string n, string r, int c) : AnimalEstimacao(n,r), cgf(c){}

    void imprimir (){
        AnimalEstimacao::imprimir();
        cout << "cgf: " << cgf << endl;

    }

    void mia (){
        cout << "miau" << endl;
    }
};

int main()
{
    cachorro c1("toto", "golden", 123);
    c1.late();
    c1.caminha();
    c1.imprimir();

    gato g1 ("fred", "sei la", 987);
    g1.mia();
    g1.caminha();
    g1.imprimir();
    return 0;
}
