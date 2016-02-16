//
//  main.cpp
//  BinarySearchTree
//
//  Created by Ian Murphy on 2/11/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include "BSTree.h"

void Print(int data)
{
    std::cout<<data<< " " ;
}

int main(int argc, const char * argv[])
{
    BSTree<int> tree;
    cout<<"Inserting several values"<<endl;
    tree.Insert(10);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(90);
    tree.Insert(20);
    tree.Insert(23);
    tree.Insert(4632);
    tree.Insert(35);
    tree.Insert(65);
    tree.Insert(71);
    
    
    
    cout<<"Testing Traversals: "<<endl;
    cout<<"\n\nIn Order"<<endl;
    tree.InOrderTraverse(&Print);
    cout<<"\n\nPre Order"<<endl;
    tree.PreOrderTraverse(&Print);
    cout<<"\n\nPost Order"<<endl;
    tree.PostOrderTraverse(&Print);
    cout<<"\n\nBreadth Fist"<<endl;
    tree.BreadthFirstTraverse(&Print);
    
    //tree.Purge();
    //tree.PostOrderTraverse(&Print);
    
    
    
    cout<<"\n\nTest delete 35"<<endl;
    cout<<"\n\nBefore"<<endl;
    tree.InOrderTraverse(&Print);
    tree.Delete(35);
    cout<<"\n\nAfter"<<endl;
    tree.InOrderTraverse(&Print);
    
    cout<<"\n\nTest Canonicals: "<<endl;
    cout<<"Test Copy c'tor: "<<endl;
    BSTree<int> tree2(tree);
    tree.InOrderTraverse(&Print);
    cout<<"\n";
    tree2.InOrderTraverse(&Print);
    
    cout<<"\n\nTest OP =: "<<endl;
    tree2.Delete(10);
    tree2.Delete(40);
    tree2.Delete(60);
    tree = tree2;
    tree.InOrderTraverse(&Print);
    cout<<"\n";
    tree2.InOrderTraverse(&Print);
    
    cout<<"Test Purge empty list: "<<endl;
    tree.Purge();
    tree.Purge();
    cout<<"\n\nTest Purge tree with one node: "<<endl;
    tree.Insert(1);
    tree.Purge();
    cout<<"\n\nTest height: "<<endl;
    cout<<tree.Height()<<endl;
    tree.Insert(50);
    cout<<tree.Height()<<endl;
    tree.Insert(60);
    cout<<tree.Height()<<endl;
    tree.Insert(40);
    cout<<tree.Height()<<endl;
    tree.Insert(30);
    cout<<tree.Height()<<endl;
    tree.Insert(30);
    cout<<tree.Height()<<endl;
    tree.Insert(30);
    cout<<tree.Height()<<endl;
    tree.InOrderTraverse(&Print);
    cout<<endl;
    
    tree.Delete(30);
    tree.InOrderTraverse(&Print);
    
    for (int i = 0; i<100; i++)
    {
        tree.Insert(30);
        tree.Delete(30);
    }
    tree.Delete(30);
    
    
    
    cout<<"\n\nRandomly put twenty million nodes into the tree: "<<endl;
    srand(4998503859);
    for (int i = 1; i<20000000; i++)
    {
        tree.Insert(rand());
        if(i%(1024*1024) == 0)
            cout<<"~"<<i/(1024*1024)<<" Million Nodes, Height: "<<tree.Height()<<endl;
    }
    
    
    
    return 0;
}
