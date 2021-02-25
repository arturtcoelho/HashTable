# My Hash Table

Esse trabalho foi realizado por Artur Temporal Coelho e Gabriel Nascarella Hishida do Nascimento para a disciplina de Algoritmos e Estrutura de dados III do ERE 2, em Janeiro de 2021

# Arquivos
- hash_table.h: Define tamanhos e a struct utilizada
- hash_table.c: Implementação das funções de hash e código principal de IO   

# Como funciona

As funções de busca, inserção e remoção se baseiam nas funções h1 e h2 para realizar as operações nas tabelas, utilizando ambas conforme necessário.

Existem duas tabelas para resolver algumas colisões, alocando um valor na tabela disponivel com o indice correspondente

## Funções

- hash_initialize(): Aloca memória e inicializa os valores;
- h1() e h2(): Funções de hash, principal e complementares;
- hash_search(): procura uma chave nas tabelas;
- hash_insert(): Insere uma chave na tabela;
- hash_remove(): Remove uma chave da tabela;

## Funções complementares

- hash_print(): imprime os elementos presentes na tabela, a sua posição e a qual tabela pertence
