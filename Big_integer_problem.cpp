#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string bytwo(string add){
    int total;
    int carry=0;
    string res="";
    for(int i=0;i<add.size();++i){
        total=0;
        total+=(add[i]-'0');
        total+=carry;
        char p=(total/2)+'0';
        if(!(p=='0' && res.empty())){
            res.push_back(p);
        }
        carry=(total%2)*10;
    }
    return res;
}


string big_add(string a,string b){
    string res="";
    if(a.size()>b.size()){
        swap(a,b);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int total,carry=0;
    for(int i=0;i<b.size();++i){
        total=0;
        if(i<a.size()){
            total=a[i]-'0';
        }
        total+=(b[i]-'0');
        total+=carry;
        res.push_back((total%10)+'0');
        carry=total/10;
    }
    if(carry){
        res.push_back(carry+'0');
    }
    reverse(res.begin(),res.end());
    return res;
}

string big_sub(string a,string b){
    if(b.size()>a.size()){
        swap(a,b);
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sub=0,carry=0;
    string res="";
    for(int i=0;i<a.size();++i){
        sub=a[i]-'0';
        carry=0;
        if(i<b.size()){
            if((b[i]-'0') > (a[i]-'0')){
                carry=10;
                sub+=carry;
                int t=a[i+1]-'0';
                t-=1;
                a[i+1]=t+'0';
            }
            sub-=(b[i]-'0');
        }
        res.push_back(sub+'0');
    }
    return res;
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string add=big_add(s1,s2);
    string x,y;
    x=bytwo(add);
    y=big_sub(s1,x);
    int ny=y.size();
    while(y[ny-1]=='0'){
        y.pop_back();
        ny-=1;
    }
    reverse(y.begin(),y.end());
    cout<<x<<endl<<y<<endl;
    return 0;
}