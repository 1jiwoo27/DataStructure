#LN06스택ADT


class Stack:
    def __init__(self):
        self.data=[]
        self.top=-1
        self.size=0
    
        
    def push(self, element):
        if not self.is_full():
            self.data.append(element)
            self.top+=1
            self.size+=1
        else:
            print(" Stack overflow")


    def printS(self):
        new=[] #새로운 스택에 top부터 push
        for i in range(self.top, -1, -1):
            new.append(self.data[i])

        for i in range(0, len(new)):
            if i==self.top:
                print("(%s)"%(new.pop(-1)), end=' ')
            else:
                print("%2s"%(new.pop(-1)), end=' ')
                       

    def peek(self):
        if not self.is_empty():
            print(" %s"%self.data[-1], end='')
        else:
            pass


    def pop(self):
        if not self.is_empty():
            self.top-=1
            self.size-=1
            pop=[]
            pop.append(self.data.pop(-1))
            for i in range(0,len(pop)):
                print(" return %s"%pop[i])
        else:
            print(" Error (nothing to pop)",end='')


    def is_full(self):
        return self.size==Max_Size
   

    def is_empty(self):
        return self.size==0


    def element_count(self):
        print(" %d"%(self.size), end='')


    def data_count(self, element):
        cnt=0
        new=[]
        for i in range(self.top, -1, -1):
            if self.data[i]==element:
                cnt+=1
            new.append(self.data[-1])
        print(" %d"%cnt, end='')


    def topS(self):
        if self.is_empty():
            pass
        else:
            print(" (%d, %s)"%(self.top+1, self.data[-1]), end='')
        

    def is_member(self, element):
        new1=[] 
        for i in range(self.top, -1, -1): #새로운 스택에 element가 나올 때까지 옮기기
            if self.data[i]==element:
                break
            new1.append(self.data[-1])
            self.data.pop(-1)

        if len(self.data)==0: 
            print(" False", end='') #self.data에 element가 없다면 다 옮겨지니 len==0
        else:
            print(" True", end='') #self.data에 element가 있다면 남아있으니 len!=0

        
        new2=[] #다른 새로운 스택에 전체 옮기기
        if len(self.data)>0: #True라면
            for i in range(0, len(self.data)):
                new2.append(self.data[i])
        
        for i in range(len(new1)-1, -1, -1):
            if len(new1)==0:
                pass
            new2.append(new1[i])
            
        self.data=new2

        
    def replace(self, new_element):
        if self.is_empty():
            pass
        else:
            self.data[-1]=new_element


    def reverse(self):
        if self.is_empty():
            pass
        else:
            new=[]
            for i in range(self.top, -1, -1):
                new.append(self.data[-1])
                self.data.pop(-1)
            self.data=new


    def clear(self):
        self.__init__()


    def help(self):
        print('='*14+'H E L P'+'='*14)
        print('{:22}{}'.format('PUSH',': +(data)'))
        print('{:22}{}'.format('PRINT',': L'))
        print('{:22}{}'.format('PEEK',': P'))
        print('{:22}{}'.format('TOP',': T'))
        print('{:22}{}'.format('POP',': -'))
        print('{:22}{}'.format('IS_FULL',': F'))
        print('{:22}{}'.format('IS_EMPTY',': E'))
        print('{:22}{}'.format('ELEMENT_COUNT',': #'))
        print('{:22}{}'.format('DATA_COUNT',': @(data)'))
        print('{:22}{}'.format('IS_MEMBER',': ?(data)'))
        print('{:22}{}'.format('REPLACE',': =(data)'))
        print('{:22}{}'.format('REVERSE',': R'))
        print('{:22}{}'.format('CLEAR',': C'))
        print('{:22}{}'.format('HELP',': H'))
        print('{:22}{}'.format('QUIT',': Q'))
        print()
        print('{:22}{}'.format('**Max Size of Stack',': 10'))
        print()
        print('{:22}'.format('**Spacing between commands'))
        print('{:22}'.format('**Only one character for one data'))
        print('='*35)
        

    
#변수
my_stack=Stack()
Max_Size=10

my_stack.help()


while True:
    
    key=list(input('>> '))


    for i in range(len(key)):

   
        if 48<=ord(key[i])<=57: #0<=key[0]<=9 / key[0]이 한 자릿수 정수일 때
            if key[i+1]=='-':
                for i in range(int(key[i])):
                    my_stack.pop()
            break
        
 
        elif key[i]=='+': 
            my_stack.push(key[i+1])

        elif key[i]=='L': 
            pass
                    
        elif key[i]=='P': 
            my_stack.peek()
                              
        elif key[i]=='-':
            my_stack.pop()
            
               
        elif key[i]=='F': 
            result=my_stack.is_full()
            print(" %s"%result, end='')

        elif key[i]=='E': #추가 기능1 (pop할 게 남아있는지 확인)
            result=my_stack.is_empty()
            print(" %s"%result, end='')
            
        elif key[i]=='#':
            my_stack.element_count()

        elif key[i]=='@': #추가 기능2 (특정 data의 개수 확인)
            my_stack.data_count(key[i+1])
             
        elif key[i]=='T': 
            my_stack.topS()

        elif key[i]=='?': 
            my_stack.is_member(key[i+1])
                            
        elif key[i]=='=': 
            my_stack.replace(key[i+1])

        elif key[i]=='R': #추가 기능2 (stack 순서 거꾸로)
            my_stack.reverse()
                
        elif key[i]=='C': 
            my_stack.clear()

        elif key[i]=='H': 
            my_stack.help()

     
        elif key[i]=='Q': #추가 기능3 (프로그램 종료 시)
            print(" QUIT")
            break

        

    if my_stack.is_empty():
    
        if key[0]=='-':
            pass
        elif key[0]=='Q':
            pass
        elif key[0]=='E':
            pass
        elif key[0]=='H':
            pass
        elif key[0]=='F':
            pass
        elif key[0]=='#':
            pass
        elif key[0]=='@':
            pass
        elif key[0]=='?':
            pass
        else:
            print(" -",end='')

    else:
        pass
    

    if key[0]=='Q':
        break
    elif key[0]=='P':
        pass
    elif key[0]=='F':
        pass
    elif key[0]=='E':
        pass
    elif key[0]=='#':
        pass
    elif key[0]=='@':
        pass
    elif key[0]=='T':
        pass
    elif key[0]=='C':
        pass
    elif key[0]=='H':
        pass
    elif key[0]=='?':
        pass
    else:
        my_stack.printS()
    print()
