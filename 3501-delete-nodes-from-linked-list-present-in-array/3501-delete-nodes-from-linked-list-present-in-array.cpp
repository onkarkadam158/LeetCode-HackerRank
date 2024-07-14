/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto a:nums) mp[a]++;
        ListNode* result=new ListNode(0);
        ListNode* temp=head,*res=result;
        while(temp){
            int val=temp->val;
            if(mp.find(val)==mp.end()){
                res->next=temp;
                res=res->next;
            }
            temp=temp->next;
        }
        res->next=NULL;
        return result->next;
    }
};