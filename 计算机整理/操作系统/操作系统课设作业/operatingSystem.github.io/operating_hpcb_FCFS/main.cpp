#include <iostream>
using namespace std;

#define MAXQSIZE 5//设置的队列大小
#define MAXINT 100;//用于for循环寻找进程的辅助变量
int mainTapes = 5;//磁带数
int mainSize = 1024;//内存数
int forceTime = 0;//全局时间，从零开始
typedef struct HPCB {
    string name;// 作业名
    string account;//用户名
    int time;//需要运行的时间
    int needSize;//需要的内存空间数目
    int needTapes;//需要的磁带数
    int arvTime;//到达的时间
    int staus;//目前作业状态,1表示就绪状态，2表示运行，3表示结束
}HPCB,*qHPCB;

//----队列的定义及操作--------
typedef struct {
    HPCB *base;							//初始化的动态分配存储空间
    int front;							//头指针，若队列不空，指向队头元素
    int rear;							//尾指针，若队列不空，指向队尾元素的下一个位置
    int count;                          //主存中有的作业数
}sqQueue;

/////////////////////////////////////////////////////////////////////////////////////////

//进队
void EnQueue(sqQueue &Q, HPCB e){
    //插入元素e为Q的新的队尾元素
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%MAXQSIZE;
    Q.count += 1;
    mainSize -= e.needSize;
    mainTapes -= e.needTapes;
}//EnQueue

bool QueueEmpty(sqQueue Q){
    //判断是否为空队
    if (Q.rear == Q.front) {
        return true;
    } else {
        return false;
    }
}//QueueEmpty

//弹出一个元素
void DeQueue(sqQueue &Q, HPCB &u){
    //队头元素出队并置为u
    u = Q.base[Q.front];
    //以下补充一条语句
    Q.front = (Q.front + 1)%MAXQSIZE;
    mainSize += u.needSize;
    mainTapes += u.needTapes;
}//DeQueue

void initQueue(sqQueue &Q); //对5个HPCB进行初始化
void display(sqQueue q); //展示所有作业的状态
void onControl(sqQueue &Q); //将队列中的一个进程调度到处理器中运行
void scan(sqQueue &Q);//扫描整个队列，将0-2个作业调入运行队列
bool checkIn(sqQueue Q);//检查队列里面是否还有有可以进入处理机的作业
int main() {
    cout<<"姓名：徐睿航 学号：202013160210 实验：作业调度"<<endl;
    sqQueue Q;
    initQueue(Q);
    cout<<"------最开始初始化状态------"<<endl;
    display(Q);
    while(checkIn(Q)) {
        onControl(Q);
    }

//    onControl(Q);



    return 0;
}

//对5个作业初始化
void initQueue(sqQueue &Q) {

    Q.base = new HPCB[MAXQSIZE];
    Q.front = Q.rear = 0;

    Q.base[0].name = "JA";
    Q.base[0].account = "A";
    Q.base[0].staus = 1;
    Q.base[0].time = 20;
    Q.base[0].needSize = 150;
    Q.base[0].needTapes = 2;
    Q.base[0].arvTime = 0;

    Q.base[1].name = "JB";
    Q.base[1].account = "B";
    Q.base[1].staus = 1;
    Q.base[1].time = 35;
    Q.base[1].needSize = 600;
    Q.base[1].needTapes = 1;
    Q.base[1].arvTime = 2;


    Q.base[2].name = "JC";
    Q.base[2].account = "C";
    Q.base[2].staus = 1;
    Q.base[2].time = 6;
    Q.base[2].needSize = 500;
    Q.base[2].needTapes = 3;
    Q.base[2].arvTime = 3;

    Q.base[3].name = "JD";
    Q.base[3].account = "D";
    Q.base[3].staus = 1;
    Q.base[3].time = 24;
    Q.base[3].needSize = 100;
    Q.base[3].needTapes = 2;
    Q.base[3].arvTime = 4;

    Q.base[4].name = "JE";
    Q.base[4].account = "E";
    Q.base[4].staus = 1;
    Q.base[4].time = 12;
    Q.base[4].needSize = 300;
    Q.base[4].needTapes = 3;
    Q.base[4].arvTime = 5;

    Q.count = 0;//最开始处理器上的作业数量为0

    cout<<"---------初始化完成----------"<<endl;
}

//扫描整个队列，将目前就绪进程中，时间最小的一个或两个作业调整状态为2,或者不做调整
void scan(sqQueue &Q) {

    int min = MAXINT;
    int positon1 = -1;
    int positon2 = -1;//如果有两个进程可以的话，则position2有值

    for (int i = 0; i < MAXQSIZE; ++i) {
        if (Q.base[i].staus == 1 && Q.base[i].arvTime < min && mainSize >= Q.base[i].needSize && Q.count < 2 && mainTapes >= Q.base[i].needTapes) {
            min = Q.base[i].arvTime;
            positon1 = i;
        }
    }

    if (positon1 != -1) {
        mainSize -= Q.base[positon1].needSize;
        mainTapes -= Q.base[positon1].needTapes;
        Q.base[positon1].staus = 2;
        Q.count  += 1;//队列中任务数量+1
    }
//    cout<<Q.base[positon1].name<<endl;
//    cout<<"--------"<<mainTapes<<endl;
//    cout<<"--------"<<mainSize<<endl;


    min = MAXINT;

    for (int i = 0; i < MAXQSIZE; ++i) {
        if (Q.base[i].staus == 1 && Q.base[i].arvTime < min && mainSize >= Q.base[i].needSize && Q.count < 2 && mainTapes >= Q.base[i].needTapes) {
            min = Q.base[i].arvTime;
            positon2 = i;
        }
    }

    if (positon2 != -1) {
        mainSize -= Q.base[positon2].needSize;
        mainTapes -= Q.base[positon2].needTapes;
        Q.base[positon2].staus = 2;
        Q.count += 1;//队列中任务数量+1
    }
//    cout<<Q.base[positon2].name<<endl;
//    cout<<"--------"<<mainTapes<<endl;
//    cout<<"--------"<<mainSize<<endl;
}

//整个队列的状态
void display(sqQueue q) {
    for (int i = 0; i < MAXQSIZE; ++i) {
        cout<<"第"<<i + 1<<"个作业状态: ";
        cout<<"该作业的名称是： "<<q.base[i].name<<"\t\t";
        cout<<"该作业的用户是： "<<q.base[i].account<<"\t\t";
        cout<<"该作业还剩余的时间片为： "<<q.base[i].time<<endl;
    }
}
//将队列中的一个进程调度到处理器中运行
void onControl(sqQueue &Q) {

    scan(Q);

    cout<<"---------此处显示即将放上处理机运行的作业的状态----------"<<endl;
    if (Q.count == 1) {
        for (int i = 0; i < MAXQSIZE; ++i) {
            if (Q.base[i].staus == 2) {
                cout<<"该作业的目前的用户名为： "<<Q.base[i].account<<endl;
                cout<<"该作业的名称是： "<<Q.base[i].name<<endl;
                cout<<"该作业还剩余的时间片为： "<<Q.base[i].time<<endl;
                forceTime += Q.base[i].time;//标准时间修改
                Q.base[i].time = 0;
                Q.base[i].staus = 3;//作业状态修改
                Q.count -= 1;//队列作业量减1
            }
        }
    } else {
        int position1 = -1;
        int position2 = -1;

        //此for循环用于找出运行的作业坐标
        for (int i = 0; i < 5; ++i) {
            if (Q.base[i].staus == 2) {
                cout<<"该作业的目前的用户名为： "<<Q.base[i].account<<endl;
                cout<<"该作业的名称是： "<<Q.base[i].name<<endl;
                cout<<"该作业还剩余的时间片为： "<<Q.base[i].time<<endl;
//                forceTime += Q.base[i].time;
//                Q.base[i].time = 0;
//                Q.base[i].staus = 3;
                if (position1 == -1) {
                    position1 = i;
                } else {
                    position2 = i;
                }
            }
        }//for
         
        //Q.base[position1].time 中的time表示所需运行时间
        if (Q.base[position1].time < Q.base[position2].time) {
            forceTime += Q.base[position1].time;//标准时间修改

            Q.base[position2].time = Q.base[position2].time - Q.base[position1].time;

            Q.base[position1].time = 0;
            Q.base[position1].staus = 3;//作业状态修改

            mainSize += Q.base[position1].needSize;//释放资源
            mainTapes += Q.base[position1].needTapes;//释放资源

            Q.count -= 1;//队列容纳数增加1
        } else if (Q.base[position1].time > Q.base[position2].time) {
            forceTime += Q.base[position2].time;//标准时间修改

            Q.base[position1].time -= Q.base[position2].time;

            Q.base[position2].time = 0;
            Q.base[position2].staus = 3;//作业状态修改

            mainSize += Q.base[position2].needSize;//释放资源
            mainTapes += Q.base[position2].needTapes;//释放资源


            Q.count -= 1;//队列容纳数增加1
        } else {
            forceTime += Q.base[position1].time;//标准时间修改

            Q.base[position1].time = 0;
            Q.base[position1].staus = 3;//作业状态修改
            Q.count -= 1;//队列容纳数增加1

            mainSize += Q.base[position1].needSize;//释放资源
            mainTapes += Q.base[position1].needTapes;//释放资源

            Q.base[position2].time = 0;
            Q.base[position2].staus = 3;//作业状态修改

            Q.count -= 1;//队列容纳数增加1
            mainSize += Q.base[position2].needSize;//释放资源
            mainTapes += Q.base[position2].needTapes;//释放资源
        }

    }
//    for (int i = 0; i < 5; ++i) {
//        if (Q.base[i].staus == 2) {
//

//            cout<<"该作业的目前的用户名为： "<<Q.base[i].account<<endl;
//            cout<<"该作业的名称是： "<<Q.base[i].name<<endl;
//            cout<<"该作业还剩余的时间片为： "<<Q.base[i].time<<endl;

//            if (Q.base[i].time - 1 > 0) {
//                Q.base[i].time -= 1;//将时间减1
//            } else {
//                Q.base[i].staus = 3;//表明此进程已经运行结束
//                Q.base[i].time = 0;//时间片自然为0
//                mainSize += Q.base[i].needSize;//将占用资源全部释放
//                mainTapes += Q.base[i].needTapes;
//            }
//
//        }
//    }


    cout<<"有作业已经完成，目前时间是第"<<forceTime<<"个时间片\n";
    cout<<"------作业完成后的队列状态是-------"<<endl;
    display(Q);
}

//将正在进行的作业进行单独展示
void displaySlected(sqQueue Q) {
    for (int i = 0; i < MAXQSIZE; ++i) {
        if (Q.base[i].staus == 2){
            cout<<"该作业的目前的用户名为： "<<Q.base[i].account<<endl;
            cout<<"该作业的名称是： "<<Q.base[i].name<<endl;
            cout<<"该作业还剩余的时间片为： "<<Q.base[i].time<<endl;
        }
    }
}

//检查队列里面是否还有可以执行的作业
bool checkIn(sqQueue Q) {
    for (int i = 0; i < 5; ++i) {
        if (Q.base[i].staus != 3) {
            return true;
        }
    }
    return false;
}



