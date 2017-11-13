#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;
struct et
{
    char value;
    et* left, *right;
};
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    if(c == ' '){
    	return false;
    }
    return false;
}
void inorder(et *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->value);
        inorder(t->right);
    }
}
et* newNode(int v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};
et* constructTree(char postfix[])
{
    stack<et *> str;
    et *t, *ri, *le;
    for (unsigned int i=0; i<strlen(postfix); i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            str.push(t);
        }
        else
        {
            t = newNode(postfix[i]);
            ri = str.top(); // Store top
            str.pop();      // Remove top
            le = str.top();
            str.pop();
            t->right = ri;
            t->left = le;
            str.push(t);
        }
    }
    t = str.top();
    str.pop();
    return t;
}
int main(){
    char postfix[] = "34+2*";
    char postfix1[] = "234*+";
    char postfix2[] = "xx-ab+*";
    char postfix3[] = "x1*";
    et* r = constructTree(postfix);
    et* r1 = constructTree(postfix1);
    et* r2 = constructTree(postfix2);
    et* r3 = constructTree(postfix3);
    cout << "infix expression is" << "\n";
    inorder(r);
    cout << "\n";
    inorder(r1);
    cout << "\n";
    inorder(r2);
    cout << "\n";
    inorder(r3);
    return 0;
}

