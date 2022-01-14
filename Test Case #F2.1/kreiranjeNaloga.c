#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kreiranjeNaloga.h"

#define USERNAMEFORMAT_LEN 5
#define PASSWORDFORMAT_LEN 8
#define CONFIG_N 2
#define NALOZI_TXT "nalozi.txt"

int birajVrstuNaloga(){
    int vrsta;
    do
    {
    printf("Izaberite vrstu naloga:\n");
    printf("1. Sef\n2. Radnik\n");
    scanf("%d", &vrsta);
    }
    while( vrsta < 1 || vrsta > 2);
    return vrsta - 1;
}


int provjeraLozinke(char* lozinka)
{
 if(strlen(lozinka) < PASSWORDFORMAT_LEN)
    {
        printf("Prekratka lozinka.\n\n");
        return 0;
    }
    int br;
    for(int i = 0; i < strlen(lozinka); i++)
    {
        if (('1' <= lozinka[i]) && (lozinka[i]<='9'))
            br++;
    }
    if (br == 0)
    {
        printf("Lozinka mora da sadrzi bar jedan broj.\n\n");
        return 0;
    }
    else return 1;
}

int postojiLi(char* korIme, FILE* file)
{
    FILE *fp;
if (fp = fopen(file, "r"))
{
    NALOG n;
    while (fscanf(fp, "%d %s %s %d", &n.vrstaNaloga, n.korisnickoIme, n.lozinka, &n.brojPrijava) != EOF)
        {
            if(strcmp(korIme, n.korisnickoIme) == 0)
            {printf("Ovo korisnicko ime vec postoji. Izaberite drugo.\n\n");
            return 0;}
        }
    return 1;

}
else printf("Greska pri otvaranju.\n");
fclose(fp);
}

int provjeraKorisnickogImena(char* korisnickoIme, FILE* file){

    if(strlen(korisnickoIme) < USERNAMEFORMAT_LEN)
    {
        printf("Prekratko korisnicko ime.\n");
        return 0;
    }
    if(postojiLi(korisnickoIme, file) == 0) return 0; else return 1;
}

void ucitavanje()
{
    int vrsta = birajVrstuNaloga();
    printf("\n");
    FILE *fp;
    if(fp = fopen(NALOZI_TXT, "a"))
    {
    NALOG novi;
    do
    {
    printf("Korisnicko ime: "); scanf("%s", novi.korisnickoIme);
    printf("Lozinka: "); scanf("%s", novi.lozinka);
    printf("\n");
    }
    while ((provjeraKorisnickogImena(novi.korisnickoIme, NALOZI_TXT) == 0) || (provjeraLozinke(novi.lozinka) == 0));
    fprintf(fp, "%d %s %s %d\n", vrsta, novi.korisnickoIme, novi.lozinka, 0);
    printf("Novi nalog je uspjesno kreiran.\n");
    }
    fclose(fp);
}
