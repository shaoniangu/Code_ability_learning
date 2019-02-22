/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL || headB==NULL) return NULL;
    int num=0;
    struct ListNode* nodehead1=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead1->next=headA;
    struct ListNode* nodehead2=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead2->next=headB;
    struct ListNode *p1=nodehead1, *p2=nodehead2;

    while(p1!=NULL && p2!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }

    while(p1!=NULL)
    {
        p1=p1->next;
        num++;
    }
    
    while(p2!=NULL)
    {
        p2=p2->next;
        num--;
    }

    p1=nodehead1,p2=nodehead2;
    if(num>=0)
    {
        while(num)
        {
            p1=p1->next;
            num--;
        }
        while(p1!=NULL && p2!=NULL)
        {
            if(p1==p2)
            {
                printf("%d", p1->val);
                return p1;
            }
            else
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        return NULL;
    }
    else
    {
        while(num)
        {
            p2=p2->next;
            num++;
        }
        while(p1!=NULL && p2!=NULL)
        {
            if(p1==p2)
            {
                printf("%d", p1->val);
                return p1;
            }
            else
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        return NULL;
    }
}