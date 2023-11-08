#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int q,num;
    vector<int > v;
    string opr;
    cin >> q;
    while(q--){
        cin >> opr;
        if(opr == "pb"){
            cin >> num;
            v.push_back(num);
        }else if(opr == "sa"){
            sort(v.begin(),v.end());
        }else if(opr == "sd"){
            sort(v.rbegin(),v.rend());
        }else if(opr == "r"){
            for(vector<int >::iterator i = v.begin(),j = v.end()-1;i<j;i++,j--)
                swap(*i,*j);
        }else{
            cin >> num;
            v.erase(v.begin()+num);
        }
    }
    for(auto x:v)
        cout << x << ' ';
    return 0;
}
