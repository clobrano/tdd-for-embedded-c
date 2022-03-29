UNITY := ${HOME}/workspace/me/Unity

lib := libleddriver.a
lib_src := $(wildcard *.c) 
lib_obj := $(lib_src:%.c=%.o) 

test_srcs := $(wildcard tests/*.c)
test_obj := testrunner
CFLAGS := -I${UNITY}/src
LDFLAGS := -lunity -L${UNITY}/build/src/

${lib_obj}: ${lib_src}
	$(CC) -g -Wall -o $@ -c $<

${lib}: ${lib_obj}
	ar -rcs $@ $^

test: ${test_srcs} ${lib}
	$(CC) -g -Wall ${CFLAGS} -o ${test_obj} $< ${lib} ${LDFLAGS}  
	./${test_obj}

unittest:
	if command -v raffaello >/dev/null;\
	then 	ls * | entr $(MAKE) test 2>&1 | raffaello -r "OK=>green_bold FAIL=>red_bold"; \
	else ls * | entr $(MAKE) test; \
	fi

clean: 
	-rm ${lib}
	-rm ${test_obj}
	-rm ${lib_obj}
