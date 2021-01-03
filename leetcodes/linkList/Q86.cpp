#include <cstdlib>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smallHead = new ListNode(1);
        ListNode *largeHead = new ListNode(1);
        ListNode *s = smallHead;
        ListNode *l = largeHead;
        while (head != NULL)
        {
            if (head->val < x)
            {
                s->next = new ListNode(head->val);
                s = s->next;
            }
            else
            {
                l->next = new ListNode(head->val);
                l = l->next;
            }
            head = head->next;
        }
        s->next = largeHead->next;
        return smallHead->next;
    }
};
