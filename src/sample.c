#include <stdio.h>
#include "exception.h"

// catch an exception
void foo(void)
{
    printf(".. In function: %s\n", __FUNCTION__);
    printf(".. In function: %s, throw exception, error code: %d\n",
           __FUNCTION__, 1);
    throw(1);
}

// catch and rethrow an exception
void bar(void)
{
    printf(".. In function: %s\n", __FUNCTION__);
    try {
        foo();
    } catch(1) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 1);
        printf(".. In function: %s, rethrow exception, error code: %d\n",
               __FUNCTION__, 2);
        throw(2);
    }
}

// nested try-catch blocks
void baz(void)
{
    printf(".. In function: %s\n", __FUNCTION__);
    try {
        try {
            foo();
        } finally {
            printf
                (".. In function: %s, exception is detected, error code: %d!\n",
                 __FUNCTION__, _except_code_);
        }
        bar();
    } finally {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, _except_code_);
    }
}

int main(void)
{
    printf(".. In function: %s\n", __FUNCTION__);

    printf(".. Test 'try - catch - finally' block:\n");
    // begin detecting exception
    try {
        bar();
        // the bellowing code is unreachable,
        // because process always throws error
        printf(".. Unreachable code!\n");
    }

#if 0
    // exception (1) caught
    catch(1) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 1);
    }

    // exception (2) caught
    catch(2) {
        printf(".. In function: %s, exception is detected, error code: %d!\n",
               __FUNCTION__, 2);
    }
#endif

    // other exceptions caught
    finally {
        printf
            (".. In function: %s, default exception is detected, error code: %d!\n",
             __FUNCTION__, _except_code_);
    }

    printf("\n.. Test nested 'try - catch - finally' blocks:\n");
    baz();

    printf(".. End of program.\n");

    return 0;
}
