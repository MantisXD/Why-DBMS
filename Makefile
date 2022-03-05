CC = g++
CFLAGS = -W -O2 -std=c++11
LDFLAGS =
TARGET = project1 
SRC_DIR = ./

SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cc))
OBJS = $(SRCS:.cc=.o)

%.o : $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET) *.d