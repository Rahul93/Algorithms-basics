#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}


int main() {

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

}
