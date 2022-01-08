#include <direct.h>
#include <dirent.h>
#include <stdio.h>
#include "izvjestaj.h"


char** getStringoveRacune(DIR *dir, int from, int to, int *brojRacuna);
char** getStringoveZapise(char **nizRacuna, int brojRacuna, int element, int *brojZapisa);
void ispisiZapise(char **nizZapisa, int brojZapisa);

void freeData(char** niz, int brojElemenata);


void prikaziIzvjestaj(int from, int to, int element)
{
    //_mkdir("noviFolder/novi1/januar");
    DIR *d = opendir(FOLDER_RACUNI); // open the path
  if(d==NULL) return printf("Nije moguce povezivanje sa bazom podataka.\n"); // if was not able, return

  struct dirent *dir; // for the directory entries
  while ((dir = readdir(d)) != NULL) // if we were able to read something from the directory
    {
      if(dir-> d_type != DT_DIR) // if the type is not directory just print it with blue color
        printf("%s%s\n",BLUE, dir->d_name);
      else
      if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
        printf("%s%s\n",GREEN, dir->d_name); // print its name in green
        char d_path[255]; // here I am using sprintf which is safer than strcat
        sprintf(d_path, "%s/%s", path, dir->d_name);
        show_dir_content(d_path); // recall with the new path
      }
    closedir(d); // finally close the directory
    }

  int brojFoldera = 0, brojRacuna = 0, brojZapisa = 0;
  char **nizFoldera = getStringoveFoldere(d, from, to);
  char **nizRacuna = getStringoveRacune(sedmicaDir, &brojRacuna);
  char **nizZapisa = getStringoveZapise(nizRacuna, brojRacuna, element, &brojZapisa);
  ispisiZapise(nizZapisa, brojZapisa);

  freeData(nizRacuna, brojRacuna);
  freeData(nizZapisa, brojZapisa);
}

char** getStringoveRacune(DIR *dir, int from, int to, int *brojRacuna)
{
    char **nizRacuna = calloc(10, sizeof(char*));

    while ((dir = readdir(d)) != NULL) // if we were able to read something from the directory
    {
      if(dir-> d_type != DT_DIR) // if the type is not directory just print it with blue color
        printf("%s%s\n",BLUE, dir->d_name);
      else
      if(dir -> d_type == DT_DIR && strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0 ) // if it is a directory
      {
        printf("%s%s\n",GREEN, dir->d_name); // print its name in green
        char d_path[255]; // here I am using sprintf which is safer than strcat
        sprintf(d_path, "%s/%s", path, dir->d_name);
        show_dir_content(d_path); // recall with the new path
      }
    }

}

char** getStringoveZapise(char **nizRacuna, int brojRacuna, int element, int *brojZapisa)
{


}

void ispisiZapise(char **nizZapisa, int brojZapisa)
{


}

void freeData(char** niz, int brojElemenata)
{
    for(int i = 0; i < brojElemenata; i++)
    {
        free(niz[i]);
    }
    free(niz);
}
*/
