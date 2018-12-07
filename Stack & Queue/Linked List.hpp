//
//  File Name: Linked List.hpp
//  Project: Linked List
//  Description: This file contains a Node Class with all linked list functions.
//  Created by Jack Zhao on 10/15/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp
#include <iostream>
namespace nz {
    
    template <class T>
    struct node {
        T _item;
        node* _next;
        // CTORS
        node(const T& item = T(), node<T>* next = nullptr);
    };
    
    // CTORS
    template <class T>
    node<T>::node(const T& item, node<T>* next): _item(item), _next(next) {
    }
    
    // Function declaration
    template <class T>
    node<T>* InsertHead(node<T>* &head, const T& item);
    
    template <class T>
    node<T>* InsertBefore(node<T>* &head, node<T>* mark, const T& item);
    
    template <class T>
    node<T>* InsertAfter(node<T>* &head, node<T>* mark, const T& item);
    
    template <class T>
    void PrintList(node<T>* head_ptr);
    
    template <class U>
    std::ostream& PrintList(std::ostream& outs, node<U>* head_ptr);
    
    template <typename T>
    node<T>* PreviousNode(node<T>* head, node<T>* prevToThis);
    
    template <class T>
    node<T>* SearchList (node<T>* head, const T& item);
    
    template <class T>
    T DeleteNode (node<T>*& head, node<T>* marker);
    
    template <class T>
    node<T>* CopyList(node<T>* head);
    
    template <class T>
    void ClearList(node<T>*& head_ptr);
    
    template <class T>
    T& at(node<T>* head, int pos);

    template <class T>
    node<T>* end(node<T>* head_ptr);
    
    // Function definition starts..
    template <class T>
    node<T>* InsertHead(node<T>* &head, const T& item) {
        //1. create a new node
        node<T>* temp = new node<T>(item);
        
        //2. temp's next points to where head points to.
        temp->_next = head;
        
        //3. point head_ptr to where temo is pointing to.
        head = temp;
        
        //4. return head pointer.
        return head;
    }
    
    template <class T>
    node<T>* InsertBefore(node<T>* &head, node<T>* mark, const T& item){
        // Find if the mark is head.
        // if true then do insert head.
        if (mark == head) {
            return InsertHead(head, item);
        }
        // Create a new node marked as the previous node.
        node<T>* previous = PreviousNode(head, mark);
        
        // Insert item after mark's previous
        return InsertAfter(head, previous, item);
    }
    
    template <class T>
    node<T>* InsertAfter(node<T>* &head, node<T>* mark, const T& item) {
        // If head is null, insert head.
        if (head == nullptr) {
            return InsertHead(head, item);
        }
        node<T>* new_node = new node<T>(item);
        node<T>* walker = head;
        while (walker != nullptr) {
            if (walker == mark) {
                // point next to mark's next node
                new_node->_next = mark->_next;
                // Point mark to the new node.
                mark->_next = new_node;
                return new_node;
            }
            // Point walker to the next walker
            walker = walker->_next;
        }
        return nullptr;
    }
    
    template <class T>
    node<T>* PreviousNode(node<T>* head, node<T>* prevToThis) {
        assert(head != nullptr);
        while (head != nullptr) {
            // if head is pointing to prevToThis
            if (head -> _next == prevToThis) {
                // return head.
                return head;
            }
            // point head to its next node.
            head = head -> _next;
        }
        return nullptr;
    }
    
    template <class U>
    std::ostream& PrintList(std::ostream& outs, node<U>* head_ptr) {
        // Print nothing if head is empty.
        if (head_ptr == nullptr) {
            return outs;
        }
        // Create a new node walker.
        node<U>* walker;
        // Point walker to the head ptr
        walker = head_ptr;
        while (walker != nullptr) {
            // Output item.
            outs<< "[" << walker -> _item << "] ";
            // Point walker to the next node.
            walker = walker->_next;
        }
        return outs;
    }
    
    template <typename T>
    void PrintList_backwards(node<T> *head_ptr) {
        // Print nothing if head is empty.
        if (head_ptr == nullptr) {
            std::cout << "";
            return;
        }
        // Create a new node pointer pointing to the head.
        node<T>* previous = head_ptr;
        // If head ptr is not the last node,
        if (head_ptr -> _next != nullptr) {
            // Point head to the next node
            head_ptr = head_ptr -> _next;
            // Call the function again,
            PrintList_backwards(head_ptr);
        }
        // Output the item from the last node.
        std::cout << "[" << previous -> _item << "] ";
    
    }
    
    template <class T>
    node<T>* SearchList (node<T>* head, const T& item) {
        // Return null if head is empty.
        if (head == nullptr)
            return nullptr;
        // Create a new node pointer pointing to head.
        node<T>* walker = head;
        while (walker != nullptr) {
            // If walker's item is the item we are looking for.
            if (walker->_item == item)
                // Return walker.
                return walker;
            // Otherwise, move walker to the next node.
            walker = walker->_next;
        }
        return nullptr;
    }
    
    template <class T>
    T DeleteNode (node<T>*& head, node<T>* marker) {
        assert(head != nullptr);
        if (marker == nullptr)
            return T();
        
        node<T>* walker = head;
        // If the marker is the only item in the list.
        if (walker == marker) {
            // Store return value
            T return_value = head->_item;
            // Point head to null
            head = marker -> _next;
            // Deallocate the space where marker points to
            delete marker;
            // Return deleted item.
            return return_value;
        }
        
        while (walker != nullptr) {
            if (walker -> _next == marker) {
                // Store return value
                T return_value = marker -> _item;
                // Point next to the marker's next node.
                walker -> _next = marker -> _next;
                // Delete marker.
                delete marker;
                return return_value;
            }
            walker = walker -> _next;
        }
        
        return T();
    }
    
    template <typename T>
    node<T>* CopyList(node<T>* head) {
        if (head == nullptr)
            return nullptr;
        // Create a new head pointer.
        node<T>* new_head = new node<T>(head->_item);
        // Create a walker.
        node<T>* walker = new_head;
        while (head -> _next != nullptr) {
            // Head points to the next node.
            head = head -> _next;
            // Insert after the next item to the right of the formmer walker.
            InsertAfter(new_head, walker, head->_item);
            // Walker points to the next node.
            walker = walker -> _next;
        }
        return new_head;
    }

    template <typename T>
    void ClearList(node<T>*& head_ptr) {
        while (head_ptr != nullptr) {
            // Delete the head ptr until it becomes a nullptr.
            DeleteNode(head_ptr, head_ptr);
        }
    }
    
    template <typename T>
    T& at(node<T>* head, int pos) {
        node<T>* walker = head;
        for (int i = 0; i < pos; i ++) {
            assert(walker != nullptr);
            // Walker points to the next node.
            walker = walker -> _next;
        }
        return walker -> _item;
    }
    
    template <class T>
    node<T>* end(node<T>* head_ptr) {
        node<T>* walker = head_ptr;
        if (walker == nullptr)
            return nullptr;
        while (walker -> _next != nullptr) {
            walker = walker -> _next;
        }
        return walker;
    }

}
    
#endif /* Node_hpp */
