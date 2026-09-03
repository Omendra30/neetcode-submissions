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
        if(head == nullptr) return head;

        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            count++;
        }

        if(count == 1 && n == 1) return nullptr;
        if(count == n)return head->next;
        int idx  = count-n;
        int i=1;
        ListNode* prev = head;
        while(i!=idx){
            prev = prev->next;
            i++;
        }
        ListNode* curr = prev->next;

        prev->next = curr->next;
        curr->next = nullptr;

    return head;
    }
};
