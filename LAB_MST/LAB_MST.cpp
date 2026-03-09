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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr  = head;
        int count= 0 ;
        while(curr!=NULL && count<k){
            curr = curr->next;
            count++;
        }
        if(count==k){
            ListNode* prev = NULL;
            ListNode* next = NULL;
            curr = head;
            count = 0 ;

            while(count<k && curr!=NULL){
                next  = curr->next;
                curr->next  = prev;
                prev = curr;
                curr = next;
                count++;
            }
            head->next = reverseKGroup(curr,k);
            return prev;
        }
        return head;

    }
};