all : build



build: lib/scalar.a lib/matrix.so src/main.cpp src/exceptions.cpp src/log.cpp src/Matrix.cpp src/Scalar.cpp 
	mkdir -p bin
	mkdir -p build
	g++ src/*.cpp -o ./bin/main.exe -L ./lib/scalar.a ./lib/matrix.so  -I ./include

lib/scalar.a : build/main.o build/exceptions.o build/log.o build/Matrix.o build/Scalar.o include/logger.h include/Scalar.h include/Matrix.h
	mkdir -p lib
	ar rcs ./lib/scalar.a ./build/main.o
	ar rcs ./lib/scalar.a ./build/exceptions.o
	ar rcs ./lib/scalar.a ./build/log.o
	ar rcs ./lib/scalar.a ./build/Scalar.o
	ar rcs ./lib/scalar.a ./include/logger.h
	ar rcs ./lib/scalar.a ./include/Scalar.h
	g++ -fPIC ./include/logger.h -o ./lib/matrix.so
	g++ -fPIC ./include/Matrix.h -o ./lib/matrix.so
	g++ -fPIC ./src/*.cpp -o ./lib/matrix.so

build/main.o : src/main.cpp src/exceptions.cpp src/log.cpp src/Matrix.cpp src/Scalar.cpp
	mkdir -p build
	g++ -c ./src/main.cpp  -o ./build/main.o
	g++ -c ./src/exceptions.cpp  -o ./build/exceptions.o
	g++ -c ./src/log.cpp  -o ./build/log.o
	g++ -c ./src/Matrix.cpp  -o ./build/Matrix.o
	g++ -c ./src/Scalar.cpp  -o ./build/Scalar.o

libs: build/main.o build/exceptions.o build/log.o build/Matrix.o build/Scalar.o include/logger.h include/Scalar.h include/Matrix.h
	mkdir -p lib
	ar rcs ./lib/scalar.a ./build/main.o
	ar rcs ./lib/scalar.a ./build/exceptions.o
	ar rcs ./lib/scalar.a ./build/log.o
	ar rcs ./lib/scalar.a ./build/Scalar.o
	ar rcs ./lib/scalar.a ./include/logger.h
	ar rcs ./lib/scalar.a ./include/Scalar.h
	g++ -fPIC ./include/logger.h -o ./lib/matrix.so
	g++ -fPIC ./include/Matrix.h -o ./lib/matrix.so
	g++ -fPIC ./src/*.cpp -o ./lib/matrix.so
	

run:
	./bin/main.exe TO 


test1: 
	./bin/main.exe -a < ./tests/test1.in > ./tests/test1.out
	cmp -s ./tests/test1.out ./tests/test1.exp; \
	flag=$$?; \
	if [$$flag -eq 0]; then \
		echo "TEST1 Passed"; \
	else
		echo "TEST1 Failed"; \
	fi
test2: 
	./bin/main.exe -a < ./tests/test2.in > ./tests/test2.out
	cmp -s ./tests/test2.out ./tests/test2.exp; \
	flag=$$?; \
	if [$$flag -eq 0]; then \
		echo "TEST2 Passed"; \
	else
		echo "TEST2 Failed"; \
	fi

test3: 
	./bin/main.exe -a < ./tests/test3.in > ./tests/test3.out
	cmp -s ./tests/test3.out ./tests/test3.exp; \
	flag=$$?; \
	if [$$flag -eq 0]; then \
		echo "TEST3 Passed"; \
	else
		echo "TEST3 Failed"; \
	fi

test4: 
	./bin/main.exe -a < ./tests/test4.in > ./tests/test4.out
	cmp -s ./tests/test4.out ./tests/test4.exp; \
	flag=$$?; \
	if [$$flag -eq 0]; then \
		echo "TEST4 Passed"; \
	else
		echo "TEST4 Failed"; \
	fi

test5: 
	./bin/main.exe -a < ./tests/test5.in > ./tests/test5.out
	cmp -s ./tests/test5.out ./tests/test5.exp; \
	flag=$$?; \
	if [$$flag -eq 0]; then \
		echo "TEST4 Passed"; \
	else
		echo "TEST4 Failed"; \
	fi

tests:
	for FILE in ./tests/*
	do
		./bin/main.exe -a < FILE > ./tests/${FILE}.out; \
		cmp -s ./tests/${FILE}.out ./tests/${FILE}.exp; \
		flag=$$?; \
		if [$$flag -eq 0]; then \
			echo "${FILE} Passed"; \
		else
			echo "${FILE} Failed"; \
		fi
	done
clean:
	rm -rf build bin lib
