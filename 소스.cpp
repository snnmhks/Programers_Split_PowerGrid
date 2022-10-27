#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* height = (int*)malloc(sizeof(int) * n);
    int* TotalNumberOfWire = (int*)malloc(sizeof(int) * n);
    int* CheckingList = (int*)malloc(sizeof(int) * n);
    int* StartNum = (int*)malloc(sizeof(int) * n);
    int* StartNumBackup = (int*)malloc(sizeof(int) * n);
    int* Num = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        TotalNumberOfWire[i] = 1;
        StartNum[i] = 0;
        height[i] = 0;
        CheckingList[i] = 0;
    }
    StartNum[0] = 1;
    height[0] = n;
    TotalNumberOfWire[0] = n;

    int count = 0;
    int minus = 0;
    int StartNumLen = 1;
    int index = 1;
    while (1)
    {
        StartNumLen = index;
        index = 0;
        minus++;
        for (int i = 0; i < StartNumLen; i++)
        {
            for (int j = 0; j < wires_rows; j++)
            {
                if (wires[j][0] == StartNum[i] && CheckingList[j] == 0)
                {
                    height[wires[j][1] - 1] = n - minus;
                    count++;
                    StartNumBackup[index] = wires[j][1];
                    index++;
                    CheckingList[j] = 1;
                }
                else if (wires[j][1] == StartNum[i] && CheckingList[j] == 0)
                {
                    height[wires[j][0] - 1] = n - minus;
                    count++;
                    StartNumBackup[index] = wires[j][0];
                    index++;
                    CheckingList[j] = 1;
                }
            }
        }
        for (int i = 0; i < index; i++)
        {
            StartNum[i] = StartNumBackup[i];
            StartNumBackup[i] = 0;
        }

        if (count >= n-1)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (height[i] == n - minus)
        {
            int Snum = i + 1;
            while (1)
            {
                for (int j = 0; j < wires_rows; j++)
                {
                    if (wires[j][0] == Snum && height[wires[j][0]-1] > height[Snum-1])
                    {
                        TotalNumberOfWire[wires[j][1] - 1] += TotalNumberOfWire[Snum - 1];
                        Snum = wires[j][1];
                        break;
                    }
                    else if (wires[j][1] == Snum && height[wires[j][1] - 1] > height[Snum - 1])
                    {
                        TotalNumberOfWire[wires[j][0] - 1] += TotalNumberOfWire[Snum - 1];
                        Snum = wires[j][0];
                        break;
                    }
                }
                if (Snum == 1)
                {
                    break;
                }
            }
        }
    }

    int MinNum = 100;
    for (int i = 0; i < n; i++)
    {
        int diff = n - TotalNumberOfWire[i] * 2;
        if (diff < 0)
        {
            diff = -diff;
        }

        if (diff < MinNum)
        {
            MinNum = diff;
        }
    }

    int answer = MinNum;
    return answer;
}

#define ROW 6

int main()
{
    int* list[ROW];
    int aaa[ROW][2] = { {1,2},{2,7},{3,7},{3,4},{4,5},{6,7} };
    for (int i = 0; i < ROW; i++)
    {
        list[i] = aaa[i];
    }

    int a = solution(7, list, ROW, 2);

    cout << a;

    int j;
    cin >> j;
}