
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

OBJECTS=$(SOURCES:%=$(OBJECT_DIRECTORY)/%.o)
DEPENDENCIES=$(SOURCES:%=$(OBJECT_DIRECTORY)/%.d)

-include $(DEPENDENCIES)

.PHONY: all prsys re rmourput clear

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
	find make -name "*.d" -delete

$(OUTPUT): $(OBJECTS)
	echo "$@..."
	mkdir -p $(shell dirname $@)
	$(LINKER) $(OBJECTS) $(LINKER_FLAGS) -o $@

$(OBJECT_DIRECTORY)/%.c.o: %.c
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_CC) $(COMPILER_CC_FLAGS) $< -o $@
	$(COMPILER_CC) $(COMPILER_CC_FLAGS) -M -MM -MT $(OBJECT_DIRECTORY)/$<.o $< > $(OBJECT_DIRECTORY)/$<.d

$(OBJECT_DIRECTORY)/%.cpp.o: %.cpp
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_CPP) $(COMPILER_CPP_FLAGS) $< -o $@
	$(COMPILER_CPP) $(COMPILER_CPP_FLAGS) -M -MM -MT $(OBJECT_DIRECTORY)/$<.o $< > $(OBJECT_DIRECTORY)/$<.d

$(OBJECT_DIRECTORY)/%.cu.o: %.cu
	echo "$<..."
	mkdir -p $(shell dirname $@)
	$(COMPILER_NV) $(COMPILER_NV_FLAGS) $< -o $@
	$(COMPILER_NV) $(COMPILER_NV_FLAGS) -M -MM -MT $(OBJECT_DIRECTORY)/$<.o $< > $(OBJECT_DIRECTORY)/$<.d
