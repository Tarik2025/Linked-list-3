#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to convert binary number in a linked list to an integer
int getDecimalValue(ListNode* head) {
    int num = 0;
    while (head) {
        num = (num << 1) | head->val; // Shift left and add current value
        head = head->next;
    }
    return num;
}

// Main function to test the solution
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    std::cout << "Decimal value of the binary linked list: " << getDecimalValue(head) << std::endl;

    return 0;
}

