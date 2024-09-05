// 

// Insert a node at the head of a linked list
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* a=new SinglyLinkedListNode(data);
    a->next=llist;
    return a;
}
// Insert a Node at the Tail of a Linked List
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* a= new SinglyLinkedListNode(data);
    SinglyLinkedListNode* temp=head;
    a->next=nullptr;
    a->data=data;
    if (temp==NULL) return a;
    while(temp->next!=nullptr) temp=temp->next;
    temp->next=a;
    return head;
}
// Reverse a linked list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev   = NULL;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next;
    
    while (current != NULL) {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    return prev;
}
// Print in Reverse
void reversePrint(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* prev   = NULL;
    SinglyLinkedListNode* current = llist;
    SinglyLinkedListNode* next;
    
    while (current != NULL) {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    llist=prev;
    SinglyLinkedListNode* temp=llist;
    while(temp!=nullptr){
        cout<<temp->data << endl;
        temp=temp->next;
    }
    return ;
}
// Compare two linked lists
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) return 0;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) return 1;
    else return 0;
}
// Get Node Value
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    SinglyLinkedListNode* a=llist;
    SinglyLinkedListNode* b=llist;
    int i=0;
    while(i < positionFromTail && a->next != NULL){
        a=a->next;
        i++;
    }
    while(a->next!=NULL){
        b=b->next;
        a=a->next;
    }
    return b->data;
}
// Merge two sorted linked lists
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* result = NULL;
 
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    
    if (head1->data <= head2->data) {
        result = head1;
        result->next = mergeLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeLists(head1, head2->next);
    }
    return result;
}
/*
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *head = new SinglyLinkedListNode(0);
    SinglyLinkedListNode *temp = head;
    while(head1 != nullptr && head2 != nullptr){
        if (head1->data <= head2->data){
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    
    if(head1 != nullptr) temp->next = head1;
    else if(head2 != nullptr) temp->next = head2;
    
    return head->next;
}
*/
// Delete duplicate-value nodes from a sorted linked list
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if (llist == NULL || llist->next == NULL) return llist;

    SinglyLinkedListNode *p = llist->next, *last = llist;
    
    while(p != NULL) {
        if (last->data == p->data) {
            last->next = p->next;
            p = last->next;
        } else {
            last = p;
            p = p->next;
        }
    }
    
    return llist;
}


