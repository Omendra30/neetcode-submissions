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

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* curr = secondHalf;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* A = head;
        ListNode* B = prev;
        while(B != nullptr){
            ListNode* A_next = A->next;
            ListNode* B_next = B->next;

            A->next = B;
            B->next = A_next;
            A = A_next;
            B = B_next;
        }
        return ;
    }
};
