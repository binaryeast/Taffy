태피
===

한글 사용자를 위한 컴파일 가능한 인터프리팅 언어


한마디로 완전한 비전공자 = 예술인을 위한 한글 프로그래밍 언어


ICU랑 이것저것 잘 살펴보고 일단 UTF-8로 작성하면, 

C언어 함수 호출해서 코드를 조합형으로 바꾸고, 조합형에서 자음 모음 읽어서
인터프리팅을 일단 하는 거지.

심지어 C나 파이썬으로 트랜스컴파일도 할 수 있게 만드는 거야.

조합형 파일이랑 원본 파일이랑 메타데이터랑 JIT용 바이트코드 같은 거 싸그리
모아서 압축해서 docx파일처럼 만드는 거야.

일단 파이썬 기반으로 해야지. 별 수가 없잖아?

한글에서 가장 중요한 문법적 특징이 있지.
어순과 체언생략, 어미변화.

그걸 최대한 활용해 보도록 하자.

그리고 타자를 고려해 비전공자용으로 만든 거니까, 특수문자와 괄호는 최대한 줄여.

세미콜론 빼. 필요 없어.

그리고 명령어 작명할 때 최소한 C랑 파이썬보다는 짧은 명령어 써라.
마침표랑 쉼표 같은 것도 좋은 명령어 되겠는데?


공격력 500.

실행코드와 저장코드로 구분? 문학적 프로그래밍?
마침표로 실행코드 - 함수와 클래스 등등

맹 코드는 변수 할당, 주석, 이것저것

레이어화&초매크로 : hyper가 단지 한글에서는 '초' 붙이면 되니까 초함수 등을 만든다.

같은 모음이나 자음 등을 활용한 변수 묶음? 클래스에다 메소드를 자음에 할당?

와 넘모 변태같다...

수식은 인용 기호 등을 붙이던가 해서 하자. > 이것도 괜찮고. 아니면 |> 이것도? -> 이것도?


기존 트랜스래이터는 트리 짜는데 순차적으로 명령어 뒤 변수나 함수 호출을 했지만 한글은...

OOP로 할 거야? 할 거야.



일단 조합형 완성형 구글링해서 C 코드랑 라이브러리들 다운받아야 해.

구분은 공백x4로. 최대한 파이썬으로 넘어가는 학습곡선이 부드럽게.

목표는 게임 제작용 스크립트 언어. 원한다면 C-like 언어로 트랜스컴파일 가능해야 함.

컴파일하면 걍 트랜스컴파일만 하자. 귀찮다.

인터프리팅 두 종류. 파이썬으로 트랜스컴파일 혹은 걍 스스로 돌아가는 인터프리터.

단계 도입. 

import는 부름.

일단 조사를 제외한 모든 걸 리스트로 만든 다음에 적당 적당히 명령어를 기준으로 자르고 처리하면 오히려 낫지 않나?

and	exec	not
assert	finally	or
break	for	pass
class	from	print
continue	global	raise
def	if	return
del	import	try
elif	in	while
else	is	with
except	lambda	yield


and or break for pass class from print continue global def if return del import try elif in while else is with except lambda

합 교  중단? for는_조사로 class&def도_조사로 에서 출력 다음 전역 라면 귀환 파괴 부름 ~(해)봐서 ~(라)면 ~의 ~동안 아니면 은/는/이/가 ~와 때워 람다

와 이거 제대로 해보면 대박이겠다.