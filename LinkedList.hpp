#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList
{
    public: // DO NOT CHANGE THIS PART.
        LinkedList();
        LinkedList(const LinkedList &obj);

        ~LinkedList();

        Node<T> *getFirstNode() const; //
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        int getNumberOfNodes();
        bool isEmpty(); //

        void insertAtTheFront(const T &data); //
        void insertAtTheEnd(const T &data); //
        void insertAfterGivenNode(const T &data, Node<T> *prev); //

        void removeNode(Node<T> *node);
        void removeAllNodes();

        Node<T> *findNode(const T &data); //

        void printAllNodes();
        void printReversed();

        LinkedList &operator=(const LinkedList &rhs);

    private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

    private: // DO NOT CHANGE THIS PART.
        Node<T> *head;
        Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head=new Node<T>;
    tail=new Node<T>;
    head->next=tail;
    tail->prev=head;
    head->prev=NULL;
    tail->next=NULL;
    /* TODO */
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    removeAllNodes();
    if (obj.head->next!=tail) {
        
    head->next=new Node<T>;
    Node<T>* temp=obj.head->next;
    Node<T>* curr=head->next;
    curr->element=temp->element;
    curr->next=tail;
    curr->prev=head;
    temp=temp->next;
  
    while (temp!=tail) {
        curr->next=new Node<T>;
        curr->next->prev=curr;
        curr=curr->next;
        curr->element=temp->element;
        curr->next=tail;
        
        temp=temp->next;
    }
    }

}

template<class T>
LinkedList<T>::~LinkedList()
{

    removeAllNodes();
    delete head;
    delete tail;

}
template<class T>
Node<T> * LinkedList<T>::getFirstNode() const
{
    if (head->next!=NULL && head->next!=tail) {
        
        return head->next;
    }
    return NULL;
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getHead() const
{
    return head;
    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::getTail() const
{
    return tail;
    /* TODO */
}

template<class T>
int LinkedList<T>::getNumberOfNodes()
{
    int i=0;
    if(head->next==tail){
        return i;
                        }
    
    Node <T> *curr;
    curr=head->next;
    while (curr) {
        i++;
        curr=curr->next;
    }
    curr=NULL;
    delete curr;
    return i;
    
    /* TODO */
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    return head->next==tail;
    /* TODO */
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data)
{
    Node<T> *n1 = new Node<T>(data,head,head->next);
    n1->element=data;
    head->next->prev=n1;
    head->next=n1;
    
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data)
{
    Node<T> *n1=new Node<T>;
    n1->element=data;
    if(head->next==tail){
        tail->prev=n1;
        n1->prev=head;
        head->next=n1;
        n1->next=tail;

        //n1->next=tail;
        //head->next=n1;
        //tail->prev=n1;
        //n1->prev=head;

}
    else{
        tail->prev->next=n1;
        n1->prev=tail->prev;
        n1->next=tail;
        tail->prev=n1;
        //n1->next=tail;
        //n1->prev=tail->prev;
        //tail->prev->next=n1;
        //tail->prev=n1;
    
}

}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev)
{
    Node<T> *n1=new Node<T>;
    n1->element=data;
    if(prev!=tail){
        n1->next=prev->next;
        n1->prev=prev;
        prev->next->prev=n1;
        prev->next=n1;
}
    else{
        throw "prev cannot be tail";
        }
    n1=NULL;
    delete n1;
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    Node<T> *temp=head->next;
    while(temp){
        if(temp==node){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            break;
}
    temp=temp->next;
}
    temp=NULL;
    delete temp;

}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    while(!isEmpty()){
        removeNode(head->next);
}

    /* TODO */
}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data)
{
    Node<T> *temp=head->next;
    while(temp!=tail){
        if(temp->element == data) {
            
            return temp;
    }
        temp=temp->next;
}
    
    return NULL;
    /* TODO */
}

template<class T>
void LinkedList<T>::printAllNodes()
{


    Node<T> *temp;
    temp=head->next;
    while(temp!=tail){
    std::cout<<temp->element<<std::endl;
    temp=temp->next;
                }
    temp=NULL;
    delete temp;
    

    /* TODO */
}

template<class T>
void LinkedList<T>::printReversed()
{
    Node<T> *temp=tail->prev;
    while(temp!=head){
        std::cout<<temp->element<<std::endl;
        temp=temp->prev;
}
    temp=NULL;
    delete temp;
    /* TODO */
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs)
{
    if(this != &rhs){
        removeAllNodes();
    if (rhs.head->next!=tail) {
        
    head->next=new Node<T>;
    Node<T>* temp=rhs.head->next;
    Node<T>* curr=head->next;
    curr->element=temp->element;
    curr->next=tail;
    curr->prev=head;
    temp=temp->next;
  
    while (temp!=tail) {
        curr->next=new Node<T>;
        curr->next->prev=curr;
        curr=curr->next;
        curr->element=temp->element;
        curr->next=tail;
        
        temp=temp->next;
    }
    }
    return *this;
}
    
    return *this;
    /* TODO */
}


#endif //LINKED_LIST_HPP
