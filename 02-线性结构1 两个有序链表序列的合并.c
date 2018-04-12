//本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

List Merge(List L1, List L2)
{
	PtrToNode p, rear, t1, t2, t;

	t1 = L1;
	t2 = L2;
	t1 = t1->Next;
	t2 = t2->Next;
	p = (PtrToNode)malloc(sizeof(struct Node));
	p->Next = NULL;
	rear = p;
	while(t1 && t2){
		if (t1->Data <= t2->Data){
		  //Attach(t1->Data, &rear);
			rear->Next = t1;
			rear = t1;
			t1 = t1->Next;
		}
		else{
			//Attach(t2->Data, &rear);
			rear->Next = t2;
			rear = t2;
			t2 = t2->Next;
		}
	}
	while(t1){
	  //Attach(t1->Data, &rear);
		rear->Next = t1;
		rear = t1;
		t1 = t1->Next;
	}
	while(t2){
	  //Attach(t2->Data, &rear);
		rear->Next = t2;
		rear = t2;
		t2 = t2->Next;
	}
//	t2 = p;
//	p = p->Next;
//	free(t2);
//	while(L1){
//	  t = L1;
//	  L1 = L1->Next;
//	  free(t);
//	}
//	while(L2){
//	  t = L2;
//	  L2 = L2->Next;
//	  free(t);
//	}
	L1->Next = NULL;
	L2->Next = NULL;
	
	return p;
}

// void Attach(int Data, PtrToNode *prear)
// {
//   PtrToNode t;
  
//   t = (PtrToNode)malloc(sizeof(struct Node));
// 	t->Data = Data;
// 	t->Next = NULL;
// 	(*prear)->Next = t;
// 	*prear = t;
// }
