all:
	sh scripts/stags.sh
	stanza compile src/*.stanza -ccfiles src/curl.c -pkg pkgs
install:
	stanza compile t/test010-simple.stanza -ccfiles src/curl.c -ccflags -lcurl -o bin/testbin
	./bin/testbin
