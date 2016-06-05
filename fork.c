#include <stdio.h>
int main(){
	int fork(void),value;
	value = fork();

	printf("In main: value = %d\n",value);
	return 0;
}
