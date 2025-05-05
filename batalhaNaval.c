#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;
    int linhaNavioVertical = 5;
    int colunaNavioVertical = 4;

    // Validação: Verifica se o navio horizontal cabe no tabuleiro
    if (colunaNavioHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora do limite do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
    }

    // Validação: Verifica se o navio vertical cabe no tabuleiro
    if (linhaNavioVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora do limite do tabuleiro.\n");
        return 1;
    }

    // Verifica se há sobreposição com o navio horizontal
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0) {
            sobreposicao = 1;
        }
    }

    // Se houver sobreposição, exibe erro e encerra
    if (sobreposicao) {
        printf("Erro: Os navios estão se sobrepondo.\n");
        return 1;
    }

    // Posiciona o navio vertical (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }

    // Exibe o tabuleiro no console
    printf("Tabuleiro da Batalha Naval:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
