#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int s)
{
	string result = "";
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    for (int i=0;i<text.length();i++)
    {
        if(text[i]==' ')
        {
            continue;
        }
        result += char(int(text[i]+s-97)%26 +65);
    }
    return result;
}

string decrypt(string text, int s)
{
    string result = "";
    for (int i=0;i<text.length();i++)
    {
        result += char(int(text[i]-s-65)%26 + 97);
    }
    return result;
}


int main()
{
    string s;
    getline(cin,s);
	int key;
    cin >> key;
	cout << "Text : " << s;
	cout << "\nShift: " << key;
    string cipher = encrypt(s, key);
	cout << "\nCipher: " << cipher;
    string plain = decrypt(cipher, key);
	cout << "\nPlain: " << plain;
	return 0;
}
