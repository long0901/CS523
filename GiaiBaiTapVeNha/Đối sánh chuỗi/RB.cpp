#include <Bits.h> 
#include <iostream>
using namespace std;
/*function to find the pattern in effective way*/
void rabin_karp(string& text, string& pattern, int q)
{
    /*length of the pattern string*/
    int m = pattern.length();
    /*length of the text string*/
    int n = text.length();
    int p = 0, t = 0, h = 1, d = 26;// here p is the hash value for pattern and t is the hash value of the substring;
    /*h=pow(d,M-1) where d is 26 if the text contain only lowe case characters.*/
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    /*calculate the hash value for the pattern string and the first substring of length m*/
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;//pattern string;
        t = (d * t + text[i]) % q;//substring;
    }
    /*for remaining substring of length m*/
    for (int i = 0; i <= n - m; i++)
    {
        /*if hash values are same then check charachter by character in substring and pattern string.*/
        if (p == t)
        {
            int flag = 0;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    flag = 1;
                    break;
                }
            }
            /*if all the character are match then print the starting index of substring.*/
            if (flag == 0)
            {
                cout << "Pattern found at index: " << i + 1 << endl;
            }
        }
        /*find the hash value of the next substring by removinf the first character from previos substring
         and add next char to the end of the previous string*/
         /*it take O(1) time to find the hash values*/
        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}
int main()
{
    /*input values*/
    string text = "toi thay ban than o hien tai co nhieu diem khac so voi qua khu ngay ng ova ngoc nghech truoc kia toi da khon lon that roi";
    string pattern = "toi";
    rabin_karp(text, pattern, 97);
    return 0;
}