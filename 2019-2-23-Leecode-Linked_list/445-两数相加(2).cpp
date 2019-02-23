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
    //�ݹ�߽�
    if (l1->next==NULL)
    {
        int temp=l1->val+l2->val;
        if(temp>=10)
        {
            //�ݹ�����µĽ�����
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

    //�ݹ�ʽ
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
    //�ݹ�߽�
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

    //�ݹ�ʽ
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
        //���ͷ��㣬�������λ��λʱ�Ĳ���
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
        //���ͷ��㣬�������λ��λʱ�Ĳ���
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
    //�����λ������Ĳ���
    frontrear->next=NULL;
    //�ݹ齫�ȳ��Ĳ�����ӣ��������λ
    int carry = addTwoEqualNumbers(head, p1,p2);

    //�ͷŵȳ������ͷ���
    p1=head;
    head=head->next;
    p1->next=NULL;
    free(p1);

    //��û�н�λ����ֱ�ӽ���λ����Ĳ��ֽ��ڵȳ���ӽ��ǰ
    if(carry==0)
    {
        //ƴ�ӣ����ͷŸ�λͷ���
        frontrear->next=head;
        head=fronthead->next;
        fronthead->next=NULL;
        free(fronthead);
    }
    else
    {
        int topcarry=addCarry(fronthead->next);

        //������λ�н�λ�������һ����λΪ1�Ľ��,Ҳ��ͷ������ֵ��Ϊ1
        if (topcarry)
        {
            frontrear->next=head;
            fronthead->val=1;
            head=fronthead;
        }
        else
        {
            //ƴ�ӵȳ���λ�����ͷ�ͷ���
            frontrear->next=head;
            head=fronthead->next;
            fronthead->next=NULL;
            free(fronthead);
        }
    }
    return head;
}