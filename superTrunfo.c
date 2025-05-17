#include <stdio.h>
#include <stdlib.h>

//struct de dados para calculo.
struct dadosCalculados {
    float PIBperCapta, densidadePopulacional;
};
    
//Definindo struct das cartas.
struct Carta {
    char estado, cidade[50], codigoCarta[4];
    float area, PIB;
    int pontosTuristicos;
    unsigned long int populacao;
    struct dadosCalculados resultados; 
};

//struct para armazenamento do resultado do supe poder para comparação.
struct dadosSuperPoder {
    float superCarta1, superCarta2;
};

int main() {
    struct Carta carta1, carta2;
    struct dadosSuperPoder resultadoComparacao;

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

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta1.area);

    printf(" Digite o PIB (sem pontos e sem centavos): ");
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

    printf(" Digite a quantidade de habitantes (sem pontos): ");
    scanf("%lu", &carta2.populacao);

    printf(" Digite o tamanho da área em km² (sem pontos): ");
    scanf("%f", &carta2.area);

    printf(" Digite o PIB (sem pontos e sem centavos): ");
    scanf("%f", &carta2.PIB);

    printf(" Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    printf(" Digite o código da carta: ");
    scanf("%3s", carta2.codigoCarta); //limitando caracteres para evitar buffer overflow.

    system("clear"); //limpando o terminal.

    //Calculo PIB e Densidade da Carta 1.
    carta1.resultados.PIBperCapta = carta1.PIB / carta1.populacao; //PIB per Capta.
    carta1.resultados.densidadePopulacional = (float)carta1.populacao / carta1.area; //Densidade Populacional.

    //Calculo PIB e Densidade da Carta 2.
    carta2.resultados.PIBperCapta = carta2.PIB / carta2.populacao; //PIB per Capta.
    carta2.resultados.densidadePopulacional = (float)carta2.populacao / carta2.area; //Densidade Populacional.

    //Calculo do super poder.
    resultadoComparacao.superCarta1 = carta1.area + carta1.PIB + carta1.populacao + carta1.pontosTuristicos + carta1.resultados.PIBperCapta + carta1.resultados.densidadePopulacional;
    resultadoComparacao.superCarta2 = carta2.area + carta2.PIB + carta2.populacao + carta2.pontosTuristicos + carta2.resultados.PIBperCapta + carta2.resultados.densidadePopulacional;
        
    // Exibição dos Dados das Cartas:
    //EXIBIÇÃO DA PRIMEIRA CARTA.
    printf("\n --- Carta 1 ---\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigoCarta);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);

    //Identificação das casas milhões/bilhões.
    printf("PIB: %.2f %s de reais\n", 
        carta1.PIB >= 1000000000 ? carta1.PIB / 1000000000 : 
           (carta1.PIB >= 1000000 ? carta1.PIB / 1000000 : carta1.PIB),
           carta1.PIB >= 1000000000 ? "bilhões" : 
           (carta1.PIB >= 1000000 ? "milhões" : "reais"));

    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("PIB per Capta: %.2f reais\n", carta1.resultados.PIBperCapta);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.resultados.densidadePopulacional);
    printf("Super Poder: %.f\n", resultadoComparacao.superCarta1); // Exibindo o super poder


    //EXIBIÇÃO DA SEGUNDA CARTA.
    printf("\n --- Carta 2 ---\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigoCarta);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);

    //Identificação das casas milhões/bilhões.
    printf("PIB: %.2f %s de reais\n", 
        carta2.PIB >= 1000000000 ? carta2.PIB / 1000000000 : 
           (carta2.PIB >= 1000000 ? carta2.PIB / 1000000 : carta2.PIB),
           carta2.PIB >= 1000000000 ? "bilhões" : 
           (carta2.PIB >= 1000000 ? "milhões" : "reais"));
    
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("PIB per Capta: %.2f reais\n", carta2.resultados.PIBperCapta);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.resultados.densidadePopulacional);
    printf("Super Poder: %.f\n", resultadoComparacao.superCarta2); // Exibindo o super poder


    printf("\n --- Comparação das Cartas ---\n");
    
    printf(" População: %s\n",
    carta1.populacao > carta2.populacao ? "Carta 1 venceu!! (1)" :
    (carta2.populacao > carta1.populacao ? "Carta 2 venceu!! (0)" : "Empate!"));
    
    printf(" Área: %s\n",
    carta1.area > carta2.area ? "Carta 1 venceu!! (1)" : 
    (carta2.area > carta1.area ? "Carta 2 venceu!! (0)" : " Empate!"));
    
    printf(" PIB: %s\n",
    carta1.PIB > carta2.PIB ? "Carta 1 venceu!! (1)" : 
    (carta2.PIB > carta1.PIB ? "Carta 2 venceu!! (0)" : "Empate!"));
   
    printf(" Pontos Turisticos: %s\n",
    carta1.pontosTuristicos > carta2.pontosTuristicos ? "Carta 1 venceu!! (1)" : 
    (carta2.pontosTuristicos > carta1.pontosTuristicos ? "Carta 2 venceu!! (0)" : "Empate!"));
    
    // a carta com o menor valor vence
    printf(" Densidade Populacional: %s\n",
    carta1.resultados.densidadePopulacional < carta2.resultados.densidadePopulacional ? "Carta 1 venceu!! (1)" :
    (carta2.resultados.densidadePopulacional < carta1.resultados.densidadePopulacional ? "Carta 2 venceu!! (0)" : "Empate!"));
    
    printf(" PIB per Capta: %s\n",
    carta1.resultados.PIBperCapta > carta2.resultados.PIBperCapta ? "Carta 1 venceu!! (1)" : 
    (carta2.resultados.PIBperCapta > carta1.resultados.PIBperCapta ? "Carta 2 venceu!! (0)" : "Empate!"));
    
    printf(" Super Poder: %s\n",
    resultadoComparacao.superCarta1 > resultadoComparacao.superCarta2 ? "Carta 1 venceu!! (1)" : 
    (resultadoComparacao.superCarta2 > resultadoComparacao.superCarta1 ? "Carta 2 venceu!! (0)" : "Empate!"));


    return 0;
}