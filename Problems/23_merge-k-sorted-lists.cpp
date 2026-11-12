#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        std::size_t k = lists.size();
        for(std::size_t step = 1; step < k ;step*= 2){
            for(std::size_t j = 0; step + j < k; j += 2*step)
             lists[j] = mergeTwoLists(lists[j], lists[j+step]);
        }
        return lists[0];
    }
};