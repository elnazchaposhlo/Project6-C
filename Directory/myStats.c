/*
 * @author Elnaz Chaposhlo
 *
 * Directory
*/
#define _XOPEN_SOURCE 700
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <stdint.h>

int fileC = 0;
int dirC = 0;
int symC = 0;

static int
display(const char *fpath, const struct stat *sb, int tflag,struct FTW *ftwbuf)
{
	if(tflag == FTW_D) { // Number of directories
	  dirC =  dirC+1;
	}
	else if(tflag == FTW_F) { // Number of files
	  fileC =fileC+1;
	}
	else if(tflag == FTW_SL) { // Number of symbolink
          symC = symC+1;
	}
	return(0);
}
int main(int argc, char *argv[]){

	if (nftw((argc < 2) ? "." : argv[1], display, 25, 0) == -1) {
	perror("Call to nftw failed"); // In case of failure
	exit(EXIT_FAILURE);
	}

	printf("There are %d regular files\n", fileC); // printing regular files
	printf("There are %d directories\n", dirC); // printing directories
	printf("There are %d symbolic links\n", symC); // printing symbolinc links
	exit(EXIT_SUCCESS); // In case of success
}

