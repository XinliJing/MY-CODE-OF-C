#include <stdio.h>

int main(){
	char a[120], w;
	int sum;
	for(int i = 0; i < 120; i++)
		a[i] = ' ';
	while(scanf("%d,%c", &sum, &w)==2){
		if(sum==1 || sum==3 || sum==6 ||
		   sum==12 || sum==24 || sum==-1 ||
		   sum==-2){
			if(sum > 0){
				int t = 0, flag = 1;
					for(int i = t; i < 120 && flag; i++){
						if(a[i] == ' '){
							t = i;
							flag = 0;
							for(int j = sum; j > 0;i++, j--){
								if(a[i] != ' ')
									flag = 1;
							}
						}
					}
					if(!flag){
						for(int i = t, j = sum; j > 0; i++, j--){
							a[i] = w;
						}

					}
				}
			else if(sum < 0){
				sum = -sum;
				int t = 0, flag = 1;
				for(int i = t; i < 120 && flag; i++){
					if(a[i] == w){
						t = i;
						flag = 0;
						for(int j = sum; j > 0;i++, j--){
							if(a[i] != w){
								flag = 1;
								printf("not enough\n");
							}
						}
					}
				}
				if(!flag){
					for(int i = t, j = sum; j > 0; i++, j--){
						a[i] = ' ';
					}
				}
			}
		}
		else if(sum > 0)
			printf("don't buy so many\n");
		else if(sum < 0)
			printf("don't drink so many\n");
		for(int i = 0; i < 120; i++)
			printf("%d %c\t", i+1, a[i]);
	}
	return 0;
}
