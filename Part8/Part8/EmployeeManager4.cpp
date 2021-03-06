#include <iostream>
#include <cstring>
using namespace std;

class Employee {

private:
	char name[100];

public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}

	void ShowYourName() const {

		cout << "name : " << name << endl;
	}

	virtual int GetPay() const { // 나중에 상속받은 클래스가 함수를 언젠가 필요할거라고 예상하고 미리 가상함수를 만들어 둠

		return 0;
	}

	virtual void ShowSalaryInfo() const { } // 나중에 상속받은 클래스가 함수를 언젠가 필요할거라고 예상하고 미리 가상함수를 만들어 둠
};

class PermanentWorker : public Employee {

private:
	int salary;

public:
	PermanentWorker(const char* name, int money) : Employee(name), salary(money) { }

	int GetPay() const {

		return salary;
	}

	void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;

	}
};

class TemporaryWorker : public Employee {

private:
	int workTime;
	int payPerHour;

public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }

	void AddWorkTime(int time) {

		workTime += time;

	}

	int GetPay() const {

		return workTime * payPerHour;
	}

	void ShowSalaryInfo() const {

		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;

	}
};

class SalesWorker : public PermanentWorker {

private:
	int salesResult;
	double bonusRatio;

public:
	SalesWorker(const char* name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }

	void AddSalesResult(int value) {

		salesResult += value;
	}

	int GetPay() const {

		// 부모의 함수 오버라이딩해서 불러올 때는 명시적으로 PermanentWorker::를 붙여줘야 함 
		return PermanentWorker::GetPay() + (int)(salesResult*bonusRatio);
	}

	void ShowSalryInfo() const {

		ShowYourName();
		cout << "salary : " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {

private:
	Employee* empList[50];
	int empNum;

public:
	EmployeeHandler() : empNum(0) { }
	void AddEmployee(Employee* emp) {

		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo() const {
		
		for(int i = 0 ; i < empNum ; i++)
		empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const {

		int sum = 0;
		
		for(int i = 0 ; i < empNum ; i++)
		sum += empList[i]->GetPay();

		cout << "salary sum : " << sum << endl;
	}

	~EmployeeHandler() {

		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {

	// 직원관리를 목적을 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;

	// 직원등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));


	// 임시직 등록
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// 영업직 등록
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();

	return 0;
}