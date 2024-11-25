#include<iostream>
#include<stack>

using namespace std;

  struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        ListNode* temp = head;
        stack<int> stack;

        while (temp != nullptr) {
            stack.push(temp->val);
            temp = temp->next;
        }

        ListNode* newHead = nullptr;
        ListNode* current = nullptr;

        while (!stack.empty()) {
            ListNode* newNode = new ListNode(stack.top());
            stack.pop();

            if (newHead == nullptr) {
                newHead = newNode;
                current = newHead;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }
        return newHead;
    }
};