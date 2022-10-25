#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* NumberOfLine = (int*)malloc(sizeof(int) * n);
    int* TotalNumberOfWire = (int*)malloc(sizeof(int) * n);
    int* CheckingList = (int*)malloc(sizeof(int) * wires_rows);
    int* StartNum = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        NumberOfLine[i] = 0;
        TotalNumberOfWire[i] = 1;
        StartNum[i] = 0;
    }
    
    for (int i = 0; i < wires_rows; i++)
    {
        NumberOfLine[wires[i][0]-1]++;
        NumberOfLine[wires[i][1]-1]++;
        CheckingList[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << NumberOfLine[i] << " ";
    }
    cout << endl;

    for (int LineNum = 1; LineNum < n+1; LineNum++)
    {
        for (int WireNum = 0; WireNum < n; WireNum++)
        {
            if (NumberOfLine[WireNum] == LineNum)
            {
                for (int k = 0; k < wires_rows; k++)
                {
                    if (wires[k][1] == WireNum +1 && CheckingList[k] == 0)
                    {
                        TotalNumberOfWire[wires[k][0] - 1] += TotalNumberOfWire[WireNum];
                        CheckingList[k] = 1;
                    }
                    else if (wires[k][0] == WireNum + 1 && CheckingList[k] == 0)
                    {
                        TotalNumberOfWire[wires[k][1] - 1] += TotalNumberOfWire[WireNum];
                        CheckingList[k] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << TotalNumberOfWire[i] << " ";
    }
    cout << endl;

    int MinNum = 100;
    for (int i = 0; i < n; i++)
    {
        int diff = n - TotalNumberOfWire[i]*2;
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

    int a = solution(7,list,ROW,2);

    cout << a;

    int j;
    cin >> j;
}