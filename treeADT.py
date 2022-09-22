#LN08treeADT

#Node 정의
class Node:
    def __init__(self, data): 
        self.data=data
        self.parent=None
        self.left=None
        self.right=None


class Tree:


    n_find=Node    

    def find_preorder(self, f_data): 
        if self.parent==None:
            pass
        if self.data==f_data:
            n_find=self
        Tree.find_preorder(self.left, f_data)
        Tree.find_preorder(self.right, f_data)


    def find(self, data): 
        Tree.find_preorder(self, data)
        return n_find


    def find_node(self, data):
        n_find=None
        print("Tree: %s"%Tree.find(self, data))
        return Tree.find(self, data)
    

    def new_node(data): 
        new_node=Node(data)
        new_node.parent=None
        new_node.left=None
        new_node.right=None
        return new_node

        
    def insert_node(self, p_data, c_data): 
        parent=Tree.find_node(self, p_data)
        print("parent: %s"%parent.data)
        if parent==None:
            print("Error\n")
        else:
            if parent.left==None:
                parent.left=create_node(c_data)
                parent.left.parent=parent
            else:
                child=parent.left
                while child.right!=None:
                    child=child.right
                child.right=create_node(c_data)
                child.right.parent=parent


    def insert_node2(self, p_data, c_data): 
        parent=Tree.find_node(self, p_data)
        if parent==None:
            print("Error\n")
        else:
            if parent.left==None:
                parent.left=new_node(c_data)
                parent.left.parent=parent
            else:
                child=parent.left
                if child.right!=None:
                    child.right=new_node(c_data)
                    child.right.parent=parent
                else:
                    print("Full\n")
                
      

    def get_sibling(self, data): 
        find=Tree.find_node(self, data)
        parent=find.parent
        child=parent.left
        print("{")
        while True:
            if child.data!=data:
                if child.right==None:
                    print("%s"%child.data)
                else:
                    print("%s,"%child.data)
            if child.right==None:
                break
            child=child.right
        print("}")


    def get_sibling2(self, data): 
        find=Tree.find_node(self, data)
        parent=find.parent
        child=parent.left
        if child==None:
            print("Error\n")
        else:
            print("{")
            if child!=find:
                print("%s"%child.data)

            if child.right==None:
                pass
            else:
                if child.right!=find:
                    print("%s"%child.right.data)
            print("}")

    def printT(self):
        if self==None:
            pass
        else:
            print("%s"%self.data)
            if self.left!=None:
                print("(")
            Tree.printT(self.left)
            if self.left!=None:
                print(")")
            if self.right!=None:
                print(",")
            Tree.printT(self.right)
        

    def get_parent(self, data): 
        child=Tree.find_node(self, data)
        parent=child.parent
        print("%s"%parent.data)
       

    def get_child(self, data): 
        parent=Tree.find_node(self, data)
        child=parent.left
        print("{")
        while True:
            print("%s"%child.data)
            if child.right==None:
                break
            child=child.right
            print(",")
        print("}")


    def get_child2(self, data): 
        parent=Tree.find_node(self, data)
        child=parent.left
        print("{")
        if child==None:
            pass
        else:
            print("%s"%child.data)
            if child.right==None:
                print("%s"%child.right.data)
            else:
                pass
        print("}")
        

    def level_of_node(self, data): 
        level=0
        child=Tree.find_node(self, data)
        if child.parent==None:
            level=0
        else:
            while child.parent!=None:
                level+=1
                child=child.parent
        print("%d"%level)
        

    def level_of_tree(self):
        level=0
        while self.left!=None:
            level+=1
            self=self.left
        print("%d"%level)


    def level_of_tree2(self):
        level=0
        while self.left==None:
            level+=1
            self=self.left
        print("%d"%level)


    def delete_node(self, data): 
        delete=Tree.find_node(self, data)
        if delete.left!=None:
            print("Error\n")
        else:
            before=delete.parent.left
            after=delete.right
            parent=delete.parent
            if before==delete:
                if after==None:
                    before=None
                else:
                    before=after
            elif after==None:
                before.right=None
            else:
                while before.right!=delete:
                    before=before.right
                print("%s"%before.data)
            del(delete)


    def delete_node2(self, data): 
        delete=Tree.find_node(self, data)
        if delete.left!=None:
            print("Error\n")
        else:
            before=delete.parent.left
            after=delete.right
            parent=delete.parent
            if before==delete:
                if delete.right!=None:
                    before=after
                    after,right=None
                else:
                    before=None
            else:
                before.right=None
            del(delete)
        

    def get_ancestors(self, data): 
        child=Tree.find_node(self, data)
        while True:
            if child.parent==None:
                break
            print("%s"%child.parent.data)
            child=child.parent


    def get_descendants(self, data): 
        find=Tree.find_node(self, data)
        while True:
            if find.left==None:
                break
            else:
                find=find.left
                print("%s"%find.data)
                while find.right!=None:
                    find=find.right
                    print("%s"%find.data)
                


    def get_descendants2(self, data): 
        find=Tree.find_node(self, data)
        while True:
            if find.left==None:
                break
            find=find.left
            print("%s"%find.data)
            if find.right==None:
                break
            print("%s"%find.right.data)
        

    def degree_of_node(self, data): 
        find=Tree.find_node(self, data)
        degree=0
        if find.left!=None:
            find=find.left
            degree+=1
            while find.right!=None:
                find=find.right
                degree+=1
        else:
            degree=0
        print("%d"%degree)


    def degree_of_node2(self, data): 
        find=Tree.find_node(self, data)
        degree=0
        if find.left!=None:
            find=find.left
            degree=1
            if find.right!=None:
                degree=2
        else:
            degree=0
        print("%d"%degree)


    def degree_of_tree(self):
        degree=0


    def degree_of_tree2(self):
        degree=0
        

    def count_node(self): 
        cnt=0
        if self==None:
            cnt=0
        else:
            cnt=count_node(self.left)+count_node(self.right)+1
        return cnt
            


    def insert_sibling(self, data, s_data):
        find=Tree.find_node(self, data)
        if find==None:
            print("Error\n")
        else:
            while find.right!=None:
                find=find.right
            find.right=new_node(s_data)
            find.right.parent=find.parent
                


    def insert_sibling2(self, data, s_data): 
        find=Tree.find_node(self, data)
        parent=find.parent
        child=parent.left
        if find==None:
            print("Error\n")
        else:
            if child.right!=None:
                print("Full\n")
            else:
                child.right=new_node(s_data)
                child.right.parent=child.parent
            

    def join_trees(n_data, tree1, tree2): 
        root=Node(n_data)
        root.left=tree1
        root.right=tree2
        tree1.parent=root
        tree2.parent=root
        return root


    def clear(self): 
        if self==None:
            pass
        else:
            if self.left!=None:
                clear(self.left)
            if self.right!=None:
                clear(self.right)
            self.left=None
            self.right=None
            del(self)
        

global my_tree
my_tree=Tree()

def General_Tree():

    my_tree=Tree()
    
    t=Node("-")


    while True:

        user=list(input('>> '))
    

        for i in range(len(user)):
 
            if user[i]=='+':
                if len(user)<3:
                    my_tree=Tree.new_node(user[i+1])
                elif user[i+2]=='(':
                    p_data=i+1
                    index=i+3
                    if user[i+4]!=',':
                        Tree.insert_node(my_tree, user[i+1], user[i+3])
                    else:
                        while True:
                            if user[index]==')':
                                break
                            elif user[index]!=',':
                                Tree.insert_node(my_tree, user[p_data], user[index])
                            index+=1
                break
                    

            elif user[i]=='S': 
                Tree.get_sibling(my_tree, user[i+2])
                break

            elif user[i]=='T': 
                Tree.printT(my_tree)
                break


            elif user[i]=='P': 
               Tree.get_parent(my_tree, user[i+2])
               break


            elif user[i]=='C': 
                Tree.get_child(my_tree, user[i+2])
                break


            elif user[i]=='L':
                if user[i+2]!=None:
                    Tree.level_of_node(my_tree, user[i+2])
                else:
                    Tree.level_of_tree(my_tree)
                break
            
            
            elif user[i]=='-': 
                Tree.delete_node(my_tree, user[i+1])
                break


            elif user[i]=='A': 
               Tree.get_ancestor(my_tree, user[i+2])
               break


            elif user[i]=='D': 
                Tree.get_descendants(my_tree, user[i+2])
                break



            elif user[i]=='G':
                if len(user)>3:
                    Tree.degree_of_node(my_tree, user[i+2])
                else:
                    Tree.degree_of_tree(my_tree)
                break
            
            
            elif user[i]=='#':
                cnt=Tree.count_node
                print("%d"%cnt)
                break


            elif user[i]=='=':
                if user[i+1]=='+':
                    sib=i+2
                    index=i+4
                    if user[i+5]!=',':
                        Tree.insert_sibling(my_tree, user[i+2], user[i+4])
                    else:
                        while True:
                            if user[index]==')':
                                break
                            elif user[index]!=',':
                                Tree.insert_sibling(my_tree, user[sib], user[index])
                            index+=1
                break 
               


            elif user[i]=='J': 
                Tree.join_trees(user[i+2], my_tree, t)
                break

            elif user[i]=='K': 
                Tree.clear(my_tree)
                print("Clear")
                break

                
            elif user[i]=='Q': 
                print(" QUIT")
                break


        if user[0]=='Q':
            break
        elif user[0]=='S':
            pass
        elif user[0]=='T':
            pass
        elif user[0]=='P':
            pass
        elif user[0]=='C':
            pass
        elif user[0]=='L':
            pass
        elif user[0]=='A':
            pass
        elif user[0]=='D':
            pass
        elif user[0]=='G':
            pass
        elif user[0]=='#':
            pass
        elif user[0]=='K':
            pass
        else:
            Tree.printT(my_tree)
            
        print()



def Binary_Tree():

    my_tree=Tree()
       
    t=Node("-")


    while True:

        user=list(input('>> '))
        

        for i in range(len(user)):
     
            if user[i]=='+':
                if len(user)<3:
                    Tree.new_node(user[i+1])
                elif user[i+2]=='(':
                    p_data=i+1
                    index=i+3
                    if user[i+4]!=',':
                        Tree.insert_node2(my_tree, user[i+1], user[i+3])
                    else:
                        while True:
                            if user[index]==')':
                                break
                            elif user[index]!=',':
                                Tree.insert_node2(my_tree, user[p_data], user[index])
                            index+=1
                break
                    

            elif user[i]=='S': 
                Tree.get_sibling2(my_tree, user[i+2])
                break

            elif user[i]=='T': 
                Tree.printT(my_tree)
                break


            elif user[i]=='P': 
               Tree.get_parent(my_tree, user[i+2])
               break


            elif user[i]=='C': 
                Tree.get_child2(my_tree, user[i+2])
                break


            elif user[i]=='L':
                if user[i+2]!=None:
                    Tree.level_of_node(my_tree, user[i+2])
                else:
                    Tree.level_of_tree2(my_tree)
                break
            
            
            elif user[i]=='-': 
                Tree.delete_node2(my_tree, user[i+1])
                break


            elif user[i]=='A': 
               Tree.get_ancestor(my_tree, user[i+2])
               break


            elif user[i]=='D': 
                Tree.get_descendants2(my_tree, user[i+2])
                break



            elif user[i]=='G':
                if user[i+2]!=None:
                    Tree.degree_of_node2(my_tree, user[i+2])
                else:
                    Tree.degree_of_tree2(my_tree, user[i+2])
                break
            
            
            elif user[i]=='#':
                cnt=Tree.count_node
                print("%d"%cnt)
                break


            elif user[i]=='=':
                if user[i+1]=='+':
                    sib=i+2
                    index=i+4
                    if user[i+5]!=',':
                        Tree.insert_sibling2(my_tree, user[i+2], user[i+4]) 
                else:
                    while True:
                        if user[index]==')':
                            break
                        elif user[index]!=',':
                            Tree.insert_sibling2(my_tree, user[sib], user[index])
                        index+=1
                break 
               


            elif user[i]=='J': 
                Tree.join_trees(my_tree, user[i+2], my_tree, t)
                break

            elif user[i]=='K': 
                Tree.clear(my_tree)
                print("Clear")
                break

                
            elif user[i]=='Q': 
                print(" QUIT")
                break


        if user[0]=='Q':
            break
        elif user[0]=='S':
            pass
        elif user[0]=='T':
            pass
        elif user[0]=='P':
            pass
        elif user[0]=='C':
            pass
        elif user[0]=='L':
            pass
        elif user[0]=='A':
            pass
        elif user[0]=='D':
            pass
        elif user[0]=='G':
            pass
        elif user[0]=='#':
            pass
        elif user[0]=='K':
            pass
        else:
            Tree.printT(my_tree)
        print()

    
print("-"*5, end='')
print("Type of Tree", end='')
print("-"*5)
print("1. General Tree")
print("2. Binary Tree")
print()
choice=int(input("Tree Type: "))

print("-"*22)

if choice==1:
    General_Tree()

elif choice==2:
    Binary_Tree()
