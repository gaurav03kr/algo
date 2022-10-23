#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t a,b,c;
b=fork();
if(b==-1)
{
printf("Error");
}
if(b==0)
{
printf("Child process 'B', id= %d\n",getpid());
c=fork();
if(c==-1)
{
printf("Error");
}
if(c==0)
{
printf("Child process 'C', id= %d\n",getpid());
}
else
{
printf("Parent Process 'B', id= %d\n",getpid());
}
}
else
{
printf("Parent Process 'A', id= %d\n",getpid());
}
return 0;
}
