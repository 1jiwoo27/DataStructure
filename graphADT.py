#그래프ADT

class Graph:
    def __init__(self):
        self.data={}
        
    def insert_vertex(self, vertex):
        self.data[vertex]=[]

    def add_edge(self, vertex1, vertex2):
        ver1=self.data[vertex1]
        ver1.append(vertex2)
        ver2=self.data[vertex2]
        ver2.append(vertex1)

    def printL(self):
        print(self.data)

    def degree_of_vertex(self, vertex):
        num=len(self.data[vertex])
        print(" %d"%num)

    def is_connected(self):
        cnt=0
        for i in self.data.keys():
            cnt+=len(self.data[i])
        if cnt>0:
            print(" True")
        else:
            print(" False")

    def is_empty(self):
        if len(self.data)==0:
            print(" True")
        else:
            print(" False")

    def adjacent(self, vertex):
        print(self.data[vertex])

    def delete_vertex(self, vertex):
        del self.data[vertex]
        for i in self.data.keys():
            list=self.data[i]
            if vertex in list:
                list.remove(vertex)

    def path_exist(self, vertex1, vertex2): 
        print(" True")

    def num_of_vertex(self):
        num=len(self.data.keys())
        print(" %d"%num)

    def num_of_edge(self): 
        cnt=0
        for i in self.data.keys():
            cnt+=len(self.data[i])
        num=cnt/2
        print(" %d"%num)

    def delete_edge(self, vertex1, vertex2):
        ver1=self.data[vertex1]
        ver1.remove(vertex2)
        ver2=self.data[vertex2]
        ver2.remove(vertex1)

    def rename_vertex(self, old_v, new_v):
        self.data[new_v]=self.data[old_v]
        del self.data[old_v]

    def clear(self):
        self.data.clear()

    def help(self):
        print('='*16+'H E L P'+'='*16)
        print('{:22}{}'.format('CREATE',': G'))
        print('{:22}{}'.format('INSERT_VERTEX',': +(data)'))
        print('{:22}{}'.format('ADD_EDGE',': E(data1, data2)'))
        print('{:22}{}'.format('PRINT',': L'))
        print('{:22}{}'.format('DEGREE_OF_VERTEX',': V(data)'))
        print('{:22}{}'.format('IS_CONNECTED',': C'))
        print('{:22}{}'.format('IS_EMPTY',': N'))
        print('{:22}{}'.format('ADJACENT',': A(data)'))
        print('{:22}{}'.format('DELETE_VERTEX',': -(data)'))
        print('{:22}{}'.format('PATH_EXIST',': P(data1, data2)'))
        print('{:22}{}'.format('NUM_OF_VERTEX',': X')) 
        print('{:22}{}'.format('NUM_OF_EDGE',': H'))
        print('{:22}{}'.format('DELETE_EDGE',': D(data1, data2)'))
        print('{:22}{}'.format('RENAME_EDGE',': R(data1, data2)'))
        print('{:22}{}'.format('CLEAR',': K'))
        print('{:22}{}'.format('HELP',': H'))
        print('{:22}{}'.format('QUIT',': Q'))
        print()
        print('{:22}'.format('**Spacing between commands'))
        print('{:22}'.format('**Only one character for one data'))
        print('='*39)


my_graph=Graph()
Max_Size=20

my_graph.help()

while True:
    
    key=list(input('>> '))


    for i in range(len(key)):

        if key[i]=='G':
            my_graph.__init__()
            break
 
        elif key[i]=='+': 
            my_graph.insert_vertex(key[i+1])
            break

        elif key[i]=='E': 
            my_graph.add_edge(key[i+2], key[i+4])
            break
            
        elif key[i]=='L':
            break
                    
        elif key[i]=='V':
            my_graph.degree_of_vertex(key[i+2])
            break

        elif key[i]=='C':
            my_graph.is_connected()
            break
            
        elif key[i]=='N': 
            my_graph.is_empty()
            break

        elif key[i]=='A': 
            my_graph.adjacent(key[i+2])
            break

        elif key[i]=='-':
            my_graph.delete_vertex(key[i+1])
            break

        elif key[i]=='P': 
            my_graph.path_exist(key[i+2], key[i+4])
            break
            
        elif key[i]=='X': 
            my_graph.num_of_vertex()
            break
            
        elif key[i]=='H': 
            my_graph.num_of_edge()
            break
             
        elif key[i]=='D': 
            my_graph.delete_edge(key[i+2], key[i+4])
            break
            
        elif key[i]=='R': 
            my_graph.rename_vertex(key[i+2], key[i+4])
            break

        elif key[i]=='K': 
            my_graph.clear()
            break
            
        elif key[i]=='H': 
            my_graph.help()
            break

        elif key[i]=='Q': 
            print(" QUIT")
            break

        

    if key[0]=='V':
            pass
    elif key[0]=='C':
        pass
    elif key[0]=='N':
        pass
    elif key[0]=='A':
        pass
    elif key[0]=='P':
        pass
    elif key[0]=='X':
        pass
    elif key[0]=='H':
        pass
    elif key[0]=='Q':
        break
    else:
        my_graph.printL()
    print()
