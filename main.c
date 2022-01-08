#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 20
#define PW_LEN 20
#define MAX 20
#define CONFIG_IME_PRODAVNICE "Supermarket Vladimir Putin"
#define CONFIG_ADRESA "Jevrejska 71"
#define CONFIG_GRAD "78000 Banja Luka"

typedef struct artikl
{
    char ime_artikla[NAME_LEN];
    char sifra[PW_LEN];
    int kolicina;
    double cijena;

} ARTIKL;


void header_racuna()
{
  printf("Ime prodavnice: %s\n",CONFIG_IME_PRODAVNICE);
  printf("Adresa: %s\n",CONFIG_ADRESA);
  printf("%s\n",CONFIG_GRAD);
  printf("\n");
  printf("---------------------------------------------\n");
  printf("       MALOPRODAJNI FISKALNI RACUN\n");
  printf("---------------------------------------------\n");
  printf("=== ==================== ====== ====== ======\n");
  printf("RB. NAZIV                KOL.   CIJENA UKUPNO\n");
  printf("=== ==================== ====== ====== ======\n");
}







void kreiranje_racuna(){


    int i=0;
    int x;
    char niz[MAX][MAX];
    int niz1[MAX];

do{
    printf("Sifra: "); fgets(niz[i],MAX,stdin); niz[i][strlen(niz[i])]='\0'; //eat new line from string
    printf("Kolicina: "); scanf("%d",&niz1[i]); while(getchar()!='\n'); //eat new line from stdin
    i++;
    printf("Kraj unosa?\n");
    printf("1. Da\n2. Ne ");
    scanf("%d", &x); while(getchar()!='\n');
} while (x!=1);
printf("%d",niz1[0]);
printf("%s",niz[1]);

header_racuna();
ARTIKL* niz2 = (ARTIKL*)calloc(niz,100*sizeof(ARTIKL));
    int k=0;
    FILE *fp;
    FILE *fpp=fopen("rezultat.txt","w"); //umjesto rezultat.txt staviti funkciju koja vraca string novog imena datoteke
    if(fp=fopen("artikli.txt","r"))
    {
        printf("Hello world!");

       while (fscanf(fp,"%s %s %d %lf",niz2[k].ime_artikla,niz2[k].sifra,&niz2[k].kolicina,&niz2[k].cijena)!=EOF && printf("Test")){
        printf("%s %s %d %lf",niz2[k].ime_artikla,niz2[k].sifra,&niz2[k].kolicina,&niz2[k].cijena);
        k++;
       }

    }
/*

    int array[MAX];
    for(int q=0;q<i;q++){
       for(int p=0;p<k;p++){
         if(strcmp(niz[q],niz2[p].sifra)==0)
            {
                    printf("%2d",q+1);
                    printf("%-20s %6.2lf %6.2lf %6.2lf", niz2[p].ime_artikla, niz1[q], niz2[p].cijena, niz1[q] * niz2[p].cijena);
                    //ovdje header
                    fprintf(fpp,"%-20s %6.2lf %6.2lf %6.2lf", niz2[p].ime_artikla, niz1[q], niz2[p].cijena, niz1[q] * niz2[p].cijena);
                    //ovdje footer
                    array[q]=niz1[q] * niz2[p].cijena;
                    printf("\n");
                    niz2[p].kolicina-=niz1[q];

            }
       }
    }
int suma=0;
for(int n=0;n<i;n++)
    suma+=array[n];

printf("=== ==================== ======\n");
printf("Za  uplatu ukupno:%d\n",suma);
printf("=== ==================== ======\n");

free(niz2);
    */
}


int main()
{

    printf("Unesite podatke o kupljenim artiklima:\n");
    kreiranje_racuna();
    return 0;

}
