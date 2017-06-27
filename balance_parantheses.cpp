// stack::push/pop
#include <iostream>       // std::cout
#include <string>
#include <stack>          // std::stack
using namespace std;
int main ()
{
    int i=0,a,b,len;
    string str="((()()())";
    //cin>>str;
    stack <int> s1;
    len=str.length();
    for(i=0;i<len;i++)
    {
        if(str.at(i)=='(')
            s1.push(1);
        else if(str.at(i)==')')
            {
                s1.pop();
            }
    }
    if(s1.size()==0)
        cout<<"Balance";
    else 
        cout<<"Unbalance";
  return 0;
}
