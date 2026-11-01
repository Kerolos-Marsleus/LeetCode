struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast != nullptr){
        if(fast->next == nullptr){
            return slow;
        }else if(fast->next->next == nullptr){
            return slow->next;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return nullptr;
}

ListNode* reverseList(ListNode* head) {
        ListNode* n = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        
        while(curr != nullptr){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }

void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)return;
    ListNode* midNode = middleNode(head);
    ListNode* midReversed = reverseList(midNode->next);
    midNode->next = nullptr;
    ListNode* a1 = head;
    ListNode* b1 = midReversed;

    while(b1 != nullptr){
        ListNode* a2 = a1->next;
        ListNode* b2 = b1->next;

        a1->next = b1;
        b1->next = a2;

        a1 = a2;
        b1 = b2;
    }
    


}
