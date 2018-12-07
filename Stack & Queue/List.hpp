//
//  List.hpp
//  List
//
//  Created by Jack Zhao on 10/31/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include "Linked List.hpp"
template <class T>
class list {
private:
    nz::node<T>* _head;
    
public:
    class Iterator {
        //the nested class
    public:
        friend class list;
        ////////////////////////////////////////////////////////////
        // This allows the nested class have access to the queque.
        ////////////////////////////////////////////////////////////
        
        
        Iterator(nz::node<T>* p = NULL):_ptr(p){}
        ////////////////////////////////////////////////////////////
        /// -brief Default Constructor
        ///
        /// -param: a type T* pointer, with default value nullptr.
        ///
        ////////////////////////////////////////////////////////////
        
        Iterator next() {
            return Iterator(_ptr -> _next);
        }
        ////////////////////////////////////////////////////////////
        /// -brief Element accessor
        ///
        /// -return An Iterator that points to the next node.
        ///
        ////////////////////////////////////////////////////////////
        
        T& operator *(){                    //dereference oprator
            assert(_ptr);
            return _ptr->_item;
        }
        ////////////////////////////////////////////////////////////
        /// -brief Deference Operator.
        ///
        /// -return the value which _ptr points to.
        ///
        ////////////////////////////////////////////////////////////
        
        friend Iterator operator ++(Iterator& it, int unused){
            Iterator hold;
            hold = it;
            it._ptr = it._ptr -> _next;
            return hold;
        }
        ////////////////////////////////////////////////////////////
        /// -brief ++ operator overloading.
        ///
        /// Move the pointer to its next address.
        /// example: it++;
        ///
        /// -return an Iterator.
        ///
        ////////////////////////////////////////////////////////////
        
        Iterator& operator ++(){              //++it
            _ptr = _ptr -> _next;
            return *this;
        }
        ////////////////////////////////////////////////////////////
        /// -brief ++operator overloading, element modifier.
        ///
        /// Move the pointer to its next address.
        /// example: ++it;
        ///
        /// -return an Iterator.
        ///
        ////////////////////////////////////////////////////////////
        
        friend bool operator !=(const Iterator& left, const Iterator& right){
            return left._ptr != right._ptr;
        }
        ////////////////////////////////////////////////////////////
        /// -brief != operator overloading.
        ///
        /// Determine if two iterators are the same.
        ///
        /// -return a boolean.
        ///
        ////////////////////////////////////////////////////////////
        
    private:
        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        int _SIZE;
        nz::node<T>* _ptr;                    //pointer being encapsulated
    };
    
    // CTORS
    list(nz::node<T>* p = nullptr): _head(p){}
    // Destructor.
    ~list() {nz::ClearList(_head);}
    // Copy Constructor
    list(const list<T> &copyThis) {
        _head = nz::CopyList(copyThis._head);
    }
    // Assignment operator.
    list& operator =(const list& RHS) {
        return (this == &RHS)? *this:(_head = nz::CopyList(RHS._head), *this);
    }
    
    T& front() const{
        return _head -> _item;
    }
    
    nz::node<T>* Begin() const{
        return _head;
    }
    
    nz::node<T>* End() const{
        return nz::end(_head);
    }
    
    Iterator find(const T& _FIND_THIS) {
        return Iterator(nz::SearchList(_head, _FIND_THIS));
    }
    
    Iterator insertAfter(const Iterator& mark, const T& item) {
        return Iterator(nz::InsertAfter(_head, mark._ptr, item));
    }
    
    Iterator insertHead(const T& item) {
        return Iterator(nz::InsertHead(_head, item));
    }
    
    bool isEmpty() const{
        return _head == nullptr;
    }
    
    T removeNode(const Iterator& mark) {
        return nz::DeleteNode(_head, mark._ptr);
    }
    
    void clear() {
        nz::ClearList(_head);
    }
    
    nz::node<T>* head() const{
        return _head;
    }
    
    std::ostream& print(std::ostream& outs, const list& print_me) const{
        return nz::PrintList(outs, print_me._head);
    }
    
    
};

#endif /* List_hpp */
