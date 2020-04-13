.PHONY: clean

T1= 1_btree_traversal
T2= 2_btree_BFT
TARGETS= $(T1) $(T2)

FLAGS= -std=c99 -Wall -Werror

all: $(TARGETS)


$(T1): $(T1).c
	gcc $< -o $@ $(FLAGS)

$(T2): $(T2).c
	gcc $< -o $@ $(FLAGS)


clean:
	rm $(T1) $(T2)
