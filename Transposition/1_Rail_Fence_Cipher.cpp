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

string decrypt(string cipher, int depth)
{
    string plain = "";
    int k = 0;
    int l;
    int len = cipher.length() / depth;
    if (cipher.length() % depth != 0)
        len++;
    for (int i = 0; i < len; i++)
    {
        k = 0;
        l = i;
        while (k < depth)
        {
            plain += cipher[l];
            l += len;
            k++;
        }
    }
    return plain;
}

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
    string plain = decrypt(cipher, depth);
    cout << "\nPlain: " << plain;
    return 0;
}