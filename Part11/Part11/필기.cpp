/*
디폴트 대입 연산자는 얕은 복사을 함 -> 메모리 동적할당 할때 문제가 됨

복사 생성자의 특징 : 정의하지 않으면 디폴트 복사 생성자가 삽입, 얕은 복사, 깊은 복사가 필요하다면 직접 정의해야함. 

대입 연산자의 특징 : 정의하지 않으면 디폴트 대입 연산자가 삽입, 얕은 복사, 깊은 복사가 필요하다면 직접 정의해야함.

배열의 인덱스 연산자 오버로딩

C와 C++의 기본배열의 단점은 경계검사를 하지 않음 -> A[3]으로 선언해도 A[-1]에 접근가능

static이 붙어있는 멤버함수는 객체와 상관없고 클래스하고만 상관이 있음.

Smart Pointer -> 자기 스스로 하는 일이 존재하는 포인터

유니크(Unique) 포인터 -> 객체마다 하나씩 포인터가 할당됨

쉐어드(Shared) 포인터 -> 객체 하나에 여러개의 포인터가 할당 가능.

두 개다 우리가 직접 할당해줄 필요도 없고 해제 해줄 필요도 없음.

shared_ptr<AAA>에서 <> 부분은 템플릿이라고 하며, 완벽한 다형성을 제공하기 위해 사용함. <> 안의 값은 자료형이 들어감.

Functor - ()연산자를 이용해서 객체를 함수처럼 쓰는걸 의미, 함수 오브젝터

*/