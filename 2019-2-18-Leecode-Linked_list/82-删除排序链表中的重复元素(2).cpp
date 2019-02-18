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
            p->next=q->next;    //�����ظ�ɾ���ڶ�����������һ����p������q����flag��Ϊtrue
            q->next=NULL;
            free(q);
            q=p->next;
            flag=true;
            
        }
        else
        {
            if(flag==false) //���p��ǰ��Ĳ��ظ���p��q��������һ��
            {
                lastrear=p;
                p=p->next;
                q=p->next;
            }
            else
            {
                lastrear->next=q;   //���p��ǰ��Ĵ����ظ���q��p���ظ��ˣ���ɾ��p
                p->next=NULL;
                free(p);
                p=q;
                q=p->next;
                flag=false;
            }
        }
    }
    if(q==NULL && flag==true)   //qΪ�յ���flag��ȻΪtrue��˵������Ҫɾqǰ�����һ����Ȼ�������while���˳�
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