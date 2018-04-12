//输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式
//输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
//数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode{
	int coef;
	int expon;
	Polynomial link;
};

Polynomial ReadPoly();//
void Attach(int c, int e, Polynomial *pRear);//
Polynomial Mult(Polynomial P1, Polynomial P2);//
Polynomial Add(Polynomial P1, Polynomial P2);//
void PrintPoly(Polynomial P);//

int main()
{
	Polynomial P1, P2, PP, PS;
	
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	PrintPoly(PS);
	
	return 0;
}

Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int N, c, e;
	
	scanf("%d", &N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(N--){
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}
	t = P;
	P = P->link;
	free(t);
	return P;
}

void Attach(int c, int e, Polynomial *pRear)
{
	Polynomial P;
	
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, temp;
	int sum;
	
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(t1 && t2){
		if(t1->expon == t2->expon){
			sum = t1->coef + t2->coef;
			if(sum)
				Attach(sum, t1->expon, &Rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if(t1->expon > t2->expon){
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;
		}
		else{
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}
	}
	while(t1){
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}
	while(t2){
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}
	Rear->link = NULL;
	temp = P;
	P = P->link;
	free(temp);
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;
	
	if(!P1 || !P2) return NULL;
	
	t1 = P1;
	t2 = P2;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;
	while(t2){
		Attach(t1->coef*t2->coef, t1->expon+t2->expon, &Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while(t1){
		t2 = P2;
		Rear = P;
		while(t2){
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while(Rear->link && Rear->link->expon > e)
				Rear = Rear->link;
			if(Rear->link && Rear->link->expon == e){
				if(Rear->link->coef + c)
					Rear->link->coef += c;
				else{
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}
			else{
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	free(t2);
	
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0;
	if(!P){
		printf("0 0\n");
		return;
	}
	while(P){
		if(!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}
