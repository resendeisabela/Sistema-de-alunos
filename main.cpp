#include "include/programa.h"

int main() {
  lista alunos[MAX];  //declarando a lista de alunos e seus
  int acao;
  int quantAlunos = 0;
  
  while(true) {
  printf("\n");
  printf("1. Cadastrar novo aluno\n2. Buscar aluno\n");
  printf("3. Ler arquivo com listagem de alunos\n4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética\n");
  printf("5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética\n6. Fechar programa\n");

//entrada do usuário, informando a ação escolhida
  scanf("%d", &acao);

//condicionais do menu de ações
if(acao==1){  //chamar função cadastro
    int quantCadastro;
    printf("\nQuantidade de alunos a cadastrar: ");
    scanf("%d", &quantCadastro);
    
    for(int i=0;i<quantCadastro;i++){
        printf("\n");
        cadastro(alunos,quantAlunos);
      }

  }//if acao 1
  else if(acao==2){ //chamar função busca
    char pesquisa[MAX];
    
      printf("\nNome do aluno: ");
      scanf(" %[^\n]",pesquisa);

      int resultado = busca(alunos,quantAlunos,pesquisa);
      if(resultado>0)
        printf("\n");
      
  } //else if acao 2
  else if(acao==3){ //chamar função listaDeAlunos
    printf("Foram cadastrados %d alunos\n", listaDeAlunos(alunos, quantAlunos));
  }
  if(acao==4){
    char resultado[] = "aprovados";
    ordenar(alunos,quantAlunos,resultado);
  } 
  if(acao==5){
    char resultado[] = "reprovados";
    ordenar(alunos,quantAlunos,resultado);
  } 
  if(acao==6){
    char resultado[] = "atual";
    ordenar(alunos, quantAlunos, resultado);
    break;
  }

  else if(acao<1 && acao>6){
  printf("\nOpa, comando inválido. Tente novamente :)\n");}

} //fecha while
} //fecha main