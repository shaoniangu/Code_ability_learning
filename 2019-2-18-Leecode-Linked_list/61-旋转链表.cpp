/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* findNthFromEnd(struct ListNode* head, int n) {
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
        return p;
    }
    
    rear=rear->next;    //保持n+1个间隔
    while(rear!=NULL)
    {
        rear=rear->next; //如果rear到NULL,p的即指向倒数第n+1个数,之所以指向倒数第n+1个数，是为了方便删除倒数第n个数
        p=p->next;
    }
    
    return p;

}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k==0) return head;
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    struct ListNode *p=head, *q=p->next, *newhead;
    int num=1;
    while(q->next!=NULL)    //q指向最后一个结点
    {
        num++;
        q=q->next;
    }
    num++;
    k=k%num;
    if(k==0)    return head;
    p=findNthFromEnd(head,k);    //p指向倒数第n+1个结点
    newhead=p->next;
    p->next=NULL;
    q->next=head;
    head=q;
    k--;
    return newhead;
}