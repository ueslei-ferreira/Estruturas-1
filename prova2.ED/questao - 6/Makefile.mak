CPP    = g++
RM     = rm -f
OBJS   = NovoArquivo.o

LIBS   =
CFLAGS =

.PHONY: 1q_pierre.exe clean clean-after

all: 1q_pierre.exe

clean:
	$(RM) $(OBJS) 1q_pierre.exe

clean-after:
	$(RM) $(OBJS)

1q_pierre.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

NovoArquivo.o: NovoArquivo.c
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

