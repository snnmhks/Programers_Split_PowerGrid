#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// 트리구조기 때문에 꼭대기에 있는 숫자를 정해주고 각 숫자에 높이를 부여한다.
// 꼭대기 숫자가 제일 높고 이후 연결되는 숫자들에게 높이-1 그 이후는 높이 -1-1...이런식으로 높이를 부여한다.
// 높이를 부여하는 이유는 탐색과정에서 혼선이 일어나지 않게 하기 위함이다. -> 루트를 탐색하는데
// 길이 여러 갈래라면 어디로 가야하는가? -> 아래에서 부터 올라간다면 높이가 높은 곳을 향해 가면된다.
// 트리 구조이기 때문에 갈림길에서 높이가 같은 경우는 없다. (높이가 같은 경우라면 트리 구조가 아니라 순환 구조다.)
// 높이가 제일 낮은 곳부터 시작해서 그 다음 높이에 1씩 더해준다. (계속 따라 올라가는 것이 아니라 높이가 같은
// 모든 숫자에 대해 이 과정을 하고 다음 높이로 넘어간다.)
// 그러면 각 숫자에 따른 갯수가 주어지는데 이 갯수는 자신 위를 자를 경우 자신 포함 송전선의 갯수이다.
// 그러면 총 송전선 수 - 2*선택한 송전선의 무리 갯수 의 절댓값이 가장 작은 경우를 골라서 리턴하면 된다.

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
        for (int i = 0; i < n; i++)
        {
            cout << height[i] << " ";
        }
        cout << endl;
        if (count >= n-1)
        {
            break;
        }
    }

    

    cout << n - minus << endl;

    for (int i = n - minus; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (height[j] == i)
            {
                int Snum = j + 1;
                for (int k = 0; k < wires_rows; k++)
                {
                    if (wires[k][0] == Snum && height[wires[k][1] - 1] > height[Snum - 1])
                    {
                        TotalNumberOfWire[wires[k][1] - 1] += TotalNumberOfWire[Snum - 1];
                        break;
                    }
                    else if (wires[k][1] == Snum && height[wires[k][0] - 1] > height[Snum - 1])
                    {
                        TotalNumberOfWire[wires[k][0] - 1] += TotalNumberOfWire[Snum - 1];
                        break;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        cout << TotalNumberOfWire[i] << " ";
                    }
                    cout << endl;
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

#define ROW 14

int main()
{
    int* list[ROW];
    int aaa[ROW][2] = { {1,3},{1,6},{1,7},{2,3},{2,4},{2,5},{4,8},{4,9},{5,10},{5,11},{6,12},{6,13},{7,14},{7,15} };
    for (int i = 0; i < ROW; i++)
    {
        list[i] = aaa[i];
    }

    int a = solution(15, list, ROW, 2);

    cout << a;

    int j;
    cin >> j;
}