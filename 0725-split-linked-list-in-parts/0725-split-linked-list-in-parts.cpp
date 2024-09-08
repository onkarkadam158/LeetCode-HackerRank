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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp){n++,temp=temp->next;}
        vector<ListNode*>res(k);
        vector<ListNode*>end(k);
        temp=head;
        // time O(N) space O(K+k)
        for(int i=0;i<k and temp;i++){
            int t=n/k;
            while(t-- and temp){
                ListNode* node = new ListNode(temp->val);
                if(!res[i]){
                    res[i]=node;
                    end[i]=node;
                }
                else{
                    // ListNode* curr=res[i];
                    // while(curr->next) curr=curr->next;
                    end[i]->next=node;
                    end[i]=node;
                }
                temp=temp->next;
            }
            if(i<(n%k) and temp){
                ListNode* node = new ListNode(temp->val);
                if(!res[i]){
                    res[i]=node;
                    end[i]=node;
                }
                else{
                    // ListNode* curr=res[i];
                    // while(curr->next) curr=curr->next;
                    end[i]->next=node;
                    end[i]=node;
                }
                temp=temp->next;
            }
        }
        return res;
    }
};