proFile: main.o recruitEmployee.o duplicateIdCheck.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o
	gcc -Wall -std=c99 -g main.o recruitEmployee.o duplicateIdCheck.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o -o bin/proFile

main.o: src/main.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/main.c

recruitEmployee.o: src/recruitEmployee.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/recruitEmployee.c

duplicateIdCheck.o: src/duplicateIdCheck.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/duplicateIdCheck.c

printAll.o: src/printAll.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/printAll.c

printOne.o: src/printOne.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/printOne.c

lookOnId.o: src/lookOnId.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/lookOnId.c

lookOnFullName.o: src/lookOnFullName.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/lookOnFullName.c

countEmployees.o: src/countEmployees.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/countEmployees.c

sortEmployeesId.o: src/sortEmployeesId.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/sortEmployeesId.c

fireOne.o: src/fireOne.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/fireOne.c

fireAll.o: src/fireAll.c include/functionHeaders.h
	gcc -Wall -std=c99 -c -g src/fireAll.c

clean:
	rm *.o
