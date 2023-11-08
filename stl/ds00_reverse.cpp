#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,int a,int b) {
//  write your code only in this function
//  for (int i=0; i<=(a-b+1)/2; i++) {
//     int tmp = v[i+a];
//     v[i+a] = v[b-i];
//     v[b-i] = tmp;
//  }
   for (int i=0; i<(a+b)/2+1; i++) {
      swap(v[i], v[b--]);
   }
}
int main() {
 //read input
 int n,a,b;
 cin >> n;
 vector<int> v;
 for (int i = 0;i < n;i++) {
 int c;
 cin >> c;
 v.push_back(c);
 }
 cin >> a >> b;
 //call function
 reverse(v,a,b);
 //display content of the vector
 for (auto &x : v)
 cout << x << " ";
 cout << endl;
}