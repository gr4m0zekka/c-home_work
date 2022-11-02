#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

struct book
{
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

void print_book(Book* b) {
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b->title, b->pages, b->price);
}
struct library
{
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void library_create(Library* L, int NOB) {
    L->books = (Book*)malloc(sizeof(Book) * NOB);
    L->number_of_books = NOB;
}
void library_set(Library L, int i, char name[], double size, double value) {
    L.books[i].title = malloc(sizeof(char) * 40);
    strcpy(L.books[i].title, name);
    L.books[i].pages = size;
    L.books[i].price = value;
}
Book* library_get(Library L, int i) {
    return &L.books[i];
}
void library_print(Library L) {
    for (int j = 0; j < L.number_of_books; ++j) {
        print_book(&L.books[j]);
    }
}
void library_destroy(Library* L) {
    for (int i = 0; i < L->number_of_books; ++i) {
        free(L->books[i].title);
    }
    free(L->books);
}
int main()
{
    Book* DQ = (Book*)malloc(sizeof(Book));/*Восьмой пункт первой задачи*/
    DQ->title = malloc(sizeof(char) * 40);
    strcpy(DQ->title, "Don Quixote");
    DQ->pages = 1000;
    DQ->price = 750.0;

    print_book(DQ);
    free(DQ);

    Book* shelf = (Book*)malloc(sizeof(Book) * 3);
    shelf[0].title = malloc(sizeof(char) * 40);
    strcpy(shelf[0].title, "Don Quixote");
    shelf[1].title = malloc(sizeof(char) * 40);
    strcpy(shelf[1].title, "Oblomov");
    shelf[2].title = malloc(sizeof(char) * 40);
    strcpy(shelf[2].title, "Incredible life of Aleksandr Ptitsyn");
    shelf[0].pages = 1000;
    shelf[1].pages = 400;
    shelf[2].pages = 7;
    shelf[0].price = 750.0;
    shelf[1].price = 250.0;
    shelf[2].price = 31499.0;
    for (int i = 0; i < 3; ++i) {
        print_book(&shelf[i]);
    }
    free(shelf);

    Library a; /* десятый пункт первой задачи*/
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote Doflamingo", 1000, 340000000);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);


}
