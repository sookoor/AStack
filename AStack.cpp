/* -*- C++ -*- */

#ifndef ASTACK_CPP
#define ASTACK_CPP

// Implementation of a bounded stack abstraction in C++.
#include "AStack.h"

#if !defined (__INLINE__)
#define INLINE 
#include "AStack.inl"
#endif /* __INLINE__ */

//
//Method name: AStack
//Purpose: Dynamically create an uninitialized array.
//Parameters: <size> is of type size_t. 
//            <size> is the size of the stack to be created.
//            <size> is passed by value.
//Return value: None
//
template <typename T>
Stack::AStack<T>::AStack (size_t size)
    : top_(0),
      stack_(size)
{
}

//
//Method name: AStack
//Purpose: The copy constructor (performs initialization).
//Parameters: <s> is of type Stack<T>. 
//            <s> is the stack to be copied.
//            <s> is passed by reference.
//Return value: None
//
template <typename T>
Stack::AStack<T>::AStack (const Stack::AStack<T> &s)
    : top_(s.top_),
      stack_(s.stack_)
{
}

//
//Method name: ~AStack
//Purpose: Perform actions needed when stack goes out of scope.
//Parameters: void
//Return value: None
//
template <typename T>
Stack::AStack<T>::~AStack (void)
{
}

//
//Method name: operator==
//Purpose: Checks for stack equality.
//Parameters: <s> is of type AStack<T>.
//            <s> is the stack with which the current stack is to be compared.
//            <s> is passed by reference.
//Return value: bool: true if the stacks are equal, otherwise false.
//
template <typename T> bool
Stack::AStack<T>::operator== (const Stack::AStack<T> &s) const
{
    if (this->top_ == s.top_)
        {
            for (size_t i = 0; i < this->top_; i++)
                {
                    if (this->stack_[i] != s.stack_[i])
                        return false;
                }
            return true;
        }
    else
        return false;
}

//
//Method name: operator!=
//Purpose: Checks for stack inequality.
//Parameters: <s> is of type AStack<T>.
//            <s> is the stack with which the current stack is to be compared.
//            <s> is passed by reference.
//Return value: bool: true if the stacks are inequal, otherwise false.
//
template <typename T> bool
Stack::AStack<T>::operator!= (const Stack::AStack<T> &s) const
{
    return !(*this == s);
}

//
//Method name: operator=
//Purpose: Assignment operator (performs assignment).
//Parameters: <s> is of type AStack<T>.
//            <s> is the stack to be assigned.
//            <s> is passed by reference.
//Return value: void
//
template <typename T> void
Stack::AStack<T>::operator= (const Stack::AStack<T> &s)
{
    if (this != &s) // Check for self-allocation.
        {
            this->stack_ = s.stack_;
            this->top_ = s.top_;
        }
}

//
//Method name: push
//Purpose: Place a new item on top of the stack.
//Parameters: <new_item> is of type T.
//            <new_item> is the item to be added to the stack.
//            <new_item> is passed by reference.
//Return value: void
//
template <typename T> void
Stack::AStack<T>::push (const T &new_item) throw (Stack::overflow)
{
    // Throws the <Stack::overflow> exception if the stack is full.
    try
        {
            this->stack_.set(new_item, this->top_);
            this->top_++;
        }
    catch (std::bad_alloc &)
        {
            throw Stack::overflow ();
        }
}

//
//Method name: pop
//Purpose: Remove and return the top stack item.
//Parameters: <item> is of type T.
//            <item> is used to return the removed item.
//            <item> is passed by reference.
//Return value: void
//
template <typename T> void
Stack::AStack<T>::pop (T &item) throw (Stack::underflow)
{
    // Throws the <Stack::underflow> exception if the stack is empty.
    if (is_empty ())
        throw Stack::underflow ();
    else
        {
            item = this->stack_[this->top_];
            this->top_--;
        }
}

#endif /* ASTACK_CPP */
