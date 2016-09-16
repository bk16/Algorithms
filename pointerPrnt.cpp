#include <cstdio>
#include <cstring>

int main() 
{
	int k = 10;
	int * p = &k;
	unsigned int x = 1022;
	printf("%08x\n",p);
	printf("%p\n",p);		//0x7fff0dd1a644 - this value?

	printf("%08X\n",x);		//prints 00000018

    	int data = 29;
    	printf("%x\n", data);    // just print data
    	printf("%0x\n", data);   // just print data ('0' on its own has no effect)
    	printf("%8x\n", data);   // print in 8 width and pad with blank spaces
    	printf("%08x\n", data);  // print in 8 width and pad with 0's
	return 0;
}
