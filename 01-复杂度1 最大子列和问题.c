//�����1�и���������K (��100000)����2�и���K������������Կո�ָ���
//
//��һ�������������к͡��������������������Ϊ�����������0��

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
