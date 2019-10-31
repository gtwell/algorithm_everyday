#include <iostream>

struct Node
{
    int data;  // 存放int数据
    Node* next;  // 指向下一个节点指针
};

// 遍历链表
void PrintLists(Node* pNode)
{
    while (NULL != pNode)
    {
        printf("%d ", pNode->data);
        pNode = pNode->next;
    }
    printf("\n");
}

Node* InsertAfter(Node* curr, int newData)
{
    Node* pTempNode = new Node;
    pTempNode->data = newData;

    // 注意判断curr是否为空
    if (NULL != curr)
    {
        pTempNode->next = curr->next;
        curr->next = pTempNode;
    }
    
    return pTempNode;
}

Node* DeleteAfter(Node* curr)
{
    Node* pTempNode;

    if (NULL != curr)
    {
        pTempNode = curr->next->next;
        delete curr->next;
        curr->next = pTempNode;
    }

    return pTempNode;
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    Node* pTemp = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    pTemp = InsertAfter(second, 5);
    PrintLists(head);

    DeleteAfter(second);

    PrintLists(head);

    return 0;
}