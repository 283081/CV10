#include "CV10.h"
#include <ctype.h>
#include <stdio.h>
using namespace std;

int main()
{
    FILE* vstup;
    FILE* vystup;

    int znak;
    int pocetPismen = 0;
    int pocetCislic = 0;
    int pocetSlov = 0;

    char slovo[100];

    if (fopen_s(&vstup, "D:\\temp\\vstup.txt", "r") != 0)
    {
        printf("Soubor se nepodarilo otevrit!\n");
        return 1;
    }

    while (1)
    {
        znak = getc(vstup);

        if (feof(vstup))
            break;

        if (ferror(vstup))
            break;

        if (isalpha((unsigned char)znak))
            pocetPismen++;

        if (isdigit((unsigned char)znak))
            pocetCislic++;
    }

    fseek(vstup, 0, SEEK_SET);

    while (fscanf_s(vstup, "%99s", slovo,
        (unsigned)sizeof(slovo)) == 1)
    {
        pocetSlov++;
    }
    fclose(vstup);

    printf("Pocet pismen: %d\n", pocetPismen);
    printf("Pocet cislic: %d\n", pocetCislic);
    printf("Pocet slov: %d\n", pocetSlov);

   
    if (fopen_s(&vystup, "D:\\temp\\vysledky.txt", "w") != 0)
    {
        printf("Vystupni soubor nelze vytvorit!\n");
        return 1;
    }
   
    fprintf(vystup, "Pocet pismen: %d\n", pocetPismen);
    fprintf(vystup, "Pocet cislic: %d\n", pocetCislic);
    fprintf(vystup, "Pocet slov: %d\n", pocetSlov);

    fclose(vystup);

    printf("\nVysledky byly ulozeny do souboru.\n");

    return 0;
    
	
}
