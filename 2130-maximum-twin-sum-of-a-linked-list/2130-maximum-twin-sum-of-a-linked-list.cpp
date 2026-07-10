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
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int start = 0;
        int end = arr.size()-1;
        int twinSum = INT_MIN;
        while(start<end){
            int sum = arr[start] + arr[end];
            twinSum = max(sum,twinSum);
            start++;
            end--;
        }
        return twinSum;
    }
};