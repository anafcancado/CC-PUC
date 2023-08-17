#include <iostream>

using namespace std;

class Carro{
private:
    float litros;
    float km;

public:
    Carro (float litros, float km): litros(litros), km(km){}

    void imprimir (float gasolina, float distancia){
        float gasrest;

        gasrest=distancia/15;
        gasrest=gasolina-gasrest;

        cout << "Gasolina restante: " << gasrest << endl;
        cout << "Distancia percorrida: " << distancia << endl;

    }

};

int main()
{
    Carro carro1(20, 200);
    Carro carro2(30, 400);

    carro1.imprimir(20,200);

    carro2.imprimir(30,400);
    return 0;
}
