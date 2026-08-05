#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_set<ListNode*> visited;

        while(head != NULL)
        {
            if(visited.count(head))
                return true;

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};
