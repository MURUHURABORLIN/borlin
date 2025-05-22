#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book PK;
    FILE *file;

    printf("Enter book title: ");
    fgets(PK.title, sizeof(PK.title), stdin);

    printf("Enter author name: ");
    fgets(PK.author, sizeof(PK.author), stdin);

    printf("Enter price: ");
    scanf("%f", &PK.price);

    file = fopen("book.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%s%s%.1f\n", PK.title, PK.author, PK.price);
    fclose(file);

    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\nSaved Book Details:\n");

    fgets(PK.title, sizeof(PK.title), file);
    fgets(PK.author, sizeof(PK.author), file);
    fscanf(file, "%f", &PK.price);

    printf("Title: %s", PK.title);
    printf("Author: %s", PK.author);
    printf("Price: %.0f shs\n", PK.price);

    fclose(file);
    return 0;
}
