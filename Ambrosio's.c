#include <stdio.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
    int hora;
    int minuto;
}horario;

typedef struct{

    int passagem;
    data partida;
    char saida[50];
    char destino[50];
    horario time;
    int poltrona;
    int idade;
    char nome[50];

}passageiro;

int main(){

    
    passageiro ficha[44];
    float media = 0;
    int total_idade = 0;
    int quantos = 0;
    
    for (int i = 0; i<44; i++)
    {
        scanf("%d", &ficha[i].passagem);
        if(ficha[i].passagem == -1)
        {
            break;
        } else 
            {
            scanf("%d/%d/%d", &ficha[i].partida.dia, &ficha[i].partida.mes, &ficha[i].partida.ano);
            scanf(" %49[^\n]", ficha[i].saida);
            scanf(" %49[^\n]", ficha[i].destino);
            scanf("%d:%d", &ficha[i].time.hora, &ficha[i].time.minuto);
            scanf("%d", &ficha[i].poltrona);
            scanf("%d", &ficha[i].idade);
            scanf(" %49[^\n]", ficha[i].nome);
            quantos++;
            }
    }


    for (int j = 0; j<quantos; j++){
        total_idade = total_idade + ficha[j].idade;
    }

    media = total_idade/quantos;

    for (int j = 0; j<quantos; j++)
    {
        if (ficha[j].idade>media){
            if(ficha[j].poltrona%2==0){
                printf("%s\n", ficha[j].nome);
            }
        }
    }

    return 0;
}