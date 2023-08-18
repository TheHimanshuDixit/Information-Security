#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int depth)
{
    string cipher = "";
    int k = 0;
    while (k < depth)
    {
        for (int i = k; i < text.length(); i = i + depth)
        {
            cipher += text[i];
        }
        k++;
    }
    return cipher;
}

// string decrypt(string cipher, int depth)
// {
//     string plain = "";
//     int k = 0;
//     while (k < depth)
//     {
//         for (int i = k; i < cipher.length(); i = i + depth)
//         {
//             plain += cipher[i];
//         }
//         k++;
//     }
//     return plain;
// }

int main()
{
    string text;
    getline(cin, text);
    int depth;
    cin >> depth;
    cout << "Text : " << text;
    cout << "\nDepth: " << depth;
    string cipher = encrypt(text, depth);
    cout << "\nCipher: " << cipher;
    // string plain = decrypt(cipher, depth);
    // cout << "\nPlain: " << plain;
    return 0;
}