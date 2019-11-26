/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        
        Node *end;
        
        if (head == NULL)
            return head;
        end = rec_flat(head);
        
        return head;
    }
    
        Node* rec_flat(Node* head) {
    
            Node* current = head;
            Node* next;
            Node* child;
            Node* end;

            while(current->next!=NULL){
                            
                if(current->child!=NULL){
                    next = current->next;
                    child = current->child;
                    end = rec_flat(current->child);
                    current->next = child;
                    child->prev = current;
                    current->child = NULL;
                    end->next = next;
                    cout << (end->val)<<endl;
                    cout << "next val" <<endl;
                    cout << (next->val)<<endl;
                    next->prev = end;
                    current = end;
                }
                current = current->next;
                
            }
            if(current->child!=NULL){
                    child = current->child;
                    end = rec_flat(current->child);
                    current->next = child;
                    child->prev = current;
                    current->child = NULL;
                    current = end;
                }
            return current;
    
        }
    
};