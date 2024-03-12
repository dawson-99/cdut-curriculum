#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class person{
public:
    string name ;
    int age;
public:
    person(){
        this->name="";
        this->age=0;
    }
    person(string name,int age ){
        this->name =name ;
        this->age = age;
    }
    bool operator==(const person &p){
        if(p.name==this->name && p.age==this->age){
            return true;
        }else{
            return false;
        }
    }
    bool operator <(const person & p){
        if(this->age<p.age){
            return true;
        }
        else{
            return false;
        }
    }
};

void test01(){
    vector<person> vec;
    vec.push_back(person("a",1));
    vec.push_back(person("b",3));
    vec.push_back(person("c",2));
    vec.push_back(person("d",4));
    vec.push_back(person("A",7));
    vec.push_back(person("B",5));
    cout<<"---------vec------------- "<<endl;
    for_each(vec.begin(),vec.end(),[](person & p){
        cout<<"  "<< p.name<<""<<p.age;
    });
    cout<<endl;

    vector<person> vec2;
    vec2.push_back(person("A",7));
    vec2.push_back(person("B",5));
    vec2.push_back(person("C",9));
    vec2.push_back(person("D",10));

    cout<<"---------vec2------------- "<<endl;
    for_each(vec2.begin(),vec2.end(),[](person & p){
        cout<<"   "<< p.name<<""<<p.age;
    });
    cout<<endl;

    //交集
    vector<person> v;
    v.resize(min(vec.size(),vec2.size()));
    vector<person>::iterator end=set_intersection(vec.begin(),vec.end(),vec2.begin(),vec2.end(),v.begin());
    cout<<"---------交集------------- "<<endl;
    for_each(v.begin(),end,[](person & p){
        cout<<"  "<< p.name<<""<<p.age;
    });
    cout<<endl;

    vector<person> v2;
    v2.resize(vec.size()+vec2.size());
    cout<<"---------并集------------- "<<endl;
    vector<person>::iterator end_u=set_union(vec.begin(),vec.end(),vec2.begin(),vec2.end(),v2.begin());
    for_each(v2.begin(),end_u,[](person &p){
        cout<<"   "<<p.name<<p.age;
    });
    cout<<endl;

    vector<person> v3;
    v3.resize(vec.size());
    cout<<"---------差集（vec-vec2）------------- "<<endl;
    vector<person>::iterator end_d=set_difference(vec.begin(),vec.end(),vec2.begin(),vec2.end(),v3.begin());
    for_each(v3.begin(),end_d,[](person &p){
        cout<<"   "<<p.name<<p.age;
    });
    cout<<endl;

    vector<person> v4;
    v4.resize(vec2.size());
    cout<<"---------差集（vec2-vec）------------- "<<endl;
    vector<person>::iterator end_d2=set_difference(vec2.begin(),vec2.end(),vec.begin(),vec.end(),v4.begin());
    for_each(v4.begin(),end_d2,[](person &p){
        cout<<"   "<<p.name<<p.age;
    });

    cout<<endl;
}
int main()
{
    test01();

    return 0;
}


