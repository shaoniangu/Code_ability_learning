/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int calculateNumDiff(struct ListNode* l1, struct ListNode* l2)
{
    int num1=0, num2=0;
    while(l1)
    {
        num1++;
        l1=l1->next;
    }
    while(l2)
    {
        num2++;
        l2=l2->next;
    }
    return num1-num2;
}

int addTwoEqualNumbers(struct ListNode* head, struct ListNode* l1, struct ListNode* l2)
{
    //递归边界
    if (l1->next==NULL)
    {
        int temp=l1->val+l2->val;
        if(temp>=10)
        {
            //递归添加新的结果结点
            struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=temp%10;
            newnode->next=head->next;
            head->next=newnode;
            return 1;
        }
        else
        {
            struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=temp;
            newnode->next=head->next;
            head->next=newnode;
            return 0;
        }
    }

    //递归式
    int carry = addTwoEqualNumbers(head, l1->next, l2->next);
    int temp2=l1->val+l2->val+carry;
    if(temp2>=10)
    {
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=temp2%10;
        newnode->next=head->next;
        head->next=newnode;
        return 1;
    }
    else
    {
        struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=temp2;
        newnode->next=head->next;
        head->next=newnode;
        return 0;
    }
}


int addCarry(struct ListNode* l)
{
    if(l==NULL) return 1;
    //递归边界
    if (l->next==NULL)
    {
        int temp=l->val+1;
        if(temp>=10)
        {
            l->val=temp%10;
            return 1;
        }
        else
        {
            l->val=temp;
            return 0;
        }
    }

    //递归式
    int carry = addCarry(l->next);
    
    int temp2=l->val+carry;
    if(temp2>=10)
    {
        l->val=temp2%10;
        return 1;
    }
    else
    {
        l->val=temp2;
        return 0;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    int num=calculateNumDiff(l1, l2), num2=num;
    struct ListNode* p1=l1, *p2=l2, *fronthead, *frontrear;
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->next=NULL;
    if(num2>=0)
    {
        //添加头结点，方便最高位进位时的插入
        struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
        nodehead->next=l1;
        fronthead=nodehead;
        frontrear=nodehead;
        while(num2)
        {
            frontrear=frontrear->next;
            p1=p1->next;
            num2--;
        }
    }
    else
    {
        //添加头结点，方便最高位进位时的插入
        struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
        nodehead->next=l2;
        fronthead=nodehead;
        frontrear=nodehead;
        while(num2)
        {
            frontrear=frontrear->next;
            p2=p2->next;
            num2++;
        }
    }
    //提出高位多出来的部分
    frontrear->next=NULL;
    //递归将等长的部分相加，并求出进位
    int carry = addTwoEqualNumbers(head, p1,p2);

    //释放等长结果的头结点
    p1=head;
    head=head->next;
    p1->next=NULL;
    free(p1);

    //若没有进位，则直接将高位多出的部分接在等长相加结果前
    if(carry==0)
    {
        //拼接，并释放高位头结点
        frontrear->next=head;
        head=fronthead->next;
        fronthead->next=NULL;
        free(fronthead);
    }
    else
    {
        int topcarry=addCarry(fronthead->next);

        //如果最高位有进位，再添加一个高位为1的结点,也即头结点的数值设为1
        if (topcarry)
        {
            frontrear->next=head;
            fronthead->val=1;
            head=fronthead;
        }
        else
        {
            //拼接等长低位链表并释放头结点
            frontrear->next=head;
            head=fronthead->next;
            fronthead->next=NULL;
            free(fronthead);
        }
    }
    return head;
}