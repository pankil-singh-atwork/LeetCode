/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // copy the next node data to the current node
        node->val = node->next->val;
        ListNode* temp = node->next;
        // now link the current node to the next->next node
        node->next = node->next->next;
        // delete the temp node
        delete(temp);
    }
};