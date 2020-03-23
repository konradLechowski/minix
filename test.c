#include</usr/include/lib.h>
#include</usr/include/stdio.h>

int getprocnr(int proc_id)
{
	message msg;
	msg.m1_i1 = proc_id;
	return (_syscall(0,78,&msg));
}

int main(int argc, char * argv[])
{
	int result;
	int i;
	if(argc == 1) printf("za malo argumentow\n");
	else
	{
		int value=atoi(argv[1]);
		for( i = 0 ; i < 10 ; ++i )
		{
			result = getprocnr(value+i);
			if(result!=-1) printf ( "indeks procesu  o pid: %d to %d\n", value+i,result);
			else printf ("procesu o pid: %d nie ma w tablicy! kod bledu: %d\n", value+i,errno);
		}
	}
	return 0;
}   

