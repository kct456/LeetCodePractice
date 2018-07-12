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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        for(int i = 0; i < lists.size(); ++i){
            while(lists[i]){
                q.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(q.empty())
            return nullptr;
        ListNode *mergedList = new ListNode(q.top());
        ListNode *traversal = mergedList;
        q.pop();
        while(!q.empty()){
            traversal->next = new ListNode(q.top());
            traversal = traversal->next;
            q.pop();
        }
        return mergedList;
    }
};