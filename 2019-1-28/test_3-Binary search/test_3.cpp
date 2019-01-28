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

//二分查找算法 
int  BinarySearch(List Tbl, ElementType K)
{   
	/*在表Tbl中查找关键字为K的数据元素*/     
	int left, right, mid, NotFound=-1; 
	left = 0;  /*初始左边界*/     
	right = Tbl->Last;      /*初始右边界*/     
	while ( left  <= right )     
	{        
		mid = (left+right)/2;    /*计算中间元素坐标*/         
		if( K < Tbl->Element[mid])         
			right = mid-1;    /*调整右边界*/         
		else if( K > Tbl->Element[mid])  
			left = mid+1;      /*调整左边界*/         
		else  
			return  mid;      /*查找成功，返回数据元素的下标*/     
	}     
	return  NotFound;         /*查找不成功，返回-1*/ 
} 

void Insert( ElementType X, int i, List PtrL )
 {       
	int j;         
	if ( PtrL->Last == MAXSIZE-1 )
	{        
		/* 表空间已满，不能插入*/               
		printf("表满\n");                  
		return;          
	}           
	if ( i < 1 || i > PtrL->Last+2)
	{              
		/*检查插入位置的合法性*/                
		printf("位置不合法\n");               
		return;          
	}          
	for ( j = PtrL->Last; j >= i-1; j-- )               
		PtrL->Element[j+1] = PtrL->Element[j];  /*将 ai～ an倒序向后移动*/       
	PtrL->Element[i-1] = X;                             /*新元素插入*/       
	PtrL->Last++;                                       /*Last仍指向最后元素*/        
	return;  
} 

void Delete( int  i, List PtrL ) 
{      
	int  j;        
	if( i < 1 || i > PtrL->Last+1 ) 
	{        
		/*检查空表及删除位置的合法性*/             
		printf("不存在第%d个元素\n", i );              
		return ;         
	}       
	for ( j = i; j <= PtrL->Last; j++ )             
		PtrL->Element[j-1] = PtrL->Element[j];     /*将 ai+1～ an顺序向前移动*/       
	PtrL->Last--;                                        /*Last仍指向最后元素*/       
	return;    
} 

void PrintList(List PtrL)
{
	int i=0;
	if ((PtrL->Last+1)==0)
		printf("表空\n");
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