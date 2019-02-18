/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {  
    bool flag=false, firstnode=true;
    int temp_val;
    struct ListNode *head, *temp, *rear1,*rear2,*rear3;
    
    if(l1==NULL || l2==NULL)    head=NULL;
    rear1=l1;
    rear2=l2;
    while(rear1!=NULL && rear2!=NULL)
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        if (!flag)
        {
            temp_val=rear1->val+rear2->val;
            if(temp_val>=10)
            {
                temp->val=temp_val%10;
                flag=true;
            }
            else
            {
                temp->val=temp_val;
                flag=false;
            }
        }
        else
        {
            temp_val=rear1->val+rear2->val+1;
            if(temp_val>=10)
            {
                temp->val=temp_val%10;
                flag=true;
            }
            else
            {
                temp->val=temp_val;
                flag=false;
            }
        }

        if(firstnode)       //����ǵ�һ���ڵ����Ϊͷ��㣬l3����ָ��ָ��ͷ���
        {
            head=temp;
            rear3=temp;
            firstnode=false;
        }
        else
        {
            rear3->next=temp;  //������ǵ�һ���ڵ㣬��l3��nextָ��ǰ�ڵ���ӵ�����󣬻���ָ��l3ָ��ǰ�¼���Ľڵ�
            rear3=temp;
        }
        rear1=rear1->next;
        rear2=rear2->next;
    }

    if(rear1==NULL)      //���l1������l2��û����
    {
        while(rear2!=NULL)
        {
            temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->next=NULL;
            if (!flag)
            {
                temp_val=rear2->val;
                if(temp_val>=10)
                {
                    temp->val=temp_val%10;
                    flag=true;
                }
                else
                {
                    temp->val=temp_val;
                    flag=false;
                }
            }
            else
            {
                temp_val=rear2->val+1;
                if(temp_val>=10)
                {
                    temp->val=temp_val%10;
                    flag=true;
                }
                else
                {
                    temp->val=temp_val;
                    flag=false;
                }
            }

            if(firstnode)   //����ǵ�һ���ڵ����Ϊͷ��㣬l3����ָ��ָ��ͷ���
            {
                head=temp;
                rear3=temp;
                firstnode=false;
            }
            else
            {
                rear3->next=temp;  //������ǵ�һ���ڵ㣬��l3��nextָ��ǰ�ڵ���ӵ�����󣬻���ָ��l3ָ��ǰ�¼���Ľڵ�
                rear3=temp;
            }
            rear2=rear2->next;
        }
    }
    
    if(rear2==NULL)  //���l2������l1��û����
    {
        while(rear1!=NULL)
        {
            temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->next=NULL;
            if (!flag)
            {
                temp_val=rear1->val;
                if(temp_val>=10)
                {
                    temp->val=temp_val%10;
                    flag=true;
                }
                else
                {
                    temp->val=temp_val;
                    flag=false;
                }
            }
            else
            {
                temp_val=rear1->val+1;
                if(temp_val>=10)
                {
                    temp->val=temp_val%10;
                    flag=true;
                }
                else
                {
                    temp->val=temp_val;
                    flag=false;
                }
            }
            if(firstnode)   //����ǵ�һ���ڵ����Ϊͷ��㣬l3����ָ��ָ��ͷ���
            {
                head=temp;
                rear3=temp;
                firstnode=false;
            }
            else
            {
                rear3->next=temp;  //������ǵ�һ���ڵ㣬��l3��nextָ��ǰ�ڵ���ӵ�����󣬻���ָ��l3ָ��ǰ�¼���Ľڵ�
                rear3=temp;
            }
            rear1=rear1->next;
        }
    }

    if(!flag)    //����������������˻��и���1λ
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp_val=1;
    }

    if(firstnode)   //����ǵ�һ���ڵ����Ϊͷ��㣬l3����ָ��ָ��ͷ���
    {
        head=temp;
        rear3=temp;
        firstnode=false;
    }
    else
    {
        rear3->next=temp;  //������ǵ�һ���ڵ㣬��l3��nextָ��ǰ�ڵ���ӵ�����󣬻���ָ��l3ָ��ǰ�¼���Ľڵ�
        rear3=temp;
    }

    return head;
}