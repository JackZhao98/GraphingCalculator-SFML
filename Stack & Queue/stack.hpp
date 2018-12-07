//
//  steck.hpp
//  steck
//
//  Created by Jack Zhao on 10/30/18.
//  Copyright © 2018 Jack Zhao. All rights reserved.
//

#ifndef steck_hpp
#define steck_hpp
#include "List.hpp"

////////////////////////////////////////////////////////////
/// \class steck
///
/// This class is a built-in stack class clone,
/// contains most of the member functions like push() and pop()...
/// it pushes from the top and pops from the top like a real stack.
/// It integrates a nested Iterator class in case users need access to
///  the pointers.
///
/// Usage example:
/// \code
/// steck<int> q;
/// for (int i = 0; ++i < 10;) q.push(i);
/// std::cout << q;
/// std::cout << q.pop() << std::endl << q;
/// q.push(1);
/// std::cout << q;
///
/// \endcode
/// \example print
///
/// [9] [8] [7] [6] [5] [4] [3] [2] [1]
/// 9
/// [8] [7] [6] [5] [4] [3] [2] [1]
/// [1] [8] [7] [6] [5] [4] [3] [2] [1] 
/// Program ended with exit code: 0
///
////////////////////////////////////////////////////////////
template <class T>
class steck {
private:
    ////////////////////////////////////////////////////////////
    // Member data.
    ////////////////////////////////////////////////////////////
    list<T> _steck;
    int _SIZE;
    
public:
    class Iterator {
        //the nested class
    public:
        friend class steck;
        ////////////////////////////////////////////////////////////
        // This allows the nested class have access to the steck.
        ////////////////////////////////////////////////////////////
        
        
        Iterator(nz::node<T>* p = NULL):_ptr(p){}
        ////////////////////////////////////////////////////////////
        /// -brief Default Constructor
        ///
        /// -param: a type T* pointer, with default value nullptr.
        ///
        ////////////////////////////////////////////////////////////
        
        Iterator(const list<T>& _COPY_ITERATOR):_ptr(_COPY_ITERATOR.Begin()){}
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
        nz::node<T>* _ptr;                    //pointer being encapsulated
    };
    
    
    steck():_steck(), _SIZE(0){};
    ////////////////////////////////////////////////////////////
    /// -brief Default Constructor
    ///
    /// -param: steck list.
    ///
    ////////////////////////////////////////////////////////////
    
    ~steck() {_steck.clear();}
    ////////////////////////////////////////////////////////////
    /// -brief Destructor
    ///
    ///  Runs clear() from the List class
    ///
    ////////////////////////////////////////////////////////////
    
    steck(const steck& _COPY_ITEM);
    ////////////////////////////////////////////////////////////
    /// -brief Copy Constructor
    ///
    /// -param: steck type another item.
    ///
    ////////////////////////////////////////////////////////////
    
    steck& operator = (const steck& _COPY_ITEM);
    ////////////////////////////////////////////////////////////
    /// -brief Copy constructor operator.
    ///
    /// -param: steck type another item.
    ///
    ////////////////////////////////////////////////////////////
    
    void push(const T& _T_TYPE_ITEM);
    ////////////////////////////////////////////////////////////
    /// -brief Element modifier.
    ///
    /// Add new item to the linked list from the front of the list.
    ///
    /// -param Type T item to be pushed.
    ///
    ////////////////////////////////////////////////////////////
    
    const T pop();
    ////////////////////////////////////////////////////////////
    /// -brief Element modifier.
    ///
    /// Pop()
    /// Return the value of the first item.
    /// Meanwhile, remove the first item that is popped.
    /// Function asserts only if the list is not empty.
    ///
    /// -return the popped item
    ///
    ////////////////////////////////////////////////////////////
    
    Iterator begin() const{
        return Iterator(_steck.head());}
    ////////////////////////////////////////////////////////////
    /// -brief Element Accessor.
    ///
    /// Returns an Iterator object that points to the first element
    ///
    /// -return an Iterator.
    ////////////////////////////////////////////////////////////
    
    Iterator end() const{
        return Iterator(_steck.End());}
    ////////////////////////////////////////////////////////////
    /// -brief Element Accessor.
    ///
    /// Returns an Iterator object that points to the last element
    ///
    /// -return an Iterator
    ////////////////////////////////////////////////////////////
    
    T top() const;
    ////////////////////////////////////////////////////////////
    /// -brief Element Accessor
    ///
    /// top()
    /// Return the first item in the steck
    ///
    /// -return Type T item.
    ///
    ////////////////////////////////////////////////////////////
    
    bool empty();
    ////////////////////////////////////////////////////////////
    /// -brief Boolean
    ///
    /// Return a boolean of either the list is empty or not.
    ///
    /// -return _FRONT == nullptr.
    ///
    ////////////////////////////////////////////////////////////
    
    void clear();
    ////////////////////////////////////////////////////////////
    /// -brief Element modifier.
    ///
    /// Clear out the whole steck list.
    ///
    ////////////////////////////////////////////////////////////
    
    std::ostream& printStack(std::ostream& outs) const;
    ////////////////////////////////////////////////////////////
    /// -brief Ostream print function.
    ///
    /// Print the steck list.
    /// Print Template: [1] [2] [3] ...
    ///
    /// -return an ostream.
    ///
    ////////////////////////////////////////////////////////////
    
    template <class U>
    friend std::ostream& operator << (std::ostream& outs, const steck<U> PRINT);
    ////////////////////////////////////////////////////////////
    /// -brief Friend Ostream << operator overloading.
    ///
    /// Allow users print the queque object with << operator.
    /// Print Template: [1] [2] [3] ...
    ///
    /// -return ostream
    ///
    ////////////////////////////////////////////////////////////
};

template <class T>
steck<T>::steck(const steck& _COPY_ITEM) {
    _steck = _COPY_ITEM._steck;
    _SIZE = _COPY_ITEM._SIZE;
}

template <class T>
steck<T>& steck<T>::operator = (const steck& _COPY_ITEM) {
    return (this == &_COPY_ITEM)? *this:(_steck = _COPY_ITEM._steck_head, *this);
}

template <class T>
void steck<T>::push(const T& _T_TYPE_ITEM) {
    _SIZE ++;
    _steck.insertHead(_T_TYPE_ITEM);
}

template <class T>
const T steck<T>::pop() {
    assert(!_steck.isEmpty());
    _SIZE --;
    return _steck.removeNode(_steck.Begin());
}

template <class T>
T steck<T>::top() const{
    return _steck.front();
}

template <class T>
bool steck<T>::empty() {
    return _steck.isEmpty();
}

template <class T>
void steck<T>::clear() {
    _steck.clear();
    _SIZE = 0;
}

template <class T>
std::ostream& steck<T>::printStack(std::ostream& outs) const{
    return _steck.print(outs, _steck);
}

template <class U>
std::ostream& operator << (std::ostream& outs, const steck<U> PRINT) {
    return PRINT.printStack(outs);
}

#endif /* steck_hpp */
