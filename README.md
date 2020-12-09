[2020-2] 시스템프로그래밍 프로젝트
======================

# A. 프로젝트 명
## 가계부 프로그램

****

# B. 프로젝트 멤버 및 파트

* 20165014 컴퓨터공학과 권성민

> 전체적인 함수 구조 구성 \
 가계부 작성 함수 구현 \
 카테고리 설정 함수 구현

* 학번 학과 송기룡

> 자료 조사 및 발표 자료 작성 \
 가계부 계획 작성 함수 구현 \
 계획에 대한 피드백 제안 함수 구현
 
 ****

# C. 프로젝트 소개 및 개발 내용 소개
> 요즘은 밥을 먹거나, 쇼핑을 하거나 혹은 여러 소비가 있는 상황에서 간편결제를 많이 이용합니다.\
특히 코로나로 인터넷 쇼핑도 많아지고 그만큼 간편하게 결제하고 소비합니다.\
그러다보면 본인이 돈을 얼마나 어떻게 쓰는지 놓치기 쉽습니다.\
결제가 간편해진만큼 가계부를 이용하여 본인의 소비 내역을 확인할 필요가 있다고 느꼈습니다.\
그 느낌점을 가지고 프로젝트를 계획하게 되었습니다. \


이 프로그램은 가계부로써의 기본적인 기능들이 있습니다.
1. 본인의 소비 내역 작성하기
2. 본인이 작성한 내역 조회하기
3. 소비 계획 짜기
4. 소비 카테고리 설정하기.

****

# D. 다이어그램
![image](https://user-images.githubusercontent.com/73637543/101609825-c6122180-3a4a-11eb-9c6e-f0cd7fc65501.png)

****

# E. 실행 방법
## Makefile 실행
* 실행 파일 이름 : moneyBook.exe

```
$ make
$ ./moneyBook.exe
```

****

# F. 사용 방법
## ● write 기능
![image](https://user-images.githubusercontent.com/73637543/101611649-1db18c80-3a4d-11eb-871d-46f4da0f97dc.png)

1. option 메뉴에서 1. write를 선택합니다.
2. category 항목이 표시되고 date, category, money 순서로 입력합니다.
3. 엔터키를 누르면 저장이 완료됩니다.

## ● read 기능
### * TOTAL SPEND 기능
![image](https://user-images.githubusercontent.com/73637543/101612160-afb99500-3a4d-11eb-9835-1c21bb008d96.png)

1. option 메뉴에서 2. read를 선택합니다.
2. read option 메뉴에서 1. total spend를 선택합니다.
3. 본인이 적었던 지출내역을 확인할 수 있습니다.

### * ADVICE 기능
#### > plan을 미리 설정해둬야 사용할 수 있습니다.
![image](https://user-images.githubusercontent.com/73637543/101614050-ceb92680-3a4f-11eb-8c2c-d0996f5e5ac8.png)

1. option 메뉴에서 2. read를 선택합니다.
2. read option 메뉴에서 2. advice를 선택합니다.
3. 현재 총 얼마 썻는지 확인이 가능합니다. (*Total spend)
4. 세웠던 목표에서 돈을 얼마나 더 쓸 수 있는지 확인할 수 있습니다. (*목표까지 남은 금액)

## ● plan 기능
### * make plan 기능
![image](https://user-images.githubusercontent.com/73637543/101613517-315df280-3a4f-11eb-84ba-5aca0e9c74bb.png)

1. option 메뉴에서 3. plan을 선택합니다.
2. plan option 메뉴에서 1. make plan을 선택합니다.
3. date, money 순으로 작성합니다.

### * read plan 기능
![image](https://user-images.githubusercontent.com/73637543/101613748-797d1500-3a4f-11eb-981a-d6a201afcbab.png)

1. option 메뉴에서 3. plan을 선택합니다.
2. plan option 메뉴에서 2. read plan을 선택합니다.
3. 본인이 설정한 목표를 확인합니다.

## ● category setting 기능
### * add category 기능
![image](https://user-images.githubusercontent.com/73637543/101614480-5868f400-3a50-11eb-99ec-d58bd9d1898e.png)

1. option 메뉴에서 4. category setting을 선택합니다.
2. category option 메뉴에서 1. add category를 선택합니다.
3. "quit" 을 입력할 때 까지 추가할 수 있습니다.

### * sub category 기능
![image](https://user-images.githubusercontent.com/73637543/101614870-d0371e80-3a50-11eb-898c-8aef8bd4f85a.png)

1. option 메뉴에서 4. category setting을 선택합니다.
2. category option 메뉴에서 2.sub category를 선택합니다.
3. 지우고 싶은 카테고리를 하나 입력합니다.

#### 카테고리 목록에서 사라진 모습
![image](https://user-images.githubusercontent.com/73637543/101615050-06749e00-3a51-11eb-937f-2c6681d21b28.png)

****

# G. 개발 결과물의 필요성 및 활용방안

* 위에서도 말했듯이 소비가 쉽고 많아진 요즘에는 돈 관리는 필수적이라 할 수 있습니다. \
그래서 가계부 프로그램을 만들게 되었습니다.\
특히 소비, 지출에대해 무감각한 젋은 분들에게는 필요한 프로그램이라고 생각합니다.
결과적으로는 이 프로그램을 쓰는 분들에게는 본인만의 소비패턴이 확립되고 규칙적인 소비를 기대하고 있습니다.
