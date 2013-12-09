//
//Method name: is_empty
//Purpose: Check if the stack is empty.
//Parameters: void
//Return value: bool: true if the stack is empty, otherwise false.
//
template <typename T> INLINE bool
Stack::AStack<T>::is_empty (void) const
{
    return (this->top_ == 0); 
}

//
//Method name: top
//Purpose: Return top stack item without removing it.
//Parameters: <item> is of type T.
//            <item> is used to return the removed item.
//            <item> is passed by reference.
//Return value: void
//
template <typename T> INLINE void
Stack::AStack<T>::top (T &item) const throw (Stack::underflow)
{
    if (is_empty ())
        throw Stack::underflow ();
    else
        item = this->stack_[this->top_-1]; 
}

