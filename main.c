#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXNUMBER 65

static void error(char *,...);
static void scanargs(int,char **);

int nibble;
char *prog;

int main(int argc,char  *argv[])
{
	char number[MAXNUMBER];
	int i,j;
	long n;

	prog = *argv;
	number[64] = '\0';
	nibble = 0;

	if (argc == 1)
		error("Usage: %s decimal numbers \n",prog);
		
	scanargs(argc,argv);

	while (--argc > 0) {
		if(!(n = atoi(*++argv)))
			continue;
		for(i = MAXNUMBER-2,j=0; i >= 0 && n ;n/=2,--i,j += nibble ? 1 : 0 ){
			if (j == 4 && nibble)	{
				number[i--] = ' ';
				j = 0;
			}
			number[i] = '0' + (n % 2);
		}
		printf("%s\n",number+i+1);
	}


	exit(0);
}


static void scanargs(int argc,char **argv)
{
	while (--argc > 0)
		if (**++argv == '-')
			while (*++*argv)
				switch (**argv){
				  case 'n':
				  	nibble = 1;
				  	break;
				  default:
				   error("%s unknown option %c",prog,**argv);
				   break;
				}
		
}


static void error(char *fmt,...)
{
	va_list args;

	va_start(args,fmt);
	vfprintf(stderr,fmt,args);
	va_end(args);

	exit(1);
}