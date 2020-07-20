obj    = rngchk.o get_cpuid_v1_lix64.o
cc     = gcc
target = rng-test
installpath = /usr/local/bin/

$(target): $(obj)  
	$(CC) $(obj) -o $(target)
rngchk.o:rngchk.c
	$(CC) -g -c rngchk.c -o rngchk.o
get_cpuid_v1_lix64.o:get_cpuid_v1_lix64.s 
	$(CC) -g -c get_cpuid_v1_lix64.s -o get_cpuid_v1_lix64.o
install:
	cp $(target) $(installpath)
uninstall:
	rm $(installpath)/$(target)
.PHONY:clean
clean:
	-rm  $(obj) $(target)
