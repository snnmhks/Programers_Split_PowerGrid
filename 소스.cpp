#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

using namespace std;

// Ʈ�������� ������ ����⿡ �ִ� ���ڸ� �����ְ� �� ���ڿ� ���̸� �ο��Ѵ�.
// ����� ���ڰ� ���� ���� ���� ����Ǵ� ���ڵ鿡�� ����-1 �� ���Ĵ� ���� -1-1...�̷������� ���̸� �ο��Ѵ�.
// ���̸� �ο��ϴ� ������ Ž���������� ȥ���� �Ͼ�� �ʰ� �ϱ� �����̴�. -> ��Ʈ�� Ž���ϴµ�
// ���� ���� ������� ���� �����ϴ°�? -> �Ʒ����� ���� �ö󰣴ٸ� ���̰� ���� ���� ���� ����ȴ�.
// Ʈ�� �����̱� ������ �����濡�� ���̰� ���� ���� ����. (���̰� ���� ����� Ʈ�� ������ �ƴ϶� ��ȯ ������.)
// ���̰� ���� ���� ������ �����ؼ� �� ���� ���̿� 1�� �����ش�. (��� ���� �ö󰡴� ���� �ƴ϶� ���̰� ����
// ��� ���ڿ� ���� �� ������ �ϰ� ���� ���̷� �Ѿ��.)
// �׷��� �� ���ڿ� ���� ������ �־����µ� �� ������ �ڽ� ���� �ڸ� ��� �ڽ� ���� �������� �����̴�.
// �׷��� �� ������ �� - 2*������ �������� ���� ���� �� ������ ���� ���� ��츦 ��� �����ϸ� �ȴ�.

// wires_rows�� 2���� �迭 wires�� �� ����, wires_cols�� 2���� �迭 wires�� �� �����Դϴ�.
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