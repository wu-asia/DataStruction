list create(int n)
{
    //如果只有一个人，则直接返回一个节点
    if (n == 1){
        node* head = (node*)malloc(sizeof(node));
        head->data = 1;
        head->next = head;
        return head;
    }
    //如果有多个人，则创建一个循环链表
    node* head = NULL;
    node* tail = NULL;
    head = (node*)malloc(sizeof(node));
    tail = (node*)malloc(sizeof(node));
    head->data = 1;
    head->next = tail;
    tail->data = n;
    tail->next = head;
    //从n-1开始，使用头插法创建一个循环链表
    for (int i = n - 1; i >= 2; i--)
{
        node* t = (node*)malloc(sizeof(node));
        t->data = i;
        t->next = head->next;
        head->next = t;
    }
    return head;
}
