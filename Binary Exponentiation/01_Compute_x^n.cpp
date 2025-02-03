// Binary Exponentiation (Exponentiation by Squaring)

// Binary Exponentiation is an efficient algorithm to compute  x^n  in  O(\log n)  time by using the idea of dividing the exponent into powers of 2.

// How It Works:
// 	1.	If  n  is even:

// x^n = (x^{n/2})^2

// 	2.	If  n  is odd:

// x^n = x \times (x^{(n-1)/2})^2

// 	3.	Base case: If  n = 0 , return 1 (since  x^0 = 1 ).

// Instead of multiplying  x  repeatedly  n  times ( O(n) ), this method reduces the number of multiplications to  O(\log n)  by halving the exponent in each step.


// Example: Compute  2^10  Using Binary Exponentiation

// Let’s calculate  2^{10} :
// 	1.	 10  is even, so:

// 2^{10} = (2^5)^2

// 	2.	 5  is odd, so:

// 2^5 = 2 \times (2^2)^2

// 	3.	 2  is even, so:

// 2^2 = (2^1)^2

// 	4.	 1  is odd, so:

// 2^1 = 2


// Now, working backwards:

// 2^2 = (2)^2 = 4


// 2^5 = 2 \times (4)^2 = 2 \times 16 = 32


// 2^{10} = (32)^2 = 1024


