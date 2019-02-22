/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL || head->next == NULL) return head;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    struct ListNode *sorted=head, *beforesorted=nodehead, *tobesort=head->next,*temp;
    sorted->next=NULL;
    while(tobesort!=NULL)
    {
        while(sorted!=NULL)
        {
            if(sorted->val>tobesort->val)
            {
                break;
            }
            else
            {
                sorted=sorted->next;
                beforesorted=beforesorted->next;
            }
        }
        temp=tobesort->next;
        tobesort->next=sorted;
        beforesorted->next=tobesort;
        tobesort=temp;
        sorted=nodehead->next;
        beforesorted=nodehead;
    }
    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}