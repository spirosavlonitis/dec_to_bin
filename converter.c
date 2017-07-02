#include <stdio.h>
#include <stdlib.h>

char  convertNumbers(int number,int Base){

	char buffer[33];
	char *pConverted=&buffer[32];

	do{
		int value=number % Base;
		pConverted=pConverted-1;
		*pConverted='0'+value;
		number/=Base;

	}while(number != 0);

	printf("%s\n",pConverted);
	return 0;

}




int main(void){

	printf("%s","Enter the number you wish to convert to binary: " );
	int number=0;
	scanf(" %d",&number);
	int Base=2;
	convertNumbers(number,Base);
	return 0;
}
