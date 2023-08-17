#include <iostream>
#include <string>

using namespace std;

class Relogio {
private:
    int hora;
    int minuto;
    int segundo;


public:
    Relogio (){}

    void setHora (int hora, int minuto, int segundo){
        this->hora=hora;
        this->minuto=minuto;
        this->segundo=segundo;
    }

    string getHora () {
        string horario;
        horario = to_string(hora) + ":" + to_string(minuto) + ":" + to_string(segundo);
        return horario;
    }

    void avancar (){
        segundo ++;
        if (segundo==60){
            segundo=00;
            minuto++;
        }
        if (minuto==60){
            minuto=00;
            hora++;
        }
        if (hora==24){
            hora==00;
            minuto=00;
            segundo=00;
        }

    }


};

int main()
{
    Relogio relogio;

    relogio.setHora(17, 9, 59);

    cout << relogio.getHora ();


    return 0;
}
