# Exercícios de Backtracking

Este repositório contém implementações de dois problemas clássicos de algoritmos e estruturas de dados, frequentemente resolvidos utilizando **backtracking** e **busca combinatória**.

---

# 1️⃣ Problema das N-Rainhas

## Descrição

O problema das **N-Rainhas** consiste em posicionar **N rainhas em um tabuleiro de xadrez N × N** de forma que **nenhuma rainha ataque outra**.

No xadrez, uma rainha pode atacar:

* na **mesma linha**
* na **mesma coluna**
* nas **diagonais**

O objetivo é encontrar todas as possíveis configurações válidas.

---

## Entrada

O usuário informa um valor inteiro **N**, que representa:

* número de rainhas
* tamanho do tabuleiro

```
N = 8
```

---

## Saída

O programa deve imprimir **todas as configurações possíveis** utilizando a seguinte legenda:

| Símbolo | Significado  |
| ------- | ------------ |
| R       | Rainha       |
| -       | Espaço vazio |

### Exemplo de solução para N = 8

```
- - - R - - - -
- R - - - - - -
- - - - - R - -
- - R - - - - -
- - - - - - R -
R - - - - - - -
- - - - R - - -
- - - - - - - R
```

---

# 2️⃣ Problema das K-Partições

## Descrição

Dado um vetor **V de números inteiros positivos**, o objetivo é encontrar diferentes formas de **dividir o vetor em subconjuntos disjuntos**, de forma que:

* todos os elementos sejam utilizados
* todos os subconjuntos tenham **a mesma soma**

---

## Exemplo de entrada

```
V = { 7, 3, 5, 12, 2, 1, 5, 3, 8, 4, 6, 4 }
```

---

## Resultados esperados

### Partição em 2 subconjuntos

Soma de cada subconjunto = **30**

```
S1 = { 5, 3, 8, 4, 6, 4 }
S2 = { 7, 3, 5, 12, 2, 1 }
```

---

### Partição em 3 subconjuntos

Soma de cada subconjunto = **20**

```
S1 = { 2, 1, 3, 4, 6, 4 }
S2 = { 7, 5, 8 }
S3 = { 3, 5, 12 }
```

---

### Partição em 4 subconjuntos

Soma de cada subconjunto = **15**

```
S1 = { 1, 4, 6, 4 }
S2 = { 2, 5, 8 }
S3 = { 12, 3 }
S4 = { 7, 3, 5 }
```

---

### Partição em 5 subconjuntos

Soma de cada subconjunto = **12**

```
S1 = { 2, 6, 4 }
S2 = { 8, 4 }
S3 = { 3, 1, 5, 3 }
S4 = { 12 }
S5 = { 7, 5 }
```

---

# 🧠 Conceitos utilizados

* Backtracking
* Busca combinatória
* Recursão
* Particionamento de conjuntos
* Problemas clássicos de otimização

---

# 🎯 Objetivo do projeto

Praticar técnicas de **exploração de espaço de busca** e **resolução de problemas combinatórios**, fundamentais em áreas como:

* algoritmos
* in
