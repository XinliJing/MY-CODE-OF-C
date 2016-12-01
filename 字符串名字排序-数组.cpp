#include <stdio.h>
#include <string.h>

int main(){
	int sum, flag;
	char a[100][25], b[100];
//	printf("put the summary of number:");
	scanf("%d", &sum);
	for(int i = 0; i < sum; i++){
//		printf("put the %d number:", i);
		scanf("%s", a[i]);
	}
	for(int i = 0; i < sum-1; i++)
		for(int j = 0; j < sum-1-i; j++){
			flag = strcmp(a[j], a[j+1]);
			if(flag > 0){
				strcpy(b, a[j]);
				strcpy(a[j], a[j+1]);
				strcpy(a[j+1], b);
			}
		}
	for(int i = 0; i < sum; i++){
		printf("%s\n", a[i]);
	}
	return 0;
}

/*int compare(char *pa, char *pb){
			int i = 0, flag = 0;
			while(*pa!='\0' && *pb!='\0' && !flag){
				if(*pa > *pb)
					flag = 1;
				else if(*pa < *pb)
					flag = -1;
				else if(*pa = *pb){
					pa++;
					pb++;

			if(*pa == '\0' && *pb == '\0')
				flag = 0;
			else if(*pa == '\0' && *pb != '\0')
				flag = -1;
			else if(*pa != '\0' && *pb == '\0')
				flag = 1;
			return flag;
		}*/
	/*while(*pa == *pb){
		if(*pa == '\0')
			return 0;
		pa++;
		pb++;
	}
	return *pa-*pb;
}*/

/*void exchange(char *pa, char *pb){
	char *pz;
	char *px;
	pz = pa;
	px = pb;
	char a[9999];
	int i = 0;
	while(pa != '\0'){
		a[i++] = *pa++;
	}
	a[i] = '\0';
	pa = pz;
	pb = px;
	while(pb != '\0'){
		*pa = *pb;
		pa++;
		pb++;
	}
	*pa = '\0';
	pa = pz;
	pb = px;
	i = 0;
	while(a[i] != '\0'){
		*pb = a[i];
		pb++;
		i++;
	}
	*pb = '\0';
}*/
