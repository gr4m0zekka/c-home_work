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
    Book** books;
    int number_of_books;
};
typedef struct library Library;


void library_create(Library* L, int NOB) {
    L->books = (Book**)malloc(sizeof(Book*) * NOB);
    L->number_of_books = NOB;
    for (int i = 0; i < L->number_of_books; ++i) {
        L->books[i] = (Book*)malloc(sizeof(Book));
    }
}
void library_set(Library L, int i, char name[], double size, double value) {
    L.books[i]->title = malloc(sizeof(char) * 40);
    strcpy(L.books[i]->title, name);
    L.books[i]->pages = size;
    L.books[i]->price = value;
}
Book* library_get(Library L, int i) {
    return L.books[i];
}
void library_print(Library L) {
    for (int j = 0; j < L.number_of_books; ++j) {
        print_book(L.books[j]);
    }
}
void library_destroy(Library* L) {
    for (int i = 0; i < L->number_of_books; ++i) {
        free(L->books[i]->title);
        free((L->books[i]));
    }
    free(L->books);
}
int main()
{

    Library a;
    library_create(&a, 3);
    library_set(a, 0, "Don Quixote", 1000, 750.0);
    library_set(a, 1, "Oblomov", 400, 250.0);
    library_set(a, 2, "The Odyssey", 500, 500.0);
    library_print(a);
    print_book(library_get(a, 1));
    library_destroy(&a);


}