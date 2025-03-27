#include <stdio.h>

#include <stdio.h>
#include <string.h> // Biblioteca necessária para usar strcmp

// Definição da estrutura CartaSuperTrunfo
typedef struct {
    char estado[3];           // Estado da cidade (ex: SP, RJ)
    char codigo[10];          // Código identificador da carta
    char cidade[50];          // Nome da cidade
    int populacao;            // População da cidade
    float area;               // Área da cidade em km²
    float pib;                // PIB da cidade
    int pontos_turisticos;    // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional calculada
    float pib_per_capita;     // PIB per capita calculado
} CartaSuperTrunfo;

// Função para calcular a densidade populacional e PIB per capita
void calcularIndicadores(CartaSuperTrunfo *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

int main() {
    // Definição das cartas
    CartaSuperTrunfo carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 699000000000, 250};
    CartaSuperTrunfo carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1182.30, 362000000000, 200};
    
    // Calcula os indicadores das cartas
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);
    
    // Escolha do atributo para comparação
    char atributo_comparacao[] = "populacao"; // Modifique para "populacao", "area", "pib", "densidade_populacional" ou "pib_per_capita"
    
    float valor_carta1, valor_carta2;
    
    // Obtém os valores dos atributos a serem comparados
    if (strcmp(atributo_comparacao, "populacao") == 0) {
        valor_carta1 = carta1.populacao;
        valor_carta2 = carta2.populacao;
    } else if (strcmp(atributo_comparacao, "area") == 0) {
        valor_carta1 = carta1.area;
        valor_carta2 = carta2.area;
    } else if (strcmp(atributo_comparacao, "pib") == 0) {
        valor_carta1 = carta1.pib;
        valor_carta2 = carta2.pib;
    } else if (strcmp(atributo_comparacao, "densidade_populacional") == 0) {
        valor_carta1 = carta1.densidade_populacional;
        valor_carta2 = carta2.densidade_populacional;
    } else if (strcmp(atributo_comparacao, "pib_per_capita") == 0) {
        valor_carta1 = carta1.pib_per_capita;
        valor_carta2 = carta2.pib_per_capita;
    } else {
        printf("Atributo inválido!\n");
        return 1; // Encerra o programa se o atributo não for válido
    }
    
    // Determina a carta vencedora
    CartaSuperTrunfo *vencedora;
    if (strcmp(atributo_comparacao, "densidade_populacional") == 0) {
        // Para densidade populacional, vence a menor
        vencedora = (valor_carta1 < valor_carta2) ? &carta1 : &carta2;
    } else {
        // Para os demais atributos, vence a maior
        vencedora = (valor_carta1 > valor_carta2) ? &carta1 : &carta2;
    }
    
    // Exibe o resultado da comparação
    printf("Comparação de cartas (Atributo: %s):\n\n", atributo_comparacao);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, valor_carta1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.cidade, carta2.estado, valor_carta2);
    printf("Resultado: Carta vencedora - %s (%s)!\n", vencedora->cidade, vencedora->estado);
    
    return 0; // Finaliza o programa com sucesso
}
