#include <bits/stdc++.h>
using namespace std;

string encode(string key)
{
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    bool arr[26] = {0};
    string result = "";
    for (int i = 0; i < key.length(); i++)
    {
        result += key[i];
        arr[key[i] - 65] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 0)
        {
            result += char(i + 65);
        }
    }
    return result;
}

string encrypt(string text, string key)
{
    map<char, char> mp;
    for (int i = 0; i < 26; i++)
    {
        mp[char(i + 65)] = key[i];
    }
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            continue;
        }
        result += mp[text[i]];
    }
    return result;
}

string decrypt(string text, string s)
{
    map<char, char> mp;
    for (int i = 0; i < 26; i++)
    {
        mp[s[i]] = char(i + 65);
    }
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        result += mp[text[i]];
    }
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string key;
    cin >> key;
    if (key.length() < 26)
    {
        key = encode(key);
    }
    cout << "Text : " << s;
    cout << "\nKey: " << key;
    string cipher = encrypt(s, key);
    cout << "\nCipher: " << cipher;
    string plain = decrypt(cipher, key);
    cout << "\nPlain: " << plain;
    return 0;
}