PROJ := sortieren
OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))

all: $(OBJECTS)
	gcc $(OBJECTS) -o $(PROJ)
	
$(OBJECTS):
	gcc -c *.c -std=c99
	
run: all
	./$(PROJ)
	
clean:
	@rm *.o $(PROJ)