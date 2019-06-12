.PHONY: clean


TARGETS= damn_vulnerable
FLAGS= -m32 -fno-stack-protector -z execstack 
 

damn_vulnerable: damn_vulnerable.c
	gcc $(FLAGS) $< -o $@


clean:
	rm $(TARGETS)
