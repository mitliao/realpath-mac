BIN=realpath

${BIN}: realpath.c
	gcc -Wall -o $@ $^

install:
	cp -f ${BIN} /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/${BIN}

clean:
	rm -f ${BIN}
