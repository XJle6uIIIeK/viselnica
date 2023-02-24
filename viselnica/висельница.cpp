#define _CRT_SECURE_NO_WARNINGS
#include "imageAndWord.h"
#include <windows.h>



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

    int wordID, count = 0, err = 0;
    string secret = "", data = "",trying = "";
    char answ;
    bool flag;
    
    do
    {
        wordID = getNextRandom(66);
    } while (wordID < 0);

    for (int i = 0; i < words[wordID].size(); i++)
        secret += " _";
    cout << words[wordID] << "\n";
    
    do
    {
        cout << ASCII[err] << secret << "\n��������� ����� " << data;
        cout << "\n������� �����: ";
        cin >> answ;
        for (size_t i = 0; i <= data.size(); i++)
        {
            if (answ == data[i])
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }
        }
        for (int i = 0; i < words[wordID].size(); i++)
        {

            if (answ == (char)words[wordID][i] && flag)
            {

                count++;
                secret[i*2+1] = answ;
            }
        }
        system("cls");
        data = data + answ + " ";
        err++;
    } while (count < words[wordID].size() || err < 9);

    system("cls");

    if (count == words[wordID].size())
    {
        cout << "������";
    }
    else
    {
        cout << "�� ������";
    }
}