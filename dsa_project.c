#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define d 10
#include<conio.h>
#define INFINITY 9999
#define MAX 10


int flag=0;
int op = 0;
int loc;
FILE*fp1,*fp2,*fp3;
float G[MAX][MAX] = {{6.2, 1.8, 5.1, 2.6},
                          {2.4, 2.4, 4.5, 5.0},
                          {2.8, 2.2, 4.2, 4.8},
                          {4.9, 4.1, 0.75, 5.4}};

struct movie
 {
    char title[50];
    int year;
    char actor[50];
    char type[10];
    float imbd;
};

struct theathre
{
    int num;
    char title[50];
    char thethre[100];
};

struct songs
{
    char name[1000];
    char title[50];
    char song[5000];

};
struct movie m[11];
struct theathre t[11];
int comparator(const void* p, const void* q)
{
    return (((struct movie*)p)->imbd - ((struct movie*)q)->imbd);
}

void rabinKarp(char pattern[], char text[], int q)
{
  int m = strlen(pattern);
  int n = strlen(text);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++)
    h = (h * d) % q;


  for (i = 0; i < m; i++)
 {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }


  for (i = 0; i <= n - m; i++)
    {
    if (p == t)
    {
      for (j = 0; j < m; j++)
      {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == m)
      {
        //printf("\nPattern is found at position:  %d \n", i + 1);
        flag=1;
      }

    }

    if (i < n - m)
    {
      t = (d * (t - text[i] * h) + text[i + m]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}

void sorting(struct movie m[11])
{

  qsort(m,11, sizeof(struct movie), comparator);
  printf("highest to lowest\n");
      for(int i=11;i>=1;i--)
      {
          printf("->%s\n",m[i].title);
      }

}
void movie_display(FILE*fp1,struct movie m[11])
{

    printf("::HERE ARE SOME RECENTLY RELEASED MOVIES::\n");
    for(int i=1;i<=11;i++)
      {
        fscanf(fp1,"%s%d%s%s%f",m[i].title,&m[i].year,m[i].actor,m[i].type,&m[i].imbd);
      }
    for(int i=1;i<=11;i++)
      {
          printf("%d:%s\n",i,m[i].title);
      }
}

void song_display(FILE*fp3,struct songs p1)
{
        int q=13;
    char line[1000];
        printf("Enter song line \n");
        scanf("%s",line);
        for(int i=1;i<=12;i++)
        {
            fscanf(fp3,"%[^\n]%*c",&p1.name);
            fscanf(fp3,"%[^\n]%*c",&p1.title);
            fscanf(fp3,"%[^\n]%*c",&p1.song);
            //printf("\n%s\n%s\n%s\n",p1.name,p1.song,p1.title);
            rabinKarp(line, p1.song, q);
            if(flag==1)
            {
                printf("Oh cool I got it!\n");
                printf("\nThis song title is :%s",p1.name);
                printf("\nMovie name is :%s",p1.title);
                match(p1,m);
                flag=0;
            }
        }
}
void theathre_display(FILE*fp2,struct theathre t[11])
{

       int ch;
        scanf("%d",&ch);
        printf("\nThis movie is available at:");
        for(int i=1;i<=11;i++)
       {
        fscanf(fp2,"%d%s%s",&t[i].num,t[i].title,t[i].thethre);
       }
        for(int i=1;i<=11;i++)
       {
         if(ch==t[i].num)
           printf("%s",t[i].thethre);
       }
        printf("\n\nLet me help you to choose theatre which is near to you.. ");
         printf("which of the following is your nearby location\nVidyanagar-0\nKeshwapur-1\nAshok nagar-2\nGokul road-3\n");
         printf("Enter your nearby location\n");
         scanf("%d",&loc);
          if(loc==0)
         {
             printf("\nnearest thethre is APSARA");
         }
         else if(loc==1)
         {
             printf("\nnearest thethre is PVR");
         }
         else if(loc==2)
         {
             printf("\nnearest thethre is APSARA");
         }
         else if(loc==3)
         {
             printf("\nnearest thethre is CINEPOLIS");
         }
         dijikstra(G,loc);

}

void match(struct songs p1,struct movie m[11])
{
    for(int i=1;i<=11;i++)
      {
        fscanf(fp1,"%s%d%s%s%f",m[i].title,&m[i].year,m[i].actor,m[i].type,&m[i].imbd);
      }
    for(int j=0;j<=12;j++)
    if(strcmp(m[j].title,p1.title)==0)
    {
        printf("\nPRESENT IN THEATERS.\n");
        int ch=j;
        intheater(m,ch);
        op=0;
        break;
     }
    else
    {
        op = 1;
    }
    if(op==1)
    {
        printf("\nTHIS FILM IS NOT IN THEATERS\n");
    }

}

void intheater(struct movie m[11],int ch)
{
     for(int i=1;i<=11;i++)
       {
        fscanf(fp2,"%d%s%s",&t[i].num,t[i].title,t[i].thethre);
       }

     for(int i=1;i<=11;i++)
    {if(ch==t[i].num)
    {

        printf("theaters are:%s",t[i].thethre);
        printf("\n\nLet me help you to choose theatre which is near to you.. ");
        printf("which of the following is your nearby location\nVidyanagar-0\nKeshwapur-1\nAshok nagar-2\nGokul road-3\n");
         printf("Enter your nearby location\n");
         scanf("%d",&loc);
         if(loc==0)
         {
             printf("\nnearest thethre is APSARA");
         }
         else if(loc==1)
         {
             printf("\nnearest thethre is PVR");
         }
         else if(loc==2)
         {
             printf("\nnearest thethre is APSARA");
         }
         else if(loc==3)
         {
             printf("\nnearest thethre is CINEPOLIS");
         }
         dijikstra(G,loc);
    }
    }
}

void dijikstra(float G[MAX][MAX],int startnode)
{
    float temp;
	float cost[MAX][MAX];
	float distance[MAX];
	int pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < 4;i++)
		for(j=0;j < 4;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i< 4;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < 3){
		mindistance=INFINITY;
		for(i=0;i < 4;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < 4;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}

			for(int i=0;i<3-1;i++)
            {
                for(j=0;j<3-i-1;j++)
                {
                   if(distance[j]>distance[j+1])
                   {
                       temp=distance[j];
                       distance[j]=distance[j+1];
                       distance[j+1]=temp;
                   }
                }
            }
            for(int i=0;i<1;i++)
            printf(" of distance %0.1f kms",distance[i+1]);


}
int main()

{
    int i,j,ch;
    char yn[5];
    struct songs p1;
    //FILE*fp1,*fp2,*fp3;
    struct movie m[11];
    struct theathre t[11];
    fp1=fopen("movie.txt","r");
    fp2=fopen("theatre.txt","r");
    fp3=fopen("lyrics.txt","r");
    if(fp1==NULL||fp2==NULL||fp3==NULL)
    {
        printf("file does not exist");
        exit(0);
    }

    printf("::HELLO WELCOME TO ONLINE BOOKING::\n");
    printf("SELECT 1->To display movie list\n");
    printf("SELECT 2->To know the movie by its song\n");
    printf("Your choice:");
    scanf("%d",&ch);
    if(ch==1)
    {
       movie_display(fp1,m);
       printf("Do you want film list based on popularity YES/NO:");
    scanf("%s",&yn);
    if(strcasecmp(yn,"YES")==0)
    {

         sorting(m);
         printf("\nSelect movie no:");
         theathre_display(fp2,t);
    }
    else if(strcasecmp(yn,"NO")==0)
      {
       printf("Ok.. check among this\n");
       printf("\nSelect movie no:");
       theathre_display(fp2,t);
      }
      else
      {
          printf("please answer in YES or NO\n");
      }

    }
    else if(ch==2)
    {
        song_display(fp3,p1);
    }
    else
    {
        printf("Invalid choice\n");
    }

         fclose(fp1);
         fclose(fp2);
         fclose(fp3);
}
