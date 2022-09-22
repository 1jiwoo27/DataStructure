'ADD 함수를 사용할 때는 HELP에 적혀 있는 내용을 참조해 주세요!'

#Node 정의
class Node:
    def __init__(self, data, next=None):
        self.data=data
        self.next=next


#함수
class LinkedList:
    def __init__(self): 
        self.head=Node(None) #head 노드
        self.head.next=None
        self.current=self.head
        self.cur_pos=0 #현재 위치
        self.size=0
  

    def addTail(self, data): 
        NEW=Node(data)
        NEW.next=None

        NEXT=self.head.next
        for i in range(self.size-1):
            NEXT=NEXT.next
        if self.size==0:
            self.head.next=NEW
            self.size+=1
        else:
            NEXT.next=NEW
            self.size+=1
            self.cur_pos=self.size-1

        self.current=NEW


    def add(self, count, data):
        NEW=Node(data)

        PREV=self.head
        for i in range(self.cur_pos):
            PREV=PREV.next
        if count==0:
            PREV.next=NEW
            NEW.next=self.current
        elif count==1:
            NEW.next=self.current.next
            self.current.next=NEW
            self.cur_pos+=1

        self.current=NEW
        self.size+=1
        

    def printL(self): 
        NEXT=self.head.next
        for i in range(self.size):
            if i==self.cur_pos:
                print("(%c)"%(NEXT.data), end=' ')
            else:
                print("%2c"%(NEXT.data), end=' ')
            NEXT=NEXT.next
        print()                
   

    def traverse_front(self, count):
        self.cur_pos=count
        NEXT=self.head.next
        for i in range(self.cur_pos):
            NEXT=NEXT.next
        self.current=NEXT


    def traverse_rear(self, count): 
        self.cur_pos=self.size-count-1
        LAST=self.head
        for i in range(self.cur_pos+1):
            LAST=LAST.next 
        self.current=LAST
    
        
    def get_data(self): 
        print(" %c"%(self.current.data), end=' ')
        if key[0]=='G':
            NEXT=self.head.next
            for i in range(self.size):
                if i==0:
                    if self.cur_pos==0:
                        print("((%c)"%(NEXT.data), end=' ')
                    else:
                        print("(%c"%(NEXT.data), end=' ')
                elif i==self.size-1:
                    if self.size-1==self.cur_pos:
                        print("(%c))"%(NEXT.data),end='')
                    else:
                        print("%2c)"%(NEXT.data),end='')
                elif i==self.cur_pos:
                    print("(%c)"%(NEXT.data), end=' ')
                else:
                    print("%2c"%(NEXT.data), end=' ')
                NEXT=NEXT.next
        print()
                
        
    def delete(self): 
        PREV=self.head.next
        for i in range(self.cur_pos-1):
            PREV=PREV.next 

        if self.current.next==None: 
            PREV.next=None 
            if self.size==1: 
                self.current=self.head 
                self.cur_pos=0 
            else: 
                self.current=self.head.next 
                self.cur_pos=0 
            
        else:
            DEL=self.current
            PREV.next = self.current.next 
            self.current = self.current.next 
            del(DEL)
    
        self.size-=1


    def replace(self, new_data): 
        self.current.data=new_data
        

    def data_count(self): 
        return self.size


    def is_member(self, data): 
        mpos=0 
        savepos=self.cur_pos
        savecur=self.current 
        NEXT=self.head.next 

        while NEXT!=None:
            self.cur_pos=mpos 
            self.current=NEXT
            if NEXT.data==data:
                return mpos+1 
            NEXT=NEXT.next 
            mpos+=1
        
        self.cur_pos=savepos
        self.current=savecur
        return -1 
        

    def is_empty(self): 
        if self.size==0:
            print(" True")
        else:
            print(" False")


    def move_prev(self):
        PREV=self.head.next
        for i in range(self.cur_pos-1):
            PREV=PREV.next

        savedata=self.current.data
        self.current.data=PREV.data
        PREV.data=savedata
        
        self.cur_pos-=1
        self.current=PREV


    def move_next(self):
        NEXT=self.head.next
        for i in range(self.cur_pos+1):
            NEXT=NEXT.next
            
        savedata=self.current.data
        self.current.data=NEXT.data
        NEXT.data=savedata
        
        self.cur_pos+=1
        self.current=NEXT


    def clear(self): 
        DEL=Node(None)
        NEXT=self.head.next 
        while (NEXT!= None):
            DEL=NEXT
            NEXT= NEXT.next 
            del(DEL) 
        
        self.__init__()
        
        print()


    def help(self):
        print('='*14+'H E L P'+'='*14)
        print('{:22}{}'.format('ADDTAIL',': +(data)'))
        print('{:22}{}'.format('ADD',': ^(data)')) 
        print('{:22}{}'.format('DELETE',': -'))
        print('{:22}{}'.format('DELETE LAST',': > -'))
        print('{:22}{}'.format('TRAVERSE_FRONT',': <'))
        print('{:22}{}'.format('TRAVERSE_REAR',': >'))
        print('{:22}{}'.format('GET_DATA',': G'))
        print('{:22}{}'.format('REPLACE',': =(data)'))
        print('{:22}{}'.format('CLEAR',': C'))
        print('{:22}{}'.format('DATA_COUNT',': #'))
        print('{:22}{}'.format('IS_MEMBER',': ?(data)'))
        print('{:22}{}'.format('IS_EMPTY',': E'))
        print('{:22}{}'.format('MOVE_PREV',': MP')) 
        print('{:22}{}'.format('MOVE_NEXT',': MN')) 
        print('{:22}{}'.format('PRINT',': L'))
        print('{:22}{}'.format('PREV',': P'))
        print('{:22}{}'.format('NEXT',': N'))
        print('{:22}{}'.format('HELP',': H'))
        print('{:22}{}'.format('QUIT',': Q'))
        print()
        print('{:22}'.format('**Use ADD(0) like this:'))
        print('{:22}'.format('>> ^(data) ^N(data) ^N(data)'))
        print('{:22}'.format('**Use ADD(N) like this:'))
        print('{:22}'.format('>> ^N(data) ^N(data) ^N(data)'))
        print()
        print('{:22}'.format('**Spacing between commands'))
        print('{:22}'.format('**Only one character for one data'))
        print('='*35)
        
        
    
my_list=LinkedList()
my_list.help()


while True:

    key=list(input('>> '))

    Ncnt=0 #N 카운트변수
    Pcnt=0 #P 카운트변수
    
    for i in range(len(key)):
        if key[i]=="N":
            if key[i-1]=='^':
                pass
            else:
                Ncnt+=1
        elif key[i]=="P":
            Pcnt+=1
    

    for i in range(len(key)):

        if 48<=ord(key[0])<=57: #0<=key[0]<=9 / key[0]이 한 자릿수 정수일 때
            my_list.traverse_front(int(key[0])-1)
 
        if key[i]=='+': 
            my_list.addTail(key[i+1])

        elif key[i]=='L': 
            pass
                    
        elif key[i]=='G': 
            my_list.get_data()
                              
        elif key[i]=='<': 
            my_list.traverse_front(Ncnt)

        elif key[i]=='>': 
            my_list.traverse_rear(Pcnt)

        elif key[i]=='^':
            if key[i+1]=='N':
                my_list.add(1, key[i+2])
            else:
                my_list.add(0, key[i+1]) 
                        
        elif key[i]=='-': 
            my_list.delete()

        elif key[i]=='=': 
            my_list.replace(key[i+1])
                            
        elif key[i]=='#': 
            result=my_list.data_count()
            print(' ',end='')
            print(result)
                
        elif key[i]=='C': 
            my_list.clear()

        elif key[i]=='E': 
            my_list.is_empty()

        elif key[i]=='M':
            if key[i+1]=='P': #추가 기능1
                my_list.move_prev()
            elif key[i+1]=='N': #추가 기능2
                my_list.move_next()
                    
        elif key[i]=='?': 
            result=my_list.is_member(key[i+1])
                    
            if result>0:
                print(" %d:" %(result),end='')
            elif(result==-1):
                print(" NOT FOUND")

        elif key[i]=='H':
            my_list.help()
                    
        elif key[i]=='Q': #추가 기능3
            print(" QUIT")
            break


    if key[0]=='Q':
        break
    elif key[0]=='H':
        pass
    elif key[0]=='#':
        pass
    elif key[0]=='C':
        pass
    elif key[0]=='G':
        pass
    elif key[0]=='E':
        pass
    elif key[0]=='?':
        if result==-1:
            pass
        else:
            my_list.printL()
    elif len(key)>1 and key[1]=='G':
        pass
    
    else:
        my_list.printL()

    

    

                
 
    


