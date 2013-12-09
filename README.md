Compilation instructions using g++ under emacs:

1. Open a command line prompt that accepts the g++ command.
2. Change the directory to the folder containing the source code and Makefile.
3. Type 'make'.
4. When the compilation is complete and focus is returned to the user
type 'gdb' to start the debugger.
5. At the prompt 'Run gdb (like this): type 'gdb AS-test'.
6. At the debugger prompt type 'run'.
7. Follow the screen prompts.

Updates made:

1. Comment: "I'm not sure what you are trying to do here, but it's not what you think it is..  
             Just do this in the base/member initialization section:
             : top_ (0),
               stack_ (size)"

   Changes: Changed "Array<T> stack_ (size)" to "stack_(size) in the base/member initialization section."

2. Comment: "Yikes, please move this into the base/member portion of the copy constructor, i.e.,
             : top_ (s.top_),
               stack_ (s.stack_)"

   Changes:  Changed "this->stack_ = s.stack_" to "stack_ (s.stack_)" in the base/member portion.

3. Comment: "This is incorrect since the contents of this->stack_ and s.stack_ may be arbitrarily different past 
             "top_", yet the stacks may still be equal from 0 to top_ - 1, which won't be detected properly by 
             this implementation."

   Changes:  Changed "if (this->stack_ == s.stack_)
                          return true;" to 
             "for (size_t i = 0; i < this->top_; i++)
                  {
                      if (this->stack_[i] != s.stack_[i])
                          return false;
                  }
              return true;"

4. Comment: "Please use this->top_--; here."

   Changes: Changed "this->top_ = this->top_ - 1;" to "this->top_--;"




