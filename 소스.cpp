#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// wires_rows�� 2���� �迭 wires�� �� ����, wires_cols�� 2���� �迭 wires�� �� �����Դϴ�.
int solution(int n, int** wires, size_t wires_rows, size_t wires_cols) {
    int* NumberOfLine = (int*)malloc(sizeof(int) * wires_cols);
    int* StartNum = (int*)malloc(sizeof(int) * wires_cols);
    int StartNumIndex = 0;

    for (int i = 0; i < wires_cols; i++)
    {
        NumberOfLine[i] = 0;
        StartNum[i] = 0;
    }
    
    int index = 0;
    for (int i = 0; i < wires_cols; i++)
    {
        if (wires[i][0] == index + 1)
        {
            index = wires[i][0];
        }
        else if (wires[i][0] != index)
        {
            for (int j = index + 1; j < wires[i][0]; j++)
            {
                StartNum[StartNumIndex] = j;
                NumberOfLine[j]++;
                StartNumIndex++;
            }
            index = wires[i][0];
        }
    }

    int Num = StartNumIndex;
    while (1)
    {
        StartNumIndex = Num;
        Num = 0;
        for (int i = 0; i < StartNumIndex; i++)
        {
            for (int j = 0; j < wires_cols; j++)
            {
                if (StartNum[i] == wires[j][1])
                {
                    NumberOfLine[wires[j][0]] += NumberOfLine[StartNum[i]];
                    StartNum[i] = wires[j][0];
                    Num++;
                    break;
                }
            }
        }
        if (Num == 0)
        {
            break;
        }
    }


    int answer = -1;
    return answer;
}