#Author: Patrick Almeida
prog:
	gcc $$(for i in $$(ls *.c *.h 2> /dev/null); do printf "$$i "; done) -o prog

clean: 
	rm -f *.o *prog*
