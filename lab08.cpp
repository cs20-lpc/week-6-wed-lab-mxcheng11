#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);


//helper tail recursive functions
unsigned fact_helper(unsigned, unsigned);
unsigned fib_helper(unsigned, unsigned, unsigned);
unsigned mult_helper(unsigned, unsigned, unsigned);
unsigned power_helper(unsigned, unsigned, unsigned);
unsigned product_helper(unsigned, unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

unsigned fact_helper(unsigned n, unsigned accum) {
    // base cases (combined)
    if (n <= 1) {
        return accum; //updated return to be accum instead of 1
    }

    // recursive case
    // unsigned res = fact(n - 1);
    // return res * n;

    // tail recursive 
    return fact_helper(n-1, n * accum); //move operation to function call

}

unsigned fib_helper(unsigned n, unsigned prev = 0, unsigned curr = 1) {
    // base case 1
    if (n == 0) {
        return prev; //return 0th fib number
    }

    // base case 2
    else if (n == 1) {
        return curr; //return 1st fib number
    }

    // recursive case
    return fib_helper(n - 1, curr, prev + curr); 
}

unsigned mult_helper(unsigned x, unsigned y, unsigned accum) {
    // base case
    if (y == 0) {
        return accum; //return total
    }

    // recursive case
    // unsigned res = mult(x, y - 1);
    // return res + x;

    // tail recursive 
    return mult_helper(x, y-1, accum + x); //move operation to function call
}

unsigned power_helper(unsigned x, unsigned y, unsigned accum) {
    // base case
    if (y == 0) {
        return accum;
    }

    // recursive case
    // unsigned res = power(x, y - 1);
    // return res * x;

    // tail rescursive 
    return power_helper(x, y-1, accum * x); //move operation to function call
}

unsigned product_helper(unsigned x, unsigned y,unsigned accum) { // multiplies nums from x to y 
    // base case
    if (x == y) {
        return accum * x; // mult last number to total and return
    }

    // recursive case
    // unsigned p = product(x + 1, y);
    // return p * x;

    // tail recursive 
    return product_helper(x + 1, y, accum * x); //move operation to function call
}


//call helper functions 
unsigned fact(unsigned n) {
    return fact_helper(n, 1);  // Start with accumulator = 1
}

unsigned fib(unsigned n) {
    return fib_helper(n, 0, 1);  // Start with prev=0, curr=1
}

unsigned mult(unsigned x, unsigned y) {
    return mult_helper(x, y, 0);  // Start with accumulator = 0
}

unsigned power(unsigned x, unsigned y) {
    return power_helper(x, y, 1);  // Start with accumulator = 1
}

unsigned product(unsigned x, unsigned y) {
    return product_helper(x, y, 1);  // Start with accumulator = 1
}
