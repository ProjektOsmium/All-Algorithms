# Python 3 program to calculate
# Euler's Totient Function
# using Euler's product formula

def run(n) :

result = n # Initialize result as n

# Consider all prime factors
# of n and for every prime
# factor p, multiply result with (1 – 1/p)
p=2
while(p*p<=n) :

# Check if p is a prime factor.
if (n % p == 0) :

# If yes, then update n and result
while (n % p == 0) :
n = n // p
result = result * (1.0 – (1.0 / (float) (p)))
p = p + 1

# If n has a prime factor
# greater than sqrt(n)
# (There can be at-most one
# such prime factor)
if (n > 1) :
result = result * (1.0 – (1.0 / (float)(n)))

return (int)(result)

# Driver program to test above function
for n in range(1,11) :
print(“run(“,n,”) = “,run(n))
