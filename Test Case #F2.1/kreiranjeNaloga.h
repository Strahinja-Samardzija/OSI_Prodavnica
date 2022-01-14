#ifndef KREIRANJENALOGA_H_INCLUDED
#define KREIRANJENALOGA_H_INCLUDED


#define NAMESIZE 20
#define PWSIZE 20

typedef struct nalog{
char korisnickoIme[NAMESIZE];
char lozinka[PWSIZE];
int vrstaNaloga;
int brojPrijava;

}NALOG;

void ucitavanje();


#endif // KREIRANJENALOGA_H_INCLUDED
