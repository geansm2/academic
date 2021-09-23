---
title: "Projeto Integrador em Ciências de Dados e Inteligência Artificial III A"
author: "Gean Machado - 2019705"
date: "22/09/2021"
output: html_document
---

```{r setup, include=FALSE}
knitr::opts_chunk$set(echo = TRUE)
```

### Introdução

Este relatório demonstra as etapas de análise de dados numa abordagem da estatística descritiva. Com intuito de se compreender como os dados se comportam e que informações estão disponiveis nas observações catalogadas.

A análise de dados foi realizada usando a Linguagem R [https://www.r-project.org/]. O R é um ambiente de software livre para computação estatística e gráficos. Ele é compilado e executado em uma ampla variedade de plataformas UNIX, Windows e MacOS. Mantido pela The R Foundation

A base de dados adotada é `Islands`, uma base nativa da instalação do R que tem informações sobre o conjunto de dados das ilhas que pertencem às principais massas de terra.

### Análise

### Etapa 1:  Importação da base de dados
A base de dados possui um formato vetorial, tendo como fonte o livro The World Almanac and Book of Facts, 1975, página 406.

```{r}
data(islands)
```

Contendo o total de 48 observações

```{r}
length(islands)
```

### Etapa 2:  Média e mediana

Quando se pretende resumir dados quantitativos aproximadamente simétricos, é normal calcular a média aritmética como uma medida de locação.
A mediana (ou percentil 50) é definida como o valor que divide os dados ordenados ao meio.

```{r}
mean(islands)
median(islands)
```
`mean()` é uma função genérica para a média aritmética.
`median()` Calcula a mediana da amostra.

### Etapa 3:  Função range (maior e menor ilha)

```{r}
range(islands)[1]
range(islands)[2]
```

`range()` é uma função que retorna um vetor contendo o mínimo e o máximo de todos os argumentos fornecidos.
[1] e [2] indica a posição do vetor para acessar o valor mínimo e máximo.

### Etapa 4:  Desvio padrão (faixa de tamanho das ilhas) 

```{r}
sd(islands)
range(islands)[2] - range(islands)[1]
```

`sd()` calcula o desvio padrão dos valores em x. Se a base conter valores vazio, os valores ausentes serão removidos antes que o cálculo seja realizado.

### Etapa 5:  Função quantile

```{r}
quantile(islands)
quantile(islands, c(.05,.95))
```

Sabe-se que metade dos dados têm valores maiores e a outra metade tem valores menores do que a mediana. Adicionalmente, ainda é possivel subdividir essas duas metades, e defini-las como os valores abaixo dos quais estão um quarto e três quartos dos dados. Estes três valores são frequentemente usados para resumir os dados juntamente com o mínimo e o máximo. Eles são obtidos ordenando os dados do menor para o maior, e então conta-se o número apropriado de observações para o quartil inferior, mediana e quartil superior, respectivamente.

`quantile()` é uma função que produz os quantis de amostra correspondentes às probabilidades fornecidas. A menor observação corresponde a uma probabilidade de 0 e a maior a uma probabilidade de 1. 

### Etapa 6:  Intervalos interquartil

```{r}
IQR(islands)
```

IQR() calcula o intervalo interquartil dos valores de x. É uma medida de dispersão que mede a amplitude inter-quartis, que é a diferença entre o quartil superior e o inferior.

### Etapa 7:  Histograma

```{r}
hist(islands)
hist(islands,prob=T)
```

O método mais comum de apresentação de dados numéricos é o histograma. As áreas dos retângulos resultantes devem ser proporcionais à frequência.
`hist()` calcula um histograma dos valores de dados fornecidos. Se plot = TRUE, o objeto resultante da classe "histograma" é plotado por `plot.histogram`, antes de ser retornado. Os parametros da função inclui o tipo de distribuição de probabilidade, a densidade, os limites da legendas, classes e outros.

### Etapa 8: Boxblot (com e sem outliers)

```{r}
boxplot(islands)
boxplot(islands, outline = F)
```

`boxplot()` também é conhecido como diagrama de caixa, é uma forma pratica de plotar sumarização de dados (mínimo, quartil inferior, mediana, quartil superior, máximo), facilitando a visualização da distribuição das observações calculadas. Além disso facilita a observação de valores outliers. 

### Etapa 9:  Outliers do conjunto

```{r}
boxplot(islands, plot=F)$out
```

A função `boxplot()` possui uma lista de componentes, sendo uma deles o `out`	que retornar os valores que estejam além dos extremos das observações.

### Etapa 10: Plot sten e leaf

```{r}
stem(islands)

```

O gráfico de ramos e folhas é utilizado quando a quantidade de dados não é muito grande.

`stem()` produz um gráfico de ramos e folha dos valores em x. O parâmetro `scale` pode ser usado para expandir a escala do gráfico. Um valor de escala = 2 fará com que o gráfico seja aproximadamente o dobro do tamanho padrão.

### Considerações finais

Apesar do número pequeno de observações na base de dados, é possivel observar e explorar várias abordagem da analise descritiva afim de se conhecer melhor os dados.

### Referências

COSTA NETO, P. L. de O. Estatística Básica.

BUSSAB, W. O. & MORETTIN, P. A. . Estatística Básica. Atual Editora.

SOARES, J. F. . Introdução à Estatística. Guanabara Koogan.

MEYER, PL.. Probabilidade: Aplicações à Estatística.

GAUVREAU, K.; PAGANO, M.: Bioestatística