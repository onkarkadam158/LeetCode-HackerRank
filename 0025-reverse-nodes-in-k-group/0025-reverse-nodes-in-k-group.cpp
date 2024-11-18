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
    
    ListNode* bruteforce(ListNode* head, int K) {
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr;
            vector<int>arr;
            int k=K;
            while(temp and k--){
                arr.push_back(temp->val);
                temp=temp->next;
            }
            if(arr.size()==K){
                int i=arr.size()-1;
                temp=curr;
                while(temp and i>=0){
                    temp->val = arr[i--];
                    temp=temp->next;
                }
            }
            curr=temp;
        }
        return head;
    }
    //Solution 2 
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next))
            return head;

        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return node;
    }
    ListNode* optimal(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp){
            ListNode* curr=temp;
            for(int i=0;i<k-1 and curr;i++){
                curr=curr->next;
            }
            if(curr==NULL) break;
            ListNode* nextNode=curr->next;
            curr->next=NULL;
            ListNode* temp1=reverseList(temp);
            if(prev==head){
                head=temp1;
            }
            else{
                prev->next=temp1;
            }
            prev=temp;
            temp->next=nextNode;
            temp=nextNode;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // return bruteforce(head,k);  //time O(N) space O(k)

        return optimal(head,k); // time O(N) space O(1)
    }
};