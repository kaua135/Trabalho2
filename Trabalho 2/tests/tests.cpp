#include <iostream>
#include "../include/stack.h"

using namespace std;

int main() {
    Stack<int> pilha;
    pilha.init(5);

    cout << "===== TESTES DA PILHA =====" << endl;

    if (pilha.empty())
        cout << "Teste 1 OK - Pilha inicia vazia" << endl;
    else
        cout << "Teste 1 ERRO" << endl;

    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    if (pilha.size() == 3)
        cout << "Teste 2 OK - Push funcionando" << endl;
    else
        cout << "Teste 2 ERRO" << endl;

    int topo;

    if (pilha.peek(&topo) && topo == 30)
        cout << "Teste 3 OK - Peek funcionando" << endl;
    else
        cout << "Teste 3 ERRO" << endl;

    int valor;

    pilha.pop(&valor);

    if (valor == 30)
        cout << "Teste 4 OK - Pop funcionando" << endl;
    else
        cout << "Teste 4 ERRO" << endl;

    if (pilha.size() == 2)
        cout << "Teste 5 OK - Size funcionando" << endl;
    else
        cout << "Teste 5 ERRO" << endl;
    pilha.push(40);
    pilha.push(50);
    pilha.push(60);

    if (pilha.is_full())
        cout << "Teste 6 OK - Pilha cheia" << endl;
    else
        cout << "Teste 6 ERRO" << endl;

    while (!pilha.empty())
        pilha.pop(nullptr);

    if (!pilha.pop(nullptr))
        cout << "Teste 7 OK - Underflow tratado" << endl;
    else
        cout << "Teste 7 ERRO" << endl;

    pilha.destroy();

    return 0;
}