#include <stdio.h>
int main(){
	char ch, s[9999];
	int i = 0, a = 0, b = 0, c = 0;
	ch = getchar();
	while(ch!='\0' && ch!='\n'){
		if(ch=='(' || ch=='[' || ch=='{'){
			s[i] = ch;
			i++;
		}
		switch(ch){
			case '(': a++;
			break;
			case ')': a--;
			break;
			case '[': b++;
			break;
			case ']': b--;
			break;
			case '{': c++;
			break;
			case '}': c--;
			break;
		}

		switch(ch){
			case ')':
				if(s[i-1] == '(')
					i--;
				break;
			case ']':
				if(s[i-1] == '[')
					i--;
				break;
			case '}':
				if(s[i-1] == '{')
					i--;
				break;
		}
		ch = getchar();
	}
	if(!i && (a || b || c))
		i++;
	if(!i)
		printf("yes");
	else
		printf("no");
	return 0;
} 
