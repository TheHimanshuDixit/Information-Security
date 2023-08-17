#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int depth)
{
    string cipher = "";
    for (int i = 0; i < text.length(); i = i + 2)
    {
        cipher += text[i];
    }
    for (int i = 1; i < text.length(); i = i + 2)
    {
        cipher += text[i];
    }
    return cipher;
}

string decrypt(string text, int depth)
{
    string plain = "";
    int mid = text.length() / 2;
    int i = 0, j = mid;
    while (i < mid && j < text.length())
    {
        plain += text[i];
        plain += text[j];
        i++;
        j++;
    }
    if (i < mid)
    {
        plain += text[i];
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