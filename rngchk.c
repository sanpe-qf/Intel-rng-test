#include <stdio.h>
#include <stdlib.h>
 
#include "get_cpuid_v1_lix64.h"
 
void _CPUID(CPUIDinfo *info, const unsigned int func, const unsigned int subfunc)
{
	get_cpuid_info_v1(info, func, subfunc);
}
 
typedef unsigned int DWORD;
 
int _rdrand_check_support()
{
	CPUIDinfo info;
	int got_intel_cpu=0;
 
	_CPUID(&info, 0, 0);
 
	if(memcmp((char *)(&info.EBX), "Genu", 4) == 0 &&
		memcmp((char *)(&info.EDX), "ineI", 4) == 0 &&
		memcmp((char *)(&info.ECX), "ntel", 4) == 0) 
    {
		got_intel_cpu = 1;
	}
 
	if (got_intel_cpu) 
    {
		_CPUID(&info, 1, 0);
		if ((info.ECX & 0x40000000)==0x40000000) return 1;
	} 
	else 
	{
		return 2;
	}
 
	return 0;
}
 
int main(int argc, char **argv) {
	int ret = _rdrand_check_support();	
    printf("is not intel cpu?       [%c]\n", (ret == 2 ? 'Y' : 'N'));
	printf("is intel rng supported? [%c]\n", (ret == 1 ? 'Y' : 'N'));
}
