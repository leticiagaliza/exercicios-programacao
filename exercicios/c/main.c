#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    float valorInvestido = 0;
    int periodo = 0;
    float percentualRendimento = 0;

    printf("Digite o valor investido\n");
    scanf("%f", &valorInvestido);
    printf("Digite a quantidade de meses do investimento\n");
    scanf("%d", &periodo);
    printf("Digite o percentual de rendimento ao mês\n");
    scanf("%f", &percentualRendimento);

    float saldoAtual = valorInvestido;

    for (int n =1; n<=periodo; n++) {
        saldoAtual += saldoAtual*(percentualRendimento/100);
        printf("Depois do mês %d terá = R$%.2f \n", n, saldoAtual);

        if (n==periodo) {
            saldoAtual -= (saldoAtual - valorInvestido)*0.15;
            printf("O valor do saque com o imposto é R$%.2f \n", saldoAtual);
        }

    }

    return 0;
}