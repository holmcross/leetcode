/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, bool carry=0) {
        if(l1 == NULL || l2 == NULL){
            if(l1 == NULL && l2 == NULL){
                if(carry){
                    ListNode* node = new ListNode(carry);
                    return node;
                }
                else{
                    return NULL;
                }
            }
            else if(l1){
                int sum = l1->val + carry;
                int carry = sum/10;
                ListNode* node = new ListNode(sum%10);
                node->next = addTwoNumbers(l1->next, NULL, carry);
                return node;
            }
            else{
                int sum = l2->val + carry;
                int carry = sum/10;
                ListNode* node = new ListNode(sum%10);
                node->next = addTwoNumbers(NULL, l2->next, carry);
                return node;
            }
        }
        else{
            int sum = l1->val + l2->val + carry;
            int carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            node->next = addTwoNumbers(l1->next, l2->next, carry);
            return node;
        }
    }
};