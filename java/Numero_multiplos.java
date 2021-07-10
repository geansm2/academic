/*
Leia 2 valores inteiros (A e B). Após, o programa deve mostrar uma mensagem "Sao Multiplos" ou "Nao sao Multiplos", indicando se os valores lidos são múltiplos entre si.

Entrada
A entrada contém valores inteiros.

Saída
A saída deve conter uma das mensagens conforme descrito acima.
*/
//Blibiotecas essenciais
import java.io.IOException;
import java.util.Scanner;

public class Classe{
    
    public static void main(String[] args) throws IOException {
        //Leitura dos números
		Scanner leitor = new Scanner(System.in);
        int valor_a = leitor.nextInt();
        int valor_b = leitor.nextInt();
        //conferência lógica
		if (valor_a % valor_b == 0 || valor_b % valor_a == 0) {
            System.out.println("Sao Multiplos");
        } else {
            System.out.println("Nao sao Multiplos");
        }
    }
    
}