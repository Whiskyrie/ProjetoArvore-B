#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Utils.h"
#include "BTree.h"
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    pBTree tree = createTree(3); // Criando uma Arvore B com grau mínimo 3

    // Inserindo elementos na Arvore
    int values[] = {3, 7, 1, 5, 2, 6, 4, 9, 10};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserindo elementos na Arvore B:\n");
    for (int i = 0; i < n; i++)
    {
        addKeyTree(tree, &values[i], compareInt, allocateInt);
    }

    // Imprimindo a Arvore
    printf("\nArvore B apos insercoes:\n");
    printTree(tree, printInt);

    // Buscando elementos
    int search_values[] = {5, 11};
    for (int i = 0; i < 2; i++)
    {
        if (searchKeyTree(tree, &search_values[i], compareInt))
        {
            printf("\nO valor %d esta presente na Arvore.\n", search_values[i]);
        }
        else
        {
            printf("\nO valor %d nao esta presente na Arvore.\n", search_values[i]);
        }
    }

    // Removendo elementos
    int remove_values[] = {4, 7};
    for (int i = 0; i < 2; i++)
    {
        printf("\nRemovendo %d da Arvore.\n", remove_values[i]);
        removeKeyTree(tree, &remove_values[i], compareInt, freeInt);
    }

    // Imprimindo a Arvore após remoções
    printf("\nArvore B apos remocoes:\n");
    printTree(tree, printInt);

    // Destruindo a Arvore
    destroyTree(tree, freeInt);
    printf("\nArvore B destriuda.\n");
    printTree(tree, printInt);

    return 0;
}