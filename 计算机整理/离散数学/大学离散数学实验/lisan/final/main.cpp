

#include <iostream>
#include<vector>
using namespace std;

const int maxn = 4;


int array1[6] = {0,1,4,5,8,9};
int matrix[maxn][maxn] = {0};
void duicheng(){
    for (int i = 0;i < 4;i++){
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 1) {
                matrix[j][i]=1;
            }
        }
    }
}

void zifan(){
    for (int i = 0; i < 4; ++i) {
        if (matrix[i][i] != 1){}
        matrix[i][i] = 1;
    }
}

void chuandi(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 1){
                for (int k = 0; k < 4; ++k) {
                    if (matrix[j][k] == 1) {
                        matrix[i][k] = 1;
                    }
                }
            }
        }
    }
}


void print(){
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout<<matrix[i][j]<<"  ";
            if (j == 3){
                cout<<endl;
            }
        }
    }
    cout<<"------------"<<endl;
}

void dengjia(){
    duicheng();
    zifan();
    chuandi();
}


int shumu(){
    int m = 2;
    for (int i = 0; i < maxn; ++i) {
        m *= 2;
    }
    return m -maxn;
}

void chushihua(){

    matrix [0][1] = 1;
    matrix [1][0] = 1;
    matrix [1][2] = 1;
    matrix [2][3] = 1;
}




vector<int> judge(vector<int> temp){

    vector<int> value;

    for (int i = 0; i < 7; ++i) {
        int size = temp.size();

    }

    return value;
}


void print2(vector<int> m){
    cout<<"{";
    for (int i = 0; i < m.size(); ++i) {
        if (i == m.size()-1){
            cout<<m[i];
        }
        else{cout<<m[i]<<",";}
    }
    cout<<"}";
}


void startTest2(){


    vector<int> n1;
    vector<int> n2;

    for (int j = 1; j < 7; j++) {

        if ( (array1[0] - array1[j])%4 == 0 ){
            n1.push_back(array1[j]);
        }

    }

    vector<int> volunm1 = judge(n1);

    if (volunm1.size() != 0){
        for (int j = 1; j < volunm1.size(); ++j) {

            if ( (volunm1[0] - volunm1[j])%4 == 0 ){
                n2.push_back(volunm1[j]);
            }

        }

    }

    print2(n1);
    cout<<endl;


}
int main() {
    startTest2();

    return 0 ;
}



