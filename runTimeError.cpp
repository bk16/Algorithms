#include <cstdio>
#include <cstring>

int main() {
    const void* res = memchr("Syshsh Pavlik", 'p', 16);
    //printf("%p\n", res);  // uncomment this line and see what happens
    return !*(int*)res;
}
