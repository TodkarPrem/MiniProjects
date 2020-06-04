CC = gcc
SRCDIR = ../src
BINDIR = ../bin
HDRDIR = ../inc
REMOVE = rm -rf

outfile:
	@mkdir -p $(BINDIR)
	$(CC) -I $(HDRDIR) $(wildcard $(SRCDIR)/*.c) -o $(BINDIR)/outfile

.PHONY:	clean
clean:
	$(REMOVE) $(BINDIR)
