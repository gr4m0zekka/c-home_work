
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(struct book b) {
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

int main()
{
    long long int* p = (long long int*)malloc(sizeof(long long int)); /*Первый пункт первого задания*/
    *p = pow(5, 10);
    printf("%lld\n", *p);
    free(p);

    char* m = (char*)malloc(20 * sizeof(char));/*Второй пункт первого задания*/
    strcpy(m, "elephant");
    for (size_t i = 0; i < 8; ++i) {
        printf("%c", m[i]);
    }
    printf("\n");
    free(m);

    char** k = (char**)malloc(sizeof(char*));
    *k = (char*)malloc(sizeof(char) * 20);
    strcpy(*k, "cats and dogs");
    printf("%s\n", *k);
    free(*k);
    free(k);


    Book* l = (Book*)malloc(sizeof(Book));/*четвертый пункт первого задания*/
    strcpy(l->title, "Don Quixote");
    l->pages = 1000;
    l->price = 750;
    print_book(*l);
    free(l);

    Book DQ;
    strcpy(DQ.title, "Don Quixote"); /*пятый пункт перого задания*/
    DQ.pages = 1000;
    DQ.price = 750;
    Book** g = (Book**)malloc(sizeof(Book*));
    *g = &DQ;
    print_book(**g);
    free(*g);

    Book** kn = (Book**)malloc(sizeof(Book*)); /*шестой пункт первого задания */
    *kn = (Book*)malloc(sizeof(Book));
    strcpy((*kn)->title, "Don Quixote");
    (*kn)->pages = 1000;
    (*kn)->price = 750.0;
    print_book(**kn);
    free(kn);
    free(*kn);

    Book* shelf = (Book*)malloc(sizeof(Book) * 3); /*седьмой пункт первого задания */
    strcpy(shelf[0].title, "Don Quixote");
    strcpy(shelf[1].title, "Oblomov");
    strcpy(shelf[2].title, "The Odissey");
    shelf[0].pages = 1000;
    shelf[1].pages = 400;
    shelf[2].pages = 500;
    shelf[0].price = 750.0;
    shelf[1].price = 250.0;
    shelf[2].price = 500.0;
    for (int i = 0; i < 3; ++i) {
        print_book(shelf[i]);
    }
    free(shelf);
}
