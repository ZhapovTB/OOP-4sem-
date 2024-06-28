#include "List.hpp"
#include "Build.hpp"

int main(){
	
	NodeList<Builder*> list;
	AndroidBuilder* k = new AndroidBuilder();
	IosBuilder* i = new IosBuilder();
	list.PushBack(k);
	list.PushBack(i);


	for (auto it = list.begin(); it != list.end(); ++it) {
	    auto k = *it;
		k->build();
		std::cout<<"\n";
	}

	for (auto it = list.cbegin(); it != list.cend(); ++it) {
		auto unit = *it;
		unit->build();
		std::cout <<std::endl;
	}
	


	
	
	return 0;
}