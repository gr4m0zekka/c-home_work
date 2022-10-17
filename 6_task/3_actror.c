#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date
{
    int day, month, year;
};
typedef struct date Date;


struct address
{
    char country[12];
    char region[52];
    char city[32];
};
typedef struct address Address;


struct actor
{
    char name[32];
    char surname[32];
    int gender;
    int height;
    Date birth_date;
    Address birth_address;
};
typedef struct actor Actor;

void print_actor(FILE* stream, const Actor* a);

int read_actors_from_file(const char* filename, Actor* actors)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_actors;
    fscanf(fin, "%i", &number_of_actors);

    for (int i = 0; i < number_of_actors; ++i)
    {
        fscanf(fin, "%[^,],%[^,],%i,%i,%i/%i/%i,%[^,],%[^,],%[^\n]\n",
            actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
            &actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year,
            actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);

    }
    fclose(fin);
    return number_of_actors;
}


void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%12s %15s. Height: %i cm. Birth date: %02i/%02i/%i. Birth Address: %s, %s, %s\n", a->name, a->surname,
        a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year,
        a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_all_actors_by_birth_year(const Actor* actors, int number_of_actors, int year)
{
    for (int i = 0; i < number_of_actors; ++i)
    {
        if (actors[i].birth_date.year == year)
            print_actor(stdout, actors + i);
    }
}
void print_all_actors_by_height(const Actor* actors, int number_of_actors, int height) {
    for (int i = 0; i < number_of_actors; ++i) {
        if (actors[i].height == height) {
            print_actor(stdout, actors + i);
        }
    }
}
void print_all_actors_by_city(const Actor* actors, int number_of_actors, char city[]) {
    for (int i = 0; i < number_of_actors; ++i) {
        if (strcmp (actors[i].birth_address.city, city) != 0) {
            print_actor(stdout, actors + i);
        }
    }
}

int main()
{
    Actor actors[2000];
    char city[50] = "Volgograd";
    // Считываем актёров (главное, чтобы их было не больше 2000)
    int number_of_actors = read_actors_from_file("actors.csv", actors);
    print_all_actors_by_birth_year(actors, number_of_actors, 1981);
    print_all_actors_by_height(actors, number_of_actors, 175);
    print_all_actors_by_city(actors, number_of_actors, city);
    printf("Size of array = %zu byte\n", sizeof(actors));
}