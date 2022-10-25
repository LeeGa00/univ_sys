#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	char input[15];
	
	printf("input: ");
	scanf("%s", input);
	getchar();

	if (strcmp(input, "id") == 0){
		if(!fork()){
			printf("my id: 20011699\n");
		} else {
			wait(NULL);
		}
	} else if (strcmp(input, "birthday") == 0) {
		if (!fork())
			printf("my birthday: 2001.12.17\n");
		else{
			wait(NULL);
		}
	}

}
