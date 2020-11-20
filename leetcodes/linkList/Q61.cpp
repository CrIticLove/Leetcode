
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0)
            return head;
        ListNode *move = head;
        int len = 1;
        if (!move)
            return nullptr;
        while (move->next)
        {
            len++;
            move = move->next;
        }
        move->next = head;
        int step = len - k % len;
        move = head;
        for (int i = 0; i < step - 1; i++)
        {
            move = move->next;
        }
        ListNode *newhead = move->next;
        move->next = nullptr;
        return newhead;
    }
};
