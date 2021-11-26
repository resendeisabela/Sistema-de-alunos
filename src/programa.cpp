// construção das funções
#include "../include/programa.h"

//função para cadastrar aluno
void cadastro(lista novaLista[MAX], int &quant) {

  printf("Nome completo: ");
  scanf(" %[^\n]", novaLista[quant].nome);

  printf("RA: ");
  scanf("%d", &novaLista[quant].ra);

  printf("P1: ");
  scanf("%lf", &novaLista[quant].p1);

  printf("P2: ");
  scanf("%lf", &novaLista[quant].p2);

  printf("Trabalho: ");
  scanf("%lf", &novaLista[quant].trab);

  printf("PO: ");
  scanf("%lf", &novaLista[quant].po);
  
  novaLista[quant].resultadoFinal=mediaFinal(novaLista, quant);
  
  quant++;
}

//função para calcular a média
double mediaFinal(lista *alunos, int num){
  double po = alunos[num].po;
  double p1 = alunos[num].p1;
  double p2 = alunos[num].p2;
  double trab = alunos[num].trab;

  if(po>p1 || po>p2){
    if(p1<p2)
      p1=po;
    else
      p2=po;
  }
  
  double nota = (0.35*p1 )+ (0.35*p2) + (0.3*trab);

  return nota;
}

//função para buscar aluno
int busca(lista *alunos, int quant, char *pesquisa) {
  if(quant==0){
    return 0;
  }

  else{
   int cont=0;
   int tam=strlen(pesquisa);
   for(int i=0; i<quant; i++){
     if(strncasecmp(alunos[i].nome, pesquisa, tam)==0){
      printf("\nNome: %s\n", alunos[i].nome);
      printf("Média Final: %.1lf\n", alunos[i].resultadoFinal);
      cont++; //incrementa a variável contadora

       if(alunos[i].resultadoFinal>=6.0){
        printf("APROVADO\n");
      }
      else{
        printf("REPROVADO\n");
      }
     }
   }
    return printf("\nResultado da busca: %d\n",cont);
  }
}

//função para ler arquivo
int listaDeAlunos(lista *novaLista, int &quant){
  FILE *alunos;
  char nomeDoArquivo[MAX+1];
  int count=quant; //atribuindo a quantidade de alunos já cadastrados à variável local count

  printf("\nNome do arquivo: ");
  scanf(" %[^\n]",nomeDoArquivo);
  alunos = fopen(nomeDoArquivo,"r");
  
  if(alunos==NULL){
      printf("Erro, tente novamente\n");
  }
  
  else{
  while(true){
    int entrada = fscanf(alunos," %[^0123456789]",novaLista[quant].nome); //leitura do nome, que segue lendo até identificar o início do RA (um número)

    if(entrada==EOF){
      printf("Arquivo lido com sucesso!\n");
      break;
    }

    fscanf(alunos,"%d",&novaLista[quant].ra);
    fscanf(alunos,"%lf",&novaLista[quant].p1);
    fscanf(alunos,"%lf",&novaLista[quant].p2);
    fscanf(alunos,"%lf",&novaLista[quant].trab);
    fscanf(alunos,"%lf",&novaLista[quant].po);
    novaLista[quant].resultadoFinal=mediaFinal(novaLista, quant);
    quant++;
  }
  fclose(alunos);
  }
  return quant-count; //retorna quantos alunos foram cadastrados através do arquivo 
}

//função para gerar aquivo de aprovados
void gerarAprovado(lista *alunos, int quant){
  FILE *aprovados;
  aprovados= fopen("aprovados.txt", "w+");
  int count=0;

  if(aprovados==NULL){
    printf("Erro, tente novamente\n");
  }
  for(int i=0; i<quant; i++){
    if(alunos[i].resultadoFinal>=6.0){
      fprintf(aprovados, "%s %d %.1f\n", alunos[i].nome, alunos[i].ra, alunos[i].resultadoFinal);
      count++; 
    }
  }
  fprintf(aprovados, "Total: %d", count);
  fclose(aprovados);
}
//função para gerar aquivo de reprovados
void gerarReprovado(lista *alunos, int quant){
  FILE *reprovados;
  reprovados= fopen("reprovados.txt", "w+");
  int count=0;

  if(reprovados==NULL){
    printf("Erro, tente novamente");
  }
  for(int i=0; i<quant; i++){
    if(alunos[i].resultadoFinal<6.0){
      fprintf(reprovados, "%s %d %.1f\n", alunos[i].nome, alunos[i].ra, alunos[i].resultadoFinal);
      count++;
    }
  }
  fprintf(reprovados, "Total: %d", count);
  fclose(reprovados);
}
//função para  gerar arquivo atual
void gerarAtual(lista *alunos, int quant){
  FILE *atual;
  atual=fopen("atual.txt", "w+"); 
  int count=0;

  if(atual==NULL){
    printf("Erro, tente novamente");
  }
  for(int i=0; i<quant; i++){
      fprintf(atual, "%s %d %.1f %.1f %.1f %.1f\n", alunos[i].nome, alunos[i].ra, alunos[i].p1, alunos[i].p2, alunos[i].trab, alunos[i].po);
      count++;
  }
  fprintf(atual, "Total: %d", count);
  fclose(atual);
}

//função para trocar posições
void trocar(lista &aluno1, lista &aluno2){
  lista aux;
  aux=aluno1;
  aluno1=aluno2;
  aluno2=aux;
}

//função para ordenar arquivo por ordem alfabética
void ordenar(lista *alunos, int quant, char *resultado){
  for(int i=0; i<quant-1; i++){
    for(int j=i+1; j<quant; j++){
      if(strcmp(alunos[i].nome, alunos[j].nome)>0){
        trocar(alunos[i], alunos[j]);
      }
      else if(strcmp(alunos[i].nome, alunos[j].nome)==0){
        if(alunos[i].ra>alunos[j].ra){
          trocar(alunos[i], alunos[j]);
        }
      }
    }
  }
  if(strcmp("aprovados", resultado)==0){
    gerarAprovado(alunos, quant);
  }
  else if(strcmp("reprovados", resultado)==0){
    gerarReprovado(alunos, quant);
  }
  else if(strcmp("atual", resultado)==0){
    gerarAtual(alunos, quant);
  }
}

