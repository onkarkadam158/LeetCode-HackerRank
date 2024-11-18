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
    ListNode* bruteforce(ListNode* head){
        vector<int>res;
        ListNode* curr=head;
        while(curr){
            res.push_back(curr->val);
            curr=curr->next;
        }
        sort(res.begin(),res.end());
        curr=head;
        int i=0;
        while(curr){
            curr->val=res[i++];
            curr=curr->next;
        }
        return head;

    }
    ListNode* getMiddle(ListNode* head){
        if(!head) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL and fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next;
            fast=fast->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode* result=new ListNode(0);
        ListNode* res=result;

        while(left and right){
            int num1=left->val;
            int num2=right->val;
            if(num1<num2){
                res->next=left;
                res=res->next;
                left=left->next;
            }
            else{
                res->next=right;
                res=res->next;
                right=right->next;
            }
        }
        while(left){
            res->next=left;
            res=res->next;
            left=left->next;
        }
        while(right){
            res->next=right;
            res=res->next;
            right=right->next;
        }
        return result->next;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result=NULL;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else{
            if(l1->val <= l2->val){
                result=l1;
                result->next=mergeTwoLists(l1->next,l2);                
            }
            else{
                result=l2;
                result->next=mergeTwoLists(l1,l2->next);
            }
        }
        return result;
    }
    ListNode* optimal(ListNode* head){
        if(!head or !head->next){
            return head;
        }
        ListNode* middle = getMiddle(head);
        // cout<<middle->val;
        ListNode* left=head,*right=middle->next;
        middle->next=NULL;
        left=optimal(left);
        right=optimal(right);
        head=mergeList(left,right);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        // return bruteforce(head); // space O(N) time O(logN)
        return optimal(head); // space O(N) time O(logN)
    }
};