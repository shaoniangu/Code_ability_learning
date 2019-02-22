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

bool isPalindrome(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return true;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    struct ListNode *slow=nodehead, *fast=nodehead, *front_rear;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *rearhead=reverseList(slow->next);
    slow->next=NULL;
    slow=head;
    fast=rearhead;
    while(fast!=NULL)
    {
        if(slow->val!=fast->val)
        {
            return false;
        }
        else
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    return true;
}