TARGET= a.out
OBJECTS=main.o include/coureur.o include/liste.o
CFLAGS= -Wall

default : main

all : main

run: main
	echo "Starting Program Execution..."
	./$(TARGET)
	make clean
	
clean :
	rm -f *.o
	rm -f $(TARGET)
	rm -f ./include/*.o
	
%.o : %.c
	gcc -c $< -o $@

main : $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(TARGET)
