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
// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         int start = 0;
//         int end = arr.size()-1;
//         int twinSum = INT_MIN;
//         while(start<end){
//             int sum = arr[start] + arr[end];
//             twinSum = max(sum,twinSum);
//             start++;
//             end--;
//         }
//         return twinSum;
//     }
// };

class Solution {
    ListNode* ReverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur!=nullptr){
            ListNode* nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = ReverseList(slow->next);
        ListNode* p = head;
        int twinSum = INT_MIN;
        while(head2!=nullptr){
            int sum = p->val + head2->val;
            twinSum = max(sum,twinSum);
            p = p->next;
            head2 = head2->next;
        }
        return twinSum;
    }
};