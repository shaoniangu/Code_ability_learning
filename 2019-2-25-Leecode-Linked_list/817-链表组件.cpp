/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool IsExistInG(int *G, int GSize, int x)
{
    for(int i=0;i<GSize;i++)
    {
        if(G[i]==x)
        {
            return true;
        }
    }
    return false;
}

int numComponents(struct ListNode* head, int* G, int GSize) {
    if(head==NULL) return 0;
    if(head->next==NULL)
    {
        if(IsExistInG(G,GSize,head->val))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    struct ListNode *front=head, *rear=head;
    int num=0;
    while(front!=NULL)
    {
        if(IsExistInG(G,GSize,front->val))
        {
            num++;
            while(rear!=NULL && IsExistInG(G,GSize, rear->val))
            {
                rear=rear->next;
            }
            front=rear;
        }
        else
        {
            front=front->next;
            rear=front;
        }
        
    }
    return num;
}