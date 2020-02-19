typedef struct ListNode ln;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
// linked list of linked lists
{
    if (listsSize == 0)
        return NULL;
    else if (listsSize == 1)
        return lists[0];
    else if (listsSize == 2)
        return mergeTwoLists(lists[0], lists[1]);

    // divide and conquor if listsSize is still > 3
    return mergeTwoLists(mergeKLists(lists, listsSize / 2),
        mergeKLists(lists + listsSize / 2, listsSize - listsSize / 2));
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
// returns a pointer to the sorted list
{
    if ((l1 == NULL) && (l2 == NULL))
        return NULL;
    else if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    if (l1->val > l2->val)
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    return NULL;
}
