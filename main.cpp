#include <iostream>
#include "stack.h"

using namespace std;

int movimentos = 0;

// Mostra torre sem perder os dados

void mostrar_torre(Stack<int>& torre)
{
    Stack<int> aux;
    aux.init(0);

    int valor;
    bool primeiro = true;

    cout << "[";

    while (!torre.empty())
    {
        torre.pop(&valor);
        aux.push(valor);
    }

    while (!aux.empty())
    {
        aux.pop(&valor);

        if (!primeiro)
            cout << ", ";

        cout << valor;
        primeiro = false;

        torre.push(valor);
    }

    cout << "]";
    aux.destroy();
}

// Mostra estado atual

void mostrar_estado(Stack<int>& A, Stack<int>& B, Stack<int>& C)
{
    cout << "A: ";
    mostrar_torre(A);

    cout << "   B: ";
    mostrar_torre(B);

    cout << "   C: ";
    mostrar_torre(C);

    cout << endl;
}

// Move disco entre torres

void mover_disco(Stack<int>& origem, Stack<int>& destino,
                 char nome_origem, char nome_destino,
                 Stack<int>& A, Stack<int>& B, Stack<int>& C)
{
    int disco;

    origem.pop(&disco);
    destino.push(disco);

    movimentos++;

    cout << "Mover disco "
         << disco
         << " de "
         << nome_origem
         << " para "
         << nome_destino
         << endl;

    mostrar_estado(A, B, C);
    cout << endl;
}

// Hanoi recursivo

void hanoi(int n,
           Stack<int>& origem,
           Stack<int>& auxiliar,
           Stack<int>& destino,
           char nome_origem,
           char nome_auxiliar,
           char nome_destino,
           Stack<int>& A,
           Stack<int>& B,
           Stack<int>& C)
{
    if (n == 1)
    {
        mover_disco(origem, destino,
                    nome_origem, nome_destino,
                    A, B, C);
        return;
    }

    hanoi(n - 1,
          origem, destino, auxiliar,
          nome_origem, nome_destino, nome_auxiliar,
          A, B, C);

    mover_disco(origem, destino,
                nome_origem, nome_destino,
                A, B, C);

    hanoi(n - 1,
          auxiliar, origem, destino,
          nome_auxiliar, nome_origem, nome_destino,
          A, B, C);
}

// main

int main()
{
    Stack<int> A, B, C;

    A.init(0);
    B.init(0);
    C.init(0);

    int n;

    cout << "===== TORRE DE HANOI =====" << endl;
    cout << "Digite o numero de discos (1 a 10): ";

    while (!(cin >> n) || n < 1 || n > 10)
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Valor invalido. Digite entre 1 e 10: ";
    }

    for (int i = n; i >= 1; i--)
    {
        A.push(i);
    }

    cout << endl;
    cout << "Estado inicial:" << endl;
    mostrar_estado(A, B, C);
    cout << endl;

    hanoi(n, A, B, C, 'A', 'B', 'C', A, B, C);

    cout << "Total de movimentos realizados: "
         << movimentos
         << endl;

    A.destroy();
    B.destroy();
    C.destroy();

    return 0;
}