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

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while(st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    // method to calculate totient of a given natural number
    private static int getTotient(int n) {
        int result = n;
        for(int i=2; i*i <=n; i++) {
            if(n % i == 0) {
                while(n % i == 0) n /= i;
                result -= result/i;
            }
        }
        if(n > 1) result -= result/n;
        return result;
    }
    public static void main(String[] args) {
        FastReader fr = new FastReader();
        int T = fr.nextInt();
        while(T-- > 0) {
            int n = fr.nextInt();
            System.out.println(getTotient(n));
        }
    }
}
