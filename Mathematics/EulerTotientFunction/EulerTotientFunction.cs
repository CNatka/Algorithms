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

using System;

namespace SPOJ {
    class Program {
        private static int getTotient(int n) {
            int result = n;
            for(int i=2; i * i <= n; i++) {
                if(n % i == 0) {
                    while(n % i == 0) n /= i;
                    result -= result/i;
                }
            }
            if (n > 1) result -= result / n;
            return result;
        }
        static void Main(string[] args) {
            int T = Convert.ToInt32(Console.ReadLine());
            while(T-- > 0) {
                int n = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine(getTotient(n));
            }
        }
    }
}
