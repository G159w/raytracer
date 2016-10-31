CC = gcc
CFLAGS = -Werror -Wextra -Wall -pedantic -std=c99 -I"includes"
LDLIBS = -lm

VPATH = src src/math_funcs

OBJS = inout.o
OBJS += basic_vec_oper2.o
OBJS += basic_vec_oper.o
OBJS += ray_plane_intersec.o
OBJS += ray_sphere_intersec.o
OBJS += ray_triangle_intersec.o
OBJS += launch_ray.o
OBJS += lights.o
OBJS += main.o
OBJS += launch_ray.o
OBJS += lights.o
OBJS += rt.o 
OBJS += calculate_normal_vector.o
OBJS += dir_light.o
OBJS += get_caract.o
OBJS += point_light.o

BIN = rt
LIB = libparser.a


.PHONY: all clean debug check

all: $(BIN)


$(BIN): $(OBJS) $(LIB)

debug: CFLAGS += -g
debug: check

check: $(BIN)
	./tests/tests.sh

clean:
	${RM} $(OBJS) $(BIN)
	rm -r output
