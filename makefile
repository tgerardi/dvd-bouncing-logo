IDIR = include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
BDIR = bin
LDIR = lib

LIBS = -lraylib -lm

_DEPS = dvd.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dvd.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR) $(BDIR):
	mkdir -p $@

$(ODIR)/%.o: src/%.c $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/dvd: $(OBJ) | $(BDIR)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: all clean install

all: $(BDIR)/dvd

clean:
	rm -rf bin/ $(ODIR)/*.o $(BDIR)/* *~ core $(IDIR)/*~

install: $(BDIR)/dvd
	sudo cp $(BDIR)/dvd /usr/local/bin/
	sudo chmod +x /usr/local/bin/dvd