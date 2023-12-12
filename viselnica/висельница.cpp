#define _CRT_SECURE_NO_WARNINGS
#include "imageAndWord.h"
#include <windows.h>

void programStarting();

int getNextRandom(const size_t lim)
{
    int nextRand = rand() % lim;
    int nextSign = rand() % lim;
    if (nextSign < lim / 2)
        return -nextRand;
   
    return nextRand;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    programStarting();
    while (true)
    {

        int wordID = -1, count = 0, fails = 0;
        string secretWord = "", answData = "";
        char answ;
        bool flag = false;

        system("cls");
        do
        {
            wordID = getNextRandom(66);
        } while (wordID < 0);

        for (int i = 0; i < words[wordID].size(); i++)
            secretWord += " _";
        cout << words[wordID] << endl;

        do
        {
            cout << image[fails] << secretWord << endl <<"Введенные буквы " << answData << endl;
            cout << "Введите букву: ";
            cin >> answ;
            for (size_t i = 0; i <= answData.size(); i++) //проверка на введенные буквы
            {
                if (answ != answData[i])
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }

            if (!flag) { //если буква была, то пропускаем итерацию цикла
                system("cls");
                continue;
            }

            for (int i = 0; i < words[wordID].size(); i++) //если буквы небыло, то проверяем на соответствие со словом
            {

                if (answ == (char)words[wordID][i] && flag)
                {
                    fails--;
                    count++;
                    secretWord[i * 2 + 1] = answ;//"вскрываем" буквы
                }

            }
            fails++;
            if (fails < 0) fails = 0;
            system("cls");
            answData = answData + answ + " ";
        } while (count != words[wordID].size() && fails < 9);

        system("cls");

        if (count == words[wordID].size())
        {
            cout << "Победа" << endl;
        }
        else
        {
            cout << "не Победа" << endl << "Правильный ответ:" << words[wordID] << endl;
        }
        system("pause");
    }
}


void programStarting()
{
    cout << "\b\b\b\b\b\b\b\b\b\bL         " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLO        " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoA       " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoaD      " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadI     " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadiN    " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << flush;
    Sleep(100);

    for (size_t i = 0; i < 4; i++)
    {
        cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLOading.  " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoAding.. " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoaDing..." << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadIng.. " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg.  " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoadinG.. " << flush;
        Sleep(200);
        cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << flush;
        Sleep(200);
    }
    cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadiN    " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoadI     " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoaD      " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLoA       " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bLO        " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\bL         " << flush;
    Sleep(100);
    cout << "\b\b\b\b\b\b\b\b\b\b          " << flush;
    Sleep(500);
}