#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    // string str,end;
    // while(cin>>str){
    //     end+=str;
    // }
    // cout << end << endl;
    // cout << "************" << endl;
    string str0,end0;
    while(cin>>str0){
        if(end0.empty()){
            end0 = str0;
        }else{
            end0 += " " + str0; 
        }
        
    }
    cout << end0 << endl;
    return 0;
}