#!/usr/bin/env python3

"""
Script de interface do usuario com uma tabela hash.
Usa o modulo python 'hash_table.py',

Comandos:
    'i {x}'
        Insere {x} na arvore AVL
    'r {x}'
        Remove {x} da arvore, se {x} pertence a mesma

Apos cada comando, a tabela eh desenhada,
"""

from hash_table import HashTable

table = HashTable()

def process_input(line):
    """
    Processa linha de input.
    Retorna 1 se a linha contem um comando valido (e o executa);
    Retorna 0 caso contrario
    """

    try:
        # separa a linha em comandos e argumentos
        command, arguments = line.split(maxsplit=1)
    except ValueError: # comando sem argumentos
        command = line

    # Comandos com argumentos:
    try:
        n = int(arguments)
    except: # Argumento invalido
        return 0

    if (command == "i"): # input na árvore 
        table.insert(n)
    elif (command == "r"): # remove da árvore
        table.remove(n)
    else: # comando nao encontrado
        return 0

    return 1


if __name__ == '__main__':
    try:
        line = input()
        while (line): # linha nao eh vazia
            if (not process_input(line)):
                print("Input inválido!")
            # table.print() # descomente essa linha para ver a evolução da tabela
            line = input()

    except (EOFError, KeyboardInterrupt):
        pass

    table.line_print()