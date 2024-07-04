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
    ListNode* mergeNodes(ListNode* head) {
        if(head->next->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* res=new ListNode();
        ListNode* result=res;
        temp=temp->next;
        int sum=0;
        while(temp)
        {
            if(temp->val==0)
            {
                ListNode* t= new ListNode(sum);
                res->next=t;
                res=res->next;
                sum=0;
            }
            else
                sum+=temp->val;
            temp=temp->next;
        }
        //res->next=NULL;
        return result->next;
    }
};