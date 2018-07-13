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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::unordered_map<int, ListNode*> indexNode;
        ListNode *traverse = head;
        int i = 0;
        while(traverse){
            ListNode *temp = traverse;
            indexNode.insert(std::pair<int, ListNode*>(i++, temp));
            traverse = traverse->next;
        }
        if(i <= n)
            return head->next;
        i -= n;
        traverse = indexNode.at(i);
        indexNode.at(i - 1)->next = traverse->next; 
        return head;
    }
};