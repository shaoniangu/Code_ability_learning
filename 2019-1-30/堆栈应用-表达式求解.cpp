#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Error -1
#define MAXOP 100
#define INFINITY 1e9

typedef int Position;
typedef struct SNode * PtrToSNode;
typedef double ElementType;
typedef enum {num, opr, end} Type;

struct SNode{
    ElementType * Data;
    Position Top;
    int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int Maxsize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(Maxsize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = Maxsize;
    return S;
}

bool isFull(Stack S)
{
    return (S->Top == S->MaxSize-1);
}

bool Push(Stack S, ElementType x)
{
    if (isFull(S))
    {
        printf("The stack is full!");
        return false;
    }
    else
    {
        S->Data[++(S->Top)]=x;
        return true;
    }
}

bool isEmpty(Stack S)
{
    return(S->Top == -1);
}

ElementType Pop(Stack S)
{
    if(isEmpty(S))
    {
        printf("The stack is empty!");
        return Error;
    }
    else
    {
        return (S->Data[(S->Top)--]);
    }
}

void PrintStack(Stack S)
{
    Position temp = S->Top;
    while(temp != -1)
    {
        printf("%d ",S->Data[temp--]);
    }
    printf("\n");
}


Type GetOp(char *Expr, int *start, char *str)
{
    // �ѵ㣺�ַ�����ȡ�������жϣ�����ʶ����Ϊ����ԭ�ַ���Ϊ��׼��������'\0'�ͷ���end�������������һ����������������ͱ������ˣ�
    // ����������û�м��㣻
    // Ӧ����str��û����'\0'���ж��Ƿ���ֹ�������ˣ����ζ�ȡ���ùܣ����ز��������������������һ�ζ�ȡ��ֱ�Ӷ�ȡ'\0'��i��û�����ӣ�
    // Ҳ��û�ж����µĲ������Ͳ�������Ҳ����ȡ������
    // �������˲������Ͳ��������жϺ��˽�����������ջ�Ĳ��־ͺܼ��ˡ�
    int i=0;
    while((str[0]=Expr[(*start)++])==' ');

    while(str[i]!=' ' && str[i]!='\0')
    {
        str[++i]=Expr[(*start)++];
    }
    if(str[i]=='\0')
        (*start)--;
    str[i]='\0';

    if(i==0)
        return end;
    else if (isdigit(str[0]) || isdigit(str[1]))
    {
        //printf("%s",str);
        return num;
    }
    else
        return opr;
}

ElementType CalExpr(char *Expr)
{
    Stack S;
    Type T;
    ElementType op1, op2;
    int start=0;
    char str[MAXOP];

    S=CreateStack(MAXOP);
    while((T=GetOp(Expr, &start, str))!=end)
    {
        if (T==num)
        {
            Push(S, atof(str));
            printf("Push %f to stack!\n", atof(str));
        }
        else
        {
            if(!isEmpty(S))
                op2=Pop(S);
            else
                op2=INFINITY;
            if(!isEmpty(S))
                op1=Pop(S);
            else
                op2=INFINITY;
        
            switch(str[0])
            {
                case '+': Push(S, op1+op2);break;
                case '-': Push(S, op1-op2);break;
                case '*': Push(S, op1*op2);break;
                case '/': 
                    if(op2!=0.0)
                        Push(S, op1/op2);
                    else
                    {
                        printf("Wrong��divided by zero value��\n");
                        op2=INFINITY;
                    }
                    break;
                default:
                    printf("Unsupported operation %s\n", str);
                    op2=INFINITY;
                    break;
            }
            if(op2>=INFINITY)
                break;
        }
    }
    if(op2<INFINITY)
        if(!isEmpty(S))
        {
            return Pop(S);
            PrintStack(S);
        }
        else
            op2=INFINITY;
    free(S);
    return op2;
}


int main()
{
    char Expr[MAXOP]="   1.2 1.3 + 2 4.2 * -";
    ElementType f;
    f=CalExpr(Expr);
    if(f<INFINITY)
        printf("The result is %.4f.\n", f);
    else
        printf("Wrong!\n");
    return 0;
}