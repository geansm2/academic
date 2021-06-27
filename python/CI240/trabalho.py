#coding=latin-1

from math import *
from string import *
import csv

#Função AbreArquivo
def AbreArquivo(arquivo):
    fp = open(arquivo, 'r')
    texto = fp.readlines()
    fp.close()
    return texto

#variaveis e listas
romance = AbreArquivo('romance.txt')
excessoes = AbreArquivo('excessoes.txt')
histograma = []
letras=[]
linha=''
repeticao = []


for linha in excessoes:
    descarta = linha.split()

for linha in romance:
    print (linha)
    
    frase = linha.split()
    
    for palavra in frase:
        print (palavra)
        print(palavra.isdigit())
        if palavra not in descarta:
            if palavra.isdigit() == False:
                letras.append(palavra[0])        

for ocorrencia in letras:
    #trata repetição
    if ocorrencia not in repeticao:
        repeticao.append(ocorrencia)
        print(ocorrencia, letras.count(ocorrencia))
        histograma.append([ocorrencia, letras.count(ocorrencia)])
    
print (letras)
print (histograma)


arquivo = open('histograma.csv', 'wb')
myfile = open('histograma.csv', 'wb')
wr = csv.writer(myfile, quoting=csv.QUOTE_ALL,'\n')
wr.writerow(histograma)
    
#palavras = AbreArquivo('palavras.txt')
