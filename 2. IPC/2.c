#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	FILE *pfdI,*pfdO; char buffer[128];
  	// Creation d’un tube unidirectionnel
	if((pfdI = popen("ls –scottb", "r")) == NULL)
	{
		perror("popen");
		exit(1); }
  	// Creation d’un autre tube unidirectionnel
		if((pfdO = popen("sort", "w")) == NULL)
		{
			perror("popen");
			exit(1); }
	// Traitement
			while(fgets(buffer, 128, pfdI))
				fputs(buffer, pfdO);
			close(pfdI);
			close(pfdO);
			return(0);
		}

