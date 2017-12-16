# StringCrypt C++ Class

Simple encrypt/decrypt string class.

## Getting Started

https://haker.edu.pl/2017/12/16/encrypt-string-class/

### Example

```
StringCrypter *obj = new StringCrypter("a9d1r6cx4x9v0d5p7w4m5k29v9xc02457sc64u1h");
string password = obj->encryptString("H3ll0 world p@ssword!");
string plainText = obj->decryptString(password);
```



