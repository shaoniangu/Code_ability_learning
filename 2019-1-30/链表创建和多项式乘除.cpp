// review chain table
# include <stdio.h>
# include <malloc.h>

typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expon;
	Polynomial link;
};


void Attach( int c, int e, Polynomial *pRear );
Polynomial ReadPoly() ;
int Length(Polynomial head);
Polynomial FindKth(Polynomial head, int index);
Polynomial Findelement(Polynomial head, int element);
Polynomial Insert( int coef, int expo, int i, Polynomial head ) ;
Polynomial Delet(Polynomial head, int index);
int Compare(int num1, int num2);
Polynomial PolyAdd(Polynomial P1, Polynomial P2);
void PrintPoly( Polynomial P ) ;
Polynomial PolyMulti(Polynomial P1, Polynomial P2);

void Attach( int c, int e, Polynomial *pRear ) 
{    
	Polynomial P; 
	P = (Polynomial)malloc(sizeof(struct PolyNode));    
	P->coef = c;    /* ���½�㸳ֵ  */  
	P->expon = e; 
	P->link = NULL;  
	(*pRear)->link = P;   
	*pRear = P;         /* �޸�pRearֵ */ 
}


Polynomial ReadPoly() 
{      
	Polynomial  P, Rear, t;      
	int c, e, N; 
	printf("Please input maximum number of poly:");
    scanf("%d", &N);      
	P = (Polynomial)malloc(sizeof(struct PolyNode)); /* ����ͷ�ս�� */     
	P->link = NULL;      
	Rear = P;     
	while (N--) 
	{ 
		printf("please input coeffcients and exponents:(%d left)", N+1);
		scanf("%d %d", &c, &e);  
		Attach(c, e, &Rear);                   /* ����ǰ��������ʽβ�� */        
	}       
	t = P;  P = P->link;  free(t);         /* ɾ����ʱ���ɵ�ͷ��� */       
	return P; 
}

int Length(Polynomial head)
{
	Polynomial p=head;
	int i=0;
	while(p)
	{
		p = p->link;
		i++;
	}
	return i;
}

Polynomial FindKth(Polynomial head, int index)
{
	Polynomial p =head;
	int i =0;
	while(p && i<index-1)
	{
		p=p->link;
		i++;
	}
	if (p==NULL)
	{
		printf("No such element!\n");
		return NULL;
	}
	else
	{
		printf("Coefficient and exponent of the %d-th element is %d, %d\n", index, p->coef, p->expon);
		return p;
	}
}

Polynomial Findelement(Polynomial head, int element)
{
	Polynomial p =head;
	int i =0;
	while(p && p->expon != element)
	{
		p=p->link;
		i++;
	}
	if (p==NULL)
	{
		printf("No such element!\n");
		return NULL;
	}
	else
	{
		printf("Coefficient and index of the exponent %d is %d, %d\n", element, p->coef, i);
		return p;
	}
}


Polynomial Insert( int coef, int expo, int i, Polynomial head ) 
{       
	Polynomial  p, s;         
	if (i == 1) 
	{                                                       
		/* �½������ڱ�ͷ */              
		s = (Polynomial)malloc(sizeof(struct PolyNode));          /*���롢��װ���*/              
		s->coef = coef;               
		s->expon = expo;
		s->link = head;
		return s;                                                            /*�����±�ͷָ��*/         
	}         
	p = FindKth(head,i-1);                                        /* ���ҵ�i-1����� */         
	if (p == NULL) 
	{                                    
		/* ��i-1�������ڣ����ܲ��� */                  
		printf("����i��");                  
		return NULL;          
	}
	else
	{                 
		s = (Polynomial)malloc(sizeof(struct PolyNode));       /*���롢��װ���*/                 
		s->coef = coef;    
		s->expon = expo;
		s->link = p->link;                 /*�½������ڵ�i-1�����ĺ���*/                 
		p->link = s;                  
		return head;        
	} 
} 

Polynomial Delet(Polynomial head, int index)
{
	Polynomial p,s;
	if (index==1)
	{
		s = head;
		if (head!=NULL)
			head=head->link;
		else
			return NULL;
		free(s);
		return head;
	}
	p = FindKth(head,index-1);
	if (p==NULL)
	{
	/* ��i-1�������ڣ�����ɾ�� */                  
		printf("����i��");                  
		return NULL;   
	}
	else
	{
		s=p->link;
		p->link=s->link;
		free(s);
		return head;
	}
}

int Compare(int num1, int num2)
{
	if (num1>num2)
		return 1;
	else if (num1<num2)
		return -1;
	else
		return 0;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum; 
	rear = (Polynomial) malloc(sizeof(struct PolyNode));   
	front = rear; 
	while(P1 && P2)
	{
		switch(Compare(P1->expon, P2->expon))
		{
			case 1:
				Attach(P1->coef,P2->expon,&rear);
				P1=P1->link;
				break;
			case -1:
				Attach(P2->coef,P2->expon,&rear);
				P2=P2->link;
				break;
			case 0:
				sum = P1->coef+P2->coef;
				if (sum)
					Attach(sum, P1->expon,&rear);
				P1=P1->link;
				P2=P2->link;
				break;
		}
	}
	/* ��δ���������һ������ʽ�����нڵ����θ��Ƶ��������ʽ��ȥ */ 
	for ( ; P1; P1 = P1->link ) 
		Attach(P1->coef, P1->expon, &rear); 
	for ( ; P2; P2 = P2->link ) 
		Attach(P2->coef, P2->expon, &rear);
	rear->link = NULL;  
	temp = front; 
	front = front->link; /*��frontָ��������ʽ��һ�������� */ 
	free(temp);            /* �ͷ���ʱ�ձ�ͷ��� */ 
	return front; 
}

void PrintPoly( Polynomial P ) 
{   
	/* �������ʽ */  
	int flag = 0;                               /* �������������ʽ�� */ 
	if (!P) 
	{
		printf("0 0\n"); 
		return;
	} 
	while ( P ) 
	{  
		if (!flag)    
			flag = 1;   
		else    
			printf(" ");   
		printf("%d %d", P->coef, P->expon);   P = P->link;  
	}  
	printf("\n"); 
}

Polynomial PolyMulti(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;  
	int c, e; 
	if (!P1 || !P2) 
		return NULL; 
	t1 = P1; 
	t2 = P2;  
	P = (Polynomial)malloc(sizeof(struct PolyNode)); 
	P->link = NULL;  
	Rear = P;  
	//���ɳ�ʼ����ʽ
	while (t2) 
	{                          
		/* ����P1�ĵ�1�����P2���õ�P */   
		Attach(t1->coef*t2->coef, t1->expon+t2->expon, &Rear);   
		t2 = t2->link;  
	}                   
	t1 = t1->link;  
	//������˲����룬ǰ����ָ���ݼ�
	while (t1) 
	{   
		t2 = P2; 
		Rear = P;   
		while (t2) 
		{   
			e = t1->expon + t2->expon;    
			c = t1->coef * t2->coef;
			//�ҵ�����λ��
			while (Rear->link && Rear->link->expon > e)     
				Rear = Rear->link;  
			//��ָ����ȣ�����Ӻϲ�
			if (Rear->link && Rear->link->expon == e) 
			{    
				//��ϵ����Ϊ0������Ӻϲ�
				if (Rear->link->coef + c)     
					Rear->link->coef += c;
				//��ϵ��Ϊ0����ɾ��
				else 
				{     
					t = Rear->link;    
					Rear->link = t->link;     
					free(t);    
				}      
			}    
			//��ָ�����ȣ������
			else 
			{    
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

void main()
{
	Polynomial P1;
	P1 = ReadPoly(); 
	int length1 = Length(P1);
	printf("length of P1 is %d\n", length1);
	PrintPoly(P1);
	FindKth(P1, 1);
	Findelement(P1, 1);

	P1 = Insert(4,4,1,P1);
	int length2 = Length(P1);
	printf("length of P1 after insert is %d\n", length2);
	PrintPoly(P1);
	Findelement(P1, 4);

	P1 = Delet(P1,1);
	Findelement(P1, 4);
	int length3 = Length(P1);
	printf("length of P1 after delete is %d\n", length3);
	PrintPoly(P1);

	Polynomial P2=ReadPoly();
	PrintPoly(P2);

	Polynomial Add_result = PolyAdd(P1,P2);
	PrintPoly(Add_result);
	
	Polynomial Multi_result = PolyMulti(P1,P2);
	PrintPoly(Multi_result);
}