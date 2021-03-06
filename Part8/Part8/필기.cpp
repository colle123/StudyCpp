/*객체 포인터 변수 = 일반 포인터와 똑같음

함수 오버로딩 - 함수 이름은 같고 함수 매개변수의 자료형이나 개수가 다름

함수 오버라이딩 - 상속관계에서 동일한 이름과 동일한 형태가 와야함 - 재정의와 비슷

기초 클래스와 동일한 이름의 함수를 유도 클래스에서 정의한다고 해서 무조건 함수 오버라이딩이 되는 것은 아니고
매개변수의 자료형 및 개수가 다르면 이는 함수 오버로딩이 되어, 전달되는 인자에 따라서 호출되는 함수가 결정된다.

가상함수(★)

객체지향언어에서 중요한건 '객체' -> 객체포인터를 사용하면 객체포인터를 기준으로 객체에 접근하게 됨

그래서 객체를 기준으로 접근하는게 필요 -> '가상함수'를 사용

C++ 컴파일러는 포인터 연산의 가능성 여부를 판단할 때, 포인터의 자료형을 기준으로 판단, 실제 가리키는 객체의 자료형을 기준으로 판단

가상함수 -> virtual을 이용해서 상속받은 유도클래스의 오버라이딩 된 함수를 사용가능. virtual을 붙여준 함수를 사용할땐 범위스코프(Base::func1())를 써서 사용하면 됨.

virtual로 가상함수가 선언되면 이 함수를 오버라이딩 하는 함수도 가상함수가 됨

순수 가상함수와 추상 클래스

지금은 필요없지만 언젠가 상속받은 클래스가 멤버함수의 기능을 필요로 할 것이라 생각해서 만든 것
-> Virtual로 선언되어 만들어있지만 내용은 없는 것 = 순수 가상함수

순수 가상함수가 하나 이상의 멤버함수를 포함한 클래스를 추상 클래스(abstract class)라고 함.

순수 가상함수의 정확한 초기화는 비어두는게 아니라 0을 대입해서 넣어둬야함.

virtual void ShowSalaryInfo() const { } 가 아니라 virtual void ShowSalaryInfo() const = 0;으로 표현해야 함

다형성(★, Polymorphism) - 모습은 같은데 형태는 다름, 문장은 같은데 결과는 다름.
*/