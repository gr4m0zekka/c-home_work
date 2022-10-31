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

void print_book(Book b) {
    printf("Book info:\n");
    printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

int main()
{
    Book* DQ = (Book*)malloc(sizeof(Book));/*Восьмой пункт первой задачи*/
    DQ->title = malloc(sizeof(char) * 40);
    strcpy(DQ->title, "Don Quixote");
    DQ->pages = 1000;
    DQ->price = 750.0;

    print_book(*DQ);
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
        print_book(shelf[i]);
    }
    free(shelf);





}
