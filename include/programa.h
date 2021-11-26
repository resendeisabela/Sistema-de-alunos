// chamar funções
#include<stdio.h>
#include<string.h>
#define MAX 100

struct lista{
  char nome[MAX+1];
  int ra;
  double p1;
  double p2;
  double trab;
  double po;
  double resultadoFinal;
};
//cadastrar aluno
void cadastro(lista alunos[MAX], int &quant);

//buscar aluno
int busca(lista *alunos, int quant, char *pesquisa);

//calcular média final
double mediaFinal(lista *alunos, int num);

//lista de alunos
int listaDeAlunos(lista *novaLista, int &quant);

//gerar arquivo
void arquivo(lista *alunos, int quant, int aprovado);

//trocar posição dos alunos
void trocar(lista &aluno1, lista &aluno2);

//ordenar lista
void ordenar(lista *alunos, int quant, char *resultado);

//gerar lista de aprovados
void gerarAprovado(lista *alunos, int quant);

//gerar lista de reprovados
void gerarReprovado(lista *alunos, int quant);

//gerar lista atual
void gerarAtual(lista *alunos, int quant);