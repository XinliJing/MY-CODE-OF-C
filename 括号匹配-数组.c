//�ж�һ���ַ�������(��)��[��]��{��}�Ƿ�����Ҳ��ཻ��
#include <stdio.h>

int main(){
	char ch, s[9999];
	int i = 0;
	ch = getchar();
	while(ch!='\0' && ch!='\n'){
		if(ch=='(' || ch=='[' || ch=='{'){
			s[i] = ch;
			i++;
		}
		switch(ch){
			case ')':
				if(s[i] == '(')
					i--;
				break;
			case ']':
				if(s[i] == '[')
					i--;
				break;
			case '}':
				if(s[i] == '{')
					i--;
				break;
		}
		ch = getchar();
	}
	if(!i)
		printf("��");
	else
		printf("��");
	return 0;
} 
