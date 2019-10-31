## 链表
### 1. 定义一个链表
```cpp
class Node
{
    public:
    int data;
    Node* next;
};
```
### 2. 遍历链表
```cpp
void printList(Node* node)
{
    while (NULL != node)
    {
        cout << node->data << " ";
        n = n->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(head);

    delete head;
    delete second;
    delete third;

    return 0;
}


### References
1. https://www.geeksforgeeks.org/linked-list-set-1-introduction/