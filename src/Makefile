CC=gcc
CCFLAGS=-Wall

C_DIR=./sources
H_DIR=./headers
OUT_DIR=../bin

HEADERS=$(H_DIR)/list.h $(H_DIR)/vec.h
SOURCES=$(C_DIR)/list.c $(C_DIR)/vec.c main.c
OBJ=$(OUT_DIR)/main.o $(OUT_DIR)/list.o $(OUT_DIR)/vec.o 

MKDIR_P = mkdir -p

all: directories $(OBJ)
	$(CC) $(CCFLAGS) -o $(OUT_DIR)/main $(OBJ)

# all: directories ${OUT_DIR}/list.o
# 	$(CC) $(CCFLAGS) -o $(OUT_DIR)/main main.c ${OUT_DIR}/list.o 

$(OUT_DIR)/main.o: main.c
	$(CC) $(CCFLAGS) -o $(OUT_DIR)/main.o -c main.c
 
$(OUT_DIR)/list.o: ${C_DIR}/list.c ${H_DIR}/list.h
	$(CC) $(CCFLAGS) -o $(OUT_DIR)/list.o -c $(C_DIR)/list.c

$(OUT_DIR)/vec.o: ${C_DIR}/vec.c ${H_DIR}/vec.h
	$(CC) $(CCFLAGS) -o $(OUT_DIR)/vec.o -c $(C_DIR)/vec.c


.PHONY: clean directories

directories: $(OUT_DIR)

$(OUT_DIR):
	$(MKDIR_P) $(OUT_DIR)

clean: 
	rm -rf $(OUT_DIR)/

run:
	$(OUT_DIR)/main
