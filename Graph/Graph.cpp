// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;



int main()
{
	int VertexX = 0;
	int VertexY = 0;
	int Num = 0;

	cin >> VertexX;
	cin >> VertexY;
	cin >> Num;

	int** Matrix = new int*[VertexY];

	for (int i = 0; i < VertexY; i++)
	{
		Matrix[i] = new int[VertexX];
	}

    bool** Matrixbool = new bool* [VertexY];

    for (int i = 0; i < VertexY; i++)
    {
        Matrixbool[i] = new bool[VertexX];
    }


    for (int i = 0; i < VertexY; i++)
    {
        for (int j = 0; j < VertexX; j++)
        {
            Matrixbool[i][j] = false;
        }
    }


    for (int i = 0; i < VertexY; i++)
    {
        for (int j = 0; j < VertexX; j++)
        {
            Matrix[i][j] = 0;
        }
    }
	

    for (int i = 0; i < Num; i++)
    {
        int ItemX = 0;
        int ItemY = 0;

        cin >> ItemX;
        cin >> ItemY;

        Matrix[ItemY][ItemX] = 1;
    }


    for (int i = 0; i < VertexY; i++)
    {
        for (int j = 0; j < VertexX; j++)
        {
            cout << Matrix[i][j];
        }
        cout << endl;
    }

    int WormCount = Num;

    for (int i = 0; i < VertexY; i++)
    {
        for (int j = 0; j < VertexX; j++)
        {
            //배추 찾으면 탐색 시작
            if (Matrix[i][j] == 1)
            {
                const int DirectionY[4] = { -1, 1,  0, 0 };
                const int DirectionX[4] = { 0, 0, -1, 1 };

                for (int dir = 0; dir < 4; ++dir)
                {
                    int NextY = i + DirectionY[dir];
                    int NextX = j + DirectionX[dir];

                    Matrixbool[i][j] = true;

                    if (NextY < 0 || NextY >= VertexY || NextX < 0 || NextX >= VertexX)
                    {
                        continue;
                    }

                    if (Matrix[NextY][NextX] == 1 && Matrixbool[NextY][NextX] == false)
                    {
                        WormCount--;
                        Matrixbool[NextY][NextX] = true;
                        continue;
                    }
          
                }
            }
        }
    }
    

    cout << WormCount;
}





//const int VertexCount = 6;
//
//int AdjacencyMatrix[VertexCount][VertexCount] =
//{
//	{ 0, 1, 0, 1, 0, 0 },
//	{ 1, 0, 1, 1, 0, 0 },
//	{ 0, 1, 0, 0, 0, 0 },
//	{ 1, 1, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 1 },
//	{ 0, 0, 0, 0, 1, 0 }
//};
//
//bool Visited[VertexCount] = {};
//
//void DFS(int Current)
//{
//	cout << "방문 : " << Current << '\n';
//	Visited[Current] = true;
//
//	for (int Next = 0; Next < VertexCount; Next++)
//	{
//		if (AdjacencyMatrix[Current][Next] == 0)
//		{
//			continue;
//		}
//		if (Visited[Next] == true)
//		{
//			continue;
//		}
//		DFS(Next);
//	}
//}
//
//void BFS(int Current)
//{
//	cout << "방문 : " << Current << '\n';
//	Visited[Current] = true;
//
//	for (int Current = 0; Current < VertexCount; Current++)
//	{
//		if (Visited[Current] == true)
//		{
//			continue;
//		}
//		DFS(Current);
//	}
//}
//
//int main()
//{
//	DFS(0);
//}



