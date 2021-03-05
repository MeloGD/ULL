TARGET = main
SRC = src
INC = include
BIN = bin

SOURCE = $(wildcard $(SRC)/*.cc)
OBJECT = $(patsubst %,$(BIN)/%, $(notdir $(SOURCE:.cc=.o)))

CC = g++
CFLAGS = -Wall -std=c++14 -I$(INC)

$(BIN)/$(TARGET) : $(OBJECT)
	$(CC) -o $@ $^

$(BIN)/%.o : $(SRC)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY :: help run clean

run : $(BIN)/$(TARGET)
		$(BIN)/$(TARGET)

clean :
	rm -f $(OBJECT) $(BIN)/$(TARGET)


help : 
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
