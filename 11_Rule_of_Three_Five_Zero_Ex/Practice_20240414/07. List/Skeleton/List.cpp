#include "List.h"

#include <sstream>

// class List {
// private:




    // class Node {
    // private:
    //     int value;
    //     Node * prev;
    //     Node * next;

    // public:
        List::Node::Node(int value, Node * prev, Node * next) : value(value), prev(prev), next(next) {};

        int List::Node::getValue() const {
            return value;
        };


        void List::Node::setValue(int value) {
            value=value;
        };

        List::Node * List::Node::getNext() const {
            return next;
        };
        void List::Node::setNext(Node * next) {
            next=next;
        };

        List::Node * List::Node::getPrev() const {
            return prev;
        };
        void List::Node::setPrev(Node * prev) {
            prev=prev;
        };






//     Node * head;
//     Node * tail;
//     size_t size;
// public:
    List::List() : size(0), head(nullptr), tail (nullptr) {};

    List::List(const List& other){
        //todo
    };

    int List::first() const {
        return head->getValue();
    };

    void List::add(int value) {
        if (size==0) {
            head=tail=new Node(value, nullptr,nullptr);
            size++;
        }
        else {
            Node * newNode=new Node (value,tail, nullptr);
            tail->setNext(newNode);
            tail=newNode;
            size++;
        };
    };

    void List::addAll(const List& other) {
        for (Node * curr=other.head;curr!=nullptr;curr=curr->getNext()) {
            add(curr->getValue());
        };
    };

    void List::removeFirst() {
        if (size) {
            Node * newHead=head->getNext();
            newHead->setPrev(nullptr);
            delete head;
            head=newHead;
            size--;
        };
    };

    void List::removeAll() {
        while(size) {
            removeFirst();
        };
    };

    size_t List::getSize() const {
        return size;
    };

    bool List::isEmpty() const {
        return (size==0);
    };

    //static List List::getReversed(List l);

    std::string List::toString() const{
        std::ostringstream  ostr;
        for (Node * curr=head; curr!=nullptr; curr=curr->getNext()) {
            ostr<<curr->getValue()<<' ';
        };
        return ostr.str();
    };

    List& List::operator<<(const int& value) {
        add(value);
        return *this;
    };

    List& List::operator<<(const List& other) {
        addAll(other);
        return *this;
    };

    List& List::operator=(const List& other) {
        removeAll();
        addAll(other);
        return *this;
    };

    List::~List() {
        removeAll();
    };

