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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *p = res;
        int add = 0;
        int sum;
        while (l1 != nullptr && l2 != nullptr)
        {
            sum = l1->val + l2->val + add;
            p->next = new ListNode(sum % 10);
            add = sum / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            sum = l1->val + add;
            p->next = new ListNode(sum % 10);
            add = sum / 10;
            p = p->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            sum = l2->val + add;
            p->next = new ListNode(sum % 10);
            add = sum / 10;
            p = p->next;
            l2 = l2->next;
        }
        if (l1 == nullptr && l2 == nullptr && add > 0)
        {
            p->next = new ListNode(add);
            p = p->next;
        }
        return res->next;
    }
};