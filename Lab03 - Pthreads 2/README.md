# Laboratorio de Sistemas Oeracionais - Grupo A
Repositório para a anexação de atividades de laboratório da disciplina de Sistemas Operacionais (4º semestre).

### Integrantes do grupo
- Daniel Kabadayan Dias

### Seguem os arquivos pedidos no laboratório 03 - Pthreads 2 de Sistemas Operacionais
- PthreadsPI.c
- MutexPI.c
- README.md

#### Seguem as bibliotecas utilizadas e os respectivos exercícios em que aparecem
- PthreadsPI.c (<stdlib.h>, <pthreads.h>)
- MutexPI.c (<stdlib.h>, <pthreads.h>)

### Explicação dos exercícios
#### Exercício A
No caso do programa em questão, ele usa a série de Leibniz para aproximar o valor de pi. A série de Leibniz é uma série alternada que converge para pi/4, ou seja, quanto mais termos são somados, mais próximo do valor de pi a soma se aproxima.

No entanto, mesmo com um grande número de termos e usando múltiplas threads, o cálculo pode produzir divergências no resultado final. Essas divergências podem ser causadas por vários fatores, como a precisão das variáveis usadas no cálculo, erros de arredondamento e truncamento de números, e limitações de precisão da linguagem de programação ou da máquina utilizada para executar o programa.

Além disso, o uso de múltiplas threads pode introduzir problemas de concorrência, onde duas ou mais threads tentam acessar e modificar a mesma variável simultaneamente, o que pode levar a resultados incorretos ou imprevisíveis.

#### Exercício B
A única mudança no programa foi a adição de mutexes para garantir a exclusão mútua ao atualizar a variável compartilhada "sum". Essa mudança foi necessária para evitar condições de corrida que poderiam ocorrer quando várias threads tentam acessar e atualizar a mesma variável "sum" simultaneamente. O uso de mutexes garante que apenas uma thread pode acessar a variável "sum" de cada vez, garantindo a consistência do resultado final.


### Instruções para compilação de programas
Para compilar o arquivos com extensão .c deste diretório, basta acessar o diretório que contém o arquivo utilizando o comando "cd" do CMD do Windows e digitar o seguinte código: "gcc <nome_do_arquivo.c> -o <nome_do_executável>", caso o seu compilador seja o GCC.

### Comprovação dos resultados propostos
Para comprovara os resultados dos algoritmos e programas criados, basta compilá-los, conforme as instruções do tópico acima e, em sequencia, acessar o diretório onde se localizam os executáveis gerados utilizando o comando "cd" do CMD do Windows e digitar o nome do executável (./<nome_do_exercutável> caso seu sistema seja Linux/MacOS).
 
Desta maneira, o programa será inicializado no próprio terminal e estará disponível para uso e teste.