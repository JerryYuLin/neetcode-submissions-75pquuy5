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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *current_node, *head, *curr_list1 = list1, *curr_list2 = list2;

        if(curr_list1 == nullptr && curr_list2 != nullptr){
            head = curr_list2;
            current_node = curr_list2;
            curr_list2 = curr_list2->next;
        }
        else if (curr_list2 == nullptr && curr_list1 != nullptr){
            head = curr_list1;
            current_node = curr_list1;
            curr_list1 = curr_list1->next;
        }
        else if (curr_list1 != nullptr && curr_list2 != nullptr){
            if(curr_list1->val < curr_list2->val){
                head = curr_list1;
                current_node = curr_list1;
                curr_list1 = curr_list1->next;
            }
            else {
                head = curr_list2;
                current_node = curr_list2;
                curr_list2 = curr_list2->next;
            }
        }
        else {
            return nullptr;
        }

        while(true) {
            if(curr_list1 == nullptr && curr_list2 != nullptr){
                current_node->next = curr_list2;
                curr_list2 = curr_list2->next;
            }
            else if (curr_list2 == nullptr && curr_list1 != nullptr){
                current_node->next = curr_list1;
                curr_list1 = curr_list1->next;
            }
            else if (curr_list1 != nullptr && curr_list2 != nullptr){
                if(curr_list1->val < curr_list2->val){
                    current_node->next = curr_list1;
                    curr_list1 = curr_list1->next;
                }
                else {
                    current_node->next = curr_list2;
                    curr_list2 = curr_list2->next;
                }
            }
            else break;
            
            current_node = current_node->next;
        }

        return head;
    }
};