//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

// 在链表类中实现这些功能：

// get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
// addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
// addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
// addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。
// deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        LinkedList = 0;
    }
    ListNode *LinkedList;
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
       int i = 0;
        ListNode *head = LinkedList;
        while(head && i<index){
            head = head->next;
            i++;
        }
        if(head && i==index) return head->val;
        else return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *head = (ListNode *)malloc(sizeof(ListNode));
        head->next = LinkedList;
        head->val = val;
        LinkedList = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *head = LinkedList;
        ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->val = val;
        tmp->next = NULL;
        if(!head){
            LinkedList = tmp;
            return;
        }
        while(head->next){
            head = head->next;
        }
        head->next = tmp;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i = 0;
        ListNode *head = LinkedList;
        if(!head && index == 0){
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = 0;
            LinkedList = tmp;
            return ;
        }
        while(head && i<index-1){
            head = head->next;
            i++;
        }
        if(head && head->next==NULL){
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = 0;
            head->next = tmp;
            return;
        }
        else if(i == index-1 && head && head->next){
            ListNode *tmp = (ListNode *)malloc(sizeof(ListNode));
            tmp->val = val;
            tmp->next = 0;
            tmp->next = head->next;
            head->next = tmp;
            return;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int i = 0;
        ListNode *head = LinkedList;
        while(head && i<index-1){
            head = head->next;
            i++;
        }
        if (head == 0) return;
        if(head->next == 0 && index == 0 ) 
        {
            LinkedList = 0;
            return;
        }
        if(head->next){
            ListNode *tmp = head->next;
            head->next = tmp->next;
            free(tmp);
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */