#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct StaticTable *List;
#define MAXSIZE 5

struct StaticTable
{
	ElementType Element[MAXSIZE];
	int Last;
};

List MakeEmpty( ) 
{    
	List PtrL;      
	PtrL = (List )malloc( sizeof(struct StaticTable) );      
	PtrL->Last = -1;       
	return PtrL; 
}

//���ֲ����㷨 
int  BinarySearch(List Tbl, ElementType K)
{   
	/*�ڱ�Tbl�в��ҹؼ���ΪK������Ԫ��*/     
	int left, right, mid, NotFound=-1; 
	left = 0;  /*��ʼ��߽�*/     
	right = Tbl->Last;      /*��ʼ�ұ߽�*/     
	while ( left  <= right )     
	{        
		mid = (left+right)/2;    /*�����м�Ԫ������*/         
		if( K < Tbl->Element[mid])         
			right = mid-1;    /*�����ұ߽�*/         
		else if( K > Tbl->Element[mid])  
			left = mid+1;      /*������߽�*/         
		else  
			return  mid;      /*���ҳɹ�����������Ԫ�ص��±�*/     
	}     
	return  NotFound;         /*���Ҳ��ɹ�������-1*/ 
} 

void Insert( ElementType X, int i, List PtrL )
 {       
	int j;         
	if ( PtrL->Last == MAXSIZE-1 )
	{        
		/* ��ռ����������ܲ���*/               
		printf("����\n");                  
		return;          
	}           
	if ( i < 1 || i > PtrL->Last+2)
	{              
		/*������λ�õĺϷ���*/                
		printf("λ�ò��Ϸ�\n");               
		return;          
	}          
	for ( j = PtrL->Last; j >= i-1; j-- )               
		PtrL->Element[j+1] = PtrL->Element[j];  /*�� ai�� an��������ƶ�*/       
	PtrL->Element[i-1] = X;                             /*��Ԫ�ز���*/       
	PtrL->Last++;                                       /*Last��ָ�����Ԫ��*/        
	return;  
} 

void Delete( int  i, List PtrL ) 
{      
	int  j;        
	if( i < 1 || i > PtrL->Last+1 ) 
	{        
		/*���ձ�ɾ��λ�õĺϷ���*/             
		printf("�����ڵ�%d��Ԫ��\n", i );              
		return ;         
	}       
	for ( j = i; j <= PtrL->Last; j++ )             
		PtrL->Element[j-1] = PtrL->Element[j];     /*�� ai+1�� an˳����ǰ�ƶ�*/       
	PtrL->Last--;                                        /*Last��ָ�����Ԫ��*/       
	return;    
} 

void PrintList(List PtrL)
{
	int i=0;
	if ((PtrL->Last+1)==0)
		printf("���\n");
	while(i<=PtrL->Last)
	{
		printf("%d ", PtrL->Element[i]);
		i++;
	}
	printf("\n");
}

void main()
{
	List Tb1=MakeEmpty();
	PrintList(Tb1);
	Insert(5,1,Tb1);
	PrintList(Tb1);
	Insert(6,2,Tb1);
	PrintList(Tb1);
	Insert(9,3,Tb1);
	PrintList(Tb1);
	Insert(18,4,Tb1);
	PrintList(Tb1);
	Insert(19,5,Tb1);
	PrintList(Tb1);
	Delete(5, Tb1);
	PrintList(Tb1);
	
	int to_search =18;
	int result_index=BinarySearch(Tb1, to_search);
	printf("The index of %d is %d.\n", to_search, result_index+1);

}