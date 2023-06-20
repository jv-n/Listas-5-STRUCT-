#include <stdio.h>
#include <string.h>
#include <math.h>

/* Seu metodo consiste em calcular um fator vantagem subtraindo o ataque de seu Pokemon pela defesa de seu inimigo. 
Porem eh importante notar que certos tipos de Pokemon possuem vantagem contra outros. 
Isso significa que quando o tipo de um Pokemon for efetivo em relacao a outro seu ataque aumentara em 50%.

Agua é efetivo contra fogo; Grama contra agua; Fogo contra grama.

Em caso de eficiency igual, ordene alfabeticamente.*/


typedef struct {
    char nome[50];
    char tipo[7];
    float ataque;
    float defesa;
} pokemon;


int main(){

    char temp[50];
    pokemon enemy;
    int pokedex_size;
    int troca;

    scanf(" %49[^' '] %6[^' '] %f%f", enemy.nome, enemy.tipo, &enemy.ataque, &enemy.defesa);
    scanf("%d", &pokedex_size);

    pokemon pokedex[pokedex_size];

    for(int i = 0; i<pokedex_size; i++)
    {
        scanf(" %49[^' '] %6[^' '] %f%f", pokedex[i].nome, pokedex[i].tipo, &pokedex[i].ataque, &pokedex[i].defesa);
    }

    for(int i = 0; i<pokedex_size; i++)
    {
        if(enemy.tipo[0] == 'a' && pokedex[i].tipo[0] == 'g')
        {
            pokedex[i].ataque = pokedex[i].ataque + (pokedex[i].ataque*0.5);
        }
        else if(enemy.tipo[0] == 'g' && pokedex[i].tipo[0] == 'f')
        {
            pokedex[i].ataque = pokedex[i].ataque + (pokedex[i].ataque*0.5);
        }
        else if(enemy.tipo[0] == 'f' && pokedex[i].tipo[0] == 'a')
        {
            pokedex[i].ataque = pokedex[i].ataque + (pokedex[i].ataque*0.5);
        }
    }

    float vantagem[pokedex_size];
    float vant_temp;

    for (int i = 0; i<pokedex_size; i++)
    {
        vantagem[i] = pokedex[i].ataque - enemy.defesa;
    }
    
    do{
        troca = 0;

        for (int i = 1; i<pokedex_size; i++)
        {
            if (vantagem[i-1]<vantagem[i])
            {
                strcpy(temp, pokedex[i].nome);
                strcpy(pokedex[i].nome, pokedex[i-1].nome);
                strcpy(pokedex[i-1].nome, temp);
                vant_temp = vantagem[i];
                vantagem[i] = vantagem[i-1];
                vantagem [i-1] = vant_temp;
                troca = 1;
            }
            else if (vantagem[i] == vantagem[i-1])
            {
                if (pokedex[i].nome[0]<pokedex[i-1].nome[0])
                {
                    strcpy(temp, pokedex[i].nome);
                    strcpy(pokedex[i].nome, pokedex[i-1].nome);
                    strcpy(pokedex[i-1].nome, temp);
                    troca = 1;
                }
                else if (pokedex[i-1].nome[0] == pokedex[i].nome[0]) //se a primeira letra for igual
                {
                    for (int j = 0; j<50; j++) // analisa as letras subsequentes
                    {
                        if (pokedex[i-1].nome[j]>pokedex[i].nome[j]) // achou uma fora da ordem
                        {
                            strcpy(temp, pokedex[i].nome);
                            strcpy(pokedex[i].nome, pokedex[i-1].nome);
                            strcpy(pokedex[i-1].nome, temp);
                            troca = 1;
                        }
                        if (pokedex[i-1].nome[j]<pokedex[i].nome[j]) // esta ordenado
                        {
                            break;
                            troca = 0;
                        }
                    }
                }
            }
        }

    } while (troca == 1);

    for (int i = 0; i<pokedex_size; i++)
    {
        printf ("%d. %s\n", i+1, pokedex[i].nome);
    }
    
    return 0;
}
