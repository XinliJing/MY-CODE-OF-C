#include <stdio.h>
#define maxTree 10
#define elementType char
#define Tree int
#define Null -1

struct TreeNode{
	elementType element;
	Tree left;
	Tree right;
}T1[maxTree], T2[maxTree]; 

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
	Tree R1, R2;
	
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	
	if(Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
		
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int N;
	Tree root = Null;
	char cl, cr;
	
	scanf("%d\n", &N);
	//printf("%d\n", N);
	if(N){
		int check[maxTree];
		for(int i = 0; i < N; i++)
			check[i] = 0;
		for(int i = 0; i < N; i++){
			scanf("%c %c %c\n", &T[i].element, &cl, &cr);
			if(cl != '-'){
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else
				T[i].left = Null;
			if(cr != '-'){
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else
				T[i].right = Null;
		}
		for(int i = 0; i < N; i++){
			if(!check[i]){
				root  = i;
				break;
			}
		}
		
	}
	return root;
}

int Isomorphic(Tree R1, Tree R2)
{
	if((R1 == Null) && (R2 == Null))
		return 1;
	if(((R1 == Null) && (R2 != Null))|| ((R1 != Null) && (R2 == Null)))
		return 0;
	if(T1[R1].element != T2[R2].element)
		return 0;
	if((T1[R1].left == Null) && (T2[R2].left == Null))
		return Isomorphic(T1[R1].right, T2[R2].right);
	if(((T1[R1].left != Null) && (T2[R2].left != Null)) &&
	   ((T1[T1[R1].left].element) == (T2[T2[R2].left].element)))
	   	return (Isomorphic(T1[R1].left, T2[R2].left) && 
		   		Isomorphic(T1[R1].right, T2[R2].right));
	else
		return (Isomorphic(T1[R1].left, T2[R2].right) && 
				Isomorphic(T1[R1].right, T2[R2].left));
}
