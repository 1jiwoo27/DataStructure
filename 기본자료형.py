#To do list 프로그램

print('****To do list 프로그램****\n')


todo={'필라테스 예약':['3/4','X'], '사전투표 실시':['3/5','X'],
      '자료구조 과제':['3/9','X']}

def plus():
    tkey=input('추가할 To do를 입력하세요: ')
    tvalue=input('추가할 To do의 마감 기한을 입력하세요: ')
    todo[tkey]=[tvalue,'X']
    

def edit():
    tkey=input('수정할 To do를 입력하세요: ')
    tvalue1=input('수정할 To do의 마감 기한을 입력하세요: ')
    tvalue2=input('수정할 To do의 완료 여부를 입력하세요: ')
    todo[tkey]=[tvalue1,tvalue2]

    
def delete():
    tkey=input('삭제할 To do를 입력하세요: ')
    todo.pop(tkey)

def plist():
    print('\n********할 일********[ 기한 , 여부 ]\n')
    for key,value in todo.items():
        print('{0:^18}{1[0]:<4}{1[1]:>5}'.format(key,value))
        

while True:
   
    num=int(input('무엇을 하시겠습니까?[1:추가 2:수정 3:삭제 4:출력 0:종료]: '))


    if num==1:
        plus()
        
    elif num==2:
        edit()
        
    elif num==3:
        delete()
        
    elif num==4:
        plist()
        
    elif num==0:
        print('To do list 프로그램을 종료합니다.')
        break
    
    else:
        print('잘못 입력하셨습니다. 다시 시도하세요.')

    print()
