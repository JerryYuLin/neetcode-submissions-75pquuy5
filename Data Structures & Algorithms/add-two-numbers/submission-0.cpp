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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        ListNode* prev;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 !=nullptr && l2 != nullptr){
                curr->val = l1->val + l2->val;
                if(carry) curr->val++;
                if(curr->val>9){
                    curr->val -= 10;
                    carry = true;
                }
                else{
                    carry = false;
                }
                l1 = l1->next;
                l2 = l2->next;
                curr->next = new ListNode(0);
                prev = curr;
                curr = curr->next;
            }
            else if(l1 != nullptr){
                if(carry){
                    curr->val = l1->val + 1;
                    
                    if(curr->val > 9){
                        curr->val-=10;
                        carry = true;
                    }
                    else carry = false;
                }
                else {
                    curr->val = l1->val;
                    carry = false;
                }
                l1 = l1->next;
                curr->next = new ListNode(0);
                prev = curr;
                curr = curr->next;
            }
            else {
                if(carry){
                    curr->val = l2->val + 1;
                    
                    if(curr->val > 9){
                        curr->val-=10;
                        carry = true;
                    }
                    else carry = false;
                }
                else {
                    curr->val = l2->val;
                    carry = false;
                }
                l2 = l2->next;
                curr->next = new ListNode(0);
                prev = curr;
                curr = curr->next;
            }
        }

        if(carry){
            curr->val = 1;
        }
        else {
            prev->next = nullptr;
        }

        return head;
    }
};
