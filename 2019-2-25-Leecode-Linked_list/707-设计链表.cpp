typedef struct LNode{
    int val;
    //next指针用来指向链表的下一个节点，该节点同样为一个LNode结构体，因此next要声明为指向LNode结构体的指针struct LNode*。
    struct LNode * next;
}Node;

Node * make_node(int val, Node * next) {
    Node * rv = (Node *)malloc(sizeof(Node));  
    assert(rv);
    rv->val = val;  
    rv->next = next;
    return rv;
}

void free_list(Node * head) {
    Node * prev;
    while (head) {
            prev = head;
            head = head->next;
            free(prev);
    }
}
typedef struct {
    struct LNode * head;//head指针用来指向链表的头节点，该节点同样为一个LNode结构体，因此head要声明为指向LNode结构体的指针struct LNode*。
    struct LNode * tail;//tail指针用来指向链表的尾节点，该节点同样为一个LNode结构体，因此tail要声明为指向LNode结构体的指针struct LNode*。
    int size;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList * myLinkedListCreate() {
    MyLinkedList * rv = (MyLinkedList *)calloc(1,sizeof(MyLinkedList));
    return rv;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj->size <= index)  return -1;
    Node * cur = obj->head;
    for(int i=0;i<index;i++)
        cur = cur->next;
    return cur->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node * newNode = make_node(val,obj->head);
    obj->size += 1;
    obj->head = newNode;
    if(obj->size == 1)
        obj->tail = obj->head;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if(obj->tail) {
        Node * newNode = make_node(val,NULL);
        obj->tail->next = newNode;
        obj->tail = newNode;
        obj->size += 1;
    }else
        myLinkedListAddAtHead(obj,val);
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj->size < index || index < 0)   return;
    if(obj->size == index)
        return myLinkedListAddAtTail(obj,val);
    if(index == 0)
        return myLinkedListAddAtHead(obj,val);
    if(obj->size > index){
        Node * cur = obj->head;
        for(int i=1;i<index;i++)
            cur = cur->next;
        Node * newNode = make_node(val,cur->next);
        cur->next = newNode;
        obj->size += 1;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(obj->size <= index || index < 0)   return;
    if(index == 0){
        Node * delNode;
        delNode = obj->head;
        obj->head = delNode->next;
        free(delNode);
        obj->size -= 1;
        return;
    }
    if(index == obj->size-1){
        Node * delNode = obj->head;
        while(delNode->next != obj->tail)
            delNode = delNode->next;
        free(delNode->next);
        obj->tail = delNode;
        obj->size -= 1;
        return;
    }
    Node * delNode,* moveNode;
    moveNode = obj->head;
    for (int i = 1; i < index; i++) {
            moveNode = moveNode->next;
    }
    delNode = moveNode->next;
    moveNode->next = delNode->next;
    free(delNode);
    obj->size -= 1;
}

void myLinkedListFree(MyLinkedList* obj) {
    free_list(obj->head);
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */