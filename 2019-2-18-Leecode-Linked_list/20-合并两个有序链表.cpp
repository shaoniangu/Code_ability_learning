/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3, *rear1, *rear2, *rear3, *temp;
    bool firstnode=true;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    rear1=l1;rear2=l2;
    while(rear1!=NULL && rear2!=NULL)
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;

        if(rear1->val < rear2->val)
        {
            if(firstnode)
            {
                temp->val=rear1->val;
                l3=temp;
                rear3=temp;
                rear1=rear1->next;
                firstnode=false;
            }
            else
            {
                temp->val=rear1->val;
                rear3->next=temp;
                rear3=temp;
                rear1=rear1->next;
            }
        }
        else
        {
            if(firstnode)
            {
                temp->val=rear2->val;
                l3=temp;
                rear3=temp;
                rear2=rear2->next;
                firstnode=false;
            }
            else
            {
                temp->val=rear2->val;
                rear3->next=temp;
                rear3=temp;
                rear2=rear2->next;
            }
        }
    }
    while(rear1!=NULL)
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp->val=rear1->val;
        rear3->next=temp;
        rear3=temp;
        rear1=rear1->next;
    }
    while(rear2!=NULL)
    {
        temp=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next=NULL;
        temp->val=rear2->val;
        rear3->next=temp;
        rear3=temp;
        rear2=rear2->next;
    }
    return l3;
}