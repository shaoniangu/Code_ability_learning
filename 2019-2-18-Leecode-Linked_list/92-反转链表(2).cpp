/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head==NULL || head->next == NULL) return head;
    if(m==n) return head;
    int num=0;
    struct ListNode *beforefront, *startfront, *front, *rear, *p, *temp;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    p=nodehead;
    while(p)
    {
        if(num == m-1)
        {
            beforefront=p;
        }
        else if (num==m)
        {
            startfront = p;
            break;
        }
        num++;
        p=p->next;
    }
    if(num<m) return head;
    front=startfront;
    rear=startfront->next;
    while(rear!=NULL)
    {
        temp=rear->next;
        rear->next=front;
        front=rear;
        rear=temp;
        num++;
        if(num == n)
        {
            break;
        }
    }

    beforefront->next=front;
    startfront->next=rear;

    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}