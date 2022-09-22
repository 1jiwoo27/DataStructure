#LN07큐ADT


class Queue:
    def __init__(self):
        self.data=[]
        self.head=-1
        self.tail=-1
    
        
    def enqueue(self, data):
        if not self.is_full(): 
            self.data.append(data)
            self.tail+=1
        else:
            if self.head==self.tail:
                self.__init__()
                self.data.append(data)
                self.tail+=1
            else:
                print(" Queue overflow")


    def printQ(self):
        for i in range(self.head+1, self.tail+1):
            print("%2s"%(self.data[i]), end=' ')

    def printR(self):
        for i in range(self.tail, self.head, -1):
            print("%2s"%(self.data[i]), end=' ')
            
                       
    def peek(self):
        print(" %s"%self.data[self.head+1], end='')

    def peekT(self):
        print(" %s"%self.data[self.tail], end='')

   
    def dequeue(self):
        if self.head!=self.tail:
            a=self.data[self.head+1]
            self.data[self.head+1]='\0'
            print(" return %s"%a)
            self.head+=1
        else:
            print(' Error (nothing to dequeue)',end='')


    def is_full(self):
        return self.tail==Max_Size-1

    def is_empty(self):
        return self.head==self.tail
   

    def data_count(self):
        print(" %d"%(self.tail-self.head), end='')


    def headL(self):
        print(" %d"%(self.head+2), end='')


    def tailL(self):
        print(" %d"%(self.tail+1), end='')
   
        
    def is_member(self, data):
        member=-1
        for i in range(self.head+1, self.tail+1):
            if self.data[i]==data:
                member=i
        if member==-1:
            print(" False", end='')
        else:
            print(" True", end='')
        
    def replace(self, new_data):
       self.data[self.tail]=new_data


    def clear(self):
        self.__init__()


    def help(self):
        print('='*14+'H E L P'+'='*14)
        print('{:22}{}'.format('ENQUEUE',': +(data)'))
        print('{:22}{}'.format('PRINT',': L'))
        print('{:22}{}'.format('PRINT_REVERSE',': R'))
        print('{:22}{}'.format('PEEK',': P'))
        print('{:22}{}'.format('PEEK_TAIL',': >'))
        print('{:22}{}'.format('DEQUEUE',': -'))
        print('{:22}{}'.format('IS_FULL',': F'))
        print('{:22}{}'.format('IS_EMPTY',': E'))
        print('{:22}{}'.format('DATA_COUNT',': #'))
        print('{:22}{}'.format('HEAD',': H'))
        print('{:22}{}'.format('TAIL',': T')) 
        print('{:22}{}'.format('IS_MEMBER',': ?(data)'))
        print('{:22}{}'.format('REPLACE',': =(data)'))
        print('{:22}{}'.format('CLEAR',': C'))
        print('{:22}{}'.format('HELP',': !'))
        print('{:22}{}'.format('QUIT',': Q'))
        print()
        print('{:22}{}'.format('**Max Size of Queue',': 20'))
        print()
        print('{:22}'.format('**Spacing between commands'))
        print('{:22}'.format('**Only one character for one data'))
        print('='*35)
        

    
#변수
my_queue=Queue()
Max_Size=20

my_queue.help()


while True:
    
    key=list(input('>> '))


    for i in range(len(key)):

   
        if 48<=ord(key[i])<=57: #0<=key[0]<=9 / key[0]이 한 자릿수 정수일 때
            if key[i+1]=='-':
                for i in range(int(key[i])):
                    my_queue.dequeue()
            break
        
 
        elif key[i]=='+': 
            my_queue.enqueue(key[i+1])

        elif key[i]=='L': 
            pass

        elif key[i]=='R': #추가 기능1 (tail부터 head까지 역순으로 출력)
            my_queue.printR()
                    
        elif key[i]=='P':
            my_queue.peek()

        elif key[i]=='>': #추가 기능2 (tail값 peek)
            my_queue.peekT()
                              
        elif key[i]=='-':
            my_queue.dequeue()
            
               
        elif key[i]=='F': 
            result=my_queue.is_full()
            print(" %s"%result, end='')

        elif key[i]=='E': 
            result=my_queue.is_empty()
            print(" %s"%result, end='')


        elif key[i]=='#':
            my_queue.data_count()

       
        elif key[i]=='H': 
            my_queue.headL()

        elif key[i]=='T': 
            my_queue.tailL()

        elif key[i]=='?': 
            my_queue.is_member(key[i+1])

                            
        elif key[i]=='=': 
            my_queue.replace(key[i+1])

                
        elif key[i]=='C': 
            my_queue.clear()

        elif key[i]=='!': 
            my_queue.help()

     
        elif key[i]=='Q': #추가 기능3 (프로그램 종료)
            print(" QUIT")
            break

        

    if my_queue.is_empty():
    
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
    elif key[0]=='>':
        pass
    elif key[0]=='F':
        pass
    elif key[0]=='R':
        pass
    elif key[0]=='#':
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
        my_queue.printQ()
    print()

