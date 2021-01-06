
TARGET=mapa area

all: $(TARGET)

clean:
	$(RM) $(TARGET)

test: $(TARGET)
	for N in `seq 1 10`; do \
		echo $${RANDOM}"\n"\# | cat localitzacio.csv registre-covid.csv - | ./mapa | ./area ; \
	done

test1: mapa
	echo $${RANDOM}"\n"\# | cat localitzacio.csv registre-covid.csv - | ./mapa ; \
