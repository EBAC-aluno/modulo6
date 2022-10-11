.PHONY: clean

CC := cc -std=c99
BUILDDIR := ./build
SRCDIR := ./src
TARGET := ./bin
SRCOBJ := $(BUILDDIR)/inputValidator.o $(BUILDDIR)/rootsCalculator.o \
	  $(BUILDDIR)/printer.o $(BUILDDIR)/quadraticFormulaUtils.o

# compile the program 
all: quadraticFormula.out

quadraticFormula.out: $(TARGET) quadraticFormula.o 
	$(CC) -o $(TARGET)/quadraticFormula.out $(BUILDDIR)/quadraticFormula.o $(SRCOBJ) -lm
	
# build the program 
quadraticFormula.o: $(BUILDDIR) inputValidator.o rootsCalculator.o printer.o quadraticFormulaUtils.o
	$(CC) -c -o $(BUILDDIR)/quadraticFormula.o $(SRCDIR)/quadraticFormula.c

inputValidator.o: $(BUILDDIR) 
	$(CC) -c -o $(BUILDDIR)/inputValidator.o $(SRCDIR)/inputValidator.c

rootsCalculator.o: $(BUILDDIR) 
	$(CC) -c -o $(BUILDDIR)/rootsCalculator.o $(SRCDIR)/rootsCalculator.c

printer.o: $(BUILDDIR) 
	$(CC) -c -o $(BUILDDIR)/printer.o $(SRCDIR)/printer.c

quadraticFormulaUtils.o: $(BUILDDIR) 
	$(CC) -c -o $(BUILDDIR)/quadraticFormulaUtils.o $(SRCDIR)/quadraticFormulaUtils.c

# create the folders
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET):
	mkdir -p $(TARGET)

run:
	$(TARGET)/quadraticFormula.out -a -2 -b 20.0 -c -50.0

# remove the binary files
clean:
	rm -rf $(TARGET)
	rm -rf $(BUILDDIR)
