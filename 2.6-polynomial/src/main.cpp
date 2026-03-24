#include "poly.hpp"

int main()
{
    polynomial Pa, Pb;
    Pa = nullptr;
    Pb = nullptr;
    int m, n;
    printf("Please enter the number of terms in polynomial A: ");
    scanf("%d", &m);
    CreatePolyn(Pa, m);
    printf("Please enter the number of terms in polynomial B: ");
    scanf("%d", &n);
    CreatePolyn(Pb, n);
    polynomial sum, product;
    CopyPolyn(Pa, sum);
    CopyPolyn(Pa, product);
    printf("Polynomial A: ");
    PrintPolyn(Pa);
    printf("Polynomial B: ");
    PrintPolyn(Pb);
    AddPolyn(sum, Pb);
    printf("A + B: ");
    PrintPolyn(sum);
    MultiplyPolyn(product, Pb);
    printf("A * B: ");
    PrintPolyn(product);
    DestroyList(Pa);
    DestroyList(Pb);
    DestroyList(sum);
    DestroyList(product);
    return 0;
}
