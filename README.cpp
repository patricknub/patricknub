// Online C++ compiler to run C++ program online#include <iostream>
using namespace std;
#include<iostream>
#include<string.h>

class test
{
    public:
    char stack[50];
    char s[50],t[50];
    int top;
    void convert()
    {
        char opr;
        int i=0,j=0;
        while(s[i]!='\0')
        {
            if(s[i]==' '||s[i]=='\t')
            {
                i++;
                continue;
            }
            if(isdigit(s[i])||isalpha(s[i]))
            {
                while(isdigit(s[i]) || isalpha(s[i] ))
                {
                    t[j]=s[i];
                    i++;
                    j++;
                }
            }
            if(s[i] =='(')
            {
                stack[++top]=s[i];
                i++;
            }
            if(s[i]=='*' ||s[i]=='+' || s[i]=='/' || s[i]=='%' || s[i]=='-' || s[i]=='$')
            {
                if(top!=-1)
                {
                    opr=stack[top--];
                    while(priority(opr)>=priority(s[i]))
                    {
                        t[j]=opr;
                        j++;
                        opr=stack[top--];
                    }
                    stack[++top]=opr;
                    stack[++top]=s[i];
                }
                else
                stack[++top]=s[i];
                i++;
            }
            if(s[i]==')')
            {
                opr=stack[top--];
                while((opr)!='(')
                {
                    t[j]=opr;
                    j++;
                    opr=stack[top--];
                }
                i++;
            }
        }
        while(top!=-1)
        {
            char opr=stack[top--];
            t[j]=opr;
            j++;
        }
        t[j]='\0';
    }
    int priority(char c)
    {
        if(c=='$')
        return 3;
        if(c=='*' || c=='/' || c=='%')
        return 2;
        else
        {
            if(c=='+' ||c=='-')
            return 1;
            else 
            return 0;
        }
    }
};
int main()
{
    test obj;
    obj.top=-1;
    cout<<"\nEnter an expression in infix form: ";
    gets(obj.s);
    obj.convert();
    cout<<"\nThe postfix expression is: "<<obj.t;
    return 0;
}
