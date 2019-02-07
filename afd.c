/*
-----------------------------------------------
developed by Lárisson Aquino
Agosto, 27, 2017
-----------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10000

int main(){

    printf("teste pull request");

    char alfabeto[MAXSIZE], transicao[MAXSIZE], input[MAXSIZE], op;
    int qtd_estados, estado_inicial, qtd_finais, i, j;
    
    printf("\nDesenvolvido por Larisson Aquino - FBUNI\nBrazil - Setembro, 2017\n\n");

    printf("Informe o alfabeto: ");
    gets(alfabeto);
    int tam_alfabeto = strlen(alfabeto);

    printf("Informe a quantidade de estados: ");
    scanf("%d", &qtd_estados);
    if(qtd_estados == 0){
        printf("\nQuantidade invalida!\n");
        exit(1);
    }
    int linhas = qtd_estados*qtd_estados*tam_alfabeto;
    char matriz[linhas][4];

    printf("Informe o estado inicial: ");
    setbuf(stdin, NULL);
    scanf("%d", &estado_inicial);
    setbuf(stdin, NULL);

    printf("Informe a quantidade de estados finais: ");
    scanf("%d", &qtd_finais);
    if(qtd_finais == 0){
        printf("\nQuantidade invalida!\n");
        exit(1);
    }
    int estados_finais[qtd_finais];

    printf("Informe o(s) estado(s) final(is): ");
    for(i=0; i<qtd_finais; i++)
        scanf("%d", &estados_finais[i]);

    printf("Informe as regras de transicao: ");
    setbuf(stdin, NULL);
    gets(transicao);

    int contador=0;
    for(i=0; i<linhas; i++){
        matriz[i][0] = transicao[contador++];
        matriz[i][1] = transicao[contador++];
        matriz[i][2] = transicao[contador++];
        contador++;
    }
/* //IMPRIME A MATRIZ DE TRANSIÇÃO
    for(i=0; i<20; i++){
        for(j=0; j<3; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
*/
entrada:
    printf("\nInforme sua entrada: ");
    setbuf(stdin, NULL);
    gets(input);

    int aux_final = estado_inicial;
    char *c, xchar;
    for(i=0, contador=0; i<linhas; i++, contador++){
        xchar = matriz[i][0];
        c = &xchar;
        
        if(atoi(c) == aux_final){
            if(input[contador] == matriz[i][1]){
                c = &matriz[i][2];
                *(c+1) = '\0';
                aux_final = atoi(c);
                i=-1;
            }else{
                contador--;
                continue;}
        }else{
            contador--;
            continue;
        }
    }

    for(i=0; i<qtd_finais; i++){
        if(estados_finais[i] == aux_final){
            printf("\nEntrada aceita!\n\n");
            printf("Deseja testar outra entrada? [s/n]\n\n");
            op = getch();
            if(op == 's' || op == 'S')
                goto entrada;
            else
                return 0;
        }
    }
    printf("\nEntrada rejeitada!\n\n");
    printf("Deseja testar outra entrada? [s/n]\n\n");
    op = getch();
    if(op == 's' || op == 'S')
        goto entrada;
    else
        return 0;
}
