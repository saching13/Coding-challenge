// How to evaluate an infix expression ?
// 2 + 5 - 10 / ( 1 - (3 / 5) )

#include<iostream>
#include<string>
#include<sstream>
#include<vector>





class Node:
{
      string value;
      Node* left;
      Node* right;
      
};



// 2. Evaluate this tree to get a numerical result
e// 
float evaluate(Node* root);

vector<string> operands = {"+", "-", "*", "/"}; 

bool isFloat(string myStr){
    std::istringstream str(mystr);
    float f;
    str >> noskipws >> f;
    return str.eof() && !str.fail();
    
    }

float calculate_value(string& num1, string& num2, string operand){
    assert(isFloat(num1)); // if input from right or left node is not a float assert
    assert(isFloat(num2));
    
    float a = strtof(num1);
    float b = strtof(num2);
    if(operand == "+")
        return a + b;
    else if(operand == "-")
        return a - b;
    else if(operand == "/")
        return a / b;
    else if(operand == "*")
        return a * b;

}


// recursively parse through the tree to check if right node is operand. and calculate the value if right leaf is not a value
float rec_dfs(Node* root){
        float res;
          
    if(std::find(operands.begin(),operands.end(),root->right->value) == operands.end){
    
            assert(root->right != NULL); // assert if right node is not an operand             
            return calculate_value(root->left->value, root->right->value, root->value);            
    }
    else{
             // assert if right node is null and not an operand
            assert(root->left != NULL);
            assert(root->right != NULL);
            res = rec_dfs(root->right);                
            return calculate_value(root->left->value, std::to_string(res), root->value);
        }
}
            
float evaluate(Node* root){

    float res = 0;
    assert(root != NULL); // closes the program if root is null 
    
    // Checks if root node is NULL
    if (std::find(operands.begin(),operands.end(),root->value) == operands.end()){ 
        return root->value;
    }
    else{
        res = rec_dfs(root, res);
    }
   
    return res;
}



    