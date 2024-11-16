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
        if(head->next==NULL){
            return NULL;
        }
        ListNode* ptr1=head;
        ListNode* ptr=head;
        int count=0;
        while(ptr1->next){
            ptr1=ptr1->next;
            count++;
        }
        count=(count+1)/2;

        for(int i=0;i<count-1;i++){
            ptr=ptr->next;
        }
        
        ptr->next=ptr->next->next;
        return head;
    }
    ListNode* optimal(ListNode* head){
    
        if(!head->next) return NULL;
        if(!head->next->next) {
            head->next=NULL;
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(slow and fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        // return bruteforce(head);// two loops used 

        return optimal(head); //one loop
    }
};