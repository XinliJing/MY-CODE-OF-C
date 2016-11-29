#include <stdio.h>

int main(){
	int s, m, n, k, as, j = 0, t;
	printf("output the number of prisoners:");
	scanf("%d", &n);
	printf("output the begin but not die:");
	scanf("%d", &s);
	printf("input what number will be counted:");
	scanf("%d", &m);
	int a[n] = {0};
	s = s-1;
	as = m;
	while(j < n-1){
		m = as;
		for(int i = 1; i <= m; i++){
			k = (s+i)%n;
			if(a[k] == 1){
				m++;
				j++;
			}
		}
		a[k] = 1;
		s = k;
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 0)
			t = i;
	}
	printf("%d", t+1);
	return 0;
}
