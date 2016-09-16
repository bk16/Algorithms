#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	char * str = "Mai hoon don!";
	int i;

	//char rev[strlen(str) + 20];
	//for( i = 0; i<strlen(str) ; i++)
	//{
	//	rev[i] = str[ strlen(str) - i - 1 ];
	//}
	//printf(" len : %d\n", strlen(rev) );
	//rev[i] = '\0';
	//printf(" len : %d\n", strlen(str) );
	
	string temp = "";
	for( i = 0; i<strlen(str) ; i++)
	{
		if( str[i] == ' ')
			temp = temp + "%20";
		else
			temp = temp + str[i];
	}
	printf("%s\n",temp.c_str());
	return 0;
}
