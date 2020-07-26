#include <iostream>
#include<stack>
/* Algorithm
1. Put the root of the BST to the stack i.e Last element of the array
2. Start traversing the array in the reverse ,if next element if > than the element at the top of the stack then -> Set this
element as the right child of the stack top element and also push it to the stack.
3. Else if, next element is < the stack top element  then -> Start popping the all  the element from the stack until the stack
becomes empty or next element is > then stack top element.\
4. Make this element as the left child of the last popped element from the stack and repeat the above steps until array is
traversed completely.
 */
using namespace std;
class node
{
   public:
   node* lchild;
   int data;
   node* rchild;
   node(int data)
   {
      this->data=data;
      lchild=rchild=NULL;
   }
};
node* create_bst(int post[],int n)
{
    stack<node*>s;
    node* root=NULL,*t;
    root=new node(post[n-1]);
    s.push(root);// last element of the post array should be make as root of the BST
    for(int i=n-2;i>=0;i--)
    {
        if(post[i] > s.top()->data)// if the next element in the post array is greater than the stack top then simply
        // make element as right child of the stack top element
        {
             s.top()->rchild=new node(post[i]);
             s.push(s.top()->rchild);
        }
        else
        {// If the next element is lesser than stack top element then simply pop the elements untill next element becomes
        //  greater than the stack top element and then make next element as left child of last popped element
            while(s.size() && post[i] < s.top()->data)
            {
                t=s.top();
                s.pop();
            }
            if(t)
            {
                t->lchild=new  node(post[i]);
                s.push(t->lchild);
            }
        }

    }
    return root;
}
void inorder(node* root)
{
    if(root!=NULL)
    {
       inorder(root->lchild);
       cout<<root->data<<"  ";
       inorder(root->rchild);
    }
}
int main()
{
    int post[]={1,7,5,50,40,10};
    node* root=create_bst(post,6);
    cout<<"\nInorder traversal of the bst is -> ";
    inorder(root);
    return 0;
}
