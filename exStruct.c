/*
    vetor com 3 alunos, imprime os 3
*/
#include <stdio.h>
#include <string.h>

#define N 3

struct Aluno
{
    int codigo;
    char nome[20];
    float media;
};

void printAluno(struct Aluno aluno);

int main() {
    short i;
    struct Aluno Alunos[N];

    for (i = 0; i < N; i++) {
        printf("Digite o codigo do Aluno: ");
        scanf("%d", &Alunos[i].codigo);
        printf("Digite o nome do Aluno: ");
        scanf("%s", Alunos[i].nome);
        printf("Digite a media: ");
        scanf("%f", &Alunos[i].media);

    }
    for (i = 0; i < N; i++) {
        printAluno(Alunos[i]);
    }


    return 0;
}

void printAluno(struct Aluno aluno) {
    printf("Codigo: %d\n", aluno.codigo);
    printf("Nome: %s\n", aluno.nome);
    printf("Media: %g\n", aluno.media);
    printf("\n");
}
