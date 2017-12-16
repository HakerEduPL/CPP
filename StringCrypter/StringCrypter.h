#ifndef STRINGCRYPTER_H
#define STRINGCRYPTER_H
#include <iostream>
#include <cstring>

using namespace std;

class StringCrypter
{
public:
    StringCrypter(string key);
    string encryptString(string text);
    string decryptString(string text);


private:
    string encryptDecrypt(string text, bool encrypted);
    string strToHex(const string& text);
    string hexToStr(const string& text);
    string xorKey;
};

#endif // STRINGCRYPTER_H
