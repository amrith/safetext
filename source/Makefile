CC=gcc

CFLAGS=-g
LDFLAGS=-g
LD=ld
RM=rm

SRCS=make-codebook.c base64codec.c test-codec.c codebook.c safeencode.c safedecode.c test-safetext.c safecodec.c

OBJS=$(SRCS:.c=.o)

BINARIES=make-codebook test-codec test-safetext safeencode safedecode

.c.o:
	${CC} ${CFLAGS} -c $<

allbinaries: $(BINARIES)

allobjs: $(OBJS)

make-codebook: make-codebook.o

test-codec: test-codec.o base64codec.o codebook.o

test-safetext: test-safetext.o safecodec.o codebook.o base64codec.o

codebook.c: make-codebook \
	codebook.in
	./make-codebook

safeencode: safeencode.o safecodec.o base64codec.o codebook.o

safedecode: safedecode.o safecodec.o base64codec.o codebook.o

tests: $(BINARIES)
	./test-codec
	./test-safetext

clean:
	rm -f $(OBJS) $(BINARIES) codebook.c

depend:
	makedepend -- $(CFLAGS) -- $(SRCS)
	$(RM) Makefile.bak
# DO NOT DELETE

make-codebook.o: /usr/include/stdlib.h /usr/include/features.h
make-codebook.o: /usr/include/stdc-predef.h /usr/include/alloca.h
make-codebook.o: /usr/include/stdio.h /usr/include/libio.h
make-codebook.o: /usr/include/_G_config.h /usr/include/wchar.h
make-codebook.o: /usr/include/time.h /usr/include/xlocale.h
make-codebook.o: /usr/include/string.h /usr/include/assert.h codebook.h
base64codec.o: /usr/include/stdio.h /usr/include/features.h
base64codec.o: /usr/include/stdc-predef.h /usr/include/libio.h
base64codec.o: /usr/include/_G_config.h /usr/include/wchar.h
base64codec.o: /usr/include/stdint.h /usr/include/assert.h
base64codec.o: /usr/include/string.h /usr/include/xlocale.h codebook.h
base64codec.o: base64codec.h
test-codec.o: codebook.h base64codec.h /usr/include/stdio.h
test-codec.o: /usr/include/features.h /usr/include/stdc-predef.h
test-codec.o: /usr/include/libio.h /usr/include/_G_config.h
test-codec.o: /usr/include/wchar.h /usr/include/stdlib.h
test-codec.o: /usr/include/alloca.h /usr/include/string.h
test-codec.o: /usr/include/xlocale.h /usr/include/unistd.h
test-codec.o: /usr/include/getopt.h /usr/include/assert.h
codebook.o: /usr/include/stdio.h /usr/include/features.h
codebook.o: /usr/include/stdc-predef.h /usr/include/libio.h
codebook.o: /usr/include/_G_config.h /usr/include/wchar.h
codebook.o: /usr/include/stdlib.h /usr/include/alloca.h codebook.h
safeencode.o: safecodec.h /usr/include/stdio.h /usr/include/features.h
safeencode.o: /usr/include/stdc-predef.h /usr/include/libio.h
safeencode.o: /usr/include/_G_config.h /usr/include/wchar.h
safeencode.o: /usr/include/stdlib.h /usr/include/alloca.h
safeencode.o: /usr/include/string.h /usr/include/xlocale.h
safeencode.o: /usr/include/unistd.h /usr/include/getopt.h
safedecode.o: safecodec.h /usr/include/stdio.h /usr/include/features.h
safedecode.o: /usr/include/stdc-predef.h /usr/include/libio.h
safedecode.o: /usr/include/_G_config.h /usr/include/wchar.h
safedecode.o: /usr/include/stdlib.h /usr/include/alloca.h
safedecode.o: /usr/include/string.h /usr/include/xlocale.h
test-safetext.o: safecodec.h /usr/include/stdio.h /usr/include/features.h
test-safetext.o: /usr/include/stdc-predef.h /usr/include/libio.h
test-safetext.o: /usr/include/_G_config.h /usr/include/wchar.h
test-safetext.o: /usr/include/stdlib.h /usr/include/alloca.h
test-safetext.o: /usr/include/string.h /usr/include/xlocale.h
test-safetext.o: /usr/include/unistd.h /usr/include/getopt.h
test-safetext.o: /usr/include/assert.h
safecodec.o: base64codec.h codebook.h /usr/include/stdint.h
safecodec.o: /usr/include/features.h /usr/include/stdc-predef.h
safecodec.o: /usr/include/stdlib.h /usr/include/alloca.h /usr/include/stdio.h
safecodec.o: /usr/include/libio.h /usr/include/_G_config.h
safecodec.o: /usr/include/wchar.h /usr/include/string.h
safecodec.o: /usr/include/xlocale.h /usr/include/assert.h safecodec.h
