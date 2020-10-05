#include "../h/Field.h"
#include "../h/Print.h"
#include <iostream>
int main(){
	int x = 6;
	int y = 6;
	Field* Level1 = Field::GetInstanceOfField(x,y);
	Field* Level2 = Field::GetInstanceOfField(x,y);
	std::cout<<Level1<<"\n";
	std::cout<<Level2<<"\n";
	Print p;
	p.print(*Level1);
	p.print(*Level2);
	return 0;
}
