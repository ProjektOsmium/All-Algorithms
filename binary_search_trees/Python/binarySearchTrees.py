#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
"""
class Node:
    """
    
    Class for structure of nodes/leafs in Binary Search Trees
    
    params:
        data: Value to be stored in the node
        lchild: Pointer for the node with data value greater than parent node
        rchild: Pointer for the node with data value lower than parent node
    
    """
    
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
        self.parent = None
    
class BST:
    """
    
    Class for the actual Data Structure called Binary Search Trees
    
    Functions/Methods included:
            insert
            search
    
    """
    def __init__(self):
        self.root = None
        
    """
    Initializing the tree with a root
    
    """

    def insert(self, data):
        """
        Inserting element in the tree.
        
        Parameters:
            data ---> value to be inserted in the list
        
        Approach:
            Iterative approach to find minimum/maximum element 
            where to insert the element.
            
            
        Return:
            None
        """
        node = Node(data)
        if self.root:
            curr_node = self.root
            parent = None
            while True:
                parent = curr_node
                if node.data < curr_node.data:
                    curr_node = curr_node.lchild
                    if curr_node is None:
                        parent.lchild = node
                        node.parent = parent
                        return
                        
                else:
                    curr_node = curr_node.rchild
                    if curr_node is None:
                        parent.rchild = node
                        node.parent = parent
                        return
        else:
            self.root = node
                        
                    
                    
    
    def search(self, data):
        """
        Searching the list for the given element
        
        Parametes:
            data ---> value which is required to be found in the tree
            
        Return:
            the node with the data attribute equaling data
        
        """
        curr_node = self.root
        while True:
            if curr_node is None:
                return None
            elif curr_node.data is data:
                return curr_node
            elif curr_node.data > data:
                curr_node = curr_node.lchild
            else:
                curr_node = curr_node.rchild
    
    def findMin(self):
        """
        Finding the minimum node in the tree.
        
        Parameters:
            None
        
        Returns:
            Minimum node
        
        """
        curr_node = self.root
        while(curr_node.lchild is not None): 
            curr_node = curr_node.lchild  
  
        return curr_node  
                
    def inOrderTraversal(self, root):
        """
        Traverses Tree in ascending order
        
        Parameters:
            root Node from where to start the traversal
        
        Return:
            None (Prints out elements in console)
        """

        curr_node = root
        if curr_node is None:
            return
        self.inOrderTraversal(curr_node.lchild)
        print(curr_node.data)
        self.inOrderTraversal(curr_node.rchild)
        
        
    def delete(self, data):
        """
        Deleting the element from list is by far the most non-trivial task
        
        Parameters:
            data to be deleted
        Returns:
            None (Modifies the tree)
        
        """
        
        node = self.search(data)
        parent = node.parent
        
        if parent is None and node is None:
            return False
        
        children_count = 0
        
        if node.lchild and node.rchild:
            children_count = 2
        elif (node.lchild is None) and (node.rchild is None):
            children_count = 0
        else:
            children_count = 1
        
        # If the node to be deleted has no children
        
        if children_count == 0:
            if parent:
                if parent.rchild is node:
                    parent.rchild = None
                else:
                    parent.lchild = None
            else:
                self.root = None
        
        # If the node to be deleted has 1 child
        
        elif children_count ==1:
            next_node = None
            if node.lchild:
                next_node = node.lchild
            else:
                next_node = node.rchild
                
            if parent:
                if parent.lchild is node:
                    parent.lchild = next_node
                else:
                    parent.rchild = next_node
            else:
                self.root = next_node
        
    
        # If the node to be deleted has 2 childrens
        else:
            node_ = node
            l_node = node.rchild
            while l_node.lchild:
                node_ = l_node
                l_node = l_node.lchild
            node.data = l_node.data
            
            if node_.lchild == l_node:
                node_.lchild = l_node.rchild
            else:
                node_.rchild = l_node.rchild

#Testing the code
bst = BST()
bst.insert(50)
bst.insert(30)
bst.insert(20)
bst.insert(40)
bst.insert(70)
bst.insert(60)
bst.insert(80)
print('No Change \n')
bst.inOrderTraversal(bst.root)

bst.delete(20)
print('20 is deleted \n')
bst.inOrderTraversal(bst.root)

bst.delete(30)
print('30 is deleted \n')
bst.inOrderTraversal(bst.root)

bst.delete(50)
print('50 is deleted \n')
bst.inOrderTraversal(bst.root)