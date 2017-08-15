# Exception in C

A simple exception handling framework for C language, using non-local jump functions `setjmp` and `longjmp`.

## Usage

We can catch exceptions (usually unsigned integers) with `try ... catch ... finally` blocks.

### Catching Exceptions

```
try {
    // code that may throw exceptions
} catch(exception1) {
    // code that processes the exception1
} catch(exception2) {
    // code that processes the exception2
} finally {
    // defautl exception handling
    // code that processes other exceptions
}
```

Note: the semantics of `finally` is different from Java.

### Throwing Exceptions

You throw an integer (non-zero) as an exception, for example:

```
throw(1);
```

## Ceveats

In `try ... catch ... finally` blocks:

* After invoking longjmp(), non-volatile-qualified local objects should not be accessed if their values could have changed since the invocation of setjmp(). Their value in this case is considered indeterminate, and accessing them is undefined behavior.
* It's allowed to rethrow an caught exception in `catch` or `finally` clause.
* Don't use return statements.

## References
* [Exceptions in C with Longjmp and Setjmp](http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html)
* [CTurt/Exception](https://github.com/CTurt/Exception)
* [setjmp/longjmp and local variables](https://stackoverflow.com/questions/1393443/setjmp-longjmp-and-local-variables)
* [Performing Non-Local Goto](http://www.csl.mtu.edu/cs4411.ck/www/NOTES/non-local-goto/goto.html)
