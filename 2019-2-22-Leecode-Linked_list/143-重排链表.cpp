/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
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

void reorderList(struct ListNode* head) {
    if(head==NULL || head->next == NULL) return;

    //����ָ��ֳ�����
    struct ListNode *slow = head,*fast = head;
    
    while(fast->next && fast->next->next){
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //��˷�ת
    struct ListNode *rearhead = slow->next;
    slow->next = NULL;
    rearhead = reverse(rearhead);
    
    struct ListNode *front=head, *rear=rearhead, *temp;
    while(rear)
    {
        temp=rear->next;
        rear->next=front->next;
        front->next=rear;
        rear=temp;
        front=front->next->next;
    }
}