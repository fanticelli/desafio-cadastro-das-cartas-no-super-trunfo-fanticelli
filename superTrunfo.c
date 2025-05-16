#include <stdio.h>

int main() {
//Definindo struct.
struct Carta {
    char estado, cidade[50], codigoCarta[4];
    float area, PIB;
    int populacao, pontosTuristicos;
};

struct Carta carta1, carta2;  

printf(" Bem vindo ao Super-Trunfo\n");
printf(" Vamos cadastrar suas cartas!\n");
// Cadastro das Cartas:

//ENTRADA DA PRIMEIRA CARTA.
printf("\n --- Carta 1 ---\n");

printf(" Digite a letra do estado (A-H): ");
scanf(" %c", &carta1.estado); //lê somente 1 caractere.

printf(" Digite o nome da cidade: ");
scanf(" %[^\n]", carta1.cidade); //lê até o user apertar enter.

printf(" Digite a quantidade de habitantes (sem pontos): ");
scanf("%d", &carta1.populacao);

printf(" Digite o tamanho da área em km²: ");
scanf("%f", &carta1.area);

printf(" Digite o PIB: ");
scanf("%f", &carta1.PIB);

printf(" Digite a quantidade de pontos turísticos: ");
scanf("%d", &carta1.pontosTuristicos);

printf(" Digite o código da carta: ");
scanf("%3s", carta1.codigoCarta); //limitando caracteres para evitar buffer overflow.

//ENTRADA DA SEGUNDA CARTA.
printf("\n --- Carta 2 ---\n");

printf(" Digite a letra do estado (A-H): ");
scanf(" %c", &carta2.estado); //lê somente 1 caractere.

printf(" Digite o nome da cidade: ");
scanf(" %[^\n]", carta2.cidade); //lê até o user apertar enter.

printf(" Digite a quantidade de habitantes: ");
scanf("%d", &carta2.populacao);

printf(" Digite o tamanho da área em km²: ");
scanf("%f", &carta2.area);

printf(" Digite o PIB: ");
scanf("%f", &carta2.PIB);

printf(" Digite a quantidade de pontos turísticos: ");
scanf("%d", &carta2.pontosTuristicos);

printf(" Digite o código da carta: ");
scanf("%3s", carta2.codigoCarta); //limitando caracteres para evitar buffer overflow.

system("clear"); //limpando o terminal.
    
// Exibição dos Dados das Cartas:
//EXIBIÇÃO DA PRIMEIRA CARTA.
printf("\n --- Carta 1 ---\n");
printf("Estado: %c\n", carta1.estado);
printf("Código: %s\n", carta1.codigoCarta);
printf("Nome da Cidade: %s\n", carta1.cidade);
printf("População: %d\n", carta1.populacao);
printf("Área: %.2f km²\n", carta1.area);
printf("PIB: %.2f bilhões de reais\n", carta1.PIB);
printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);

//EXIBIÇÃO DA SEGUNDA CARTA.
printf("\n --- Carta 2 ---\n");
printf("Estado: %c\n", carta2.estado);
printf("Código: %s\n", carta2.codigoCarta);
printf("Nome da Cidade: %s\n", carta2.cidade);
printf("População: %d\n", carta2.populacao);
printf("Área: %.2f km²\n", carta2.area);
printf("PIB: %.2f bilhões de reais\n", carta2.PIB);
printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);

return 0;
}