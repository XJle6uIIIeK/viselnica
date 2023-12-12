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
            cout << image[fails] << secretWord << endl <<"��������� ����� " << answData << endl;
            cout << "������� �����: ";
            cin >> answ;
            for (size_t i = 0; i <= answData.size(); i++) //�������� �� ��������� �����
            {
                if (answ != answData[i])
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            }

            if (!flag) { //���� ����� ����, �� ���������� �������� �����
                system("cls");
                continue;
            }

            for (int i = 0; i < words[wordID].size(); i++) //���� ����� ������, �� ��������� �� ������������ �� ������
            {

                if (answ == (char)words[wordID][i] && flag)
                {
                    fails--;
                    count++;
                    secretWord[i * 2 + 1] = answ;//"���������" �����
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
            cout << "������" << endl;
        }
        else
        {
            cout << "�� ������" << endl << "���������� �����:" << words[wordID] << endl;
        }
        system("pause");
    }
}


void programStarting()
{
    std::cout << "\b\b\b\b\b\b\b\b\b\bL         " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLO        " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoA       " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoaD      " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadI     " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiN    " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
    Sleep(100);

    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading.  " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing..." << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg.  " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(200);
    }
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiN    " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoadI     " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoaD      " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLoA       " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bLO        " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\bL         " << std::flush;
    Sleep(100);
    std::cout << "\b\b\b\b\b\b\b\b\b\b          " << std::flush;
    Sleep(500);
}