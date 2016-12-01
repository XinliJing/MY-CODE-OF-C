#include <stdio.h>

//char a[9999];

int main(){
	char ch;
	int uppercaseletters = 0, lowercaseletters = 0, spaces = 0, numbers = 0, othersymbol = 0;
	ch = getchar();
	while(ch != '\n'){
		if(ch >= 'A' && ch <= 'Z')
			uppercaseletters++;
		else if(ch >= 'a' && ch <= 'z')
			lowercaseletters++;
		else if(ch == ' ')
			spaces++;
		else if(ch >= '0' && ch <= '9')
			numbers++;
		else
			othersymbol++;
		ch = getchar(); 
	}
	printf("upper case letters:%d\n", uppercaseletters);
	printf("lower case letters:%d\n", lowercaseletters);
	printf("spaces:%d\n", spaces);
	printf("numbers:%d\n", numbers);
	printf("othersymbol:%d", othersymbol);
	return 0;
}
