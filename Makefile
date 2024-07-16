# Compiler and Output
CC = g++
OUT = main

# Directories
ODIR = ./obj
SDIR = ./src
OUTDIR = ./bin

# Include and Library Directories
IDIR_WIN = C:/Users/Daniel/OneDrive/Documents/libraries/SFML-2.6.1/include
LDIR_WIN = C:/Users/Daniel/OneDrive/Documents/libraries/SFML-2.6.1/lib
IDIR_MAC = /path/to/SFML/include
LDIR_MAC = /path/to/SFML/lib

# Libraries
LIBS_WIN = -lsfml-graphics -lsfml-window -lsfml-system
LIBS_MAC = -lsfml-graphics -lsfml-window -lsfml-system

# Detect OS
ifeq ($(OS),Windows_NT)
    IDIR = $(IDIR_WIN)
    LDIR = $(LDIR_WIN)
    LIBS = $(LIBS_WIN)
    MKDIR = mkdir
    RMDIR = rmdir /S /Q
    EXE = .exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        IDIR = $(IDIR_MAC)
        LDIR = $(LDIR_MAC)
        LIBS = $(LIBS_MAC)
        MKDIR = mkdir -p
        RMDIR = rm -rf
        EXE =
    endif
endif

# Object files
OBJS = $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(wildcard $(SDIR)/*.cpp))

# Rules
$(ODIR)/%.o : $(SDIR)/%.cpp
	$(CC) -c -I$(IDIR) -o $@ $^

$(OUTDIR)/$(OUT)$(EXE) : $(OBJS)
	$(MKDIR) $(OUTDIR)
	$(CC) -L$(LDIR) -o $@ $^ $(LIBS)

.PHONY : clean run

clean:
	$(RMDIR) $(ODIR) $(OUTDIR)

run : $(OUTDIR)/$(OUT)$(EXE)
	$(OUTDIR)/$(OUT)$(EXE)

# Create the obj directory if it doesn't exist
$(ODIR):
	$(MKDIR) $(ODIR)

# Make sure obj directory is created before compiling objects
all: $(ODIR) $(OUTDIR)/$(OUT)$(EXE)
