#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, vector<vector<char>> &key)
{
    for (int i = 0; i < text.length(); i = i + 2)
    {
        if (text[i] == text[i + 1])
        {
            text.insert(i + 1, "X");
        }
        int x1, y1, x2, y2;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (key[j][k] == text[i])
                {
                    x1 = j;
                    y1 = k;
                }
            }
        }
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (key[j][k] == text[i + 1])
                {
                    x2 = j;
                    y2 = k;
                }
            }
        }
        if (x1 == x2 || y1 == y2)
        {
            if (x1 == x2)
            {
                text[i] = key[x1][(y1 + 1) % 5];
                text[i + 1] = key[x2][(y2 + 1) % 5];
            }
            else
            {
                text[i] = key[(x1 + 1) % 5][y1];
                text[i + 1] = key[(x2 + 1) % 5][y2];
            }
        }
        else
        {
            text[i] = key[x1][y2];
            text[i + 1] = key[x2][y1];
        }
    }
    return text;
}

string decrypt(string text, vector<vector<char>> &key)
{
    for (int i = 0; i < text.length(); i = i + 2)
    {
        int x1, y1, x2, y2;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (key[j][k] == text[i])
                {
                    x1 = j;
                    y1 = k;
                }
            }
        }
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (key[j][k] == text[i + 1])
                {
                    x2 = j;
                    y2 = k;
                }
            }
        }
        if (x1 == x2 || y1 == y2)
        {
            if (x1 == x2)
            {
                text[i] = key[x1][(y1 - 1 + 5) % 5];
                text[i + 1] = key[x2][(y2 - 1 + 5) % 5];
            }
            else
            {
                text[i] = key[(x1 - 1 + 5) % 5][y1];
                text[i + 1] = key[(x2 - 1 + 5) % 5][y2];
            }
        }
        else
        {
            text[i] = key[x1][y2];
            text[i + 1] = key[x2][y1];
        }
    }
    return text;
}

int main()
{
    string s;
    getline(cin, s);
    string key;
    cin >> key;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    vector<vector<char>> v(5, vector<char>(5, ' '));
    int arr[26] = {0};
    vector<char> temp;
    map<char, int> mp;
    for (int i = 0; i < key.size(); i++)
    {
        if (mp.find(key[i]) == mp.end())
        {
            if (key[i] == 'J' && mp.find('I') == mp.end())
            {
                temp.push_back('I');
                mp['I'] = 1;
            }
            else
            {
                temp.push_back(key[i]);
                mp[key[i]] = 1;
            }
        }
    }

    int len = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (len < temp.size())
            {
                v[i][j] = temp[len];
                arr[temp[len] - 'A'] = 1;
                if (temp[len] == 'I')
                {
                    arr['J' - 'A'] = 1;
                }
                len++;
            }
            else
            {
                for (int k = 0; k < 26; k++)
                {
                    if (arr[k] == 0)
                    {
                        v[i][j] = k + 'A';
                        arr[k] = 1;
                        if (k == 8)
                        {
                            arr[9] = 1;
                        }
                        break;
                    }
                }
            }
        }
    }

    cout << "Text : " << s;
    cout << "\nKey: ";
    for (int i = 0; i < 5; i++)
    {
        cout << "\n";
        for (int j = 0; j < 5; j++)
        {
            cout << v[i][j] << " ";
        }
    }

    string cipher = encrypt(s, v);
    cout << "\nCipher: " << cipher;
    string decipher = decrypt(cipher, v);
    for (int i = 0; i < decipher.length(); i++)
    {
        if (decipher[i] == 'X')
        {
            decipher.erase(i, 1);
            break;
        }
    }
    cout << "\nDecipher: " << decipher;
    return 0;
}