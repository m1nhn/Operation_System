#include <unistd.h>
#include <cstdlib>
//#include <windows.h>
int main(void){
while(1){
system("ps -e | wc -l >> result.txt");
fork();
}
return 0;
}

