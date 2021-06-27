/********************************************************************
Programa: P2-Carlos.c
Descrição: Programa de notas com arquivos
Data: 21/11/2009 11:29
Local: TO-BRASIL
Autor: Gean Machado, Mauro Junior
********************************************************************/

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definiçoes
#define SIZE 100

//Estruturas
typedef struct dados{
    char curso[25];
    int turma;
    int periodo;
    char disciplina[25];
    char nome[30];
    float p1,p2,pi,exm,media;
} alunos;

//Variáveis globais
int x=0;
alunos aluno[SIZE];
FILE *fp;

/***********************************************************
*Função: exame()
*Descrição: computa as notas caso precise de exame
*Parametros: n1, n2, ni, exm
*Retorno: float
************************************************************/
float exame(float n1, float n2, float ni, float exm)
{
    return((n1+n2+ni+exm)/2);
}
/***********************************************************
*Função: inserir()
*Descrição: Execulta o cadastro de novos alunos ao programa
*Parametros: Nenhum
*Retorno: void
************************************************************/
void inserir(){
    char repeat;
    do{
        system("cls");
        printf("\t\t=========================\n");
        printf("\t\t =    INSERIR ALUNOS    =\n");
        printf("\t\t=========================\n\n");
        if(x==SIZE){
            printf("\nLista Cheia!\n\n");
            system("pause");
            return;
        }
        fflush(stdin);
        printf("Nome do aluno: "); gets(aluno[x].nome);
        
        do{
            printf("Nota P1: ");   scanf("%f",&aluno[x].p1);
                if(aluno[x].p1<0 || aluno[x].p1>4){
                    printf("\nErro!, nota maior que 4 ou menor que 0, redigite a nota!\n\n");
                }
        }while(aluno[x].p1<0 || aluno[x].p1>4);
        
        do{
            printf("Nota P2: ");   scanf("%f",&aluno[x].p2);
                if(aluno[x].p2<0 || aluno[x].p2>4){
                    printf("\nErro!, nota maior que 4 ou menor que 0, redigite a nota!\n\n");
                }
        }while(aluno[x].p2<0 || aluno[x].p2>4);   
        
        do{
            printf("Nota PI: ");   scanf("%f",&aluno[x].pi);
            if(aluno[x].pi<0 || aluno[x].pi>2){
                printf("\nErro!, nota maior que 2 ou menor que 0, redigite a nota!\n\n");
            }
        }while(aluno[x].pi<0 || aluno[x].pi>2);
        
        aluno[x].exm=0;
        aluno[x].media=(aluno[x].p1+aluno[x].p2+aluno[x].pi);//Calcula a media final.
        
        if(aluno[x].media>=5 && aluno[x].media<7){//analisa necessidade de exame
            do{                           
                printf("Digite nota do exame: ");
                scanf("%f",&aluno[x].exm);
                if(aluno[x].exm<0 || aluno[x].exm>10)
                    printf("\nErro!, nota maior que 10 ou menor que 0, redigite a nota!\n\n");
            }while(aluno[x].exm<0 || aluno[x].exm>10);
            aluno[x].media=exame(aluno[x].p1,aluno[x].p2,aluno[x].pi,aluno[x].exm);//função calculo de exame com passagem de PARAMETRO.  
        }
                  
        x++;
        printf("\nCadastro concluido com sucesso!");   getchar();
        printf("\n\nDeseja adicionar outro Aluno? [S]im ou [N]ao: ");
        scanf("%c", &repeat);
    }while (repeat=='s' || repeat=='S');
}

/***********************************************************
*Função: editar()
*Descrição: Execulta o edicão de alunos presentes no programa
*Parametros: Nenhum
*Retorno: void
************************************************************/
void editar(){
    char nome[30];
    int i, j=0;

    system("cls");
    printf("\t\t=========================\n");
    printf("\t\t =    EDITAR ALUNOS     =\n");
    printf("\t\t=========================\n");
    if(x==0){
        printf("\nNao ha Alunos! Adicione!\n\n");
        system("pause");
    }
    else{
        system("cls");
        printf("\t\t=========================\n");
        printf("\t\t =    EDITAR ALUNOS     =\n");
        printf("\t\t=========================\n");
        printf("\nNomes\n");
        for (j=0;j<=x;j++){
            printf("%s\n",aluno[j].nome);//lista todos os alunos disponíveis.
        }
        printf("\nPara alterar o Aluno, digite o nome: ");
        fflush(stdin);
        gets(nome);
        for (i=0;i<x;i++){
            if (!strcmp(aluno[i].nome, nome)){//compara a string digitada, com algum nome da lista.
                fflush(stdin); 
                 printf("\nDados atuais cadastrados:\n");
                printf("Nome:       %s\n",aluno[i].nome);
                printf("P1:         %.2f\n",aluno[i].p1);
                printf("P2:         %.2f\n",aluno[i].p2);
                printf("PI:         %.2f\n",aluno[i].pi);
                if(aluno[i].exm>0){
                    printf("Exame:      %.1f\n",aluno[i].exm);
                }
                
                printf("\nObs.:\nEm caso de escrever ' ' (espaco)\nsubstitua por '_' underline\n\n");
                
                printf("\nDigite os novos dados para altera-los: \n");
                fflush(stdin);
                printf("Nome do aluno: "); gets(aluno[i].nome);
                
                do{
                    printf("Nota P1: ");  scanf("%f",&aluno[i].p1);
                    if(aluno[i].p1<0 || aluno[i].p1>4){
                        printf("\nErro!, nota maior que 4 ou menor que 0, redigite a nota!\n\n");
                        }
                }while(aluno[i].p1<0 || aluno[i].p1>4);
                
                do{
                    printf("Nota P2: ");  scanf("%f",&aluno[i].p2);
                    if(aluno[i].p2<0 || aluno[i].p2>4){
                        printf("\nErro!, nota maior que 4 ou menor que 0, redigite a nota!\n\n");
                    }
                }while(aluno[i].p2<0 || aluno[i].p2>4);   
            
                do{
                    printf("Nota PI: ");  scanf("%f",&aluno[i].pi);
                        if(aluno[i].pi<0 || aluno[i].pi>2){
                        printf("\nErro!, nota maior que 2 ou menor que 0, redigite a nota!\n\n");
                    }
                }while(aluno[i].pi<0 || aluno[i].pi>2);
                
                aluno[i].exm=0;
                aluno[i].media=(aluno[i].p1+aluno[i].p2+aluno[i].pi);
                
                if(aluno[i].media>=5 && aluno[i].media<7){         
                    do{
                        printf("Digite nota do exame: ");  scanf("%f",&aluno[i].exm);
                    }while(aluno[i].exm<0 || aluno[i].exm>10);
                    aluno[i].media=exame(aluno[i].p1,aluno[i].p2,aluno[i].pi,aluno[i].exm);//função calculo de exame  
                }
                printf("\nDados alterados com sucesso!\n\n");
                system("pause"); 
            }
        }
    }
}

/***********************************************************
*Função: pesquisar()
*Descrição: Execulta uma pesquisa (exibir nome e notas)
*Parametros: Nenhum
*Retorno: void
************************************************************/
void pesquisar(){
    char nome[30];
    int i, j=0;
    
    system("cls");
    printf("\t\t=========================\n");
    printf("\t\t =  PESQUISAR ALUNOS    =\n");
    printf("\t\t=========================\n");
    
    if(x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
	} 
    else{
        fflush(stdin);
        printf("\nDigite o nome: ");    gets(nome);
        for (i=0; i<x; i++){
            if (!strcmp(aluno[i].nome, nome)){ 
                j=1;
                printf("\nNome: %s\nNota P1: %.1f\nNota P2: %.1f\nNota PI: %.1f\n", aluno[i].nome, aluno[i].p1, aluno[i].p2,aluno[i].pi);
            
                if(aluno[i].exm>0){
                    printf("Exame: %.1f\n",aluno[i].exm);
                }
                printf("\nPesquisa Concluida\n");
                getchar();
            }
        }
        if(j==0){
            printf("\nAluno nao encontrado!\n\n");
            system("pause");
        }
    }
}

/***********************************************************
*Função: listar_alunos()
*Descrição: Exibi uma lista de alunos (sem as notas)
*Parametros: Nenhum
*Retorno: void
************************************************************/
void listar_alunos(){
    int i;
    system("cls");
    printf("\t\t=========================\n");
    printf("\t\t =   LISTA DE ALUNOS    =\n");
    printf("\t\t=========================\n");
    if (x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
    }
    else{  
        for(i=0; i<x; i++){
            printf("%s\n",aluno[i].nome);
        }
        printf("\nConsta cadastrados -%i- alunos\n",x);
        printf("\n");
        system("pause");
    }
}

/***********************************************************
*Função: listar_alunos()
*Descrição: Exibi uma lista de notas (nome do aluno, todas as
            notas, média final)
*Parametros: Nenhum
*Retorno: void
************************************************************/
void listar_notas(){
    int i;
    
    system("cls");
    printf("\t\t=========================\n");
    printf("\t\t =    LISTA DE NOTAS    =\n");
    printf("\t\t=========================\n");
    if (x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
    }
    else{
        for(i=0; i<x; i++){
            printf("Aluno: %s\n",aluno[i].nome);
            printf("P1:    %.1f\n",aluno[i].p1);
            printf("P2:    %.1f\n",aluno[i].p2);
            printf("PI:    %.1f\n",aluno[i].pi);
            if(aluno[i].exm>0){
                printf("Exame: %.1f\n",aluno[i].exm);
            }
            printf("Media: %.1f\n",aluno[i].p1+aluno[i].p2+aluno[i].pi);
                  
            printf("---------------------------\n");
        }
       
        printf("\n");
        system("pause");
    }
}

/***********************************************************
*Função: listar_aprovados()
*Descrição: Exibi uma lista de alunos aprovados
*Parametros: Nenhum
*Retorno: void
************************************************************/
void alunos_aprovados(){
    system("cls");
    int i, j=0;
    
    system("cls");
    printf("\t\t======================\n");
    printf("\t\t=  ALUNOS APROVADOS  =\n");
    printf("\t\t======================\n");
    if(x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
	} 
    else{
        i=0;
        do{
            if(aluno[i].media>=7){
                printf("%s", aluno[i].nome);
                if(aluno[i].exm>0){
                    printf(" EX");
                }
                printf("\n");
            }
            i++;
        }while(i<x);
        printf("\n");
        system("pause");
    }
}

/***********************************************************
*Função: listar_reprovados()
*Descrição: Exibi uma lista de alunos reprovados
*Parametros: Nenhum
*Retorno: void
************************************************************/
void alunos_reprovados(){
    int i, j=0;
    
    system("cls");
    printf("\t\t=======================\n");
    printf("\t\t=  ALUNOS REPROVADOS  =\n");
    printf("\t\t=======================\n");
   
    if(x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
	} 
    else{
        i=0;
        do{
            if(aluno[i].media<5){
                printf("%s\n", aluno[i].nome);
            }
            i++;
        }while(i<x);
        printf("\n");
        system("pause");
    }
}

/***********************************************************
*Função: relatorio_completo()
*Descrição: Relatório completo (nota média na P1, nota média
            na P2, nota média da PI, aluno com maior nota fi-
            nal, aluno com menor nota final)
*Parametros: Nenhum
*Retorno: void
************************************************************/
void relatorio_completo(){
    float n_maior, n_menor,media_p1=0,media_p2=0, media_pi=0;
    int i; int j=0;
    int p_maior=0, p_menor=0;
    
    system("cls");
    printf("\t\t========================\n");
    printf("\t\t=  RELATORIO COMPLETO  =\n");
    printf("\t\t========================\n");
    if(x==0){
        printf("\nNao ha Alunos Cadastrados! Adicione!\n\n");
        system("pause");
	} 
    else{
        n_maior=aluno[0].media;
        n_menor=aluno[0].media;
         
        for(i=0; i<x; i++){
            if(n_maior < aluno[i].media)
            {
                n_maior = aluno[i].media;
                p_maior=i; //Posiçao da media MAIOR
            }
            if(n_menor > aluno[i].media)
            {
                n_menor = aluno[i].media;
                p_menor=i; //Posiçao da media MENOR
            }
        } 
        
        for(i=0; i<x; i++){
        media_p1=(aluno[i].p1+media_p1);
        media_p2=(aluno[i].p2+media_p2);
        media_pi=(aluno[i].pi+media_pi);
        }

        printf("Media na P1: %.1f\n",(media_p1/x));
        printf("Media na P2: %.1f\n",(media_p2/x));
        printf("Media na PI: %.1f\n",(media_pi/x));
        printf("Nome: %s - Media: %1.f MEDIA MAIOR\n",aluno[p_maior].nome,aluno[p_maior].media);
        printf("Nome: %s - Media: %1.f MEDIA MENOR\n",aluno[p_menor].nome,aluno[p_menor].media);
        system("pause");
    }
}                     

/***********************************************************
*Função: salva()
*Descrição: Salva os arquivos da memoria no arquivo de txt
*Parametros: Nenhum
*Retorno: void
************************************************************/
void salva(){
    fp=fopen("Banco_de_dados.txt","w"); // Abre o arquivo no modo de escrita...
    if (fp==NULL){
        printf("ERRO FATAL: Impossivel Criar Arquivo de Dados\n");
        system("pause");
        exit(0);
    }
    
    
        fprintf(fp,"%s\n",aluno[0].curso);
        fprintf(fp,"%i\n",aluno[0].turma);
        fprintf(fp,"%i\n",aluno[0].periodo);
        fprintf(fp,"%s\n",aluno[0].disciplina);    
    int i;
    for(i=0; i<x; i++){
        fprintf(fp,"%s\n",aluno[i].nome);  
        fprintf(fp,"%0.f\n",aluno[i].p1);
        fprintf(fp,"%0.f\n",aluno[i].p2);
        fprintf(fp,"%0.f\n",aluno[i].pi);
        fprintf(fp,"%0.f\n",aluno[i].exm);
        if(i+1 == x) //para nao escrever \n no final do arquivo...
        fprintf(fp,"%0.f",aluno[i].media);
        else
        fprintf(fp,"%0.f\n",aluno[i].media);
    }
    fclose(fp);
}

/***********************************************************
*Função: carrega()
*Descrição: ler os dados no txt e armazena na memoria
*Parametros: Nenhum
*Retorno: void
************************************************************/
void carrega(){
    fp=fopen("Banco_de_dados.txt","r"); // Abre o arquivo no modo de leitura...
       if (fp==NULL){
           printf("ERRO FATAL: Impossivel Abrir Arquivo\n");
           system("pause");
           exit(0);
       }
    
    int i;
        fscanf(fp,"%s",&aluno[0].curso);
        fscanf(fp,"%i",&aluno[0].turma);
        fscanf(fp,"%i",&aluno[0].periodo);
        fscanf(fp,"%s",&aluno[0].disciplina);
        
    do{ // ate que chegue ao fim do arquivo...
        fscanf(fp,"%s",&aluno[x].nome);
        fscanf(fp,"%f",&aluno[x].p1);
        fscanf(fp,"%f",&aluno[x].p2);
        fscanf(fp,"%f",&aluno[x].pi);
        fscanf(fp,"%f",&aluno[x].exm);
        fscanf(fp,"%f",&aluno[x].media);   

        x++;        
    }while (!feof(fp));
    fclose(fp);   
}
/***********************************************************
*Função: main()
*Descrição: função principal do progrma
*Parametros: Nenhum
*Retorno: int
************************************************************/
int main(){
    carrega();
    int opcao;
    do{
        system("cls");
        printf("\t    Code Source by GEAN PAULO and MAURO JUNIOR\n");
        printf("\t\t ===============================\n");
        printf("\t\t =     Calculo Notas Catolica  =\n");
        printf("\t\t ===============================\n");
        printf("\t\t|                               |\n");
	    printf("\t\t|       1: INSERIR ALUNOS       |\n");
	    printf("\t\t|       2: PESQUISAR ALUNOS     |\n");
        printf("\t\t|       3: EDITAR ALUNOS        |\n");
	    printf("\t\t|       4: LISTA DE ALUNOS      |\n");
	    printf("\t\t|       5: LISTA DE NOTAS       |\n");
	    printf("\t\t|       6: ALUNOS APROVADOS     |\n");
	    printf("\t\t|       7: ALUNOS REPROVADOS    |\n");
        printf("\t\t|       8: RELATORIO COMPLETO   |\n");
	    printf("\t\t|       0: SAIR                 |\n");
	    printf("\t\t|                               |\n");
        printf("\t\t ================================\n");
	    printf("\t\t  Consta cadastrados -%i- alunos\n",x);
        printf("\t\t  OPCAO: ");  scanf("%d", &opcao);
	    switch(opcao)
        {
	        case 1:	inserir();	          break;
	        case 2:	pesquisar();          break;
	        case 3: editar();             break;
	        case 4: listar_alunos();      break;
	        case 5:	listar_notas();	      break;
            case 6: alunos_aprovados();   break;
            case 7: alunos_reprovados();  break;
            case 8: relatorio_completo(); break;
        }
    }while(opcao!=0);
    salva();
    return 0;
}
