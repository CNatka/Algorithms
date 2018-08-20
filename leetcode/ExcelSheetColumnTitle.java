/*
    Author : CNatka
    Date   : Aug 19, 2018
    OJ     : Excel Sheet Column Title
    Link   : https://leetcode.com/problems/excel-sheet-column-title/description/
    
*/

class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        long num = (long)n;
        while(num != 0) {
            int rem = (int)(num)%26;
            rem = (rem+25)%26;
            System.out.println("rem : "+rem);
            char a = (char)('A'+rem);
            sb.insert(0, String.valueOf(a));
            if(num%26==0) {
                num /= 26;
                num--;
            }else {
            num /= 26;
            }
        }
        return sb.toString();
    }
}

/*class Solution {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        long num = (long)n;
        while(num != 0) {
            int rem = (int)(num)%26;
            rem = (rem+25)%26;
            System.out.println("rem : "+rem);
            char a = (char)('A'+rem);
            sb.insert(0, String.valueOf(a));
            num--;
            num /= 26;
        }
        return sb.toString();
    }
}*/