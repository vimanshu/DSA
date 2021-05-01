// program for the password verifier

#include <bits/stdc++.h>

using namespace std;
bool noMoreThanThree(string pass){
    for (int i = 0; i < pass.size()-2; i++) {
        if(pass[i]==pass[i+1] && pass[i+1]==pass[i+2]){
            return false;
        }
    }
    return true;
}
bool noSpace(string pass){
    for (int i = 0; i < pass.size(); i++) {
        if(pass[i]==32){
            return false;
        }
    }
    return true;
}
bool isSpecial(string pass){
    for(int i=0; i<pass.size(); i++){
        if(pass[i]>=32 && pass[i]<=47 || pass[i]>=59 && pass[i]<=64 || pass[i]>=91 && pass[i]<=96
        || pass[i]>=123 && pass[i]<=126){
            return true;
        }
    }
    return false;
}
bool isNumber(string pass){
    for(int i=0; i<pass.size(); i++){
        if(isdigit(pass[i])){
            return true;
        }
    }
    return false;
}
bool isSmall(string pass){

    for(int i=0; i<pass.size(); i++){
        if(pass[i]>=97 || pass[i]<=122){
            return true;
        }
    }
    return false;
}
bool isCapital(string pass){
    for(int i=0; i<pass.size(); i++){
        if(pass[i]>=65 || pass[i]<=90){
            return true;
        }
    }
    return false;
}
bool pass_ver(string pass){
    if(isCapital(pass) && isSmall(pass) && isNumber(pass) && isSpecial(pass) && noSpace(pass) &&noMoreThanThree(pass)){
        return true;
    }
    else
    return false;
}
int main()
{
    // password verifier
    // the different constraints
    /*
    Password should not contain any space.
    Password should contain at least one digit(0-9).
    Password length should be between 8 to 15 characters.
    Password should contain at least one lowercase letter(a-z).
    Password should contain at least one uppercase letter(A-Z).
    */
    string pass;
    cin>>pass;
    if(pass.size()<10 || pass.size()>=32){
        
        cout<<0;
    }
    else
    cout<<pass_ver(pass);

    
}
