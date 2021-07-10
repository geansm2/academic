*/
Desafios
Crie um programa que leia um número e mostre os números pares até esse número, inclusive ele mesmo.

Entrada
Você receberá 1 valor inteiro N, onde N > 0.

Saída
Exiba todos os números pares até o valor de entrada, sendo um em cada linha. 
*/
//Bibliotecas essenciais
import java.io.IOException;
import java.util.Scanner;

public class Par{
	  public static void main(String[] args) throws IOException {
	  //leitura e conferência lógica
	  Scanner scan = new Scanner(System.in);
	    
      int numero = scan.nextInt();
      for (int i = 1 ; i <= numero  ; i++) {
    		if (i % 2 == 0 ) System.out.println(i);
    	}
    }
	
}