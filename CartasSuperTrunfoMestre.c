#include <stdio.h>
#include <string.h>

typedef struct {
    char codigo[4];            
    char estado;                
    int cidade_num;             
    long populacao;             
    float area;                 
    long pib;                   
    int pontos_turisticos;      
    float densidade_populacional; 
    float pib_per_capita;       
    float super_poder;          
} Carta;

// Função para cadastrar uma nova carta
Carta cadastrarCarta(char estado, int cidade_num) {
    Carta c;
    sprintf(c.codigo, "%c%02d", estado, cidade_num);
    c.estado = estado;
    c.cidade_num = cidade_num;

    printf("\n--- Cadastro da Carta %s ---\n", c.codigo);
    printf("População: ");
    scanf("%ld", &c.populacao);
    printf("Área (km²): ");
    scanf("%f", &c.area);
    printf("PIB (R$): ");
    scanf("%ld", &c.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    // Cálculos do nível Aventureiro
    c.densidade_populacional = c.populacao / c.area;
    c.pib_per_capita = (float)c.pib / c.populacao;

    // Cálculo do Super Poder (nível Mestre)
    c.super_poder = (c.populacao * 0.2) + (c.area * 0.1) + (c.pib * 0.3) + (c.pontos_turisticos * 0.4);

    return c;
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta c) {
    printf("\n--- Dados da Carta %s ---\n", c.codigo);
    printf("Estado: %c\n", c.estado);
    printf("Cidade: %d\n", c.cidade_num);
    printf("População: %ld\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %ld\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: R$ %.2f\n", c.pib_per_capita);
    printf("Super Poder: %.2f\n", c.super_poder);
}

// Função para comparar duas cartas
void compararCartas(Carta c1, Carta c2) {
    printf("\n🆚 Comparando %s vs %s:\n", c1.codigo, c2.codigo);
    
    printf("1. População: %s vence!\n", (c1.populacao > c2.populacao) ? c1.codigo : c2.codigo);
    printf("2. Área: %s vence!\n", (c1.area > c2.area) ? c1.codigo : c2.codigo);
    printf("3. PIB: %s vence!\n", (c1.pib > c2.pib) ? c1.codigo : c2.codigo);
    printf("4. Pontos Turísticos: %s vence!\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.codigo : c2.codigo);
    printf("5. Densidade Pop.: %s vence! (menor é melhor)\n", (c1.densidade_populacional < c2.densidade_populacional) ? c1.codigo : c2.codigo);
    printf("6. PIB per capita: %s vence!\n", (c1.pib_per_capita > c2.pib_per_capita) ? c1.codigo : c2.codigo);
    printf("7. Super Poder: %s vence!\n", (c1.super_poder > c2.super_poder) ? c1.codigo : c2.codigo);
}

// Menu principal
void menu() {
    printf("\n🌟 Super Trunfo de Países - Menu Principal 🌟\n");
    printf("1. Cadastrar novas cartas\n");
    printf("2. Exibir cartas cadastradas\n");
    printf("3. Comparar cartas\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Carta cartas[32];  
    int num_cartas = 0;
    int opcao;
    
    do {
        menu();
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: {
                if(num_cartas >= 32) {
                    printf("Limite de cartas atingido!\n");
                    break;
                }
                
                char estado;
                int cidade_num;
                
                printf("Estado (A-H): ");
                scanf(" %c", &estado);
                estado = toupper(estado);
                
                if(estado < 'A' || estado > 'H') {
                    printf("Estado inválido! Use de A a H.\n");
                    break;
                }
                
                printf("Número da cidade (1-4): ");
                scanf("%d", &cidade_num);
                
                if(cidade_num < 1 || cidade_num > 4) {
                    printf("Número de cidade inválido! Use de 1 a 4.\n");
                    break;
                }
                
                cartas[num_cartas] = cadastrarCarta(estado, cidade_num);
                num_cartas++;
                break;
            }
            
            case 2: {
                if(num_cartas == 0) {
                    printf("Nenhuma carta cadastrada ainda!\n");
                    break;
                }
                
                printf("\n--- Cartas Cadastradas ---\n");
                for(int i = 0; i < num_cartas; i++) {
                    exibirCarta(cartas[i]);
                }
                break;
            }
            
            case 3: {
                if(num_cartas < 2) {
                    printf("Cadastre pelo menos 2 cartas para comparar!\n");
                    break;
                }
                
                int c1, c2;
                printf("\n--- Comparar Cartas ---\n");
                printf("Cartas disponíveis (%d):\n", num_cartas);
                for(int i = 0; i < num_cartas; i++) {
                    printf("%d. %s\n", i+1, cartas[i].codigo);
                }
                
                printf("Escolha a primeira carta (1-%d): ", num_cartas);
                scanf("%d", &c1);
                printf("Escolha a segunda carta (1-%d): ", num_cartas);
                scanf("%d", &c2);
                
                if(c1 < 1 || c1 > num_cartas || c2 < 1 || c2 > num_cartas) {
                    printf("Seleção inválida!\n");
                    break;
                }
                
                compararCartas(cartas[c1-1], cartas[c2-1]);
                break;
            }
            
            case 4:
                printf("Saindo do jogo...\n");
                break;
                
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 4);

    return 0;
}