// making the rolling hash function
// converts the lower case char a-to-z with 1-26
#define ll long long int
#include <bits/stdc++.h>
using namespace std;
int compute_hash(string &s){
    ll val=0;
    ll mod=1e9+9;
    ll p=31;
    ll p_power=1;
    for(char c:s){
        val=(val+(c-'a'+1)*p_power)%mod;
        p_power=p*p_power;
    }
    return val;
}

int main()
{
    string s;
    cin>>s;
   cout<< compute_hash(s);
    return 0;
}
