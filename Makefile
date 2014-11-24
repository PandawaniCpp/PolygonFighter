
NAME=polygonshooter

SOURCE_DIRECTORY=PolygonShooter

COMPILER_CC_FLAGS=-c -Wall
COMPILER_CPP_FLAGS=-c -Wall -std=c++11 -pedantic -IPolygonShooter/SFML-2.1/include -IPolygonShooter/Box2D/include
COMPILER_NV_FLAGS=-c -Wall
LIBS=-lsfml-system -lsfml-graphics -lsfml-window

COMPILER_CC=gcc
COMPILER_CPP=g++
COMPILER_NV=nvcc

LINKER=g++

SYSTEM_EXTENSION=

ifeq ($(strip $(shell uname | grep MINGW)),)
SYSTEM_TYPE=linux
else
SYSTEM_TYPE=windows
endif

ifeq ($(strip $(shell $(COMPILER_CC) -dumpmachine | grep x86_64)),)
MACHINE_TYPE=32
else
MACHINE_TYPE=64
endif

SYSTEM=$(SYSTEM_TYPE)$(MACHINE_TYPE)

LINKER_FLAGS=-Llib/$(SYSTEM) $(LIBS)

SOURCES=$(shell find $(SOURCE_DIRECTORY) -maxdepth 3 -type f -name "*.c" -or -name "*.cpp" -or -name "*.cu")

OUTPUT=bin/$(SYSTEM)/$(NAME)
OBJECT_DIRECTORY=make/$(SYSTEM)

OBJECTS_CC=$(filter %.c,$(SOURCES))
OBJECTS_CPP=$(filter %.cpp,$(SOURCES))
OBJECTS_NV=$(filter %.cu,$(SOURCES))

OBJECTS=$(OBJECTS_CC:%.c=%.c.o)
OBJECTS+=$(OBJECTS_CPP:%.cpp=%.cpp.o)
OBJECTS+=$(OBJECTS_NV:%.cu=%.cu.o)
OBJECTS2=$(OBJECTS:%=$(OBJECT_DIRECTORY)/%)

all: prsys $(OUTPUT)
	mkdir -p $(OBJECT_DIRECTORY)

prsys:
	echo Building for $(SYSTEM).

re: rmoutput $(OUTPUT)

rmoutput:
	rm -f $(OUTPUT)

clear:
	rm -f $(OUTPUT)
	find make -name "*.o" -delete

$(OUTPUT): $(OBJECTS2)

	echo "$@..."
	mkdir -p $(shell dirname $@)
	$(LINKER) $(OBJECTS2) $(LINKER_FLAGS) -o $@

$(OBJECT_DIRECTORY)/%.c.o: %.c
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_CC) $(COMPILER_CC_FLAGS) -M -MM -MT $@ $< > make/tmp.mk
	echo "	$(COMPILER_CC) $(COMPILER_CC_FLAGS) $< -o $@" >> make/tmp.mk
	make -f make/tmp.mk

$(OBJECT_DIRECTORY)/%.cpp.o: %.cpp
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_CPP) $(COMPILER_CPP_FLAGS) -M -MM -MT $@ $< > make/tmp.mk
	echo "	$(COMPILER_CPP) $(COMPILER_CPP_FLAGS) $< -o $@" >> make/tmp.mk
	make -f make/tmp.mk

$(OBJECT_DIRECTORY)/%.cu.o: %.cu
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_NV) $(COMPILER_NV_FLAGS) -M -MM -MT $@ $< > make/tmp.mk
	echo "	$(COMPILER_NV) $(COMPILER_NV_FLAGS) $< -o $@" >> make/tmp.mk
	make -f make/tmp.mk
