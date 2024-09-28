#include <stdbool.h>
#include <stdio.h>

const float valorIngresso = 30.50;
const int IDADE_MINIMA_MEIA_ENTRADA = 10;
const int IDADE_MAXIMA_MEIA_ENTRADA = 65;

char arr[4][20] = {"É assim que acaba", "Deadpool e Wolwerine",
                   "Divertidamente 2", "Armadilha"};

/* Calcula o valor do ingresso levando em conta a meia-entrada */
float calcularValorIngresso(int idade) {
  bool isMeiaEntrada =
      idade < IDADE_MINIMA_MEIA_ENTRADA || idade > IDADE_MAXIMA_MEIA_ENTRADA;

  if (isMeiaEntrada) {
    return valorIngresso / 2.0;
  }

  return valorIngresso;
}

/* Exibe os filmes disponíveis do cartaz */
void renderizarFilmesEmCartaz() {
  printf("Opções de Filmes Disponíveis\n");

  for (int idx = 0; idx < 4; idx++) {
    printf("%d.: %s\n", idx + 1, arr[idx]);
  }

  printf("\n");
}

/* Retorna o nome do filme baseado na opção */
char *getFilmeEscolhido(int opcao) {
  return arr[opcao - 1];
}

int main(void) {
  /* Inicializa as variáveis */
  int opcao,quantidade, idade;
  float valorTotal = 0.0f;

  renderizarFilmesEmCartaz();

  printf("Escolha uma das opções acima: ");
  scanf("%d", &opcao);

  /* Verifica se a opção informada é valida */
  if (opcao < 1 || opcao > 4) {
    printf("Opção inválida!\n");
    return 1;
  }

  printf("Quantos ingressos: ");
  scanf("%d", &quantidade);

  /* Seta quantidade como 1 caso o número fornecido seja menor que 1 */
  if (quantidade < 1) {
    quantidade = 1;
  }

  /* Soma o valor de cada ingresso de acordo com a quantidade*/
  for (int idx = 1; idx <= quantidade; idx++) {
    printf("Ingresso %d -> quantos anos? ", idx);
    scanf("%d", &idade);

  /* Verifica se a idade informada é valida */
    if (idade < 1 || idade > 140) {
      printf("Idade inválida!\n");
      return 1;
    }

    valorTotal += calcularValorIngresso(idade);
  }

  /* Exibe o resultado final */
  char *filmeEscolhido = getFilmeEscolhido(opcao);

  printf("Você escolheu o filme:\n%s, \no valor total é de R$%.2f\n",
         filmeEscolhido, valorTotal);

  return 0;
}
