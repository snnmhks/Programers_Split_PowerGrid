#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows는 2차원 배열 wires의 행 길이, wires_cols는 2차원 배열 wires의 열 길이입니다.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* NumberOfLine = (int*)malloc(sizeof(int) * wires_cols);
    for (int i = 0; i < wires_cols; i++)
    {
        NumberOfLine[i] = 0;
    }

    for (int i = 0; i < wires_cols; i++)
    {
        NumberOfLine[wires[i][0]]++;
        NumberOfLine[wires[i][1]]++;
    }

    int MaxNum[10] = { 0, };
    int MaxNumIndex[10] = { 0, };
    int index = 0;
    for (int i = 0; i < wires_cols; i++)
    {
        if (NumberOfLine[i] > MaxNum[index])
        {
            for (int j = 0; j < index; j++)
            {
                MaxNum[j] = 0;
                MaxNumIndex[j] = 0;
            }
            index = 1;
            MaxNum[0] = NumberOfLine[i];
            MaxNumIndex[0] = i;
        }
        else if (NumberOfLine[i] == MaxNum[index])
        {
            MaxNum[index] = NumberOfLine[i];
            MaxNumIndex[index] = i;
            index++;
        }
    }

    int answer = -1;
    return answer;
}