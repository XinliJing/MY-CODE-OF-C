//输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
//
//在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  int A[N];
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  int thisSum = 0;
  int maxSum = 0;
	for(int i = 0; i < N; i++){
	  thisSum += A[i];
		if(thisSum > maxSum)
	    maxSum = thisSum;
	  else if(thisSum < 0)
	  	thisSum = 0;
	}
  printf("%d", maxSum);
}
