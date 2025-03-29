#include <stdio.h>
#include <string.h>

struct CartaSuperTrunfo {
    char estado;
    char codigo[4]; 
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional; 
    float pibPerCapita;         
};

void lerCarta(struct CartaSuperTrunfo *carta, int numeroCarta) {
    printf("\nInserindo dados da Carta %d:\n", numeroCarta);
    
    // Estado (A-H)
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    while (carta->estado < 'A' || carta->estado > 'H') {
        printf("Estado inválido. Digite uma letra de A a H: ");
        scanf(" %c", &carta->estado);
    }
    
    // Código da Carta (Estado + 01-04)
    printf("Código da Carta (%c01-%c04): ", carta->estado, carta->estado);
    scanf("%s", carta->codigo);
    while (strlen(carta->codigo) != 3 || 
           carta->codigo[0] != carta->estado ||
           carta->codigo[1] < '0' || carta->codigo[1] > '0' ||
           carta->codigo[2] < '1' || carta->codigo[2] > '4') {
        printf("Código inválido. Digite no formato %c01-%c04: ", carta->estado, carta->estado);
        scanf("%s", carta->codigo);
    }
    
    // Nome da Cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // Lê até encontrar uma nova linha
    
    // População
    printf("População: ");
    scanf("%d", &carta->populacao);
    
    // Área
    printf("Área (em km²): ");
    scanf("%f", &carta->area);
    
    // PIB
    printf("PIB: ");
    scanf("%f", &carta->pib);
    
    // Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    
    // Calcular novos atributos
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void exibirCarta(struct CartaSuperTrunfo carta, int numeroCarta) {
    printf("\nDados da Carta %d:\n", numeroCarta);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
}

int main() {
    struct CartaSuperTrunfo carta1, carta2;
    
    printf("=== SUPER TRUNFO - Cadastro de Cartas ===\n");
    
    // Ler os dados das duas cartas
    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);
    
    // Exibir os dados das duas cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);
    
    return 0;
}