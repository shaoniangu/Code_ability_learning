/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *rear=head;
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    while(rear!=NULL && rear->next!=NULL)
    {
        int temp=rear->val;
        rear->val=rear->next->val;
        rear->next->val=temp;
        rear=rear->next->next;
    }
    return head;
}