#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to find the maximum twin sum of a linked list
int pairSum(ListNode* head) {
    if (!head || !head->next) return 0;

    ListNode* slow = head;
    ListNode* fast = head;

    // Find middle of the list
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode* secondHalf = reverseList(slow);

    // Calculate twin sums and find maximum
    int maxSum = 0;
    ListNode* firstHalf = head;
    while (secondHalf) {
        maxSum = std::max(maxSum, firstHalf->val + secondHalf->val);
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return maxSum;
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    std::cout << "Maximum twin sum: " << pairSum(head) << std::endl;

    return 0;
}

