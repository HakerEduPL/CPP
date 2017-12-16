/*
https://haker.edu.pl/
*/

#include "stringCrypter.h"

StringCrypter::StringCrypter(string key)
{
    this->xorKey=key;
}

string StringCrypter::strToHex(const string& text)
{
    string hexCharset = "0123456789ABCDEF";
    string result;
    int textLenght = text.length();
    result.reserve(2*textLenght);
    for (int i=0; i<textLenght; i++)
    {
        const unsigned char c = text[i];
        result.push_back(hexCharset[c >> 4]);
        result.push_back(hexCharset[c & 15]);
    }
    return result;
}

string StringCrypter::hexToStr(const string& text)
{
    const char* const hexCharset = "0123456789ABCDEF";
    string result;
    int textLenght = text.length();
    result.reserve(textLenght/2);
    for (int i=0; i<textLenght; i += 2)
    {
        char tmp1 = text[i];
        const char* p = lower_bound(hexCharset, hexCharset + 16, tmp1);
        char tmp2 = text[i + 1];
        const char* q = lower_bound(hexCharset, hexCharset + 16, tmp2);
        result.push_back(((p - hexCharset) << 4) | (q - hexCharset));
    }
    return result;
}

string StringCrypter::encryptDecrypt(string text, bool encrypted)
{
    if (encrypted)
        text=hexToStr(text);

    string key = this->xorKey;
    string result = text;
    for (int i = 0; i < text.size(); i++)
        result[i] = (int)(text[i] ^ key[i % key.length()]);

    if (encrypted)
        return result;
    else
        return strToHex(result);
}

string StringCrypter::encryptString(string text)
{
    return this->encryptDecrypt(text, false);
}

string StringCrypter::decryptString(string text)
{
    return this->encryptDecrypt(text, true);
}
