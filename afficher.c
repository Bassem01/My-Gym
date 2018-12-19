#include <stdio.h>
#include <string.h>
#include "afficher.h"

void afficher()
{
	char users[50];
	FILE *f;
	char c;
	int nligne, ncolo;
	do
	{
		printf("nom du fichier texte: ");
		scanf("%s", users);
		f = fopen("users.txt", "r");
		if (!f)
			printf("\aERREUR: Impossible d'ouvrir le fichier %s. \n", users);
	}
	while (!f);
	getchar();
	nligne = 0; ncolo = 0;
	while (!feof(f))
	{
		c=fgetc(f);
		if (!feof(f))
			{
			ncolo++;
			if (ncolo == 80 || c == '\n')
				{
					nligne++;
					if (nligne == 25)
					{
						getchar();
						nligne=1;
					}
					printf("%c", c);
					ncolo=1;
				}
			else
				printf("%c", c);
			}
	}
	fclose(f);
}
