#include <iostream>
#include "StringCrypter.h"
using namespace std;
 
int main()
{
    //encryption key
    StringCrypter *obj = new StringCrypter("a9d1r6cx4x9v0d5p7w4m5k29v9xc02457sc64u1h");
 
    //encrypt
    string password = obj->encryptString("H3ll0 world p@ssword!");
    cout << password << endl;
 
    //decrypt
    string plainText = obj->decryptString(password);
    cout << plainText << endl;
    return 0;
}