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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *start;
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        else{
            if(l1->val < l2->val){
                start = l1;
                l1 = l1->next;
            }
            else{
                start = l2;
                l2 = l2->next;
            }
        }
        ListNode *temp = start;
        while(l1 || l2){
            if(!l1){
                temp->next = l2;
                break;
            } else if(!l2){
                temp->next = l1; 
                break;
            } else {
                if(l1->val < l2->val){
                    temp->next = l1;
                    temp = temp->next;
                    l1 = l1->next;
                } else {
                    temp->next = l2;
                    temp = temp->next;
                    l2 = l2->next;
                }
            }
        }
        return start;
    }
};