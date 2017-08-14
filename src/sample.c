#include <stdio.h>
#include "exception.h"

void foo(void)
{
    printf("Call function %s() ...\n", __FUNCTION__);
    throw(1);
}

void bar(void)
{
    printf("Call function %s() ...\n", __FUNCTION__);
    try {
        foo();
    } catch(1) {
        printf(".. %s() failed due to error 1!\n", __FUNCTION__);
        throw(2);
    }
}

int main(void)
{
    printf("Call function %s() ...\n", __FUNCTION__);
    // Create a new exception
    try {
        bar();
        // this never happens because process always throws error 1 
        printf("Got to end of process!\n");
    }

    // is executed when throw(1) is called within the try
    catch(1) {
        printf(".. %s() failed due to error 1!\n", __FUNCTION__);
    }

    // is executed when throw(2) is called within the try
    catch(2) {
        printf(".. %s() failed due to error 2!\n", __FUNCTION__);
    }

    printf("End of program.\n");

    return 0;
}
