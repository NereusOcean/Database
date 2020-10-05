#include "../h/Print.h"

void Print::print(Field& field){
	for(int i =0; i < field.getX();++i){
		for(int j = 0;j < field.getY();++j){
			std::cout<<field.getField()[i][j].get_state();		
		}	
		std::cout<<'\n';
	}
}


