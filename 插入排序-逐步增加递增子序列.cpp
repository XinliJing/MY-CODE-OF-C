#include <stdio.h>

void f(int a[], int n);

int main(){
	int a[9999];
	int i, k, z;
	printf("put the number of numbers:");
	scanf("%d", &z);
	printf("put the number:");
	for(i = 0; i < z; i++)
		scanf("%d", &a[i]);
	f(a, z);
	for(k = 0; k < z; k++)
		printf("%d ", a[k]);
	return 0;
}

void f(int a[], int n){
	int t, k;
	for(int j = 1; j < n; j++){
		k = j;
		while(k){
			if(a[k] < a[k-1]){
				t = a[k];
				a[k] = a[k-1];
				a[k-1] = t;
			}
			k--;
		}
	}
}
