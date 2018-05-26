### 2016
1. Зачем нужен виртуальный декструктор, когда оправдано его использование?
1. Можно ли в наследнике получить доступ к private полям базового класса?
1. Проект состоит из нескольких source-файлов (.cpp), в каждом из которых используется некоторая целочисленная константа `maxIterationCount`. Как правильно определить эту константу?
1. Для чего нужны статические виртуальные методы?
1. Зависит ли размер структуры от порядка объявления ее полей? Если да, то приведите примеры.
1. Можно ли сделать конструктор виртуальным?
1. Что выведет программа ниже?
	```C++
	#include <iostream>

	using namespace std;

	class CHuman {

	public:
		CHuman()
		{
			cout << "Human" << endl;
		}
		~CHuman()
		{
			cout << "~Human" << endl;
		}
	};

	class CStudent : public CHuman {

	public:
		CStudent()
		{
			cout << "CStudent" << endl;
		}
		~CStudent()
		{
			cout << "~CStudent" << endl;
		}
	};

	int main()
	{
		CStudent student;
		{
			CStudent& refToStud = student;
			cout << "inBlock" << endl;
		}
		cout << "outBlock" << endl;
		return 0;
	}
	```
1. В чем разница между `const A* p`, `A* const p`, `const A* const p`?
1. Зачем нужно ключевое слово `static` в C++?
1. Почему считается, что виртуальные методы медленнее невиртуальных?
1. Зачем нужно виртуальное наследование?
1. Как может быть использовано приватное наследование?
1. При каких условиях компилятор генерирует конструктор и деструктор самостоятельно? Если класс определяет `operator =`, то какие методы класса необходимо определить и почему?
1. Зачем нужны умные указатели и какие примеры умных указателей есть в стандартной библиотеке?
1. Что выведется:
	```C++
	#include <iostream>
	#include <memory>

	class LoggedObject {
		LoggedObject() {
			log("Constructor");
		}

		virtual void log(const std::string& message) const = 0;
	};

	class ConsoleLoggedObject {

	public:
		virtual void log(const std::string& message) {
			std::cout << "Console: " << std::endl;
		}

	};

	int main() {
		ConsoleLoggedObject loggedObject;
		return 0;
	}
	```
1. Что получится в варианте 1 и в варианте 2?
	```C++
	#include <iostream>
	using namespace std;

	class A {
		int a; // (1)
		// char a; // (2)
	};

	class B : public A {
		char b;
	};

	int main() {
		cout << sizeof(B);
		return 0;
	}
	```
1. Какие конструкторы будут вызываться?
	```C++
	#include <iostream>

	class Token {
	public:
		explicit Token(int v) : val(v)
			{ std::cout << "Token()" << std::endl; }
		Token(const Token& t) : val(t.val)
			{ std::cout << "Token(const Token&)" << std::endl; }
		Token(Token&& t) : val(t.val)
			{ std::cout << "Token(Token&&)" << std::endl; }

	private:
		int val;
	};

	Token buildToken(int v) {
		return Token(v);
	}

	class Holder {
	public:
		explicit Holder(const Token t) :
			token(std::move(t))
		{}

	private:
		Token token;
	};

	int main() {
		Holder tokenHolder(buildToken(5));
		return 0;
	}
	```
