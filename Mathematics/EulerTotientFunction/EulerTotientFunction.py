'''
/----------------------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : ETF
*   Source          : SPOJ
*   Link            : https://www.spoj.com/problems/ETF/
*   DS              : NA
*   Algo            : Euler Totient Function
*   Date            : June 07, 2020
*   Complexity      : squareRoot(n)
*   Note			: This code should be used for the purpose of learning only, use it at your own risk
/----------------------------------------------------------------------------------------------------------
'''

import math

# method to calculate totient of a given int number
# Note : method doesn't check for validity of the input
def getTotient(n):
    # if n is negative, it should throw an exception
    result = n
    limit = int(math.sqrt(n))+1
    i = 2
    while (i * i <= n):
        if(n % i == 0) :
            while(n % i == 0):
                n /= i
            result -= result/i
        i += 1

    if (n > 1): 
        result -= result/n
    return int(result)


def main():
    T = int(input())
    while(T > 0):
        n = int(input())
        print(getTotient(n))
        T -= 1

if __name__ == "__main__":
    main()
