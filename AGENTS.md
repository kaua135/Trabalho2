# AGENTS.md

## Descrição do Projeto

Exercício acadêmico de implementação de **Pilha (Stack)** em C++.

A pilha é uma estrutura LIFO (Last In First Out) com alocação encadeada (dinâmica).
As operações principais são:
- `push` (empilhar): insere elemento no topo
- `pop` (desempilhar): remove elemento do topo
- Tratamento de `overflow` (pilha cheia) e `underflow` (pilha vazia)

## Estrutura do Projeto

```
/
├── .vscode/
│   ├── tasks.json      # Tarefas de build (compilar projeto e testes)
│   └── launch.json     # Configuração de debug com GDB
├── build/              # Executáveis gerados (não versionado — ignorado pelo .gitignore)
│   ├── main            # Executável do programa principal
│   └── tests           # Executável dos testes
├── include/            # Headers (.h) — declarações da estrutura e funções da pilha
├── src/                # (vazio) implementacao em headers
├── tests/              # Testes automatizados
├── .gitignore          # Ignora a pasta build/ e outros artefatos gerados
└── main.cpp            # Ponto de entrada para demonstração manual
```

## Compilação e Execução

### Manual (terminal)

```bash
# Criar a pasta de build (se não existir)
mkdir -p build

# Compilar e executar o programa principal
g++ main.cpp -Iinclude -o build/main
./build/main

# Compilar e executar os testes
g++ tests/tests.cpp -Iinclude -o build/tests
./build/tests
```

### Via VSCode

- **Build project**: `Ctrl+Shift+B` (tarefa padrão definida em `.vscode/tasks.json`)
- **Build tests**: abrir a paleta de comandos (`Ctrl+Shift+P`) → "Tasks: Run Task" → "build tests"
- **Debug**: `F5` (usa a configuração definida em `.vscode/launch.json`)

> Sempre rode os testes após qualquer alteração e certifique-se que todos passam antes de concluir.

## Configuração do VSCode

### `.vscode/tasks.json`

Define duas tarefas de build, ambas com flag `-g` para suporte a debug com GDB.

```jsonc
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "create build dir",
            "type": "shell",
            "command": "mkdir",
            "args": ["-p", "${workspaceFolder}/build"],
            "problemMatcher": []
        },
        {
            "label": "build project",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/main.cpp",
                "-I${workspaceFolder}/include",
                "-o",
                "${workspaceFolder}/build/main"
            ],
            "dependsOn": ["create build dir"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Tarefa de compilação manual para debug com GDB."
        },
        {
            "label": "build tests",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/tests/tests.cpp",
                "-I${workspaceFolder}/include",
                "-o",
                "${workspaceFolder}/build/tests"
            ],
            "dependsOn": ["create build dir"],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": ["$gcc"],
            "detail": "Tarefa de compilação para os testes."
        }
    ]
}
```

### `.vscode/launch.json`

Configura o GDB para depurar o executável principal. Executa o build automaticamente antes de iniciar o debug via `preLaunchTask`.

```jsonc
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug project",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "preLaunchTask": "build project",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        },
        {
            "name": "Debug tests",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/tests",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "preLaunchTask": "build tests",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

## .gitignore

A pasta `build/` não deve ser versionada. O `.gitignore` mínimo do projeto:

```gitignore
# Executáveis e artefatos de build
build/

# Arquivos de objeto intermediários
*.o
*.out
```

## Convenções de Código

- Linguagem: **C++17**
- Nomeação: `snake_case` para funções e variáveis, `PascalCase` para structs/classes
- Um header por struct/classe em `/include`
- Sem uso de `std::stack` ou outras estruturas prontas da STL — a pilha deve ser implementada do zero
- Comentários em **português**

## Ferramentas

- Compilador: `g++` (GCC/G++)
- Debugger: `gdb`
- Editor recomendado: Visual Studio Code com extensão **C/C++** (ms-vscode.cpptools)
