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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !(head->next)) return head; 
        ListNode* temp=head;
        int count=0;
        while(temp->next) {
            temp=temp->next;
            count++;
        }
        count++;
        temp->next=head;
        temp=head;
        k=count-k%count;
        k--;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        
        temp->next=NULL;

        return head;
    }
};