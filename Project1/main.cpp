#include "List.hpp"
#include "Build.hpp"

template<typename T>
concept check = requires(T a) {
	a.test();
};

template<check T, typename U>
void Push_list(T* obj, NodeList<U>& list) {
	
		list.PushBack(obj);
	
}

int main(){
	
	NodeList<Test*> Testlist;

	std::string str;
	std::cin >> str;

	IsdigitSimple* a = new IsdigitSimple();
	IsdigitEven* b = new IsdigitEven();
	//Testlist.PushBack(a);
	//Testlist.PushBack(b);

	Push_list(a, Testlist);
	Push_list(b, Testlist);
	

	for (auto it = Testlist.begin(); it != Testlist.end(); ++it) {
	    auto k = *it;
		if (k->Proverka(str)) std::cout << 1;
		else k->showError();
		std::cout<<"\n";
	}
	std::cout << "\n";
	for (auto it = Testlist.cbegin(); it != Testlist.cend(); ++it) {
		auto unit = *it;
		if (unit->Proverka(str)) std::cout << 1;
		else unit->showError();
		
		std::cout <<std::endl;
	}
	


	
	
	return 0;
}