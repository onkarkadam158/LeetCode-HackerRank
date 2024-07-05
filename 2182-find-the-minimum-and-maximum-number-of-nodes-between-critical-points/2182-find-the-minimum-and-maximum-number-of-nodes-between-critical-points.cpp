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
    bool iscritical(ListNode* temp,int prev){
        if(prev==-1 or temp->next==NULL) return false;
        if(prev<temp->val and temp->val>temp->next->val) return true;
        if(prev>temp->val and temp->val<temp->next->val) return true;
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // O(N) time and O(1) space
        int first=-1,prevIndex=-1,mini=-1,maxi=-1;
        int prevEle=-1,i=0;
        ListNode* temp=head;
        while(temp){
            if(iscritical(temp,prevEle)){
                if(first==-1) first=i,prevIndex=i;
                else{
                    maxi=max(maxi,i-first);
                    if(mini==-1) mini=i-prevIndex;
                    mini=min(mini,i-prevIndex);
                    prevIndex=i;
                }
            }
            i++;
            prevEle=temp->val;
            temp=temp->next;
        }
        return {mini,maxi};
    }
};