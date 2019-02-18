/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if (!head || !head->next) {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode last;
    last.next = slow;
    while (fast&&fast->next) {
        last.next = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    last.next->next = NULL;
    return slow;
}
struct TreeNode* bst(struct ListNode* head, struct ListNode* midnode) {
    if (!head) {
        return (struct TreeNode*)0;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!midnode) {
        root->val = head->val;
        root->left = (struct TreeNode*)0;
        root->right = (struct TreeNode*)0;
        return root;
    }
    root->val = midnode->val;
    struct ListNode* m = middleNode(head);
    root->left = bst(head, m);
    m = middleNode(midnode->next);
    root->right = bst(midnode->next, m);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode* m = middleNode(head);
    return bst(head, m);
}