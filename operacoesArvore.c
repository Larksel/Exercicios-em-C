/*
    Por: Lemuel e Vinicius
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore {
    int valor;
    struct noArvore *Esq;
    struct noArvore *Dir;
    int altura;
} noArvore;

int menu();
int max(int a, int b);
noArvore* criarNo(int valor);
int altura(noArvore *no);
int fatorBalanceamento(noArvore *no);
void atualizarAltura(noArvore **no);
noArvore* rotacaoSimplesDireita(noArvore *raiz);
noArvore* rotacaoSimplesEsquerda(noArvore *raiz);
noArvore* rotacaoDuplaDireita(noArvore *no);
noArvore* rotacaoDuplaEsquerda(noArvore *no);
noArvore* balancear(noArvore *no);
noArvore* inserir(noArvore *no , int valor);
noArvore* valorMinimo(noArvore *no);
noArvore* apagar(noArvore *no, int valor);
noArvore* buscar(noArvore *no, int valor);
void preOrdem(noArvore *no);
void emOrdem(noArvore *no);
void posOrdem(noArvore *no);
void mostrarArvore(noArvore *no, int espaco);

int main() {
    int escolha, valor;
    noArvore *raiz;
    raiz = NULL;
/**
 * inserir
 * buscar
 * mostrar
 * remover
 * sair
 */
    mostrarArvore(raiz, 0);

    do {
        escolha = menu();

        switch (escolha)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir(raiz, valor);
            break;

        case 2:

            break;

        case 3:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir(raiz, valor);
            break;

        case 4:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserir(raiz, valor);
            break;

        default:
            printf("Invalido\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}

int menu() {
    int escolha;
    printf("\n======== M E N U ========\n");
    printf("[1] Inserir\n");
    printf("[2] Buscar\n");
    printf("[3] Mostrar\n");
    printf("[4] Remover\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int menuMostrar() {
    int escolha;
    printf("\n======== M E N U ========\n");
    printf("[1] Inserir\n");
    printf("[2] Buscar\n");
    printf("[3] Mostrar\n");
    printf("[4] Remover\n");
    printf("[0] Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    printf("\n");
    return escolha;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

noArvore* criarNo(int valor) {
    noArvore* novoNo = (noArvore*) malloc(sizeof(noArvore));

    novoNo->valor = valor;
    novoNo->Esq = NULL;
    novoNo->Dir = NULL;
    novoNo->altura = 1;

    return novoNo;
}

int altura(noArvore *no) {
    if (no == NULL) {
        return 0;
    }
    else {
        return no->altura;
    }
}

int fatorBalanceamento(noArvore *no) {
    if (no == NULL)
        return 0;
    else
        return altura(no->Esq) - altura(no->Dir);
}

void atualizarAltura(noArvore **no) {
    if (*no == NULL)
        return;

    (*no)->altura = 1 + max(altura((*no)->Esq), altura((*no)->Dir));
}

noArvore* rotacaoSimplesDireita(noArvore *raiz) {
    noArvore *novaRaiz = raiz->Esq;
    noArvore *temp = novaRaiz->Dir;

    novaRaiz->Dir = raiz;
    raiz->Esq = temp;

    atualizarAltura(&raiz);
    atualizarAltura(&novaRaiz);

    return novaRaiz;
}

noArvore* rotacaoSimplesEsquerda(noArvore *raiz) {
    noArvore *novaRaiz = raiz->Dir;
    noArvore *temp = novaRaiz->Esq;

    novaRaiz->Esq = raiz;
    raiz->Dir = temp;

    atualizarAltura(&raiz);
    atualizarAltura(&novaRaiz);

    return novaRaiz;
}

noArvore* rotacaoDuplaDireita(noArvore *no) {
    no->Dir = rotacaoSimplesDireita(no->Dir);
    return rotacaoSimplesEsquerda(no);
}

noArvore* rotacaoDuplaEsquerda(noArvore *no) {
    no->Esq = rotacaoSimplesEsquerda(no->Esq);
    return rotacaoSimplesDireita(no);
}

noArvore* balancear(noArvore *no) {
    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1) {
        if (fatorBalanceamento(no->Esq) >= 0)
            return rotacaoSimplesDireita(no);
        else
            return rotacaoDuplaEsquerda(no);
    }
    if (balanceamento < -1) {
        if (fatorBalanceamento(no->Dir) <= 0)
            return rotacaoSimplesEsquerda(no);
        else
            return rotacaoDuplaDireita(no);
    }

    return no;
}
noArvore* inserir(noArvore *no , int valor) {
    if (no == NULL)
        return criarNo(valor);
    if (valor < no->valor){
     no ->Esq = inserir(no->Esq, valor);  
    }
    else if (valor > no->valor) {
        no ->Dir = inserir(no->Dir, valor);
    } else 
    return no;
    
    atualizarAltura (&no);
    return balancear(no);
}

noArvore* valorMinimo(noArvore *no) {
    noArvore *noAtual = no;
    while (noAtual->Esq != NULL)
    {
        noAtual = noAtual ->Esq;
    }
    return noAtual;    
}

noArvore* apagar(noArvore *no, int valor) {
    if (no == NULL)
        return no;

    if (valor < no->valor) {
        no->Esq = apagar(no->Esq, valor);
    } else if (valor > no->valor) {
        no->Dir = apagar(no->Dir, valor);
    } else {
        if (no->Esq == NULL || no->Dir == NULL) {
            noArvore *temp = no->Esq; // Pega o nó mais a direita do filho esquerdo
            if (temp == NULL) {
                temp = no;
                no = NULL;
            } else {
                no = temp;
            }
            free(temp);
        } else {
            noArvore *temp = valorMinimo(no->Dir);
            no->valor = temp->valor;
            no->Dir = apagar(no->Dir, temp->valor);
        }
    }

    if (no == NULL)
        return no;

    atualizarAltura(&no);
    return balancear(no);
}

noArvore* buscar(noArvore *no, int valor) {
    if (no == NULL || no->valor == valor)
        return no;

    if (valor < no->valor)
        return buscar(no->Esq, valor);
    else
        return buscar(no->Dir, valor);
}

void preOrdem(noArvore *no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        preOrdem(no->Esq);
        preOrdem(no->Dir);
    }
}

void emOrdem(noArvore *no) {
    if (no != NULL) {
        emOrdem(no->Esq);
        printf("%d ", no->valor);
        emOrdem(no->Dir);
    }
}

void posOrdem(noArvore *no) {
    if (no != NULL) {
        posOrdem(no->Esq);
        posOrdem(no->Dir);
        printf("%d ", no->valor);
    }
}

void mostrarArvore(noArvore *no, int espaco) {
    int i;
    if (no == NULL)
        return;

    espaco = espaco + 5;

    mostrarArvore(no->Dir, espaco);
    for (i = 0; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", no->valor);
    mostrarArvore(no->Esq, espaco);
}