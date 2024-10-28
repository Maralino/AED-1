#include <stdio.h>

#define TAM 9

// Função para ler uma matriz 9x9 da entrada padrão.
void le_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para verificar se as linhas e colunas da matriz contêm todos os números de 1 a 9 sem repetição.
// Retorna 1 se válido e 0 se houver duplicação ou número fora do intervalo [1,9].
int confere_matriz_linhas_colunas(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        int linha[TAM + 1] = {0};  // Contador de frequência para linha
        int coluna[TAM + 1] = {0}; // Contador de frequência para coluna

        for (int j = 0; j < TAM; j++) {
            int valor_linha = matriz[i][j];
            int valor_coluna = matriz[j][i];

            // Valores devem estar no intervalo [1,9] para serem válidos.
            if (valor_linha < 1 || valor_linha > 9 || valor_coluna < 1 || valor_coluna > 9) {
                return 0;
            }

            linha[valor_linha]++;
            coluna[valor_coluna]++;

            // Cada valor deve aparecer no máximo uma vez na linha e coluna.
            if (linha[valor_linha] > 1 || coluna[valor_coluna] > 1) {
                return 0;
            }
        }
    }
    return 1; // Todas as linhas e colunas estão válidas
}

// Função para verificar se cada submatriz 3x3 contém todos os números de 1 a 9 sem repetição.
// Retorna 1 se cada submatriz for válida e 0 caso contrário.
int confere_submatrizes(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i += 3) {
        for (int j = 0; j < TAM; j += 3) {
            int submatriz[TAM + 1] = {0}; // Contador de frequência para submatriz 3x3

            // Varre cada submatriz 3x3
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int valor = matriz[i + k][j + l];
                    submatriz[valor]++;

                    // Cada valor deve aparecer no máximo uma vez na submatriz
                    if (submatriz[valor] > 1) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1; // Todas as submatrizes 3x3 estão válidas
}

int main() {
    int n, matriz[TAM][TAM];

    // Leitura do número de matrizes
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        le_matriz(matriz);

        // Verifica linhas e colunas, além das submatrizes 3x3
        int matriz_linhas_colunas = confere_matriz_linhas_colunas(matriz);
        int matriz_submatrizes = confere_submatrizes(matriz);

        // Exibe o resultado
        printf("Instancia %d\n", i + 1);
        if (matriz_linhas_colunas && matriz_submatrizes) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n"); // Linha em branco entre as instâncias
    }

    return 0;
}
