// rabin karp algorithm for string matching
// question- given two strings, onr text one pattern, determine if the pattern appears in the text and if exists then enumerate all the occurances
// rolling hash function== s[i]*p**[i]%mod;

#define ll long long int
#include <bits/stdc++.h>

using namespace std;

vector<int> string_match(string t, string pat,vector <int> &occurences){
    int p=31;
    int mod=1e9+9;
    int T=t.size();
    int P=pat.size();
    vector<long long> p_pow(max(T,P));
    p_pow[0]=1;
    for (int i = 1; i < p_pow.size(); i++) {
        p_pow[i]=p_pow[i-1]*p%mod;
    }
    vector<long long>  h(T+1,0); // hash values of prefix of the text 
    for(int i=0; i<T;i++){
        h[i+1]=h[i]+(t[i]-'a'+1)*p_pow[i]%mod;
    }
    ll h_p=0; // hash of pattern
    for(int i=0; i<P;i++){
        h_p+=(pat[i]-'a'+1)*p_pow[i]%mod;
    }
    
    for(int i=0; i+P-1<T;i++){
        ll curr_hash=(h[i+P]+mod-h[i])%mod;
        if(curr_hash==h_p*p_pow[i]%mod){
            occurences.push_back(i);
        }
        
    }
    return occurences;
}
int main()
{
    string t,p; //  input:  t->text, p->pattern
    cin>>t>>p;
    vector<int> occurences;
    string_match(t,p,occurences);
    
    for (int i = 0; i < occurences.size(); i++) {
        cout<<occurences[i]<<" ";
    }

    return 0;
}
 
