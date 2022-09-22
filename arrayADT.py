#LN04배열ADT_Python


#함수
def insert(array, data):
    global cur_pos
    if not array:
        for i in range(0,len(data),1):
            if data[i]=='+':
                array.append(data[i+1])
        cur_pos=len(array)-1
    else:
        for i in range(0,len(data),1):
            if data[i]=='+':
                array[cur_pos+1:cur_pos+1]=data[i+1]
                cur_pos+=1
        
        cur_pos=array.index(data[i])
        

def traverse_front(array):
    global cur_pos
    cur_pos=0
    

def traverse_rear(array):
    global cur_pos
    cur_pos=len(array)-1


def prev(array):
    global cur_pos
    cur_pos-=1


def next(array):
    global cur_pos
    cur_pos+=1


def delete(array):
    global cur_pos
    array.remove(array[cur_pos])
    if len(array)-1 < cur_pos:
        cur_pos-=1
    

def get_data(array):
    global cur_pos
    print('Return : %c\n'%array[cur_pos],end='')


def replace(array, new_data):
    global cur_pos
    for i in range(0,len(new_data),1):
            if new_data[i]=='=':
                array[cur_pos]=(new_data[i+1])
        
def empty(array):
    array.clear()
    print('empty array\n',end='')
    

def move(array, new_position):
    global cur_pos
    if new_position<cur_pos:
        array.insert(new_position,array[cur_pos])
        array.pop(cur_pos+1)
        cur_pos=new_position
    elif new_position>cur_pos:
        array.insert(new_position+1,array[cur_pos])
        array.pop(cur_pos)
        cur_pos=new_position
    else:
        print('현재 위치입니다.')
        

def move_front(array):
    global cur_pos
    array.insert(0, array[cur_pos])
    array.pop(cur_pos+1)
    cur_pos=0
        

def move_end(array):
    global cur_pos
    array.insert(len(array), array[cur_pos])
    array.pop(cur_pos)
    cur_pos=len(array)-1
        

def move_prev(array):
    global cur_pos
    array.insert(cur_pos-1, array[cur_pos])
    array.pop(cur_pos+1)
    cur_pos-=1
        


def move_next(array):
    global cur_pos
    array.insert(cur_pos+2, array[cur_pos])
    array.pop(cur_pos)
    cur_pos+=1
        
def find(array,f_data):
    print('검색하신 문자의 인덱스는 %d입니다.'%array.index(f_data))


def sortup(array):
    array.sort()
    

def sortlow(array):
    array.sort(reverse=True)

    
def help():
    print('='*14+'H E L P'+'='*14)
    print('{:22}{}'.format('INSERT',': +(data)'))
    print('{:22}{}'.format('DELETE',': -'))
    print('{:22}{}'.format('DELETE LAST',': > -'))
    print('{:22}{}'.format('TRAVERSE_FRONT',': <'))
    print('{:22}{}'.format('TRAVERSE_REAR',': >'))
    print('{:22}{}'.format('GET_DATA',': @'))
    print('{:22}{}'.format('REPLACE',': =(data)'))
    print('{:22}{}'.format('EMPTY',': E'))
    print('{:22}{}'.format('MOVE',': M(position)'))
    print('{:22}{}'.format('MOVE FRONT',': Mf'))
    print('{:22}{}'.format('MOVE END',': Mn'))
    print('{:22}{}'.format('MOVE PREV',': MP'))
    print('{:22}{}'.format('MOVE NEXT',': MN'))
    print('{:22}{}'.format('PRINT',': L'))
    print('{:22}{}'.format('PREV',': P'))
    print('{:22}{}'.format('NEXT',': N'))
    print('{:22}{}'.format('FIND',': F(data)'))
    print('{:22}{}'.format('SORTUP',': SU'))
    print('{:22}{}'.format('SORTLOW',': SL'))
    print('{:22}{}'.format('HELP',': H'))
    print('{:22}{}'.format('QUIT',': Q'))
    print()
    print('{:22}'.format('**Spacing between commands'))
    print('{:22}'.format('**Only one character for one data'))
    print('='*35)
    

#변수
my_array=[]
global cur_pos

help()

while True:

    
    
    key = list(input('>> '))

    if 'E' in key:
        empty(my_array)


    elif 'H' in key:
        print()
        help()

    elif 'F' in key:
        while 'F' in key:
            key.remove('F')
            data=key[0]
            find(my_array, data)

    elif 'Q' in key:
        print('프로그램을 종료합니다.')
        break

    else:
        
        if '+' in key:
            data=key
            insert(my_array,data)

        elif '@' in key:
            get_data(my_array)

        

        elif '-' in key:
            if '>' in key and '-' in key:
                key.remove('>')
                key.remove('-')
                traverse_rear(my_array)
                delete(my_array)
                cur_pos=0
                for i in range(0,len(key),1):
                    if key[i]=='-':
                        delete(my_array)  
            else:
                delete(my_array)

            
        elif '<' in key:
            if '<' in key and 'N' in key:
                traverse_front(my_array)
                for i in range(0,len(key),1):
                    if key[i]=='N':
                        next(my_array)
            elif '<' in key and 'M' in key:
                while '<' in key:
                    key.remove('<')
                while 'M' in key:
                    key.remove('M')
                while ' ' in key:
                    key.remove(' ')
                position=int(key[0])
                traverse_front(my_array) 
                move(my_array, position)
                
            else:
                traverse_front(my_array)    

            
        elif '>' in key:
            if '>' in key and '-' in key:
                key.remove('>')
                key.remove('-')
                traverse_rear(my_array)
                delete(my_array)
                cur_pos=0
                for i in range(0,len(key),1):
                    if key[i]=='-':
                        delete(my_array)
            elif '>' in key and 'P' in key:
                traverse_rear(my_array)
                for i in range(0,len(key),1):
                    if key[i]=='P':
                        prev(my_array)    
            else:  
                traverse_rear(my_array)


        elif '-' in key:
            delete(my_array)

        

        elif '=' in key:
            data=key
            replace(my_array, data)
            
            
        elif 'M' in key:
            if 'M' in key and 'f' in key:
                move_front(my_array)
            elif 'M' in key and 'n' in key:
                move_end(my_array)
            elif 'M' in key and 'P' in key:
                move_prev(my_array)
            elif 'M' in key and 'N' in key:
                move_next(my_array)
            else:
                while 'M' in key:
                    key.remove('M')
                position=int(key[0])
                move(my_array, position)

        elif 'P' in key:
            prev(my_array)
        
        elif 'N' in key:
            next(my_array)


        elif 'S' in key:
            if 'S' in key and 'U' in key:
                sortup(my_array)
            elif 'S'in key and 'L' in key:
                sortlow(my_array)

        elif 'L' in key:
            my_array[cur_pos]='('+my_array[cur_pos]+')'
            for i in range(0,len(my_array)):
                print("%2s"%my_array[i], end=' ')
            my_array[cur_pos]=my_array[cur_pos].replace('(','')
            my_array[cur_pos]=my_array[cur_pos].replace(')','')
            print()
            continue

        my_array[cur_pos]='('+my_array[cur_pos]+')'
        for i in range(0,len(my_array)):
            print("%2s"%my_array[i], end=' ')
        my_array[cur_pos]=my_array[cur_pos].replace('(','')
        my_array[cur_pos]=my_array[cur_pos].replace(')','')
        print()

    
  
