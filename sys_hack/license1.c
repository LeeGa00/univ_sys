/* license1.c */
/*
 * https://github.com/LiveOverflow/liveoverflow_youtubve/blob/master/0x05_simple_crackme_intro_assembler/license_1.c */

#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if(argc==2) {
		printf("Checking License: %s\n", argv[1]);

		if(strcmp(argv[1], "AAAA-Z10N-42-OK")==0)
			printf("Access Granted!\n");
		else
			printf("WRONG!\n");
	}
	else
		printf("Useage: <key>\n");

	return 0;
}
