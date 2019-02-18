/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head; 
    struct ListNode *lastrear, *p, *q, *temp;
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    nodehead->next=head;
    bool flag=false;
    lastrear=nodehead;
    p=lastrear->next;
    q=p->next;
    while(q!=NULL)
    {
        if(q->val == p->val)
        {
            p->next=q->next;    //发现重复删除第二个，保留第一个，p不动，q动，flag置为true
            q->next=NULL;
            free(q);
            q=p->next;
            flag=true;
            
        }
        else
        {
            if(flag==false) //如果p和前面的不重复，p和q都往后走一步
            {
                lastrear=p;
                p=p->next;
                q=p->next;
            }
            else
            {
                lastrear->next=q;   //如果p和前面的存在重复，q和p不重复了，则删除p
                p->next=NULL;
                free(p);
                p=q;
                q=p->next;
                flag=false;
            }
        }
    }
    if(q==NULL && flag==true)   //q为空但是flag依然为true，说明还需要删q前面的那一个，然而上面的while已退出
    {
        lastrear->next=q;
        p->next=NULL;
        free(p);
        flag=false;
    }
    head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}