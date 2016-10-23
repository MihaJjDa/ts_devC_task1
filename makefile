COMPILER = g++
SRCMODULES = longLongLong.cpp
OBJMODULES = $(SRCMODULES:.c=.o)
NAME = prog

%.o: %.cpp %.h
	$(COMPILER) $< -o $@

$(NAME): main.cpp $(OBJMODULES)
	$(COMPILER) $^ -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f *.o $(NAME)
