/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL || head->next == NULL) return head;
    int num=0;
    struct ListNode *beforefront, *startfront, *front, *rear, *p, *temp;
    front=head;
    rear=head->next;
    while(rear!=NULL)
    {
        temp=rear->next;
        rear->next=front;
        front=rear;
        rear=temp;
    }
    head->next=NULL;
    head=front;
    return head;
}