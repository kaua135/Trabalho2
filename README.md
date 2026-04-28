# Torre de Hanoi em C++ com Pilha

## Descrição

Este projeto implementa o problema clássico da **Torre de Hanoi** em **C++**, utilizando a estrutura de dados **Pilha (Stack)** com alocação dinâmica.

O programa:

* Recebe a quantidade de discos (**mínimo 1 e máximo 10**)
* Inicializa a haste **A** com os discos corretamente empilhados
* Resolve automaticamente o problema usando **algoritmo recursivo**
* Exibe cada movimento realizado
* Mostra o estado atual das três hastes após cada jogada
* Exibe o número total de movimentos ao final

---

## Regras do Problema

Existem três hastes:

* **A** = origem
* **B** = auxiliar
* **C** = destino

Objetivo: mover todos os discos da haste **A** para a haste **C**, obedecendo:

1. Apenas um disco pode ser movido por vez.
2. Somente o disco do topo pode ser removido.
3. Um disco maior nunca pode ser colocado sobre um menor.

---

## Estrutura do Projeto

```
04-stack/
│── main.cpp
│── README.md
│
├── include/
│   └── stack.h
│
├── tests/
│   └── tests.cpp
│
├── build/
│
└── .vscode/
    ├── tasks.json
    └── launch.json
```

---

## Requisitos

### Compilador

Utilizar:

```
g++ 15 ou superior
```

Exemplo instalado:

```
g++ (Rev14, Built by MSYS2 project) 15.2.0
```

### Sistema Operacional

* Windows 10 ou superior

### IDE Recomendada

* Visual Studio Code

### Extensões Recomendadas

* C/C++
* C/C++ Extension Pack

---

## Compilação e Execução

### Via Terminal

Dentro da pasta do projeto:

```
bash

g++ main.cpp -Iinclude -o programa.exe
.\programa.exe
```

### Via Visual Studio Code

#### Compilar

```
Ctrl + Shift + B
```

#### Executar / Debug

```
F5
```

---

## Como o Programa Funciona

### 1. Entrada de Dados

O usuário informa a quantidade de discos:

```
Digite o numero de discos (1 a 10):
```

O programa valida para aceitar somente valores entre **1 e 10**.

---

### 2. Inicialização das Hastes

Todos os discos começam empilhados na haste **A**, do maior para o menor.

Exemplo para 3 discos:

```
A: [3, 2, 1]
B: []
C: []
```

---

### 3. Resolução Automática

O algoritmo utiliza **recursão** para resolver o problema automaticamente.

---

### 4. Exibição dos Movimentos

Após cada jogada, o programa mostra:

* Qual disco foi movido
* Torre de origem
* Torre de destino
* Estado atualizado das três hastes

Exemplo:

```
Mover disco 1 de A para C
A: [3, 2]   B: []   C: [1]
```

---

### 5. Finalização

Quando todos os discos chegam na torre **C**, o programa encerra mostrando:

```
Total de movimentos realizados: 7
```

---

## Exemplo Completo de Execução

```
===== TORRE DE HANOI =====
Digite o numero de discos (1 a 10): 3

Estado inicial:
A: [3, 2, 1]   B: []   C: []

Mover disco 1 de A para C
A: [3, 2]   B: []   C: [1]

Mover disco 2 de A para B
A: [3]   B: [2]   C: [1]

Mover disco 1 de C para B
A: [3]   B: [2, 1]   C: []

Mover disco 3 de A para C
A: []   B: [2, 1]   C: [3]

...

Total de movimentos realizados: 7
```

---

## Funções Principais

### mostrar_torre

Exibe uma haste sem alterar sua estrutura original.

### mostrar_estado

Mostra as três hastes no console.

### over_disco

Move um disco entre duas torres, registra o movimento e atualiza a tela.

### hanoi

Função recursiva principal responsável por resolver o problema.

### main

Controle:

* Entrada de dados
* Validação
* Inicialização
* Execução do algoritmo
* Finalização

---

## Perguntas Teóricas

### 1. Por que a Pilha é a estrutura de dados naturalmente adequada para modelar as hastes deste problema?

A Pilha segue a política de que o último elemento inserido é o primeiro a sair.

Na Torre de Hanoi, apenas o disco do topo pode ser movimentado. Isso corresponde exatamente ao comportamento de uma pilha.

Por isso, cada haste pode ser representada naturalmente por uma pilha.

---

### 2. Seria possível resolver este problema sem recursão? Se sim, como? Se não, por quê?

Sim, é possível.

Uma solução sem recursão pode ser implementada utilizando uma **pilha auxiliar** para simular manualmente as chamadas recursivas.

Também existem algoritmos iterativos baseados em sequências de movimentos.

A recursão é a forma mais simples e elegante, porém não é a única.

Por exemplo tem como fazer de forma manual onde o jogador escolhe onde as peças serão colocadas.

