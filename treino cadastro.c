#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define TF 100
#define NAME 50

typedef struct
{
    char nome[NAME];
}dados;


void cadastro (dados d[], int *tl)
{
    char nome[NAME];
    int cad;
    int i;

    if(*tl==0)
    {
        printf("Nome: "); fflush(stdin);
        gets(d[*tl].nome);
        (*tl)++;
        printf("Sucesso ao cadastrar!\n");
    }
    else
    {
        printf("Nome: "); fflush(stdin);
        gets(nome);

        cad=0;
        for(i=0;i<*tl;i++)
        {
            if(stricmp(nome,d[i].nome)==0)
                cad=1;
        }
        if(cad!=0)
            printf("Nome ja cadastrado!\n");
        else
        {
            strcpy(d[*tl].nome,nome);
            (*tl)++;
            printf("Sucesso ao cadastrar!\n");
        }
    }
    system("pause");
}

void excluir (dados d[], int *tl)
{
    char nome[NAME];
    int i, pos, achou;
    printf("Nome para excluir: "); fflush(stdin);
    gets(nome);

    achou=0;
    for(i=0;i<*tl;i++)
    {
        if(stricmp(nome,d[i].nome)==0)
            achou=1;
    }
    if(achou==1)
    {
        pos=0;
        while(stricmp(nome,d[pos].nome)==1 && pos<*tl)
            pos++;

        if(pos<*tl)
        {
            for(i=pos;i<*tl;i++)
                strcpy(d[i].nome,d[i+1].nome);
            (*tl)--;
        }
        printf("Sucesso ao excluir!\n");
    }
    else
        printf("Falha ao encontrar esse nome!\n");
    

    system("pause");
}

void ordenacao (dados d[], int *tl)
{
    int a,b,r;
    char aux[NAME];

    for(a=0;a<*tl;a++)
    {
        for(b=a+1;b<*tl;b++)
        {
            r=stricmp(d[a].nome,d[b].nome);
            if(r>0)
            {
                strcpy(aux,d[a].nome);
                strcpy(d[a].nome,d[b].nome);
                strcpy(d[b].nome,aux);
            }
        }
    }
    printf("Ordenacao feita com exito!\n");
    system("pause");
}  

void relatorio (dados d[], int *tl)
{
    int i;

    printf("Nomes:\n");
    for(i=0;i<*tl;i++)
    {
        printf("s\n", d[i].nome);
    }
    system("pause");
}

char menu ()
{
    char m;
    system("cls");
    printf("[A] Cadastrar\n");
    printf("[B] Excluir\n");
    printf("[C] Ordenar (A - Z)\n");
    printf("[D] Relatorio\n"); fflush(stdin);
    printf("[ESC] Sair\n\n");
    m=getch();
    m=toupper(m);
    return m;
}

int main ()
{
    dados d[TF];
    char m;
    int TL=0;

    m=menu();
    while(m!=27)
    {
        switch(m)
        {
            case 'A':
                cadastro(d,&TL);
            break;

            case 'B':
                excluir(d,&TL);
            break;

            case 'C':
                ordenacao(d,&TL);
            break;

            case 'D':
                relatorio(d,&TL);
            break;
        }
        m=menu();
    }
}