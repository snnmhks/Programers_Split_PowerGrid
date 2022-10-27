#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* height = (int*)malloc(sizeof(int) * n);
    int* TotalNumberOfWire = (int*)malloc(sizeof(int) * n);
    int* StartNum = (int*)malloc(sizeof(int) * n);
    int* Num = (int*)malloc(sizeof(int) * n);
    int StartNumLen = 1;

    for (int i = 0; i < n; i++)
    {
        TotalNumberOfWire[i] = 1;
        StartNum[i] = 0;
        height[i] = 0;
    }
    StartNum[0] = 1;
    height[0] = n;

    int count = 0;
    while (1)
    {
        for (int i = 0; i < StartNumLen; i++)
        {

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