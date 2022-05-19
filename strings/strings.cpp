#include <iostream>
#include <string>
using namespace std;

void FindingDuplicates(string A)
{
    int h = 0, x = 0;
    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);
        if ((x & h) > 0)
            cout << A[i] << " is duplicate." << endl;
        else
            h = x | h;
    }
}

void Anagram(string a, string b)
{
    int H[26];
    int i = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
        H[a[i] - 97]++;
    }
    for (i = 0; b[i] != 0; i++)
    {
        H[b[i] - 97]--;
        if (H[a[i] - 97] < 0)
        {
            cout << "Not Anagram";
            break;
        }
    }
    if (b[i] == '\0')
        cout << "Anagram";
}
void permutation(string S, int k)
{
    static int A[10] = {0};
    // static string Res[10];
    static char Res[10];
    if (S[k] == '\0')
    {
        Res[k] = '\0';
        cout << Res << " ";
    }
    else
    {
        for (int i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Res[k] = S[i];
                A[i] = 1;
                permutation(S, k + 1);
                A[i] = 0;
            }
        }
    }
}
int main()
{
    // string A="finding";
    // FindingDuplicates(A);

    // string a = "decimal";
    // string b = "medical";
    // Anagram(a, b);.
    string s="abc";
    permutation(s,0);

    return 0;
}