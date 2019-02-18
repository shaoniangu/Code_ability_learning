/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head==NULL) return NULL; //空链表特殊处理
    struct ListNode* rear=head, *p=head, *temp;
    int num=0;

    while(rear!=NULL && num<n)  //第二个指针指向后n个结点
    {
        num++;
        rear=rear->next;
    }
    
    if(num<n)     //压根没有n个结点,不用删除，直接返回原链表
    {
        return head;
    }
    
    if(rear != NULL) //
    {
        rear=rear->next;
        while(rear!=NULL)
        {
            rear=rear->next; //如果rear到NULL,p的即指向倒数第n+1个数,之所以指向倒数第n+1个数，是为了方便删除倒数第n个数
            p=p->next;
        }
        temp=p->next;
        p->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
    else                //注意：如果n等于链表长度，删除的是第一个节点要特殊处理
    {
        temp=p;
        head=temp->next;
        temp->next=NULL;
        free(temp);
    }
    
    return head;
}