#include <iostream>
#include<vector>

#define Temp 999  //暂时的最大长度，保证最远，初始化为999
#define Index 22    //节点数量，同时也是位置坐标

using namespace std;

int Count[Index] = { 0 }; //初始化介点，全为零

double date[Index][Index] = {
        0,	Temp,	1,	0.9,	1.2,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	0	,1,	Temp,	Temp,	1.2,	1,	5,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	1,	0,	1,	1,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	6	,Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        0.9,	Temp,	1	,0,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	3,	Temp,	Temp,	Temp,
        1.2	,Temp,	1	,Temp,	0,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	1.2,	Temp,	Temp,	Temp,	0,	0.3,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	1,	Temp,	Temp,	Temp,	0.3	,0,	5,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	5,	Temp,	Temp,	Temp,	Temp,	5,	0,	Temp,	Temp,	Temp,	1,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	0	,1,	Temp,	Temp,	1	,Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	0	,1	,1,	Temp,	1	,Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	0,	Temp,	1	,3.1,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1	,Temp,	1	,Temp,	0,	1.5	,Temp,	1,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	Temp,	1,	1.5,	0	,Temp,	Temp,	0.8,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	6,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	3.1,	Temp,	Temp,	0,	1,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	Temp,	1,	0	,Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	0.8,	Temp,	Temp,	0,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	0,	Temp,	Temp,	Temp,	1,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	0,	1,	1,	Temp,	Temp,
        Temp,	Temp,	Temp,	3,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	0,	1,	Temp,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	1,	0	,1,	Temp,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1	,0,	1,
        Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	Temp,	1,	0,
};
//此函数用于保存节点间的距离

void DFS(int cur, int tar, double dis, double& min, vector<int>& visit, vector<int>& path) {

    if (dis > min) return;
    if (tar == cur) {
        if (dis < min) {
            min = dis;
            if (!path.empty()) {
                path.clear();
            }
            for (int i = 0; i < Index; i++) {
                if (visit[i] == 1) {
                    path.push_back(i);
                }
            }


        };

        return;
    }
    for (int i = 0; i < Index; i++) {
        if (date[cur][i] != Temp && visit[i] == 0) {
            visit[i] = 1;
            DFS(i, tar, dis + date[cur][i], min, visit, path);
            visit[i] = 0;

        }
    }
}//此函数用于寻找最短距离


int main()
{
    for (int i = 0; i < Index; i++) {
        for (int j = i; j < Index; j++) {
            if (i == j)continue;//越过自己与自己
            double min = Temp*1.0;
            vector<int>visit(Index, 0);
            vector<int>path;
            DFS(i, j, 0, min, visit, path);
            if (min == Temp)continue;
            cout << i+1 << "与" << j+1 << " 之间的最短路: " << "最短距离" << min << "	" <<
                 "二者的最短路经过的节点: ";
            for (auto i : path) {
                Count[i]++;
                cout << i+1 << "、";
            }
            cout << "\b\b" << "  ";
            cout << endl;
        }
    }
    for (int i = 0; i < Index; i++) {
        cout << "第" << i+1 << "号节点的介数: " << Count[i] << endl;
    }
}