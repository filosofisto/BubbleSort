#include <iostream>
#include <time.h>
#include <iomanip>
#include <cmath>

#define QTD 4

using namespace std;

int gerarNumeros (int menor, int maior){
    return (menor + (rand()%maior));
}

void trocar(double vetor[], int de, int para)
{
    double temp = vetor[de];
    vetor[de] = vetor[para];
    vetor[para] = temp;
}

void ordenar(double vetor[]){
    for (int i = 0; i < QTD-1; i++) {
        for (int j = 0; j < QTD - i - 1; j++) {
            if (vetor[j] > vetor[j+1]) {
                trocar(vetor, j, j+1);
            }
        }
    }
}

void show(double vetor[])
{
    for (int i=0; i<QTD; i++){
        cout << std::fixed << std::setprecision( 2 ) << vetor[i] << " - ";
    }

    cout << endl;
}

struct Pessoa
{
    string name;
    int idade;
};

void trocar(struct Pessoa vetor[], int de, int para)
{
    struct Pessoa temp = vetor[de];
    vetor[de] = vetor[para];
    vetor[para] = temp;
}

void ordenar(struct Pessoa vetor[]){
    for (int i = 0; i < QTD-1; i++) {
        for (int j = 0; j < QTD - i - 1; j++) {
            if (vetor[j].idade > vetor[j+1].idade) {
                trocar(vetor, j, j+1);
            } else if (vetor[j].idade == vetor[j+1].idade) { // Se empatar no criterio de idade, testa o criterio de nome
                if (vetor[j].name > vetor[j+1].name) {
                    trocar(vetor, j, j+1);
                }
            }
        }
    }
}

int main()
{
    struct Pessoa pessoas[4] = {
            { "Eduardo", 48 },
            { "Zulema", 70 },
            { "Jose", 20 },
            { "Hanae", 20 }
    };

    ordenar(pessoas);

    for (int i = 0; i < QTD; i++) {
        cout << pessoas[i].name << " " << pessoas[i].idade << endl;
    }
}

int main2()
{
    double alunos[QTD];
    int alturas;
    int i, j;
    srand(time(NULL));

    for (i=0; i< QTD; i++){
        alturas = gerarNumeros(100,200);
        alunos[i] = floorf(alturas)/100; //me limita a 2 casas decimais de alturas;
    }

    cout << "Array original" << endl;
    show(alunos);

    cout << "Ordenando...";
    ordenar(alunos);
    cout << "ok" << endl;

    cout << "Array ordenado" << endl;
    show(alunos);

    return 0;
}