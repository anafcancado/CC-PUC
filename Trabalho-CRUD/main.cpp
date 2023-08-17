#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>

using namespace std;

class Veiculos // nessa classe tem todos os atributos necessarios para cada veiculo, metodos set e get para usar nas funcoes ao cadastrar, editar, listar...
{
private:
    string placa;
    string marca;
    string modelo;
    int ano;
    float preco;
    string tipo;
    string observacoes;

    static string placasCadastradas[500]; // vetor para armazenar as placas cadastradas
    static int countPlacas; // contador do n mero de placas cadastradas
    static Veiculos VetVeiculos[500]; // vetor para armazenar os objetos Veiculos cadastrados


public:
    Veiculos() {}  //construtor vazio

    static Veiculos* getVetVeiculos()  //metodos get
    {
        return VetVeiculos;
    }

    string getPlaca()
    {
        return placa;
    }
    void setPlaca(string p)
    {
        placa = p;
    }

    string getMarca()
    {
        return marca;
    }
    void setMarca(string m)
    {
        marca = m;
    }

    string getModelo()
    {
        return modelo;
    }
    void setModelo(string m)
    {
        modelo = m;
    }

    int getAno()
    {
        return ano;
    }
    void setAno(int a)
    {
        ano = a;
    }

    float getPreco()
    {
        return preco;
    }
    void setPreco(float p)
    {
        preco = p;
    }

    string getTipo()
    {
        return tipo;
    }
    void setTipo(string t)
    {
        tipo = t;
    }

    string getObservacoes()
    {
        return observacoes;
    }
    void setObservacoes(string obs)
    {
        observacoes = obs;
    }

    void setVeiculo(string placa, string marca, string modelo, int ano, float preco, string tipo, string observacoes)  //metodo set
    {
        while (tipo != "carro" && tipo != "moto") // verificacao
        {
            cout << "Tipo de ve culo inv lido. Apenas carros e motos s o aceitos." << endl;
            cout << "Digite o tipo de ve culo novamente: ";
            cin >> tipo;
        }

        while (placa.length() != 7)  //verificacao
        {
            cout << "Placa inv lida. A placa deve ter 7 caracteres." << endl;
            cout << "Digite a placa novamente: ";
            cin >> placa;
        }

        while (isPlacaCadastrada(placa) != -1)  //verificacao
        {
            cout << "Placa j  cadastrada anteriormente." << endl;
            cout << "Digite a placa novamente: ";
            cin >> placa;
        }

        this->marca = marca;
        this->placa = placa;
        this->modelo = modelo;
        this->ano = ano;
        this->preco = preco;
        this->tipo = tipo;
        this->observacoes = observacoes;

        placasCadastradas[countPlacas] = placa;   //atribuindo a placa atual
        VetVeiculos[countPlacas] = *this;  //atribui o objeto do ve�culo atual ao elemento de �ndice countplacas
        countPlacas++;
    }



    int isPlacaCadastrada(const string& placa)  // ver se a placa esta cadastrada
    {
        for (int i = 0; i < countPlacas; i++)
        {
            if (placasCadastradas[i] == placa)
            {
                return i; // Retorna o  idice da placa cadastrada
            }
        }
        return -1; // Retorna -1 se a placa n o est  cadastrada
    }

    Veiculos* getVeiculoPlaca(const string& placa)  //ver se a placa esta cadastrada
    {
        for (int i = 0; i < countPlacas; i++)
        {
            if (VetVeiculos[i].getPlaca() == placa)
            {
                return &VetVeiculos[i];
            }
        }
        return nullptr; // Retorna nullptr se a placa nao esta  cadastrada
    }

    static int getCountPlacas()  //contador placas
    {
        return countPlacas;
    }
};

// innicializa  o dos membros estaticos da classe
string Veiculos::placasCadastradas[500];
int Veiculos::countPlacas = 0;

Veiculos Veiculos::VetVeiculos[500]; // vetor para armazenar os objetos Veiculos cadastrados

int menu() // coloquei o menu aqui para separar do int main e ficar mais curto essa parte, apenas com o menu realmente
{
    int num;

    cout << "Escolha o que deseja fazer" << endl;
    cout << "6- Listar todos os veiculos" << endl;
    cout << "5- Pesquisar um veiculo" << endl;
    cout << "4- Cadastrar um veiculo" << endl;
    cout << "3- Editar um veiculo" << endl;
    cout << "2- Excluir um veiculo" << endl;
    cout << "1- Sair do programa" << endl;

    scanf("%d", &num);
    return num;
}


void listar()  //essa funcao lista todos os veiculos (metodo get) que ja foam cadastrados e tira os excluidos pela funcao excluir
{
    
    if (Veiculos::getCountPlacas() == 0)
    {

        return;
    }

    cout << "Lista de veiculos cadastrados:" << endl;
    int totalVeiculos = 0;

    for (int i = 0; i < Veiculos::getCountPlacas(); i++)
    {
        Veiculos* veiculo = &Veiculos::getVetVeiculos()[i];
        if (veiculo != nullptr && veiculo->getPlaca() != "")
        {
            cout << "Veiculo " << i + 1 << ":" << endl;   // ter um controle numerico dos veiculos
            cout << "Placa: " << veiculo->getPlaca() << "|";   // usando o metodo get
            cout << "Marca: " << veiculo->getMarca() << "|";
            cout << "Modelo: " << veiculo->getModelo() << "|";
            cout << "Ano: " << veiculo->getAno() << "|";
            cout << "Preco: " << veiculo->getPreco() << "|";
            cout << "Tipo: " << veiculo->getTipo() << "|";
            cout << "Observacoes: " << veiculo->getObservacoes() << endl;
            cout << endl;
            totalVeiculos++;
        }
    }

    cout << "Total de veiculos cadastrados: " << totalVeiculos << endl;


}


void pesquisar() // ao digitar uma placa que ja foi cadastrado ele usa o vetor que tem os veiculos e mostra o resultado
{
    string placaPesquisa;
    cout << "Digite a placa do veiculo a ser pesquisado: ";
    cin >> placaPesquisa;

    Veiculos* veiculo = nullptr;

    for (int i = 0; i < Veiculos::getCountPlacas(); i++)
    {
        if (Veiculos::getVetVeiculos()[i].getPlaca() == placaPesquisa)
        {
            veiculo = &Veiculos::getVetVeiculos()[i];
            break;
        }
    }

    if (veiculo == nullptr)
    {
        cout << "Veiculo nao encontrado." << endl;
    }
    else
    {
        cout << "Veiculo encontrado:" << endl;  //mostra as informacoes do veiculo encontrado pelo metodo get
        cout << "Placa: " << veiculo->getPlaca() << endl;
        cout << "Marca: " << veiculo->getMarca() << endl;
        cout << "Modelo: " << veiculo->getModelo() << endl;
        cout << "Ano: " << veiculo->getAno() << endl;
        cout << "Preco: " << veiculo->getPreco() << endl;
        cout << "Tipo: " << veiculo->getTipo() << endl;
        cout << "Observacoes: " << veiculo->getObservacoes() << endl;
    }
}


void cadastrar()  // essa funcao cadastra os novos veiculos
{
    string placa, marca, modelo, tipo, observacoes;
    int ano;
    float preco;

    Veiculos veiculo; // verificar se j� tem a placa

    do
    {
        cout << "Digite a placa do veiculo: (7 digitos) ";
        cin >> placa;

        if (veiculo.isPlacaCadastrada(placa) != -1)
        {
            cout << "Placa ja cadastrada anteriormente. Digite outra placa." << endl;  //verificacao
        }
    }
    while (placa.length() != 7 || veiculo.isPlacaCadastrada(placa) != -1);

    cout << "Digite a marca do veiculo: ";
    cin >> marca;

    cout << "Digite o modelo do veiculo: ";
    cin >> modelo;

    cout << "Digite o ano do veiculo: ";
    cin >> ano;

    cout << "Digite o preco do veiculo: ";
    cin >> preco;

    do
    {
        cout << "Digite o tipo do veiculo (carro/moto): ";
        cin >> tipo;
    }
    while (tipo != "moto" && tipo != "carro");

    cout << "Digite as observacoes do veiculo (ou deixe em branco): ";
    cin.ignore();  // com cin eu nao conseguia deixar em branco
    getline(cin, observacoes);

    veiculo.setVeiculo(placa, marca, modelo, ano, preco, tipo, observacoes);  //metodo set para cadastrar

 

    cout << "Veiculo cadastrado com sucesso!" << endl;
    
    
}


void editar()  //funcao para editar um veiculo ja cadastrado tambem pela placa
{
    string placa;
    cout << "Digite a placa do veiculo que deseja editar: ";
    cin >> placa;

    Veiculos* veiculo = nullptr;

    for (int i = 0; i < Veiculos::getCountPlacas(); i++)
    {
        if (Veiculos::getVetVeiculos()[i].getPlaca() == placa)
        {
            veiculo = &Veiculos::getVetVeiculos()[i];
            break;
        }
    }

    if (veiculo == nullptr)
    {
        cout << "Veiculo nao encontrado." << endl;
        return;
    }

    cout << "Veiculo encontrado:" << endl;
    cout << "Placa: " << veiculo->getPlaca() << endl;  // informacoes antigas mostradas pelo metodo get
    cout << "Marca: " << veiculo->getMarca() << endl;
    cout << "Modelo: " << veiculo->getModelo() << endl;
    cout << "Ano: " << veiculo->getAno() << endl;
    cout << "Preco: " << veiculo->getPreco() << endl;
    cout << "Tipo: " << veiculo->getTipo() << endl;
    cout << "Observacoes: " << veiculo->getObservacoes() << endl;

    string marca, modelo, tipo, observacoes;  // variaveis para pegar as novas informacoes
    int ano;
    float preco;

    cout << "Digite a nova marca do veiculo: ";
    cin >> marca;
    veiculo->setMarca(marca);

    cout << "Digite o novo modelo do veiculo: ";
    cin >> modelo;
    veiculo->setModelo(modelo);

    cout << "Digite o novo ano do veiculo: ";
    cin >> ano;
    veiculo->setAno(ano);

    cout << "Digite o novo preco do veiculo: ";
    cin >> preco;
    veiculo->setPreco(preco);

    do
    {
        cout << "Digite o novo tipo do veiculo (carro/moto): ";
        cin >> tipo;
    }
    while (tipo != "moto" && tipo != "carro");
    veiculo->setTipo(tipo);

    cout << "Digite as novas observacoes do veiculo (ou deixe em branco): ";
    cin.ignore();  // com cin eu nao conseguia deixar em branco
    getline(cin, observacoes);
    veiculo->setObservacoes(observacoes);

    cout << "Veiculo atualizado!" << endl;
}


void excluir()  //funcao para excluir um veiculo
{
    string placa;

    cout << "Digite a placa do veiculo que deseja excluir: ";
    cin >> placa;

    Veiculos* veiculo = nullptr;  //procurando pela placa

    for (int i = 0; i < Veiculos::getCountPlacas(); i++)
    {
        if (Veiculos::getVetVeiculos()[i].getPlaca() == placa)
        {
            veiculo = &Veiculos::getVetVeiculos()[i];
            break;
        }
    }

    if (veiculo == nullptr)
    {
        cout << "Veiculo nao encontrado." << endl;
        return;
    }

    cout << "Veiculo encontrado:" << endl;
    cout << "Placa: " << veiculo->getPlaca() << endl;  //informacoes do veiculo encontrado
    cout << "Marca: " << veiculo->getMarca() << endl;
    cout << "Modelo: " << veiculo->getModelo() << endl;
    cout << "Ano: " << veiculo->getAno() << endl;
    cout << "Preco: " << veiculo->getPreco() << endl;
    cout << "Tipo: " << veiculo->getTipo() << endl;
    cout << "Observacoes: " << veiculo->getObservacoes() << endl;

    char confirma;
    cout << "Deseja confirmar e excluir o veiculo? Digite S ou N: ";  //confirmacao
    cin >> confirma;

    if (confirma == 'S' || confirma == 's')
    {
        // Encontrar o  indice do veiculo no vetor VetVeiculos    //percorrendo o vetor para apagar o da placa fornecida
        int index = -1;
        for (int i = 0; i < Veiculos::getCountPlacas(); i++)
        {
            if (Veiculos::getVetVeiculos()[i].getPlaca() == placa)
            {
                index = i;
                break;
            }
        }

        // Se o ve culo foi encontrado, substituir por um objeto vazio
        if (index != -1)
        {
            Veiculos::getVetVeiculos()[index] = Veiculos();
            cout << "Veiculo excluido com sucesso!" << endl;
        }
    }
    else
    {
        cout << "Exclusao cancelada." << endl;
    }
}


void sair()  // funcao que termina o programa
{
    cout << "Encerrando o programa" << endl;
    exit(0);
}



int main()
{


    int opcao;

    do
    {
        opcao = menu();  //abre o menu assim que comeca o programa

        switch (opcao)  // escolher qual opcao do menu
        {
        case 6:
            listar();
            break;
        case 5:
            pesquisar();
            break;
        case 4:
            cadastrar();
            break;
        case 3:
            editar();
            break;
        case 2:
            excluir();
            break;
        case 1:
            sair();
            break;
        default:
            cout << "Opcao invalida. Digite um numero valido." << endl;
        }
    }
    while (opcao != 1);  // voltar pro menu toda vez ate que o usuario saia

    return 0;
}













