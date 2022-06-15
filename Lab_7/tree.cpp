////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                         Author- Sabva Jay Dilipbhai                                                //
//                                         ID-202101224                                                               //
//                                         Implementation of binary tree                                              //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
class binarytree;
class node;
class queue {
   public:
      int front, rear;
   int size = 1000;
   node * arr[1000];
   queue() {
      front = -1;
      rear = -1;
   }
   void push(node * temp) {
      if (front == -1) {
         front = 0;
      }
      rear++;
      arr[rear] = temp;
   }
   void pop() {
      if (front == rear) {
         front = rear = -1;
         return;
      }
      front++;
   }
   int empty() {
      if (front == -1)
         return 1;
      else
         return 0;
   }
   node * front1() {
      return arr[front];
   }

};
class node {
   public:
      int data;
   node * left, * right;
   node(int d) {
      data = d;
      left = right = NULL;
   }
};
class binarytree {
   public:
      node * root;
   binarytree() {
      root = NULL;
   }
   queue q;
   void levelorderinsertion(int d) {
      node * temp1 = new node(d);
      if (root == NULL) {
         root = temp1;
         return;
      }
      q.push(root);
      while (!q.empty()) {
         node * temp = q.front1();
         q.pop();
         if (temp -> left == NULL) {
            temp -> left = new node(d);
            return;
         } else {
            q.push(temp -> left);
         }

         if (temp -> right == NULL) {
            temp -> right = new node(d);
            return;
         } else {
            q.push(temp -> right);
         }
      }
   }
   void inorder(node * root) {
      if (root == NULL)
         return;
      inorder(root -> left);
      cout << root -> data << " ";
      inorder(root -> right);
   }
   void preorder(node * root) {
      if (root == NULL)
         return;
      cout << root -> data << " ";
      preorder(root -> left);
      preorder(root -> right);
   }
   void postorder(node * root) {
      if (root == NULL)
         return;
      postorder(root -> left);
      postorder(root -> right);
      cout << root -> data << " ";
   }
   void levelordertraversal(node * root) {
      if (root == NULL)
         return;
      queue q;
      q.push(root);
      while (!q.empty()) {
         node * temp = q.front1();
         q.pop();
         cout << temp -> data << " ";
         if (temp -> left != NULL) {
            q.push(temp -> left);
         }
         if (temp -> right != NULL) {
            q.push(temp -> right);
         }
      }
   }
   void deletDeepest(node * temp) {
      q.push(root);
      node * temp2;
      while (!q.empty()) {
         temp2 = q.front1();
         q.pop();
         if (temp2 == temp) {
            temp2 = NULL;
            delete temp;
            return;
         }
         if (temp2 -> right != NULL) {
            if (temp2 -> right == temp) {
               temp2 -> right = NULL;
               delete temp;
               return;
            } else {
               q.push(temp2 -> right);
            }
         }
         if (temp2 -> left != NULL) {
            if (temp2 -> left == temp) {
               temp2 -> left = NULL;
               delete temp;
               return;
            } else {
               q.push(temp2 -> left);
            }
         }
      }
   }
   void deletions(int data) {
    if (root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }
      queue q;
      q.push(root);
      node * temp;
      node * data_node = NULL;
      while (!q.empty()) {
         temp = q.front1();
         q.pop();
         if (temp -> data == data) {
            data_node = temp;
         }
         if (temp -> left != NULL) {
            q.push(temp -> left);
         }
         if (temp -> right != NULL) {
            q.push(temp -> right);
         }
      }
      if (data_node == NULL) {
         cout << "Data not found" << endl;
         return;
      }
      if(data_node==root&&data_node->left==NULL&&data_node->right==NULL) 
      {
            root=NULL;
            delete data_node;
            return;
      }
      int x = temp -> data;
      deletDeepest(temp);
      data_node -> data = x;

   }
};
int main() {
   binarytree bt;
   int choice = 0;
   while (choice != 7) {
      cout << "-------------------------------------" << endl;
      cout << "1.Insertion" << endl;
      cout << "2.Inorder" << endl;
      cout << "3.Preorder" << endl;
      cout << "4.Postorder" << endl;
      cout << "5.Levelorder" << endl;
      cout << "6.Deletion" << endl;
      cout << "7.Exit" << endl;
      cout << "Enter your choice" << endl;
      cin >> choice;
      cout << "-------------------------------------" << endl;
      switch (choice) {
      case 1:
         int d;
         cout << "Enter the data" << endl;
         cin >> d;
         bt.levelorderinsertion(d);
         break;
      case 2:
        cout << "Inorder traversal" << endl;
        if(bt.root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else{
         bt.inorder(bt.root);
         cout << endl;
        }
         break;
      case 3:
         cout << "Preorder traversal" << endl;
         if(bt.root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else{
         bt.preorder(bt.root);
         cout << endl;
        }
         break;
      case 4:
      if(bt.root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else{
        cout << "Postorder traversal" << endl;
         bt.postorder(bt.root);
         cout << endl;
        }
         break;
      case 5:
        cout << "Levelorder traversal" << endl;
        if(bt.root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else{
         bt.levelordertraversal(bt.root);
         cout << endl;
        }
         break;
      case 6:
      if(bt.root==NULL)
      {
         cout<<"Tree is empty"<<endl;
         break;
      }
      else{
         int data;
         cout << "Enter the data to be deleted" << endl;
         cin >> data;
         bt.deletions(data);}
         break;
        case 7:
            break;
      default:
         cout << "Invalid choice" << endl;
      }
   }

   return 0;
}
