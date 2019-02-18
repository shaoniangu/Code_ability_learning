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

        if(firstnode)       //如果是第一个节点就作为头结点，l3滑动指针指向头结点
        {
            head=temp;
            rear3=temp;
            firstnode=false;
        }
        else
        {
            rear3->next=temp;  //如果不是第一个节点，则将l3的next指向当前节点添加到链表后，滑动指针l3指向当前新加入的节点
            rear3=temp;
        }
        rear1=rear1->next;
        rear2=rear2->next;
    }

    if(rear1==NULL)      //如果l1结束了l2还没结束
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

            if(firstnode)   //如果是第一个节点就作为头结点，l3滑动指针指向头结点
            {
                head=temp;
                rear3=temp;
                firstnode=false;
            }
            else
            {
                rear3->next=temp;  //如果不是第一个节点，则将l3的next指向当前节点添加到链表后，滑动指针l3指向当前新加入的节点
                rear3=temp;
            }
            rear2=rear2->next;
        }
    }
    
    if(rear2==NULL)  //如果l2结束了l1还没结束
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
            if(firstnode)   //如果是第一个节点就作为头结点，l3滑动指针指向头结点
            {
                head=temp;
                rear3=temp;
                firstnode=false;
            }
            else
            {
                rear3->next=temp;  //如果不是第一个节点，则将l3的next指向当前节点添加到链表后，滑动指针l3指向当前新加入的节点
                rear3=temp;
            }
            rear1=rear1->next;
        }
    }

    if(!flag)    //如果两个链表都走完了还有个进1位
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp_val=1;
    }

    if(firstnode)   //如果是第一个节点就作为头结点，l3滑动指针指向头结点
    {
        head=temp;
        rear3=temp;
        firstnode=false;
    }
    else
    {
        rear3->next=temp;  //如果不是第一个节点，则将l3的next指向当前节点添加到链表后，滑动指针l3指向当前新加入的节点
        rear3=temp;
    }

    return head;
}