#include <pthread.h> //64050183
#include <stdio.h>
#include <stdlib.h>

void *sum(void *param);

int csum;
int msum;
int main(int argc, char *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int cntmSum;
	int ans;

	pthread_create(&tid, &attr, sum, argv[1]);

	pthread_join(tid, NULL);

	cntmSum = atoi(argv[1]);
	if(cntmSum > 0)
	{
		for(int i = 1; i <= cntmSum; i++)
		{
			msum += i;
		}
	}

	ans = csum - msum;

	printf("csum : %d\n", csum);
	printf("msum : %d\n", msum);
	printf("Ans : %d\n", ans);

	return 0;
}
void *sum(void *param)
{
	int cntcSum = atoi(param);
	if(cntcSum > 0)
	{
		for(int i = 1; i <= cntcSum * 2; i++)
		{
			csum += i;
		}
	}
	pthread_exit(0);
}
