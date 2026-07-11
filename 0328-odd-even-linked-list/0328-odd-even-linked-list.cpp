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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyHead1 = new ListNode(-1);
        ListNode* dummyHead2 = new ListNode(-1);
        ListNode* odd = dummyHead1;
        ListNode* even = dummyHead2;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            if(cnt%2==0){
                odd->next = temp;
                odd = odd->next;
            }
            else{
                even->next = temp;
                even = even->next;
            }
            cnt++;
            temp= temp->next;
        }
        even->next = NULL;
        odd->next = dummyHead2->next;
        return dummyHead1->next;
    }
};