#include <iostream>

class ListNode
{
public:
    int val {};
    ListNode *next {};

    ListNode() : val(0), next(nullptr)
    {
    }

    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }

    ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
    {
    }
};

ListNode* merge(ListNode* list1, ListNode* list2)
{
    if (list1 == nullptr)
        return list2;

    if (list2 == nullptr)
        return list1;

    ListNode* head;
    if (list1->val < list2->val)
    {
        head = list1;
        list1 = list1->next;
    } else
    {
        head = list2;
        list2 = list2->next;
    }

    ListNode* cur { head };
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
        } else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    cur->next = list1 == nullptr ? list2 : list1;

    return head;
}

int main()
{
    return 0;
}
