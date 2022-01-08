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
	printf("Ime prodavnice: %s\n", CONFIG_IME_PRODAVNICE);
	printf("Adresa: %s\n", CONFIG_ADRESA);
	printf("%s\n", CONFIG_GRAD);
	printf("\n");
	printf("---------------------------------------------\n");
	printf("       MALOPRODAJNI FISKALNI RACUN\n");
	printf("---------------------------------------------\n");
	printf("=== ==================== ====== ====== ======\n");
	printf("RB. NAZIV                KOL.   CIJENA UKUPNO\n");
	printf("=== ==================== ====== ====== ======\n");
}







void kreiranje_racuna() {


	int i = 0;
	int x;
	char sifre[MAX][PW_LEN];
	int kolicine[MAX];

	do {
		printf("Sifra: "); fgets(sifre[i], MAX, stdin);
		sifre[i][strlen(sifre[i]) - 1] = '\0'; //eat new line from string
		printf("Kolicina: "); scanf("%d", &kolicine[i]); while (getchar() != '\n'); //eat new line from stdin
		i++;
		printf("Kraj unosa?\n");
		printf("1. Da\n2. Ne ");
		scanf("%d", &x); while (getchar() != '\n');
	} while (x != 1);

	header_racuna();

	ARTIKL* artikli = (ARTIKL*)calloc(100, sizeof(ARTIKL));
	int k = 0;
	FILE* fp;
	FILE* fpp = fopen("rezultat.txt", "w"); //umjesto rezultat.txt staviti funkciju koja vraca string novog imena datoteke
	if (fp = fopen("artikli.txt", "r"))
	{
		while (fscanf(fp, "%s %s %d %lf", artikli[k].ime_artikla, artikli[k].sifra, &artikli[k].kolicina, &artikli[k].cijena) != EOF) {
			k++;
		}

	}

	int cijene[MAX];
	for (int q = 0; q < i; q++) {
		for (int p = 0; p < k; p++) {
			if (strcmp(sifre[q], artikli[p].sifra) == 0)
			{
				printf("%2d", q + 1);
				printf("%-20s %6.2lf %6.2lf %6.2lf", artikli[p].ime_artikla, kolicine[q], artikli[p].cijena, kolicine[q] * artikli[p].cijena);
				//ovdje header
				fprintf(fpp, "%-20s %6.2lf %6.2lf %6.2lf", artikli[p].ime_artikla, kolicine[q], artikli[p].cijena, kolicine[q] * artikli[p].cijena);
				//ovdje footer
				cijene[q] = kolicine[q] * artikli[p].cijena;
				printf("\n");
				artikli[p].kolicina -= kolicine[q];
			}
		}
	}
	int suma = 0;
	for (int n = 0; n < i; n++)
		suma += cijene[n];
	printf("=== ==================== ======\n");
	printf("Za  uplatu ukupno:%d\n", suma);
	printf("=== ==================== ======\n");
	free(artikli);
}


int main()
{

	printf("Unesite podatke o kupljenim artiklima:\n");
	kreiranje_racuna();
	return 0;

}