# Makefile includes

-include includes.mk
-include sources.mk

# Nom du Programme

NAME 				=	tetris


# Colors

BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
ORANGE				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
LIGHT_GRAY			=	\033[0;37m
DARK_GRAY			=	\033[1;30m
LIGHT_RED			=	\033[1;31m
LIGHT_GREEN			=	\033[1;32m
YELLOW				=	\033[1;33m
LIGHT_BLUE			=	\033[1;34m
LIGHT_PURPLE		=	\033[1;35m
LIGHT_CYAN			=	\033[1;36m
WHITE				=	\033[1;37m
NO_COLOR			=	\033[0m

#	Compilation
GCC					=	gcc
FLAGS				=	-Wall -W -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
LDFLAGS				= 	`pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS				=	`pkg-config --libs-only-l MLV`


INCLUDES_PATH			=	./includes


OBJS				=	$(SOURCES:.c=.o)

#	Rules
all:	$(NAME)

#	Convertit les .c en .o
%.o:	%.c $(INCLUDES)
#	Compile
	$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@

# Compilation programme
$(NAME):	$(INCLUDES) $(OBJS)

#	Compile command
	$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -o $(NAME) $(LDFLAGS) $(OBJS) $(LDLIBS)

clean:
	$(RM) $(OBJS)

re: clean all 


# Génére les fichiers .mk 
gmk:
	@find $(INCLUDES_PATH) -type f -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk
	@find sources -type f -name '*.c' | sed 's/^/SOURCES += /' > sources.mk

.PHONY:	all clean re gmk 
