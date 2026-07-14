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
        if(head == NULL) return NULL;
        
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        n = len - n + 1;
        
        ListNode* KNode = head;
        ListNode* prevNode = NULL;
        int cnt = 0;
        while(KNode != NULL){
            cnt++;
            if(cnt == n) break;
            prevNode = KNode;
            KNode = KNode->next;
        }
        
        if(prevNode == NULL){
            // deleting the head node
            head = KNode->next;
            delete KNode;
            return head;
        }
        
        prevNode->next = KNode->next;
        delete KNode;
        return head;  
    }
};