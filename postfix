// stack::push/pop
#include <iostream>       // std::cout
#include <string>
#include <stack>          // std::stack
using namespace std;
int main ()
{
    int i=0,a,b,len;
    string str;
    cin>>str;
    stack <int> s1;
    len=str.length();
    for(i=0;i<len;i++)
    {
        if(str.at(i)>='0' && str.at(i)<='9')
            {
                s1.push(str.at(i)-48);
                //cout<<s1.top()<<' ';
            }
            else
            {
                a=s1.top();
                s1.pop();
                b=s1.top();
                s1.pop();
                //cout<<"a="<<a<<" b="<<b;
                if(str.at(i)=='+')
                {
                    s1.push(a+b);
                }
                else if(str.at(i)=='-')
                {
                    s1.push(b-a);
                }
                else if(str.at(i)=='*')
                {
                    s1.push(a*b);
                }
                else if(str.at(i)=='/')
                {
                    s1.push(b/a);
                }
            }
    }
   cout<<s1.top();
  return 0;
}
