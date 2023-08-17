#include <bits/stdc++.h>
using namespace std;

string encode(string key, string text)
{
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    for (int i = 0; i < text.length(); i++)
    {
        key += toupper(text[i]);
        if (key.length() == text.length())
        {
            break;
        }
    }
    return key;
}

string encrypt(string text, string key)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        result += char(int(text[i] + key[i]) % 26 + 65);
        // x += 'A';
        // result += x;
    }
    return result;
}

string decrypt(string text, string key)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        result += char(int(text[i] - key[i] + 26) % 26 + 97);
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string key;
    cin >> key;
    if (key.length() != s.length())
    {
        key = encode(key, s);
    }
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "Text : " << s;
    cout << "\nKey: " << key;
    string cipher = encrypt(s, key);
    cout << "\nCipher: " << cipher;
    string plain = decrypt(cipher, key);
    cout << "\nPlain: " << plain;
    return 0;
}