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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>res(m,vector<int>(n,-1));
        int maxrow=m-1,maxcol=n-1;
        int minrow=0,mincol=0;
        int counter=0;
        while(head){
            switch(counter%4){
                case 0:
                    for(int i=mincol;i<=maxcol;i++){
                        if(head){
                            res[minrow][i]=head->val;
                            head=head->next;
                        }
                        else break;
                    }
                    minrow++;
                    break;
                case 1:
                    for(int i=minrow;i<=maxrow;i++){
                        if(head){
                            res[i][maxcol]=head->val;
                            head=head->next;
                        }
                        else break;
                    }
                    maxcol--;
                    break;
                
                case 2:
                    for(int i=maxcol;i>=mincol;i--){
                        if(head){
                            res[maxrow][i]=head->val;
                            head=head->next;
                        }
                        else break;
                    }
                    maxrow--;
                    break;
                case 3:
                    for(int i=maxrow;i>=minrow;i--){
                        if(head){
                            res[i][mincol]=head->val;
                            head=head->next;
                        }
                        else break;
                    }
                    mincol++;
                    break;
            }
            counter++;
        }
        return res;
    }
};