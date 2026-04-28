#ifndef STACK_H
#define STACK_H

#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

template <typename T>
struct Stack {
    Node<T>* top;
    size_t count;
    size_t max_size;

    void init(size_t max) {
        top = nullptr;
        count = 0;
        max_size = max;
    }

    void destroy() {
        Node<T>* atual = top;

        while (atual != nullptr) {
            Node<T>* prox = atual->next;
            delete atual;
            atual = prox;
        }

        top = nullptr;
        count = 0;
    }

    bool empty() {
        return count == 0;
    }

    bool is_full() {
        if (max_size == 0)
            return false;

        return count >= max_size;
    }

    bool push(T valor) {
        if (is_full())
            return false;

        Node<T>* novo = new Node<T>{valor, top};
        top = novo;
        count++;

        return true;
    }

    bool pop(T* saida) {
        if (empty())
            return false;

        Node<T>* temp = top;

        if (saida != nullptr)
            *saida = temp->value;

        top = top->next;

        delete temp;
        count--;

        return true;
    }

    bool peek(T* saida) {
        if (empty())
            return false;

        if (saida != nullptr)
            *saida = top->value;

        return true;
    }
};

#endif