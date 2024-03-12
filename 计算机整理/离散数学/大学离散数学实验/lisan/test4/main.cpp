#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include<array>
using namespace std;

void Print01(int val)
{
    cout << val << " ";
}

void jiaoji()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);  // 范围0-9
        v2.push_back(i+5); // 范围5-15
    }

    vector<int> v3;

    v3.resize(v1.size() + v2.size()); // 最特殊情况，v2全部包含v1里面的元素，这个时候v3大小建议取v1的大小
    vector<int>::iterator targetEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "交集：" << endl;
    for_each(v3.begin(), targetEnd1, Print01);
    cout << endl;
}

void bingji()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);  // 范围0-9
        v2.push_back(i+5); // 范围5-15
    }

    vector<int> v3;
    v3.resize(max(v1.size(),v2.size()));
    //vector<int>::iterator targetEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "并集：" << endl;
    for_each(v3.begin(), v3.end(), Print01);
    cout << endl;
}


void chaji()
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(i);  // 范围0-9
        v2.push_back(i+5); // 范围5-15
    }

    cout << "集合v1：" << endl;
    for_each(v1.begin(), v1.end(), Print01);
    cout << endl;
    cout << "集合v2：" << endl;
    for_each(v2.begin(), v2.end(), Print01);
    cout << endl;

    vector<int> v3;
    v3.resize(max(v1.size(),v2.size()));
    vector<int>::iterator targetEnd1 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "v1和v2差集：" << endl;
    for_each(v3.begin(), targetEnd1, Print01);
    cout << endl;

    vector<int> v4;
    v4.resize(5);
    vector<int>::iterator targetEnd2 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    cout << "v2和v1差集：" << endl;
    for_each(v4.begin(), targetEnd2, Print01);
    cout << endl;
}


//此函数用于求子集
int powerset(char *a,int len)
{
    int i = 0, j = 0;
    bool flag = false;
    cout<<"{ }"<<endl;
    for(i = 1; !flag ; i++)
    {
        cout<<"{";
        flag = true;
        for(j = 0; j < len; j++)
        {
            if( (i >> j) & 1)
                cout << a[j] << " ";
            else
                flag = false;
        }
        cout << "}" <<endl;
    }
    return i;
}

//print2用于初始化原集合并输出子集
void print2(){
    int num = 4;
    cout<<"此集合中设定原集合为{a,b,c,d}"<<endl;
    char *item = new char[num];
    for(int i = 0;i < num; i++){
        item[i] = 'a' + i;
    }
    int count = powerset(item,num);
    cout << num << "个元素幂集总数:" << count <<endl;
    delete [] item;
}

#define MAX 20
//此函数用于求集合中的m元子集
void mziji(){
    int set[MAX];
    int m, n, position;
    int i;
    cout<<"集合设定为从1开始的数学集合"<<endl;
    printf("输入集合数: ");
    scanf("%d", &m);
    printf("输入取出元素 n：");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        set[i] = i + 1;
    }

    for(i = 0; i < n; i++)
    {
        printf("%d", set[i]);
    }
    putchar('\n');

    position = n - 1;

    while(1)
    {
        if(set[n - 1] == m)
        {
            position--;
        }
        else
        {
            position = n - 1;
        }
        set[position]++;
        for(i = position + 1; i < n; i++)
        {
            set[i] = set[i - 1] + 1;
        }
        for(i = 0; i < n; i++)
        {
            printf("%d", set[i]);
        }
        putchar('\n');
        if(set[0] >= m - n + 1)
        {
            break;
        }
    }
}

void display(array<int,4> arr)
{
    for(auto value:arr){
        cout<<value<<" ";
    }
    cout<<endl;
}

//此函数用于求全排列
void getPermutation1()
{
    array<int,4> arr ={3,2,1,0};

    sort(arr.begin(),arr.end());  //如果将此行注释，最终结果会不完整
    do{
        display(arr);
    }while(next_permutation(arr.begin(),arr.end()));
}



int main()
{
    cout<<"此集合为{1,2,3,4}"<<endl
        <<"------------------"<<endl;

    getPermutation1();
    return 0;

}



