#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// An expression tree node
class ExpressionTree
{
    public:
     char value;
    bool isLeaf;
     ExpressionTree *left , *right;
};

int isOperator(char c);

int whichbrace(char c);

int isnumeral(char c);

int calculate(int a, int b, char c);

// Utility function to do inorder traversal
void inorder(ExpressionTree *t);

void postorder(ExpressionTree *t);

void preorder(ExpressionTree *t);

int findValue(ExpressionTree * t);

// A utility function to create a new node
ExpressionTree* createNode();


// Returns root of constructed tree for given
// postfix expression
ExpressionTree* constructTree(char *expression);


int isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' )
        return 1;
    return 0;
}

int whichbrace(char c)
{
    if(c=='(')
    {
        return 0;
    }
    else if(c==')')
    {
        return 1;
    }
    else return 2;
}

int isnumeral(char c)
{
   return isdigit(c);
}

int calculate(int a, int b, char c){
    if(c=='+'){
       return a+b;
    }
    if(c=='-'){
       return a-b;
    }
    if(c=='*'){
       return a*b;
    }
    if(c=='/'){
       return a/b;
    }
    return 0;
}

// Utility function to do inorder traversal
void inorder(ExpressionTree *t)
{
    if(t==NULL){
        return;
    }
    else
    {
        if(t->left!=NULL)
        {
            printf("( ");
            inorder(t->left);
        }
        printf("%c ", t->value);
       if(t->right!=NULL)
        {
            inorder(t->right);
            printf(") ");
        }
    }
}
void postorder(ExpressionTree *t)
{
    if(t==NULL){
        return;
    }
    else if(t->isLeaf){
        printf("%c ", t->value);
    }
    else
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c ", t->value);
    }
}
void preorder(ExpressionTree *t)
{
    if(t==NULL){
        return;
    }
    else if(t->isLeaf){
        printf("%c ", t->value);
    }
    else
    {
        printf("%c ", t->value);
        preorder(t->left);
        preorder(t->right);
    }
}

int findValue(ExpressionTree * t)
{
    // printf (string(t->value));

    // printf("sdaf");
    if(t==NULL){
        return 0;
    }
    else if(t->isLeaf==1){

        return (t->value) -'0';

    }
    else
    {

        return calculate(findValue(t->left),findValue(t->right),t->value);

    }
}

// A utility function to create a new node
ExpressionTree* createNode()
{
    ExpressionTree *node = new ExpressionTree;
    node->left = node->right = NULL;
    return node;
};


// Returns root of constructed tree for given
// postfix expression
ExpressionTree* constructTree(char *expression)
{
    stack<ExpressionTree *> stack0;
    ExpressionTree *t, *t1, *t2, *t3;

    //iterating on the input string
    for (int i=0; i<strlen(expression); i++)
    {
       //push number
        if(whichbrace(expression[i])==0)
        {
            //do nothing

        }
        else if(whichbrace(expression[i])==1)
        {
            t = createNode();
            t->isLeaf =false;
            // Pop 1)number , 2)operator and another 3)number
            t1 = stack0.top();
            stack0.pop();
            t2 = stack0.top();
            stack0.pop();
            t3 = stack0.top();
            stack0.pop();
            t->left = t3;
            t->right = t1;
            t->value = t2->value;
            stack0.push(t);
        }
        //number
        else if (isnumeral(expression[i]))
        {

            t = createNode();
            t->isLeaf =true;
            t->value = expression[i];
            stack0.push(t);
        }
        //operator
        else if(isOperator(expression[i]))
        {

            t = createNode();
            t->isLeaf =false;
            t->value = expression[i];
            stack0.push(t);
        }
    }

    // pop the bult tree
    t = stack0.top();
    stack0.pop();

    return t;
}

int main(int arg,char* args[1])
{

    ifstream myReadFile(args[1]);
    string line;
    while(std::getline(myReadFile, line))
    {
        char* infix = strdup(line.c_str());
        ExpressionTree* r = constructTree(infix);
        printf("Preorder: ");
        preorder(r);
        printf("\n");

        printf("Inorder: ");
        inorder(r);
        printf("\n");

        printf("Postorder: ");
        postorder(r);
        printf("\n");

        int val = findValue(r);
        printf("Value: ");
        printf("%d\n",val );
        printf("\n");
        printf("\n");
   }

    return 0;
}
