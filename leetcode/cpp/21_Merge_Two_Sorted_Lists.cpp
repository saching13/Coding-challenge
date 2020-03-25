/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Use a dummy node.
// This  cod doesntuse dummynode.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* sorted_list ;
        ListNode* current_update;
        
        if (l1!=NULL || l2!=NULL)
        {
            //cout << "rere";
            if (l1==NULL)
                    return l2;
            if (l2==NULL)
                return l1;
            if (p->val < q->val){
                sorted_list = p;
                p = p->next;}
            else{
                sorted_list = q;
                q=q->next;
            }
        }
        
         if (l1==NULL && l2==NULL)
         {
            return l1;
         }
        current_update = sorted_list;
        
        while(p!=NULL || q!=NULL){
            //#cout <<"pval:"<<endl;
//             cout <<"qval:"<<q->val<<endl;
            
            if (p==NULL){
                current_update->next = q;
                    break;
            }
            else if (q==NULL){
                current_update->next = p;
                    break;
            }
            else if (p->val < q->val){
                current_update->next = p;
                    p=p->next;
            }
            else{
                current_update->next = q;
                    q=q->next;
            }
                
            current_update = current_update->next;
            
        }
        
        return sorted_list;
    }
};