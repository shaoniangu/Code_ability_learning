/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
    struct ListNode** lists = (struct ListNode **)malloc(k * sizeof(struct ListNode*));   
    struct ListNode *p=root;
    int len=0, num_more, num_less, num_per_less, num_per_more;
    while(p)
    {
        len++;
        p=p->next;
    }
    
    if(len!=0)
    {
        num_more = len%k;
        num_less = k-num_more;
        num_per_less=len/k;
        num_per_more=num_per_less+1;
    }
    else
    {
        num_more=0;
        num_less=k;
        num_per_less=0;
        num_per_more=0;
    }
    *returnSize=k;
    //建立每个部分的头结点，方便插入
    for(int i=0;i<k;i++)
    {
        lists[i]=(struct ListNode*)malloc(sizeof(struct ListNode));
        lists[i]->next=NULL;
    }

    printf("len=%d,num_more=%d, num_less=%d, num_per_more=%d, num_per_less=%d\n", len, num_more, num_less, num_per_more, num_per_less);
    int cur_list=0;
    p=root;
    while(cur_list<num_more && p!=NULL)
    {
        struct ListNode *cur_rear=lists[cur_list];
        for(int i=0;i<num_per_more;i++)
        {
            struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val=p->val;
            temp->next=NULL;
            cur_rear->next=temp;
            p=p->next;
            cur_rear=temp;
        }
        cur_list++;
    }

    while(cur_list<k && p!=NULL)
    {
        struct ListNode * cur_rear=lists[cur_list];
        for(int i=0;i<num_per_less;i++)
        {
            struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val=p->val;
            temp->next=NULL;
            cur_rear->next=temp;
            p=p->next;
            cur_rear=temp;
        }
        cur_list++;
    }

    //删除每个部分的头结点
    for(int i=0;i<k;i++)
    {
        struct ListNode *temp=lists[i];
        lists[i]=lists[i]->next;
        temp->next=NULL;
        free(temp);
    }
    return lists;
}