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


struct movie
{
    char title[50];
    Date release_date;
    double rating;

    int crew_size;
    int crew[20];
};
typedef struct movie Movie;


struct movie_database
{
    int number_of_movies;
    Movie movies[5000];

    int number_of_actors;
    Actor actors[5000];
};
typedef struct movie_database MovieDatabase;


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


int read_movies_from_file(const char* filename, Movie* movies)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        fprintf(stdout, "Error. Can't open file %s!", filename);
        exit(1);
    }
    int number_of_movies;
    fscanf(fin, "%i", &number_of_movies);
    for (int i = 0; i < number_of_movies; ++i)
    {

        fscanf(fin, "%[^,],%i/%i/%i,%lf,%i,", movies[i].title, &movies[i].release_date.day,
            &movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
        for (int j = 0; j < movies[i].crew_size; ++j)
        {
            fscanf(fin, "%i", &movies[i].crew[j]);
        }
    }
    fclose(fin);
    return number_of_movies;
}


void read_database(MovieDatabase* pmd, const char* actors_file_name, const char* movies_file_name)
{
    pmd->number_of_actors = read_actors_from_file(actors_file_name, pmd->actors);
    pmd->number_of_movies = read_movies_from_file(movies_file_name, pmd->movies);
}


void print_actor(FILE* stream, const Actor* a)
{
    fprintf(stream, "%10s %15s. Height: %i cm. Birth date: %02i/%02i/%i. Birth Address: %s, %s, %s\n", a->name, a->surname,
        a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year,
        a->birth_address.country, a->birth_address.region, a->birth_address.city);
}


void print_movie(FILE* stream, const Movie* a)
{
    fprintf(stream, "%20s. Rating: %.3lf. Release date: %02i/%02i/%i.\n", a->title, a->rating,
        a->release_date.day, a->release_date.month, a->release_date.year);
}


void print_movie_descriptive(FILE* stream, const MovieDatabase* pmd, int movie_id)
{
    if (movie_id < 0 || movie_id >= pmd->number_of_movies)
    {
        fprintf(stream, "Error. No movie with such id!\n");
        return;
    }
    print_movie(stdout, &pmd->movies[movie_id]);
    printf("Actors:\n");
    for (int i = 0; i < pmd->movies[movie_id].crew_size; ++i)
    {
        printf("\t");
        print_actor(stdout, &pmd->actors[pmd->movies[movie_id].crew[i]]);
    }
    printf("\n");
}
Movie find_best_movie_value(const MovieDatabase* pmd) {
    Movie best_movie;
    double best_rate = 0;
    for (int i = 0; i < pmd->number_of_movies; ++i) {
        if (pmd->movies[i].rating > best_rate) {
            best_movie = pmd->movies[i];
            best_rate = pmd->movies[i].rating;
        }

    }
    return best_movie;
}
int find_best_movie_index(const MovieDatabase* pmd) {
    int best_id;
    double best_rate = 0;
    for (int i = 0; i < pmd->number_of_movies; ++i) {
        if (pmd->movies[i].rating > best_rate) {
            best_id = i;
            best_rate = pmd->movies[i].rating;
        }
    }
    return best_id;
}
const Movie* find_best_movie_pointer(MovieDatabase* pmd) {
    Movie* best_mem;
    double best_rate = 0;
    for (int i = 0; i < pmd->number_of_movies; ++i) {
        if (pmd->movies[i].rating > best_rate) {
            best_mem = &pmd->movies[i];
            best_rate = pmd->movies[i].rating;
        }
    }
    return best_mem;
}
void find_best_movie_argument(const MovieDatabase* pmd, Movie* p_best_movie) {
    double best_rate = 0;
    for (int i = 0; i < pmd->number_of_movies; ++i) {
        if (pmd->movies[i].rating > best_rate) {
            *p_best_movie = pmd->movies[i];
            best_rate = pmd->movies[i].rating;
        }
    }
}
void filmography(const MovieDatabase* pmd, char name[20], char surname[20]) {
    for (int i = 0; i < pmd->number_of_movies; ++i) {
        for ( int j = 0; j < pmd->movies[i].crew_size; ++j) {
            if (strcmp(pmd->movies[i].crew[j].name, name) == 0 && strcmp(pmd->movies[i].crew[j].surname, surname)) {
                print_movie(stdout, &pmd->movies[i]);
            }
        }
    }
}
void movie_of_this_year(const MovieDatabase* pmd, int year) {
    Movie this_year[4020];
        int now = 0;
        for (int i = 0; i < pmd->number_of_movies; ++i) {
                if (pmd->movies[i].release_date.year == year) {
                    this_year[now] = pmd->movies[i];
                    ++now;
                }
            }
            for (int i = 0; i < now; ++i) {
                for (int j = 0; j < now - 1; ++j) {
                    if (this_year[j].rating > this_year[j + 1].rating) {
                        Movie n = this_year[j];
                        this_year[j] = this_year[j + 1];
                        this_year[j + 1] = n;
                    }
                }
            }
            for (int i = 0; i < now; ++i) {
                Movie* p = &this_year[i];
                print_movie(stdout, p);
            }
}



int main()
{
    MovieDatabase md;
    printf("%llu\n", sizeof(md));
    read_database(&md, "actors.csv", "movies.csv");
    Movie* best_movie = &find_best_movie_value(&md);

    print_movie(stdout, best_movie);

    print_movie(stdout, find_best_movie_pointer(&md));

    Movie p_best_movie;
    find_best_movie_argument(&md, &p_best_movie);
    print_movie(stdout, &p_best_movie);

    printf("%i", find_best_movie_index(&md));

    char name[10] = "Andrey";
    char surname[20] = "Solomin";
    filmography(&md, name, surname);

    movie_of_this_year(&md, 2003);

}