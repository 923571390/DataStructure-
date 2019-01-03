#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Point myMaze[10][10];
    bool Maze[10][10] = {
        { false,false,false,false,false,false,false,false,false,false },
        { false,true ,true ,false,true ,true ,true ,false,true ,false },
        { false,true ,true ,false,true ,true ,true ,false,true ,false },
        { false,true ,true ,true ,true ,false,false,true ,true ,false },
        { false,true ,false,false,false,true ,true ,true ,true ,false },
        { false,true ,true ,true ,false,true ,true ,true ,true ,false },
        { false,true ,false,true ,true ,true ,false,true ,true ,false },
        { false,true ,false,false,false,true ,false,false,true ,false },
        { false,true,true ,true ,true ,true ,true ,true , true ,false },
        { false,false,false,false,false,false,false,false,false,false } };
    for (int i = 0; i<10; i++)
        for (int j = 0; j<10; j++)
        {
            myMaze[i][j].x = i;
            myMaze[i][j].y = j;
            myMaze[i][j].acessible = Maze[i][j];
        }
    Point start(1, 1, true);
    Point end(8, 8, true);
    Stack path;
    path.push(start);
    Point me = start;
    myMaze[me.x][me.y].tab = 1;
    while (me.x != end.x || me.y != end.y)
    {
        if (me.x == end.x && me.y == end.y)
            break;
        if (myMaze[me.x + 1][me.y].acessible)
        {
            myMaze[me.x + 1][me.y].acessible = false;
            myMaze[me.x + 1][me.y].tab = 1;
            path.push(Point(me.x + 1, me.y));
            me = myMaze[me.x + 1][me.y];
            continue;
        }
        if (myMaze[me.x - 1][me.y].acessible)
        {
            myMaze[me.x - 1][me.y].acessible = false;
            myMaze[me.x - 1][me.y].tab = 1;
            path.push(Point(me.x - 1, me.y));
            me = myMaze[me.x - 1][me.y];
            continue;
        }
        if (myMaze[me.x][me.y + 1].acessible)
        {
            myMaze[me.x][me.y + 1].acessible = false;
            myMaze[me.x][me.y + 1].tab = 1;
            path.push(Point(me.x, me.y + 1));
            me = myMaze[me.x][me.y + 1];
            continue;
        }
        if (myMaze[me.x][me.y - 1].acessible)
        {
            myMaze[me.x][me.y - 1].acessible = false;
            myMaze[me.x][me.y - 1].tab = 1;
            path.push(Point(me.x, me.y - 1));
            me = myMaze[me.x][me.y - 1];
            continue;
        }
        if (0 == path.getLength())
        {
            cout << "û��·" << endl;
            return -1;
        }
        path.pop();
        me = path.getTop();
    }
    int i,j;
    cout << "�Թ���ͼ:" << endl;
    cout << "   0�� 1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9��" << endl;
    for (i = 0; i<10; i++){
        cout<<i<<"�� ";
        for (j = 0; j<10; j++)
        {
        if (myMaze[i][j].tab == 1)     cout << "X   " ;
        else if (Maze[i][j]==false)    cout << "#   " ;
        else cout << "0   " ;
        }
        cout<<endl;
    }
    cout << "�Թ�·��:" << endl;
    path.printStack();
    return 0;
}

