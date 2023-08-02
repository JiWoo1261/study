class Beverage:
    def __init__(self, name, price, count):
        self.name = name
        self.price = price
        self.count = count

    def __str__(self):
        return "{} {}원".format(self.name, self.price)  ##문자열 return이라 괄호가 필요없음



class VendingMachine:
    def __init__(self, name):
        self.name = name
        self.beverages = [Beverage("아이시스",600,20), Beverage("레몬워터",1500, 20), Beverage("옥수수 수염차", 1300, 20), Beverage("황금보리", 1300, 20), Beverage("트레비", 1000, 20), Beverage("밀키스", 800, 20), Beverage("펩시", 800, 20), Beverage("핫식스", 1000, 20), Beverage("칠성사이다", 1000, 20), Beverage("코코망고", 1000, 20), Beverage("립톤", 1000, 20), Beverage("스파클링 청포도", 1000, 20), Beverage("스파클링 포도", 1000, 20), Beverage("가나초코", 600, 20), Beverage("레쓰비", 600, 20), Beverage("칸타타", 1000, 20), Beverage("레쓰비 카페타임", 1000, 20), Beverage("게토레이", 800, 20), Beverage("코코포도", 800, 20), Beverage("잔치집 식혜", 800, 20)]
        # 음료 이름,가격,개수를 리스트로 미리 설정
        self.consumer_money=0  # 처음 금액 0원
        self.paper_1000 = 10
        self.coin_500 = 10
        self.coin_100 = 10


    def printDisplay(self):
        print("------" + self.name + "------")

        for i in range(0, len(self.beverages)):
            print("{}. {}".format((i+1), self.beverages[i]))

        print("-----------------------------")

    def input_money(self):   #소비자 금액 투입
        paper_1000 = int(input("투입할 1000원의 개수:"))
        coin_500 = int(input("투입할 500원의 개수:"))
        coin_100 = int(input("투입할 100원의 개수:"))
        self.consumer_money += paper_1000 * 1000 + coin_500 * 500 + coin_100 * 100
        print("투입한 금액:", self.consumer_money,"원")

    def add_beverage(self):
        self.printDisplay()
        sel = int(input("음료의 번호 선택:"))
        count = int(input("추가 할 음료의 개수:"))
        prev_count = self.beverages[sel-1].count

        if count <= 0:
            print("개수는 0이하로 불가능합니다.")
            return
        self.beverages[sel-1].count += count
        print("{}번 음료의 개수가 {}개에서 {}개로 추가되었습니다.".format(sel, prev_count, self.beverages[sel-1].count))

    def change_beverage(self):
        self.printDisplay()
        sel = int(input("변경할 음료의 번호 선택:"))
        name = input("음료의 이름:")
        price = int(input("음료의 가격:"))
        count = int(input("음료의 개수:"))

        prev_name = self.beverages[sel-1].name
        self.beverages[sel-1] = Beverage(name, price, count)
        print("음료 {}가 {}로 변경되었습니다.".format(prev_name, name))


    def buy_beverage(self):
        self.printDisplay()
        sel = int(input("음료의 번호 선택:"))

        if self.beverages[sel-1].count <= 0:
            print("해당 상품의 재고가 모두 소진 되었습니다.")
            return
        if self.beverages[sel-1].price > self.consumer_money:
            print("금액이 부족합니다.")
            return
        self.consumer_money -= self.beverages[sel-1].price
        self.beverages[sel-1].count -= 1
        print("{} 1개 구매 완료!".format(self.beverages[sel-1].name))
        print("남은 수량 : {} ".format(self.beverages[sel-1].count))
        print("남은 금액 : {}".format(self.consumer_money))

    def return_consumer_money(self):
        consumer_money = self.consumer_money

        paper_1000 = consumer_money // 1000

        if paper_1000 > self.paper_1000:
            paper_1000 = self.paper_1000

        consumer_money -= paper_1000 * 1000

        coin_500 = consumer_money // 500

        if coin_500 > self.coin_500:
            coin_500 = self.coin_500
        consumer_money -= coin_500 * 500

        coin_100 = consumer_money // 100

        if coin_100 > self.coin_100:
            coin_100 = self.coin_100
        consumer_money -= coin_100 * 100

        if consumer_money > 0:
            print("잔돈이 부족합니다. 관리자에게 문의해주세요.")
            return

        self.consumer_money = 0
        self.paper_1000 -= paper_1000
        self.coin_500 -= coin_500
        self.coin_100 -= coin_100

        print("1000원 지폐 {}장, 500원 동전 {}개, 100원 동전 {}개가 반환되었습니다.".format(paper_1000, coin_500, coin_100))

def printConsunerMenu():
    print("1. 금액 추가")
    print("2. 음료 구매")
    print("3. 거스름돈 반환")
    print("0. 종료")

def printAdminMenu():
    print("1. 음료수 개수 추가")
    print("2. 음료수 변경")
    print("3. 거스름돈 추가")
    print("0. 종료")
def consumerMode():
    while True:
        printConsunerMenu()
        sel = int(input("> "))

        if sel == 1:
            machine.input_money()
        elif sel == 2:
            machine.buy_beverage()
        elif sel == 3:
            machine.return_consumer_money()
        elif sel == 0:
            break
        else:
            print("잘못 선택하였습니다.")
            continue

def adminMode():
    while True:
        printAdminMenu()
        sel = int(input("> "))

        if sel == 1:
            machine.add_beverage()

        elif sel == 2:
            machine.change_beverage()

        elif sel == 3:
            paper_1000 = int(input("투입할 1000원의 개수:"))
            coin_500 = int(input("투입할 500원의 개수:"))
            coin_100 = int(input("투입할 100원의 개수:"))
            machine.paper_1000 += paper_1000
            machine.coin_500 += coin_500
            machine.coin_100 += coin_100
            print("추가된 금액: {}원".format(paper_1000 * 1000 + coin_500 * 500 + coin_100 * 100))

        elif sel == 0:
            break
        else:
            print("잘못 선택하였습니다.")
            continue


machine = VendingMachine("한국공학대학교 5층 자판기")

while True:
    print("1. 관리자 모드")
    print("2. 소비자 모드")
    print("0. 종료")
    sel = int(input("> "))

    if sel == 1:
        adminMode()
    elif sel == 2:
        consumerMode()
    elif sel == 0:
        break
    else:
        print("잘못 선택하였습니다.")
        continue


print("이용해 주셔서 감사합니다.")