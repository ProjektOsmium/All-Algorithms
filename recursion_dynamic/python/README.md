

# What is Reqursion?

* there are two main instances of recursion.
* the first is when recursion is used as a technique in which a function makes one or more calls to itself.
* The second is when a data structure uses smaller instances of the exact same type of data structure when it represents itself.

Recursion provides a powerful alternative for performing repetitions of tasks in which a loop is not ideal.
Most modern programming languges support reqursion.
Recursion serves as a great tool for building out particular data structures.



# Dynamic Programming

Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial. For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity and if we optimize it by storing solutions of subproblems, time complexity reduces to linear.

[more?!](https://www.geeksforgeeks.org/dynamic-programming/)










# Coin Change Problem


Given a target amount **n** and a list(array) of distinct coin values, what's the fewest coins needed to make the change amount.
For example:
if n=10 and coins =[1,5,10]. then there are 4 possible ways to make change:
* 1+1+1+1+1+1+1+1+1+1
* 5+1+1+1+1+1
* 5+5
* 10

with 1 coin being the minimum amount.