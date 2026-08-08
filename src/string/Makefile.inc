SRCS+=	bcopy.c index.c memcpy.c memmove.c rindex.c strchr.c strchrnul.c strcmp.c strncmp.c \
	strlen.c strnlen.c strrchr.c

MAN+=	bcopy.3 index.3 memcpy.3 memmove.3 rindex.3 strchr.c strcmp.3 strlen.3 strrchr.3

MLINKS+= strchr.3 strchrnul.3
MLINKS+= strcmp.3 strncmp.3
MLINKS+= strlen.3 strnlen.3
