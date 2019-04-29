#include <iostream>
#include <conio.h>

using namespace std;

const string vocales = "aeiou";
string pigLatin(const string s){
    if(s.size()==0){//cadena vacia
        return s;
    }
    if(s.find("qu") == 0) { //empieza con "qu"
        return s.substr(2, s.size()-2) + "-" + s.substr(0, 2) + "ay";
    }
    else if(vocales.find(s[0]) != string::npos ){//empieza con una vocal
        return s + "-way";
    }
    else {
        return s.substr(1,s.size()-1) + "-" + s[0] + "ay";
    }
}
int main(){
    string cad = "request";
    cout<<pigLatin(cad);
    getch();
    return 0;
}
