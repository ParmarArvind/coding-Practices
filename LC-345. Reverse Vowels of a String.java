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

// method 2 using 2 pointer 
class Solution {
    public String reverseVowels(String s) {
        StringBuilder str=new StringBuilder(s);
        int n=str.length();
        int j=n-1;
        int i=0;
        while(i<j)
        {
            if(str.charAt(i)=='a' ||str.charAt(i)=='e' ||str.charAt(i)=='i' ||str.charAt(i)=='o' 
                ||str.charAt(i)=='u' ||str.charAt(i)=='A' ||str.charAt(i)=='E' ||str.charAt(i)=='I' 
                ||str.charAt(i)=='O' ||str.charAt(i)=='U')  
            {
                if(str.charAt(j)=='a' ||str.charAt(j)=='e' ||str.charAt(j)=='i' ||str.charAt(j)=='o' 
                    ||str.charAt(j)=='u' ||str.charAt(j)=='A' ||str.charAt(j)=='E' ||str.charAt(j)=='I' 
                    ||str.charAt(j)=='O' ||str.charAt(j)=='U')  
                {
                     char temp=str.charAt(i);
                     str.setCharAt(i,str.charAt(j));
                     str.setCharAt(j,temp);
                     j--;
                     i++;  
                }
                else j--;
                
            }
            else 
            {
                i++;
            }
        }
        return str.toString();
    }
}

