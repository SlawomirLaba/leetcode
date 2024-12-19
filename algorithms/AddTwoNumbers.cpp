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
        int rem = 0;
        int total_val;
        int l1_val;
        int l2_val;
        auto result = l1;
        
        while(true) {
            total_val = l1->val + l2->val + rem;
            rem = total_val / 10;
            l1->val = total_val % 10;

            if (!l1->next && !l2->next) {
                if(rem != 0)
                    l1->next = new ListNode(rem);

                break;
            }

            if (l1->next) {
                l1 = l1->next;
                if (l2->next)
                    l2 = l2->next;
                else
                    l2->val = 0;
            } else {
                l1->next = l2->next;
                l1 = l1->next;
                l2->val = 0;
                l2->next = nullptr;
            }
        }

        return result;
    }
};