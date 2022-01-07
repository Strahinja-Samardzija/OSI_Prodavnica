#ifndef PRIJAVA_NA_SISTEM_H_INCLUDED
#define PRIJAVA_NA_SISTEM_H_INCLUDED

enum {SEF = 0, RADNIK = 1, POGRESNA_PRIJAVA = -1};
enum {NAMESIZE = 20, PWSIZE = 20};

typedef struct nalog{

char korisnickoIme[NAMESIZE];
char lozinka[PWSIZE];
int vrstaNaloga;
int brojPrijava;

}NALOG;

int prijavaNaSistem();


#endif // PRIJAVA_NA_SISTEM_H_INCLUDED
