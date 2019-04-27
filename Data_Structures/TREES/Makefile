.PHONY: clean

T1= 1_btree_intro
TARGETS= $(T1)

FLAGS= -std=c99 -Wall -Werror

all: $(TARGETS)


$(T1): $(T1).c
	gcc $< -o $@ $(FLAGS)


clean:
	rm $(T1)
