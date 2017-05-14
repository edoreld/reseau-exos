#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXCHNS 5
int main() {
	int cmptr;
	FILE *pfd;
	char* chaine[MAXCHNS] = { "echo", "bravo", "alpha", "charlie", "delta" };
  // Creation d'un tube unidirectionnel
	if((pfd = popen("sort > /tmp/fooBar", "w")) == NULL) {
	perror("popen");
	exit(1);
	}
  // Traitement
	for(cmptr = 0; cmptr < MAXCHNS; cmptr++) {
		fputs(chaine[cmptr], pfd);
		fputc('\n', pfd);
	}
	close(pfd);
	return(0);
}