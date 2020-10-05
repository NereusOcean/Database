
Play: src/Cell.o src/Field.o src/Print.o src/main.o
	g++ -o Play src/Cell.o src/Field.o src/Print.o src/main.o
cpp/Cell.o: src/Cell.cpp h/Cell.h
	g++ -c src/Cell.cpp -o src/Cell.o 
cpp/Field.o: src/Field.cpp h/Field.h h/Cell.h
	g++ -c src/Field.cpp -o src/Field.o
cpp/My_print.o: src/Print.cpp h/Print.h h/Field.h
	g++ -c src/Print.cpp -o src/My_print.o
cpp/main.o: src/main.cpp h/Field.h h/Print.h
	g++ -c src/main.cpp -o src/main.o	  
clean:
	rm -rf src/*.o Play
