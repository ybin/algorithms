TOPDIR=.
SRCDIR=$(TOPDIR)/src
INCLUDEDIR=$(SRCDIR)/include
OUTDIR=$(TOPDIR)/bin
TESTDIR=$(TOPDIR)/test
TARGET=algorithms
TEST=test


CC=tcc.exe
SHAREDFLAG=-shared
CFLAGS=-I$(INCLUDEDIR)

###### library, the default target
SOURCES:=$(wildcard $(SRCDIR)/*.c)
OBJECTS:=$(SOURCES:$(SRCDIR)/%.c=$(OUTDIR)/%.o)

.PHONEY: $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) -o $(OUTDIR)/$(TARGET).dll $^ $(SHAREDFLAG) $(CFLAGS)

$(OBJECTS) : $(OUTDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)


###### test
TESTSRCS=$(wildcard $(TESTDIR)/*.c)
TESTOBJS=$(TESTSRCS:$(TESTDIR)/%.c=$(TESTDIR)/%.o)
TESTLIB=$(TARGET)
DLLDEF=$(OUTDIR)/$(TARGET).def

.PHONEY: $(TEST)
$(TEST) : $(TESTOBJS) $(DLLDEF)
	$(CC) -o $(OUTDIR)/$(TEST).exe $^ $(CFLAGS)

$(TESTOBJS) : $(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(DLLDEF) : $(TARGET)
	tiny_impdef -o $@ $(OUTDIR)/$(TARGET).dll

.PHONEY: run_test
run_test : $(TEST)
	$(OUTDIR)/$(TEST).exe

.PHONEY: clean
clean:
	rm -f bin/*
