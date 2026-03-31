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
    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* tail = head;

        // find tail and mid
        while(tail != nullptr && tail->next != nullptr && tail->next->next != nullptr){
            mid = mid->next;
            tail = tail->next->next;
        }

        if(tail != nullptr && tail->next != nullptr){
            tail = tail->next;
            mid = mid->next;
        }

        // reverse mid to tail
        ListNode* curr = mid;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* temp = curr->next;

            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }

        // reorder
        ListNode* h = head;
        while(tail != mid){
            ListNode* temp = tail;
            tail = tail->next;

            temp->next = head->next;
            head->next = temp;
            head = temp->next;
        }
    }
};