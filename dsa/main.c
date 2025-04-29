#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  char nome[50];
  int matricula;
  double g1,g2;
} Aluno;

struct Nodo {
  Aluno dado;
  struct Nodo *ant;
  struct Nodo *prox;
};
typedef struct Nodo nodo;

struct Descritor {
  int n;
  struct Nodo *prim;
  struct Nodo *ult;
};
typedef struct Descritor descritor;

void renderizarMenu() {
  printf("1. Cadastrar aluno\n");
  printf("2. Pesquisar aluno\n");
  printf("3. Remover aluno\n");
  printf("4. Encerrar programa\n");
}

void limparBuffer() {
  int c;
  while ( ( c = getchar() ) != '\n' && c != EOF ) {}
}

int inputNumeroMatricula() {
  int opcao;

  printf("Digite o número de matrícula: ");

  /**
   * NOTE: scanf retorna 1 quando lê um inteiro corretamente,
   * logo, quando diferente de 1 indica input inválido.
   */
  if ( scanf( "%d", &opcao ) != 1 ) {
    printf("[ERROR]: Input inválido! Informe apenas números.\n");
    limparBuffer();
    return inputNumeroMatricula();
  }

  return opcao;
}

int renderizarInput() {
  int opcao;

  printf("Digite uma opção: ");

  /**
   * NOTE: scanf retorna 1 quando lê um inteiro corretamente,
   * logo, quando diferente de 1 indica input inválido.
   */
  if ( scanf( "%d", &opcao ) != 1 ) {
    printf("[ERROR]: Input inválido! Informe apenas números.\n");
    limparBuffer();
    return renderizarInput();
  }

  if ( opcao < 1 || opcao > 4 ) {
    printf("[ERROR]: Opção inválida! Informe um número de 1 a 4.\n");
    return renderizarInput();
  }

  return opcao;
}

Aluno* renderizarCadastroAluno() {
  printf("========================\n");
  printf("Menu de Cadastro de Alunos\n");
  printf("========================\n");

  printf("1. Cadastrar \n");
  printf("2. Voltar \n");

  int opcao = renderizarInput();

  if ( opcao == 1 ) {
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno));

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno->nome);

    printf("Digite o número de matrícula: ");
    scanf("%d", &aluno->matricula);

    printf("Digite a nota da G1: ");
    scanf("%lf", &aluno->g1);

    printf("Digite a nota da G2: ");
    scanf("%lf", &aluno->g2);

    return aluno;
  }

  return NULL;
}

void iniciar( nodo *L, descritor *D ) {
  L->ant = NULL;
  L->prox = NULL;

  D->n = 0;
  D->prim = NULL;
  D->ult = NULL;
}

int estaVazia( descritor *D ) {
  if ( D->n == 0 ) {
    return 1;
  }

  return 0;
}

void inserirFinal( nodo *L, descritor *D, Aluno *aluno ) {
  nodo *novoNodo = (nodo *) malloc(sizeof(nodo));

  strcpy(novoNodo->dado.nome, aluno->nome);
  novoNodo->dado.matricula = aluno->matricula;
  novoNodo->dado.g1 = aluno->g1;
  novoNodo->dado.g2 = aluno->g2;

  if ( estaVazia( D ) ) {
    L->prox = novoNodo;

    novoNodo->ant = NULL;
    D->prim = novoNodo;
  } else {
    nodo *no = D->ult;
    novoNodo->ant = no;
    no->prox = novoNodo;
  }

  novoNodo->prox = NULL;
  D->ult = novoNodo;
  D->n++;
}

void imprimir( nodo *L, descritor *D, char ordem ) {
  if ( estaVazia( D ) ) {
    printf("Lista vazia!\n\n");
    return;
  }

  /* esquerda para a direita. */
  if ( ordem == 'i' ) {
    nodo *no = L->prox;
    printf("%-10s %-6s %-6s %-5s \n", "Nome", "G1", "G2", "Matrícula");
    while( no != NULL ) {
      printf("%-10s %-6.1f %-6.1f %-4d \n", no->dado.nome, no->dado.g1,
	     no->dado.g2, no->dado.matricula);
      no = no->prox;
    }

    printf("\n\n");
    return;
  }

  /* Direita para a esquerda */
  if ( ordem == 'f' ) {
    nodo *no = D->ult;
    printf("%-10s %-6s %-5s \n", "Nome", "G1", "Matricula");
    while ( no != NULL ) {
      printf("%-10s %-6.1f %-4d \n", no->dado.nome,
	     no->dado.g1, no->dado.matricula);
      no = no->ant;
    }

    printf("\n\n");
    return;
  }
}

void pesquisar( nodo *L, descritor *D, int numeroMatricula ) {
  if ( estaVazia( D ) ) {
    printf("Lista vazia!\n\n");
    return;
  }

  nodo *no = L->prox;
  bool encontrou = false;

  while ( no != NULL ) {
    if ( no->dado.matricula == numeroMatricula ) {
      printf("%-8s %-10s %-4s %-4s\n", "Matrícula", "Nome", "G1", "G2");
      printf("%-8d %-10s %.2f %.2f\n\n", no->dado.matricula, no->dado.nome,
             no->dado.g1, no->dado.g2);

      encontrou = true;
      break;
    }
    no = no->prox;
  }

  if ( !encontrou ) {
    printf("Não foram encontrados registros com número de matrícula %d", 
	   numeroMatricula);
  }

  printf("\n\n");
}

void exluirMeio( nodo *L, descritor *D, int numeroMatricula ) {
  if ( estaVazia( D ) ) {
    printf("Lista vazia!\n\n");
    return;
  }

  nodo *no = D->prim;

  while ( no != NULL ) {
    if ( no->dado.matricula == numeroMatricula ) {
      if ( no->ant != NULL ) {
	no->ant->prox = no->prox;
      } else {
	D->prim = no->prox;
      }

      if ( no->prox != NULL ) {
        no->prox->ant = no->ant;
      } else {
        D->ult = no->ant;
      }

      free( no );
      D->n--;
      printf("Aluno removido com sucesso!\n");
      return;
    }
    no = no->prox;
  }

  printf("Aluno não encontrado.\n");
}

void liberarLista(descritor *D) {
  nodo *no = D->prim;
  while (no != NULL) {
    nodo *temp = no;
    no = no->prox;
    free(temp);
  }
  free(D);
}

int main() {
  printf("===================\n");
  printf("Sistema de disciplinas\n");
  printf("===================\n");

  nodo *L = (nodo *) malloc(sizeof(nodo));
  descritor *D = (descritor *) malloc(sizeof(descritor));

  iniciar( L, D );

  while ( true ) {
    renderizarMenu();
    int opcao = renderizarInput();

    /*
     * Cadastrar Aluno.
     * */
    if ( opcao == 1 ) {
      while ( true ) {
	Aluno* aluno = renderizarCadastroAluno();

	if ( aluno == NULL ) {
	  break;
	}

	inserirFinal( L , D , aluno );
	imprimir( L, D, 'i' );
	free( aluno );
      }
    }

    /*
     * Pesquisar Aluno.
     * */
    if ( opcao == 2 ) {
      printf("Pesquisa de aluno por número de matrícula \n");
      int numeroMatricula = inputNumeroMatricula();
      pesquisar( L, D, numeroMatricula );
    }

    /*
     * Exluir Aluno.
     * */
    if ( opcao == 3 ) {
      printf("Informe o número de matrícula do aluno: \n");
      int numeroMatricula = inputNumeroMatricula();
      exluirMeio( L, D, numeroMatricula );
    }

    /*
     * Encerrar programa.
     * */
    if ( opcao == 4 ) {
      liberarLista( D );
      printf("Programa encerrado!\n");
      exit(0);
    }
  }

  return 0;
}

