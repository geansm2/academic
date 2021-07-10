/*
Desafio
Você deve fazer a leitura de 5 valores inteiros. Em seguida mostre quantos valores informados são pares, quantos valores informados são ímpares, quantos valores informados são positivos e quantos valores informados são negativos.

Entrada
Você receberá 5 valores inteiros.

Saída
Exiba a mensagem conforme o exemplo de saída abaixo, sendo uma mensagem por linha e não esquecendo o final de linha após cada uma.
*/
//Blibiotecas essenciais
import java.io.IOException;
import java.util.Scanner;

public class minhaClasse {
	public static void main(String[] args) throws IOException {
        //leitura das variaveis
		Scanner leitor = new Scanner(System.in);
		int v[] = new int[5];
        int par = 0;
        int imp = 0;
        int pos = 0;
        int neg = 0;

		//iteração do teste lógico
        for (int i = 0; i<5; i++) {
        	v[i] = leitor.nextInt();
          if(v[i] % 2 == 0 || v[i] == 0){
        	  par=par+1;
        	}else{
        	  imp=imp+1;
        	}
        	if(v[i] > 0){
        	  pos=pos+1;
        	}
        	if(v[i] < 0){
        	  neg=neg+1;
        	}
        }
		//exibição dos resultados
        System.out.println(par + " valor(es) par(es)");
        System.out.println(imp + " valor(es) impar(es)");
        System.out.println(pos + " valor(es) positivo(s)");
        System.out.println(neg + " valor(es) negativo(s)");
    }
}