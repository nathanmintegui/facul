#include <stdbool.h>
#include <stdio.h>

const float valorIngresso = 30.50;
const int idadeMinimaMeiaEntrada = 10;
const int idadeMaximaMeiaEntrada = 65;

char arr[4][20] = {"É assim que acaba", "Deadpool e Wolwerine",
                   "Divertidamente 2", "Armadilha"};

float calcularValorIngresso(int idade) {
  bool isMeiaEntrada =
      idade < idadeMinimaMeiaEntrada || idade > idadeMaximaMeiaEntrada;

  if (isMeiaEntrada) {
    return valorIngresso / 2.0;
  }

  return valorIngresso;
}

void renderizarFilmesEmCartaz() {
  printf("Opções de Filmes Disponíveis\n");

  for (int idx = 0; idx < 4; idx++) {
    printf("%d.: %s\n", idx + 1, arr[idx]);
  }

  printf("\n");
}

char *getFilmeEscolhido(int opcao) { return arr[opcao - 1]; }

int main(void) {
  int opcao;
  int quantidade;
  int idade;
  float valorTotal;

  renderizarFilmesEmCartaz();

  printf("Escolha uma das opções acima: ");
  scanf("%d", &opcao);

  if (opcao < 1 || opcao > 4) {
    printf("Opção inválida");
    return 0;
  }

  printf("Quantos ingressos: ");
  scanf("%d", &quantidade);

  if (quantidade < 1) {
    quantidade = 1;
  }

  for (int idx = 1; idx <= quantidade; idx++) {
    printf("Ingresso %d -> quantos anos? ", idx);
    scanf("%d", &idade);

    if (idade < 1 || idade > 140) {
      printf("Idade inválida");
      return 0;
    }

    valorTotal += calcularValorIngresso(idade);
  }

  char *filmeEscolhido = getFilmeEscolhido(opcao);

  printf("Você escolheu o filme:\n%s, \no valor total é de R$%.2f\n",
         filmeEscolhido, valorTotal);

  return 0;
}
