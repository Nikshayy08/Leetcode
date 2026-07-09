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

    ListNode* ReverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nextNode;
        
        while(cur!=nullptr){
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = ReverseList(slow->next);
        ListNode* temp = head;
        while(head2!=nullptr){
            if(head2->val!=temp->val){
                return false;
            }
            head2 = head2->next;
            temp = temp->next;
        }
        return true;
    }
};