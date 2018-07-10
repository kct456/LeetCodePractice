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
    int getNoneNull(vector<ListNode*>& lists){
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i])
                return i;
        }
        return -1;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int x;
        if((x = getNoneNull(lists)) == -1){
            return nullptr;
        }
        ListNode *lowestStart = lists[x];
        for(int i = 0; i < lists.size(); ++i){
            if(i == x)
                continue;
            if(lists[i] && (lowestStart->val > lists[i]->val)){
                lowestStart = lists[i];
                x = i;
            }
        }
        lists[x] = lists[x]->next;
        ListNode *temp = lowestStart;
        while((x = getNoneNull(lists)) != -1){
            for(int i = 0; i < lists.size(); ++i){
                if(i == x)
                    continue;
                else if(lists[i] && (lists[x]->val > lists[i]->val)){
                    x = i;
                }
            }
            temp->next = lists[x];
            lists[x] = lists[x]->next;
            temp = temp->next;
        }
        return lowestStart;
    }
};