# Laboratorio de Sistemas Oeracionais - Grupo A
Repositório para a anexação de atividades de laboratório da disciplina de Sistemas Operacionais (4º semestre).

## Integrantes do grupo
- Daniel Kabadayan Dias

## EXERCÍCIOS
#### Exercício 1
Para criar três instâncias do objeto celula, podemos fazer o seguinte:
```c:
celula cel1, cel2, cel3;

cel1.conteudo = 10;
cel1.prox = &cel2;

cel2.conteudo = 20;
cel2.prox = &cel3;

cel3.conteudo = 30;
cel3.prox = NULL;
```

#### Exercício 2
```c:
void imprimeLista(celula *cabeca)
{
    celula *p = cabeca;
    while (p != NULL)
	{
        printf("%d ", p->conteudo);
        p = p->prox;
    }
    printf("\n");
}
```

#### Exercício 3
Sabendo que a quantidade de memória gasta por cada instância de celula é equivalente a soma dos campos "conteudo" e "prox", que são, respectivamente, dos tipos inteiro ("int") e ponteiro ("struct reg"), temos o seguinte:

- Em sistemas de 32 bits: 4 bytes para o campo "conteudo" + 4 bytes para o campo "prox" = 8 bytes por instância.
- Em sistemas de 64 bits: 4 bytes para o campo "conteudo" + 8 bytes para o campo "prox" = 12 bytes por instância.


Se utilizarmos essa lógica para calcularmos o valor de memória gasta para 3 instâncias de "celula", o resultado será:

- Em sistemas de 32 bits: 3 instâncias x 8 bytes por instância = 24 bytes no total.
- Em sistemas de 64 bits: 3 instâncias x 12 bytes por instância = 36 bytes no total.

#### Exercício 4
```c:
void removeLista(celula *lista)
{
    celula *atual = lista;
    celula *proxima;

    while (atual != NULL)
	{
        proxima = atual->prox;
        atual->prox = NULL;
        atual = proxima;
    }
}
```

#### Exercício 5
```c:
void removeLista(celula *lista)
{
    celula *atual = lista;
    celula *proxima;

    while (atual != NULL)
	{
        proxima = atual->prox;
        free(atual);	// Libera memória das células
        atual = proxima;
    }
}
```

#### Exercício 6
Podemos deduzir que o máximo de elementos possívels na fila encadeada, considerando a memória disponível no computador é igual a razão da quantidade de memória que o computador possui pelo tamanho que cada célula ocupa na fila.

```
max_elem = M / sizeof(celula), em que M = memória disponível no computador
```

Por exemplo, para um computador que possua 1 Gb de memória, ou 1024 bytes, podemos dizer que o máximo de elementos possíveis na fila será:

```
max_elem = 1 Gb / 8 bytes
max_elem = 134.217.728 elementos.
```

Resposta final: 134.217.728 elementos.
