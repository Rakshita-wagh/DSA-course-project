# DSA-course-project
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define d 10

int flag=0;

struct movie {
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
        for(int i=1;i<=11;i++)
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
                flag=0;
            }
        }
}
void theathre_display(FILE*fp2,struct theathre t[11],int loc)
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
         printf("which of the following is your nearby location\nVidyanagar(V), Keshwapur(K), Ashok nagar(A), Gokul road(G)\n");
         printf("Enter your nearby location\n");
         scanf("%s",loc);
}


int main()

{
    int i,ch,loc;
    char yn[5];
    struct songs p1;
    FILE*fp1,*fp2,*fp3;
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
    if(strcmp(yn,"YES")==0)
    {

         sorting(m);
         printf("\nSelect movie no:");
         theathre_display(fp2,t,loc);
    }
    else if(strcmp(yn,"NO")==0)
      {
       printf("Ok.. check among this\n");
       printf("\nSelect movie no:");
       theathre_display(fp2,t,loc);
      }
      else
      {
          printf("please answer in YES or NO\n");
      }

    }
    else if(ch==2)
    {
        song_display(fp3,p1);
        printf("\n\nLet me help you to choose theatre which is near to you.. ");
         printf("which of the following is your nearby location\nVidyanagar(V), Keshwapur(K), Ashok nagar(A), Gokul road(G)\n");
         printf("Enter your nearby location\n");
         scanf("%s",loc);
    }
    else
    {
        printf("Invalid choice\n");
    }

         fclose(fp1);
         fclose(fp2);
         fclose(fp3);
}
