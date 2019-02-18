/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    while(p2 != NULL && p2->next != NULL)
    {
        // 判断有无环
        p1 = p1->next;
        p2 = p2->next->next;
        
        if(p1 == p2)
        {// 重合表示有环
            p1 = head;// p1重新出发，p1、p2每次都走一步，如果重合，重合处必为环的入口
            
            while(p1!=p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
    }
    return NULL;
}