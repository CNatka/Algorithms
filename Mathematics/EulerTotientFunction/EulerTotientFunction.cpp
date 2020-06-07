/*----------------------------------------------------------------------------------------------------------
*   Name            : CNatka
*   Problem         : ETF
*   Source          : SPOJ
*   Link            : https://www.spoj.com/problems/ETF/
*   DS              : NA
*   Algo            : Euler Totient Function
*   Date            : June 07, 2020
*   Complexity      : squareRoot(n)
*   Note			: This code should be used for the purpose of learning only, use it at your own risk
/----------------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

int getTotient(int n) {
    int result = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i  == 0) {
            while(n % i == 0) n /= i;
            result -= result/i;
        }
    }

    if(n > 1) result -= result / n;
    return result;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", getTotient(n));
    }
}
