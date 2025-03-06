#include <stdio.h>

void calcularDesconto(float *preco, float desconto)
{
    *preco = *preco * (1-desconto/100);
}

int main()
{
    float preco, desconto, descontoAplicado;
    
    printf("Informe o preço do produto (em R$): ");
    scanf("%f", &preco);
    
    printf("Informe o desconto a ser aplicado (em %%): ");
    scanf("%f", &desconto);
    
    printf("Preço Original: R$ %.2f\n", preco);
    
    descontoAplicado = preco * (desconto / 100);
    calcularDesconto(&preco, desconto);
    
    printf("Desconto Aplicado: R$ %.2f (%.2f%%)\n", descontoAplicado, desconto);
    printf("Preço Final: R$ %.2f\n", preco);

    return 0;
}
