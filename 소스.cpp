#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* NumberOfLine = (int*)malloc(sizeof(int) * n);
    int* TotalNumberOfWire = (int*)malloc(sizeof(int) * n);
    int* StartNum = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        NumberOfLine[i] = 0;
        TotalNumberOfWire[i] = 1;
        StartNum[i] = 0;
    }
    
    for (int i = 0; i < wires_cols; i++)
    {
        NumberOfLine[wires[i][0]-1]++;
        NumberOfLine[wires[i][1]-1]++;
    }

    for (int LineNum = 1; LineNum < n+1; LineNum++)
    {
        for (int WireNum = 0; WireNum < n; WireNum++)
        {
            if (NumberOfLine[WireNum] == LineNum)
            {
                for (int k = 0; k < wires_cols; k++)
                {
                    if (wires[k][1] == WireNum +1)
                    {
                        TotalNumberOfWire[wires[k][0] - 1] += TotalNumberOfWire[WireNum];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << TotalNumberOfWire[i] << " ";
    }

    int answer = 0;
    return answer;
}

int main()
{
    int* list[8];
    int aaa[8][2] = { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8}, {7,9} };
    for (int i = 0; i < 8; i++)
    {
        list[i] = aaa[i];
    }

    solution(9,list,2,8);

    int j;
    cin >> j;
}