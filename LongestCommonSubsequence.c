#include <stdio.h>
#include <string.h>

int max( int a, int b)
{
	return a<b? b : a;
}

int main()
{
	char s[10];
	char t[10];
	
	int com[10][10];
	
	//s = "ABCB";
	//t = "BDCA";

	strcpy(s,"ABCBDAB");
	strcpy(t,"BDCABA");

	int i,j;

	printf("Length of s is %d\n",strlen(s));
	// initialize 0th rows

	for( i=0; i<=strlen(s) ; i++)
		com[i][0] = 0;

	for( j=0; j<=strlen(t) ; j++)
		com[0][j] = 0;

	for( i = 1; i<= strlen(s); i++)
	{
		for( j=1 ; j<= strlen(t) ; j++)
		{
			if( s[i] == t[j])
				com[i][j] = 1 + com[i-1][j-1];
			else
				com[i][j] = max( com[i-1][j], com[i][j-1]);
		}
	}
	printf("Answer is %d\n",com[strlen(s)][strlen(t)]);
	

	return 0;
}
	
