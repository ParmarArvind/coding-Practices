class Solution {
    public String reverseVowels(String str) {
        StringBuilder s=new StringBuilder();
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            if(str.charAt(i)=='a' ||str.charAt(i)=='e' ||str.charAt(i)=='i' ||str.charAt(i)=='o' 
            ||str.charAt(i)=='u' ||str.charAt(i)=='A' ||str.charAt(i)=='E' ||str.charAt(i)=='I' 
            ||str.charAt(i)=='O' ||str.charAt(i)=='U')  
                 s.append(str.charAt(i));
        }
        s.reverse();
        StringBuilder result=new StringBuilder();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(str.charAt(i)=='a' ||str.charAt(i)=='e' ||str.charAt(i)=='i' ||str.charAt(i)=='o' 
            ||str.charAt(i)=='u' ||str.charAt(i)=='A' ||str.charAt(i)=='E' ||str.charAt(i)=='I' 
            ||str.charAt(i)=='O' ||str.charAt(i)=='U')  
            {
                 result.append(s.charAt(j));
                 j++;
            }
            else result.append(str.charAt(i));
        }
        return result.toString();
    }
}
