way:	objects library stackApp

CC     = gcc
SRCDIR = ../src
HDRDIR = ../inc
OBJDIR = ../obj
BINDIR = ../bin
LIBDIR = ../lib

REMOVE := rm -rf

stackApp:
	@mkdir -p $(BINDIR)
	$(CC) -I $(HDRDIR) $(SRCDIR)/stackApp.c $(LIBDIR)/libstack.a -o \
		$(BINDIR)/stackApp

objects:
	@mkdir -p $(OBJDIR)
	$(CC) -c -I $(HDRDIR) $(SRCDIR)/stackop.c -o $(OBJDIR)/stackop.o
	$(CC) -c -I $(HDRDIR) $(SRCDIR)/stackcheck.c -o $(OBJDIR)/stackcheck.o

library:
	@mkdir -p $(LIBDIR)
	ar rcs $(LIBDIR)/libstack.a $(OBJDIR)/stackop.o $(OBJDIR)/stackcheck.o

.PHONY:	clean
clean:
	$(REMOVE) $(OBJDIR) $(LIBDIR) $(BINDIR)
