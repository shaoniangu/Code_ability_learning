/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    if(k==1) return head;

    bool firstgroup=true;
    int num,leftnum;
    struct ListNode *front=head, *rear=head->next, *temp, *curhead=head, *lastrear=NULL;
    while(1)
    {
        temp=front;
        leftnum=0;
        while(temp!=NULL && leftnum<k)
        {
            temp=temp->next;
            leftnum++;
        }
        if(leftnum<k)   //ʣ�µĲ���K�������治������
        {
            break;
        }
        else
        {
            num=1;
            rear=front->next;
            //���ڷ���ת��ע��temp����rearҪָ�����һ����㣬����rear�����Ǻ�Ͷ���
            while(rear!=NULL && num<k)
            {
                temp=rear->next;
                rear->next=front;
                num++;
                front=rear;
                rear=temp;
            }   
            // һ��һ��Ҫע��ָ��仯
            if(firstgroup)      
            {
                head=front;         //��һ�ε�ֹͣʱ����ָ��ľ������������head
                curhead->next=rear; //֮ǰ��head�����β��ָ����ʣ������ĵ�һ��
                lastrear=curhead;//֮ǰ��head����˵�ǰ��β��
                curhead=rear;//��һ����headΪʣ������ͷ
                front=curhead;//frontָ��ʣ������ĵ�һ��
                firstgroup=false;//��һ�α仯����false
            }
            else
            {
                curhead->next=rear;
                lastrear->next=front;
                lastrear=curhead;
                curhead=rear;
                front=curhead;
            }
        }
    }
    return head;    
}