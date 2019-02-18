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
        if(leftnum<k)   //剩下的不足K个，后面不用排序
        {
            break;
        }
        else
        {
            num=1;
            rear=front->next;
            //组内方向翻转，注意temp保存rear要指向的下一个结点，否则rear被覆盖后就断了
            while(rear!=NULL && num<k)
            {
                temp=rear->next;
                rear->next=front;
                num++;
                front=rear;
                rear=temp;
            }   
            // 一定一定要注意指针变化
            if(firstgroup)      
            {
                head=front;         //第一次的停止时链表指向的就是整个链表的head
                curhead->next=rear; //之前的head变成了尾巴指向了剩余链表的第一个
                lastrear=curhead;//之前的head变成了当前的尾巴
                curhead=rear;//下一步的head为剩余填表的头
                front=curhead;//front指向剩余链表的第一个
                firstgroup=false;//第一次变化后置false
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