num1 = int(input("정수를 입력하시오 : "))
num2 = int(input("정수를 입력하시오 : "))
num3 = int(input("정수를 입력하시오 : "))

sum = num1 + num2 + num3
average = sum/3

'''
if (num2 < num1 and num3 < num1):
    print("\n최대값은 %d이다" %num1)
    if num2 < num3:
        print("최솟값은 %d이다" %num2)
    else:
        print("최솟값은 %d이다" % num3)
elif (num1 < num2 and num3 < num2):
    print("\n최대값은 %d이다" %num2)
    if num1 < num3:
        print("최솟값은 %d이다" %num1)
    else:
        print("최솟값은 %d이다" % num3)
elif (num1 < num3 and num2 < num3):
    print("\n최대값은 %d이다" %num3)
    if num1 < num2:
        print("최솟값은 %d이다" %num1)
    else:
        print("최솟값은 %d이다" % num2)

print("\n합계는 %d이고 평균은 %d이다" %(sum , average))
'''

M = num1
m = num1
M = max(num1,num2,num3)
m = min(num1,num2,num3)

if M < num2:
    M = num2

if M < num3:
    M = num3

if m > num2:
    m = num2

if m > num3:
    m = num3

print("\n최대값은 %d이고 최소값은 %d이다" %(M,m))
print("합계는 %d이고 평균은 %d이다" %(sum,average))