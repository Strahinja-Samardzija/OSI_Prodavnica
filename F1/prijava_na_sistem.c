#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prijava_na_sistem.h"

#define COMMA_SEPARATOR ","


#define USERNAMEFORMAT_LEN 5
#define PASSWORDFORMAT_LEN 8
#define CONFIG_N 2


int birajVrstuNaloga();

NALOG unesiImeILozinku(int);
int provjeraKorisnickogImena(int, char*, FILE*);
int provjeraLozinke(int, char*, FILE*);
int ocitajBrojPrijava(int, char*, FILE*);

int nPrijava(NALOG);

int prijavaNaSistem()
{
    int vrstaNaloga = birajVrstuNaloga();
    NALOG nalog = unesiImeILozinku(vrstaNaloga);

    printf("Uspjesna prijava za vrstu naloga: %s", vrstaNaloga == 0 ? "sef\n" : "radnik\n");
    if(nPrijava(nalog))
    {
       // promjenaLozinke(nalog);
       printf("promjena lozinke\n");
    }

    return vrstaNaloga;
}

int birajVrstuNaloga(){
    int vrsta;
    do{
        printf("Izaberite vrstu naloga:\n");
        printf("1. Sef\n2. Radnik\n");
        scanf("%d", &vrsta);
    } while(vrsta != 1 && vrsta != 2);

    return vrsta - 1;
}

NALOG unesiImeILozinku(int vrstaNaloga){
    FILE *file;
    char korisnickoIme[NAMESIZE], lozinka[PWSIZE];
    if((file = fopen("nalozi.csv","r")) == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    int ispravno = 0, brojPokusaja = 0;

    do{
        printf("Unesite korisnicko ime:\n");
        scanf("%s", korisnickoIme);
        ispravno = provjeraKorisnickogImena(vrstaNaloga, korisnickoIme, file);
        brojPokusaja++;

    } while(!ispravno && brojPokusaja<4);

    if(brojPokusaja == 4)
    {
        printf("Neuspjesna prijava\n");
        exit(1);
    }

    do{
        printf("Unesite lozinku:\n");
        scanf("%s", lozinka);
        ispravno = provjeraLozinke(vrstaNaloga, lozinka, file);
        brojPokusaja++;

    } while(!ispravno && brojPokusaja<4);

    if(brojPokusaja == 4)
    {
        printf("Neuspjesna prijava\n");
        exit(1);
    }

    int brojPrijava = ocitajBrojPrijava(vrstaNaloga, korisnickoIme, file);

    fclose(file);

    NALOG nalog;
    nalog.vrstaNaloga = vrstaNaloga;
    nalog.brojPrijava = brojPrijava;
    strncpy(nalog.korisnickoIme, korisnickoIme, NAMESIZE);
    strncpy(nalog.lozinka, lozinka, PWSIZE);

    return nalog;
}

int provjeraKorisnickogImena(int vrstaNaloga, char* korisnickoIme, FILE* file){

    if(strlen(korisnickoIme) < USERNAMEFORMAT_LEN)
    {
        printf("Prekratko korisnicko ime\n");
        return 0;
    }

    rewind(file);

    int vrstaNalogaDummy;
    char *korisnickoImeDummy;
    char line[256], *stringVrsta;
    while(fgets(line, 256, file) != NULL)
    {
        stringVrsta = strtok(line, COMMA_SEPARATOR);
        korisnickoImeDummy = strtok(NULL, COMMA_SEPARATOR);

        sscanf(stringVrsta, "%d", &vrstaNalogaDummy);

        if(vrstaNalogaDummy == vrstaNaloga)
        {
            if(strncmp(korisnickoIme,korisnickoImeDummy, NAMESIZE) == 0)
                return 1;
        }
    }

    printf("Pogresno korisnicko ime\n");
    return 0;
}

int provjeraLozinke(int vrstaNaloga, char* lozinka, FILE* file){

    if(strlen(lozinka)<PASSWORDFORMAT_LEN)
    {
        printf("Prekratka lozinka\n");
        return 0;
    }

    for(int i = 0; i< strlen(lozinka); i++)
    {
        if(isdigit(lozinka[i]))
            break;
        if(i == strlen(lozinka))
        {
            printf("Lozinka mora imati bar jedan broj\n");
            return 0;
        }

    }

    rewind(file);

    int vrstaNalogaDummy;
    char *lozinkaDummy;
    char line[256], *stringVrsta;
    while(fgets(line, 256, file) != NULL)
    {
        stringVrsta = strtok(line, COMMA_SEPARATOR);
        strtok(NULL, COMMA_SEPARATOR); // ignore korisnickoIme
        lozinkaDummy = strtok(NULL, COMMA_SEPARATOR);

        sscanf(stringVrsta, "%d", &vrstaNalogaDummy);

        if(vrstaNalogaDummy == vrstaNaloga)
        {
            if(strncmp(lozinka, lozinkaDummy, PWSIZE) == 0)
            return 1;
        }
    }

    printf("Pogresna lozinka\n", lozinkaDummy);
    return 0;
}

int ocitajBrojPrijava(int vrstaNaloga, char* korisnickoIme, FILE* file){

    rewind(file);

    int brojPrijavaDummy, vrstaNalogaDummy;
    char *korisnickoImeDummy;
    char line[256], *stringVrsta, *stringBrojPrijava;
    while(fgets(line, 256, file) != NULL)
    {
        stringVrsta = strtok(line, COMMA_SEPARATOR);
        korisnickoImeDummy = strtok(NULL, COMMA_SEPARATOR);
        strtok(NULL, COMMA_SEPARATOR); // ignore lozinka
        stringBrojPrijava = strtok(NULL, COMMA_SEPARATOR);

        sscanf(stringVrsta, "%d", &vrstaNalogaDummy);
        sscanf(stringBrojPrijava, "%d", &brojPrijavaDummy);

        if(vrstaNalogaDummy == vrstaNaloga)
        {
            if(strncmp(korisnickoIme, korisnickoImeDummy, NAMESIZE) == 0)
                return brojPrijavaDummy;
        }
    }
}


int nPrijava(NALOG nalog){
    return nalog.brojPrijava >= CONFIG_N;
}
