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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int meep = l1->val + l2->val;
        if((meep/10) != 0){
            if(l1->next){
                l1->next->val += 1;
            }
            else{
                l1->next = new ListNode(1);
            }
            meep %= 10;
        }
        ListNode *head = new ListNode(meep);
        ListNode *temp = head;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            int meep = l1->val + l2->val;
            if((meep/10) != 0){
                if(l1->next){
                    l1->next->val += 1;
                }
                else{
                    l1->next = new ListNode(1);
                }
                meep %= 10;
            }
            temp->next = new ListNode(meep);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            ListNode *temp2 = l1;
            while((temp2->val/10) != 0){
                temp2->val %= 10;
                if(!temp2->next){
                    temp2->next = new ListNode(0);
                }
                temp2->next->val += 1;
                temp2 = temp2->next;
            }
            temp->next = l1;
            return head;
        }
        else if(l2){
            ListNode *temp2 = l2;
            while((temp2->val/10) != 0){
                temp2->val %= 10;
                if(!temp2->next){
                    temp2->next = new ListNode(0);
                }
                temp2->next->val += 1;
                temp2 = temp2->next;
            }
            temp->next = l2;
            return head;
        }
        else{
            return head;
        }
    }
};