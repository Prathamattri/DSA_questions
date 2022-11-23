#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void askChoice(){
    cout<<"\n1.Infix To Postfix\n2.Infix To Prefix\n3.Postfix Evaluation\n4.Exit\nEnter Choice: ";
}
string reverseStr(string str){
    string res="";
    for(int i=str.length();i>=0;i--){
        if(str[i]=='(') res+=')';
        else if(str[i]==')') res+='(';
        else res+=str[i];
    }return res;
}
//checking priority of operators
int priority(char ch){
    if(ch=='+' || ch=='-') return 1;
    if(ch=='*' || ch=='/') return 2;
    if(ch=='^') return 3;
    return 0;
}
//infix to postfix conversion
string convert(string infix){
    string postfix="";
    stack<char> s;
    int i=0;
    while(i<infix.length()){
        if(infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
            postfix+=infix[i++];
        }else if(infix[i]=='(') s.push(infix[i++]);
        else if(infix[i]==')'){
            while(s.top()!='('){
                postfix+=s.top();   s.pop();
            }
            s.pop();    i++;
        }
        else{
            while( !s.empty() && priority(infix[i])<=priority(s.top())){
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i++]);
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}
//Evaluate postfix expression
float evalPostfix(string postfix){
    int i=0;
    stack<float> s;
    while(i<postfix.length()){
        if(postfix[i]>='0' && postfix[i]<='9'){
            s.push(float(postfix[i++]-'0'));
        }else{
            float b=s.top(); s.pop();
            float a=s.top(); s.pop();
            switch (postfix[i])
            {case '+':
                s.push((a+b));break;
            case '-':
                s.push((a-b));break;
            case '*':
                s.push((a*b));break;
            case '/':
                s.push((a/b));break;
            case '^':
                s.push(pow(a,b));break;
            default:
                return -1;
            }
            i++;
        }
    }
    return (s.top());
}

int main(){
    string infix="(a+b)^(c+d/e)";
    cout<<"\nInfix: "<<infix<<endl<<"\nPostfix: "<<convert(infix);
    infix=reverseStr(infix);
    cout<<"\nPrefix: "<<reverseStr(convert(infix))<<endl;

    string postfix="39+99+3/*";
    cout<<evalPostfix(postfix);
    return 0;
}
