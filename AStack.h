/* -*- C++ -*- */

//=============================================================================
/**
 *  @file    AStack.h
 *
 */
//=============================================================================

#ifndef ASTACK_H
#define ASTACK_H

#include <stdlib.h>
#include "Array.h"
#include "Stack_Exceptions.h"

namespace Stack {

/**
 * @class AStack
 *
 * @brief Implement a generic LIFO abstract data type using a resizeable array.
 */

template <typename T>
class AStack
{
public:
  typedef T TYPE;
  // C++ trait.

  enum { INITIAL_STACK_SIZE = 80 };

  // Initialize a new stack so that it is empty. 
  AStack (size_t size = INITIAL_STACK_SIZE);

  // The copy constructor (performs initialization). 
  AStack (const AStack<T> &s);

  // Assignment operator (performs assignment). 
  void operator= (const AStack<T> &s);

  // Perform actions needed when stack goes out of scope. 
  ~AStack (void); 

  // Place a new item on top of the stack.  Throws the
  // <Stack::overflow> exception if the stack is full.
  void push (const T &new_item) throw (Stack::overflow);

  // Remove and return the top stack item.  Throws the
  // <Stack::underflow> exception if the stack is empty.
  void pop (T &item) throw (Stack::underflow);

  // Return top stack item without removing it.  Throws the
  // <Stack::underflow> exception if the stack is empty.
  void top (T &item) const throw (Stack::underflow);

  // Returns true if the stack is empty, otherwise returns false.
  bool is_empty (void) const;

  // Checks for stack equality.
  bool operator == (const AStack<T> &s) const;

  // Checks for stack inequality.
  bool operator != (const AStack<T> &s) const;

private:
  // Keeps track of the top of the stack.
  size_t top_;
  
  // Array that stores the elements in the stack.
  Array<T> stack_;
};

#if defined (__INLINE__)
#define INLINE inline
#include "AStack.inl"
#endif /* __INLINE__ */

#include "AStack.cpp"

}

#endif /* ASTACK_H */
