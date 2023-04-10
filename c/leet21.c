#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *push(struct ListNode *list, int val)
{
    if (list == NULL)
    {
        list = (struct ListNode *)malloc(sizeof(struct ListNode));
        list->val = val;
        list->next = NULL;
    }
    else
    {
        struct ListNode *tmp = list;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->next->val = val;
        tmp->next->next = NULL;
    }
    return list;
}

void print(struct ListNode *list)
{
    struct ListNode *tmp = list;
    while (tmp)
    {
        printf("%d\n", tmp->val);
        tmp = tmp->next;
    }
}

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode *tmp1 = list1;
    struct ListNode *tmp2 = list2;
    struct ListNode *result = NULL;

    while (tmp1 || tmp2) {
        if (!tmp1 || (tmp2 && (tmp1->val > tmp2->val))) {
            result = push(result, tmp2->val);
            tmp2 = tmp2->next;
        } else {
            result = push(result, tmp1->val);
            tmp1 = tmp1->next;
        }
    }

    return result;
}

int main()
{
    printf("List1:\n");
    struct ListNode *list1 = push(NULL, 1);
    push(list1, 2);
    push(list1, 4);
    print(list1);

    printf("\nList2:\n");

    struct ListNode *list2 = push(NULL, 1);
    push(list2, 3);
    push(list2, 4);
    print(list2);

    printf("\nOutput:\n");
    print(mergeTwoLists(list1, list2));

    return 0;
}
