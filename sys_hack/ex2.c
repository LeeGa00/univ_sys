#include <stdio.h>

int main(int argc, char *argv[]) {
	char stuid[20];
	int code = 7735;
	int pass = 0;

	printf("Your student id: ");
	scanf("%s", stuid);
	printf("Plx, enter your pin code: ");
	scanf("%d", &pass);

	if(code == pass)
		printf("Done! %s\n", stuid);
	else
		printf("Wrong! %s\n", stuid);

	return(0);
}
