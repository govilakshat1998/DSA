using namespace std; 
  
// Binary tree node 
struct node 
{ 
    struct node* left; 
    struct node* right; 
    int data; 
}; 
  
// Function to create a new 
// Binary Tree Node 
struct node* newNode(int data) 
{ 
    struct node* temp = new node; 
  
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return temp; 
} 
  
// Recursive Function to find height  
// of binary tree 
int heightOfTree(struct node* root) 
{ 
    if(root == NULL) 
    return 0; 
      
    int lheight = heightOfTree(root->left); 
    int rheight = heightOfTree(root->right); 
      
    return max(lheight + 1 ,rheight + 1); 
} 
  
// Function to print nodes from right to left 
void printRightToLeft(struct node* root ,int level) 
{ 
    if(root == NULL) 
    return; 
      
    if(level == 1) 
    cout << root->data << " " ; 
      
    else if(level > 1) 
    { 
        printRightToLeft(root->right ,level - 1); 
        printRightToLeft(root->left ,level - 1); 
    } 
} 
  
// Function to print nodes from left to right 
void printLeftToRight(struct node* root ,int level) 
{ 
    if(root == NULL) 
    return; 
      
    if(level == 1) 
    cout << root->data << " " ; 
      
    else if(level > 1) 
    { 
        printLeftToRight(root->left ,level - 1); 
        printLeftToRight(root->right ,level - 1); 
    } 
} 
  
// Function to print Reverse ZigZag of  
// a Binary tree 
void printZigZag(struct node* root ) 
{ 
    // Flag is used to mark the change 
    // in level 
    int flag = 0; 
      
    // Height of tree 
    int height = heightOfTree(root); 
      
    for(int i = 1 ; i <= height ; i++) 
    { 
        // If flag value is one print nodes 
        // from right to left 
        if(flag == 1) 
        { 
            printRightToLeft(root ,i); 
              
            // Mark flag as zero so that next time 
            // nodes are printed from left to right 
            flag = 0; 
        } 
        // If flag is zero print nodes 
        // from left to right  
        else if(flag == 0) 
        { 
            printLeftToRight(root ,i); 
              
            // Mark flag as one so that next time 
            // nodes are printed from right to left  
            flag = 1; 
        } 
    } 
} 
  
// Driver code 
int main()  
{ 
    struct node* root = newNode(7);  
    root->left = newNode(4);  
    root->right = newNode(5);  
    root->left->left = newNode(9);  
    root->right->right = newNode(10);  
    root->left->left->left = newNode(6);  
    root->left->left->right = newNode(11);  
      
    printZigZag(root);  
  
    return 0;  
} 