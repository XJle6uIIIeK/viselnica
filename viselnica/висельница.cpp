#define _CRT_SECURE_NO_WARNINGS
#include "imageAndWord.h"
#include <xstring>
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
        secret += "_";
    cout << secret << "\n" << words[wordID] << "\n";
    
    do
    {
        cout << "\n¬ведите букву: ";
        cin >> answ;
        system("cls");
        for (size_t i = 0; i < data.size(); i++)
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
                cout << "correct\n";
                count++;
                secret[i] = answ;
            }
        }
        data += answ;
        cout << secret << "\n¬веденные буквы " << data;
    } while (count != words[wordID].size());
}