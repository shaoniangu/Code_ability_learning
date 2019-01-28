// maximum subsequence sum
#include <stdio.h>

int MaxSubseqSum1(int a[], int N)
{
	int temp_sum=0, max_sum = 0;
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for (j=i;j<N;j++)
		{	
			temp_sum = 0;
			for(k=i;k<=j;k++)
				temp_sum+=a[k];
			if (temp_sum>max_sum)
				max_sum=temp_sum;
		}
	}
	return max_sum;
}

int MaxSubseqSum2(int a[], int N)
{
	int temp_sum=0, max_sum = 0;
	int i,j;
	for(i=0;i<N;i++)
	{
		temp_sum=0;
		for (j=i;j<N;j++)
		{	
			temp_sum+=a[j];
			if (temp_sum>max_sum)
				max_sum=temp_sum;
		}
	}
	return max_sum;
}

int Max3( int A, int B, int C )
{ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
 
int DivideAndConquer( int List[], int left, int right )
{ /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }
 
    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );
 
    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */
 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */
 
    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
 
int MaxSubseqSum3( int List[], int N )
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer( List, 0, N-1 );
}


int MaxSubseqSum4(int a[], int N)
{
	int temp_sum=0, max_sum = 0;
	int i;
	for(i=0;i<N;i++)
	{		
		temp_sum+=a[i];
		if (temp_sum<0)
			temp_sum =0;
		if (temp_sum>max_sum)
				max_sum=temp_sum;
	}
	return max_sum;
}

void main()
{
	int	arr[8] = {4,-3,5,-2,-1,2,6,-2};
	int result1, result2, result3,result4;
	result1 = MaxSubseqSum1(arr, 8);
	result2 = MaxSubseqSum2(arr, 8);
	result3 = MaxSubseqSum3(arr, 8);
	result4 = MaxSubseqSum4(arr, 8);
	printf("Max sum 1:%d\n",result1);
	printf("Max sum 2:%d\n",result2);
	printf("Max sum 3:%d\n",result3);
	printf("Max sum 4:%d\n",result4);
}