#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *ListNode(int val)
{
    struct ListNode *list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list->val = val;
    list->next = NULL;
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
    struct ListNode *tmpr = NULL;

    while (tmp1 || tmp2)
    {
        if (tmp2 && !tmp1 || tmp1->val > tmp2->val)
        {
            if (!result)
            {
                result = ListNode(tmp2->val);
                tmpr = result;
            }
            else
            {
                tmpr->next = ListNode(tmp2->val);
                tmpr = tmpr->next;
            }

            tmp2 = tmp2->next;
        }
        else
        {
            if (!result)
            {
                result = ListNode(tmp1->val);
                tmpr = result;
            }
            else
            {
                tmpr->next = ListNode(tmp1->val);
                tmpr = tmpr->next;
            }

            tmp1 = tmp1->next;
        }
    }

    return result;
}

int main()
{
    // struct ListNode *t = NULL;
    // struct ListNode *a;
    // t = malloc(sizeof(struct ListNode));
    // a = t;
    // a->val = 2;
    // printf("%d\n", t->val);

    printf("List1:\n");
    struct ListNode *list1 = ListNode(0);
    list1->next = ListNode(2);
    list1->next->next = ListNode(4);
    print(list1);

    printf("\nList2:\n");
    struct ListNode *list2 = ListNode(1);
    list2->next = ListNode(3);
    list2->next->next = ListNode(5);
    print(list2);

    printf("\nOutput:\n");
    print(mergeTwoLists(list1, list2));

    return 0;
}
