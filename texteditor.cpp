#include<iostream>
#include<stack>
#include<cstdio>
#include<iomanip>
using namespace std;

class textEditor{
private:
    stack<char> leftStack;
    stack<char> rightStack;
public:
    void insertCharacter(char character);
    void insertWord(char word[]);
    bool deleteCharacter();
    bool backSpaceCharacter();
    void moveCursor(int position);
    void moveLeft(int position);
    void moveRight(int position);
    //void findAndReplaceChar(char findWhat,Char replaceWith);
    void examineTop();
};

void textEditor::examineTop()
{
    if(leftStack.empty())
        cout<<endl<<"Left Stack is empty\t";
    else
        cout<<endl<<"LeftStack:"<<leftStack.top()<<","<<"LeftStack size:"<<leftStack.size()<<"\t\t";

    if(rightStack.empty())
        cout<<endl<<"Right Stack is empty\t";
    else
        cout<<endl<<"RightStack:"<<rightStack.top()<<","<<"RightStack size:"<<rightStack.size()<<endl<<endl;

}

void textEditor::insertCharacter(char character)
{
    leftStack.push(character);
}

void textEditor::insertWord(char word[])
{
    int i=0;
    while(word[i]!='\0'){
        insertCharacter(word[i]);
        i++;
    }
}


bool textEditor::deleteCharacter()
{
    if(rightStack.empty())
        return false;
    else
        rightStack.pop();
    return true;
}

bool textEditor::backSpaceCharacter()
{
    if(leftStack.empty())
        return false;
    else
        leftStack.pop();
    return true;
}

void textEditor::moveCursor(int position)
{
    int leftsize,rightsize,counter;
    leftsize= leftStack.size();
    rightsize= rightStack.size();
    if(position<leftsize)
        moveLeft(position);
    else
    {
        counter = position - leftsize;
        moveRight(counter);
    }
}
void textEditor::moveLeft(int position)
{
    while(leftStack.size()!=position)
    {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
}

void textEditor::moveRight(int position)
{
    while(rightStack.size()!=position)
    {
        leftStack.push(rightStack.top());
        rightStack.pop();
    }
}

int main()
{
    char txt[80];textEditor ed;
    cout<<"Enter the word to be inserted:"<<endl;
    gets(txt);
    ed.insertWord(txt);
    ed.examineTop();
    cout<<endl<<"Enter the position to which you wanna move the cursor:"<<endl;int pos;
    cin>>pos;
    ed.moveCursor(pos);
    ed.examineTop();
    int choice;
    do{
            cout<<endl<<"Select any operation:"<<endl<<"1.Move Right"<<" 2.Move Left"<<" 3.Quit"<<endl;
            cin>>choice;
            cout<<endl<<"Enter position of shifting:"<<endl;int posi;
            cin>>posi;
            switch(choice){
            case 1:
                ed.moveRight(posi);
                break;
            case 2:
                ed.moveLeft(posi);
                break;
            }
    }while(choice!=3);
    ed.examineTop();

}

