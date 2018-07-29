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
    ListNode* middleNode(ListNode* head) {
        ListNode *traverse = head;
        int length = 0;
        while (traverse){
            ++length;
            traverse = traverse->next;
        }
        double mid = std::ceil(length/2);
        traverse = head;
        for(int i = 0; i < mid; ++i){
            traverse = traverse->next;
        }
        return traverse;
    }
};