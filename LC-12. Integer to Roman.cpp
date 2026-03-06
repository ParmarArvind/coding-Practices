// method -1 brute force
class Solution {
public:
    void getChar(int digit ,int n, string &roman)
    {
        if(n==3)
        {
            while(digit--)
            {
                roman.push_back('M');
            }
        }
        else if(n==2)
        {
            if(digit==9) 
            {
                roman.push_back('C');
                 roman.push_back('M');
                return;
            }
            if(digit>=5)
            {
                roman.push_back('D');
                digit=digit-5;
            }
            if(digit==4)
            {
                 roman.push_back('C');
                  roman.push_back('D');
                 return;
            }
            while(digit--)
            {
                roman.push_back('C');
            }
        }

        else if(n==1)
        {
            if(digit==9) 
            {
                roman.push_back('X');
                 roman.push_back('C');
                return;
            }
            if(digit>=5)
            {
                roman.push_back('L');
                digit=digit-5;
            }
            if(digit==4)
            {
                 roman.push_back('X');
                  roman.push_back('L');
                 return;
            }
            
            while(digit--)
            {
                roman.push_back('X');
            }
        }

        else 
        {
            if(digit==9) 
            {
                roman.push_back('I');
                 roman.push_back('X');
                return;
            }
            if(digit>=5)
            {
                roman.push_back('V');
                digit=digit-5;
            }
            if(digit==4) 
            {
                roman.push_back('I');
                 roman.push_back('V');
                return;
            }
           
            while(digit--)
            {
                roman.push_back('I');
            }
        }
    }
    string intToRoman(int num) {

        string s=std::to_string(num);

        int n=s.size();
        string roman;
        
        for(int i=0; i<n;i++)
        {
            int digit=s[i]-'0';
            getChar(digit, n-i-1,roman);
        }

        return roman;
    }
};


// method -2 mapped values
class Solution {
public:
    vector<int> value{1000, 900, 500 ,400,100 ,90,  50,  40, 10,  9,  5,  4 , 1 };
    vector<string>symbol{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {

        string result="";
        for(int i=0;i<13;i++)
        {
            if(num==0) break;

            int times=num/value[i];

            while(times>0)
            {
                result =result+symbol[i];
                times--;
            }
            num = num%value[i];
        }

        return result;
        
    }
};
