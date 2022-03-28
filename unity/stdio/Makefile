UNITY := ${HOME}/workspace/Unity

CFLAGS := -I${UNITY}/src
LDFLAGS := -lunity -L${UNITY}/build/src/

sprintftest: SprintfTest.c
	$(CC) -g -Wall ${CFLAGS} -o sprintftest SprintfTest.c ${LDFLAGS}

test: sprintftest
	./sprintftest
