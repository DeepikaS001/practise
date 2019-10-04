#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int pattern(string s1, string s2, int b1, int b2)
{
    int i = 0,j = 0;
    for (i = 0; i <= b1 - b2; i++)
    {
        for (j = 0; j < b2; j++)
        {
            if (s1[i + j] != s2[j])
                break;
        }
        if (j == b2)
        {
            return i + 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    string s1 = argv[1];
    string s2 = argv[2];
    int b1 = s1.length();
    int b2 = s2.length();
    cout<<pattern(s1,s2,b1,b2);
}
