/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeSort(struct ListNode* head);
struct ListNode* merge(struct ListNode *left, struct ListNode *right);
struct ListNode* sortList(struct ListNode* head);


struct ListNode* mergeSort(struct ListNode* head)
{
    //¹é²¢ÅÅÐòµÝ¹é±ß½ç
    if(head->next==NULL) return head;

    //¹é²¢ÅÅÐòµÝ¹éÊ½
    struct ListNode *slow=head, *fast=head, *front_rear;
    while(fast!=NULL && fast->next!=NULL)
    {
        front_rear=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    front_rear->next=NULL;
    struct ListNode *left=mergeSort(head);
    struct ListNode *right=mergeSort(slow);
    return merge(left, right);
}

struct ListNode* merge(struct ListNode *left, struct ListNode *right)
{
    struct ListNode* nodehead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = nodehead;
    while (left != NULL && right != NULL) 
    {
        if (left->val <= right->val) {
            cur->next = left;
            cur = cur->next;
            left = left->next;
        } else {
            cur->next = right;
            cur = cur->next;
            right = right->next;
        }
    }
    if (left != NULL)
    {
        cur->next = left;
    }
    if (right != NULL) 
    {
        cur->next = right;
    }
    struct ListNode *head=nodehead->next;
    nodehead->next=NULL;
    free(nodehead);
    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head==NULL || head->next == NULL) return head;
    return mergeSort(head);
}