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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while(fast != nullptr){
            if(i >= n){
                prev = slow;
                slow = slow->next;
            }
            fast = fast->next;
            i++;
        }

        if(slow==head){
            head = slow->next;
        }
        else {
            prev->next = slow->next;
        }

        return head;
    }
};