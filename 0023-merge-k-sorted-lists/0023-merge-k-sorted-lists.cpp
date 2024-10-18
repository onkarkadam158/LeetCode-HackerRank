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
    #define pii pair<int,int>
    ListNode* bruteforce(vector<ListNode*>& lists){
        int n=lists.size();
        vector<int>arr;
        for(auto node:lists){
            while(node){
                arr.push_back(node->val);
                node=node->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* res= new ListNode(0);
        ListNode* temp=res;
        for(auto a:arr){
            ListNode* newNode = new ListNode(a);
            temp->next=newNode;
            temp=temp->next;
        }
        return res->next;
    }
    ListNode* priority_queue_solution(vector<ListNode*>& lists){
        int n=lists.size();
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i=0;i<n;i++){
            if(lists[i]) pq.push({lists[i]->val,i});
        }
        ListNode* res = new ListNode(0);
        ListNode* temp=res;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(top.first);
            temp->next=newNode;
            temp=temp->next;
            int ind=top.second;
            lists[ind]=lists[ind]->next;
            if(lists[ind]){
                pq.push({lists[ind]->val,ind});
            }
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // return bruteforce(lists); // time O(K*M*log(K*M)) space O(K*M)


        return priority_queue_solution(lists); // time O(K*M*log(K)) space O(K)

        
    }
};