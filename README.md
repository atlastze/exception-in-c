# Exception in C 

A simple exception handling framework for C language, using setjmp and longjmp.

## Usage

We can catch exceptions (usually unsigned integers) with `try ... catch` blocks.


## Ceveats

In `try ... catch` blocks:

* Using `volatile` for local variables.
* Rethrowing exception is allowed. 
* Don't use return statements.
