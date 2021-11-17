#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

struct TipoLista
{
    int gasto;
    int mes;
    struct TipoLista *prox;
};

typedef struct TipoLista Lista;

Lista *inicializa();
Lista *insereInicio(Lista *atual, int i, int j);
Lista *insereFinal(Lista *atual, int i, int j);
void imprime(Lista *atual, int media);
int estaVazia(Lista *atual);
void coletarImput(int *gasto, int *mes, int *continuar);
int calcularMedia(Lista *atual);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int gastoImput, mesImput, continuar = 1, controleAcao, media;
    Lista *lista1;
    lista1 = inicializa();

    while (continuar == 1)
    {
        coletarImput(&gastoImput, &mesImput, &controleAcao);

        switch (controleAcao)
        {
        case 1:
            lista1 = insereInicio(lista1, gastoImput, mesImput);
            break;

        case 2:
            lista1 = insereFinal(lista1, gastoImput, mesImput);
            break;

        default:
            printf("\nFunção não realizada, visto que uma posição inválida foi inserida.");
            break;
        }
        printf("\nDeseja inserir mais informação na lista? 1=SIM, 2=NÃO: ");
        scanf("%d", &continuar);

        while (continuar != 1 && continuar != 2)
        {
            printf("\nEntrada inválida, responda apenas 1 para SIM e 2 para NÃO: ");
            scanf("%d", &continuar);
        }
    }

    media = calcularMedia(lista1);
    imprime(lista1, media);

    Sleep (5000);
    SetConsoleOutputCP(CPAGE_DEFAULT);
    return 0;
}
Lista *inicializa()
{
    return NULL;
}

Lista *insereInicio(Lista *atual, int i, int j)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if (estaVazia(atual))
    {
        novo->gasto = i;
        novo->mes = j;
        novo->prox = NULL;
    }
    else
    {
        novo->gasto = i;
        novo->mes = j;
        novo->prox = atual;
    }
    return novo;
}

Lista *insereFinal(Lista *atual, int i, int j)
{
    /* se lista vazia, insere no inicio.*/
    if (estaVazia(atual))
    {
        return insereInicio(atual, i, j);
    }

    /* acessa o final da lista.*/
    Lista *inicio = atual; /*guarda o inicio da lista.*/
    while ((atual->prox != NULL))
    {
        atual = atual->prox;
    }

    /* insere o novo elemento no final*/
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->gasto = i;
    novo->mes = j;
    novo->prox = NULL;
    atual->prox = novo;

    return inicio;
}

int estaVazia(Lista *atual)
{
    return (atual == NULL);
}

void imprime(Lista *atual, int media)
{
    if (estaVazia(atual))
    {
        return;
    }
    printf("\nSua média de gasto foi: R$%d", media);
    while (atual != NULL)
    {
        printf("\nAs despesas do mês de ");
        switch (atual->mes) //Não consegui coletar os imputs direto em texto, então optei por fazer um switch pra alterar
        {                   //de inteiro pra output de texto. Sei que em outros casos não seria prático, mas pra esse
        case 1:             //não gera problemas.
            printf("Janeiro ");
            break;
        case 2:
            printf("Fevereiro ");
            break;
        case 3:
            printf("Março ");
            break;
        case 4:
            printf("Abril ");
            break;
        case 5:
            printf("Maio ");
            break;
        case 6:
            printf("Junho ");
            break;
        case 7:
            printf("Julho ");
            break;
        case 8:
            printf("Agosto ");
            break;
        case 9:
            printf("Setembro ");
            break;
        case 10:
            printf("Outubro ");
            break;
        case 11:
            printf("Novembro ");
            break;
        case 12:
            printf("Dezembro ");
            break;
        }
        printf("foram R$%d", atual->gasto);

        if (atual->gasto > media)
        {
            printf(" *Acima da média*");
        }
        if (atual->gasto == media)
        {
            printf(" *Exatamente na média*");
        }
        if (atual->gasto < media)
        {
            printf(" *Abaixo da média*");
        }

        atual = atual->prox;
    }
}

void coletarImput(int *gasto, int *mes, int *controleAcao)
{
    printf("\nVocê deseja inserir o mês+gasto no início ou fim da lista? Responda com 1 para início e 2 para final, por favor:");
    scanf("%d", &*(controleAcao));

    printf("\nInforme o número do mês: ");
    scanf("%d", &*(mes));
    while (*(mes) < 1 || *(mes) > 12)
    {
        printf("\nEntrada inválida, responda com um número de 1 a 12, correspondente ao mês que deseja registrar: ");
        scanf("%d", &*(mes));
    }

    printf("\nInforme o valor gasto: ");
    scanf("%d", &*(gasto));
}

int calcularMedia(Lista *atual)
{
    int somaCusto = 0, totalMeses = 0;
    int media = 0;

    if (estaVazia(atual))
    {
        return 0;
    }

    while (atual != NULL)
    {
        somaCusto = somaCusto + atual->gasto;
        totalMeses = totalMeses + 1;
        atual = atual->prox;
    }
    media = somaCusto / totalMeses;

    return media;
}