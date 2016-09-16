#include <stdio.h>
#include <string.h>
int main()
{
	char * str = "Mai hoon don!";
	int i;

	char rev[strlen(str) + 20];
	for( i = 0; i<strlen(str) ; i++)
	{
		rev[i] = str[ strlen(str) - i - 1 ];
	}
	printf(" len : %d\n", strlen(rev) );
	rev[i] = '\0';
	printf(" len : %d\n", strlen(rev) );
	
	printf("%s\n",rev);
	return 0;
}
