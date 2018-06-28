#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>
struct candidate
{
    struct candidate *link;
    int sl_no;
    char name[20];
    unsigned id;
    int votes;
};

typedef struct candidate* candidateptr;

candidateptr nominatecandidate()
{
    candidateptr temp;
    temp=(candidateptr)malloc(sizeof(struct candidate));
    temp->link=NULL;
    //temp->votes;
    return(temp);
}
candidateptr addcandidate(candidateptr memberlist)
{
    int sl_no;
    unsigned id;
    char name[20];
    candidateptr temp;
    temp=nominatecandidate();
    printf("\nenter the sl.no of candidate\n");
    scanf("%d",&sl_no);
     printf("\nenter the name of candidate\n");
     scanf("%s",name);
     printf("\nenter the id of the candidate\n");
     scanf("%u",&id);

     //else{
     temp->id=id;
     temp->votes=0;
     temp->sl_no=sl_no;
     strcpy(temp->name,name);
     if(memberlist==NULL)
     return(temp);
     else if((repeated(memberlist,id))==1)
     {
         printf("\nthe candidate already is in the list\n");
     }
     else{
     temp->link=memberlist;
     return(temp);
     }

   }

//isrepeated(memberlist,id)
int repeated(candidateptr memberlist,unsigned id)
{
    candidateptr cur=NULL;
    cur=memberlist;
    while(cur!=NULL)
    {
        if(cur->id==id)
        return 1;
        else
          cur=cur->link;
    }
            return 0;
}
/*
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void count()
 {
    int i;
    i=0;
    while(1)
    {
        printf("%d\n",i);
        delay(200);
        i++;
        if(getchar())
        return;
    }
 }*/
void displaycandidate(candidateptr memberlist)
{
    candidateptr cur;
    cur=memberlist;
    if(memberlist==NULL)
    printf("\nthe list is empty\n");
    else{
    while(cur!=NULL)
    {
        printf("\nsl.no\tname\tid");
        printf("\n%d\t%s\t%u",cur->sl_no,cur->name,cur->id);
         cur=cur->link;
    }
}
}
void voting(candidateptr memberslist)
{
    unsigned id;
    candidateptr cur=NULL;
    if(memberslist==NULL)
    printf("\nno candidates are participating in the elections");
    else
    {
    displaycandidate(memberslist);
    printf("\nenter the id of ur choice\n");
    scanf("%u",&id);
     cur=memberslist;
    while(cur!=NULL)
    {
    if(cur->id==id)
    {
        cur->votes++;
        break;
    }
        cur=cur->link;
    }
}
}
void results(candidateptr memberslist)
{
    candidateptr cur=NULL,winner=NULL;
    cur=memberslist;
    winner=memberslist;
    if(memberslist==NULL)
    printf("\elections is not yet held\n");
    else{
    while(cur->link!=NULL)
    {
        if(cur->votes>winner->votes)
        {
            winner=cur;
        }
        cur=cur->link;
     }
     printf("\nthe winner is:");
    printf("\n%s\t%u\t%d",winner->name,winner->id,winner->votes);
 }
}
 bool validatecandidate(candidateptr memberlist,unsigned id)
 {
     candidateptr cur=NULL;
  cur=memberlist;
     while(cur!=NULL)
     {

        if((cur->id)==id)
            {
                if((cur->votes)==1)
                printf("\nyou have already completed your voting\n");
                else
                {
                    cur->votes=1;
                    return true;
                }
            }

         cur=cur->link;
     }
     return false;
 }
 int main()
{
    candidateptr voters=NULL,nominees=NULL;
    int choice;
    char name[20];
    unsigned key;
    while(1){
        printf("\n enter ur user name\n");
        scanf("%s",name);
        printf("\nenter the login id\n");
        scanf("%u",&key);
       if((key==33)&&(strcmp(name,"dinesh")==0))
       {
           while(1){
           printf("\nplease make a choice\n ");
        printf("\n1.add nominees\n2.register voters\n3.view results\n4.vote\n5.exit\n6.switch user\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:nominees=addcandidate(nominees);
               break;
        case 2:voters=addcandidate(voters);
               break;
       case 3: results(nominees);
               break;
      case 4:voting(nominees);
             break;
        case 6:goto vote;
        default:printf("\nwrong choice\n");
                  break;
     }
    }
   }
   else if(validatecandidate(voters,key))
    {
  vote :      printf("\nplease make a choice");
        printf("\ncast your vote within 30 secs");
        printf("\n3.view results\n4.cast your vote\n5.exit");
//        count();
     scanf("%d",&choice);
     switch(choice){
      case 3: results(nominees);
               break;
      case 4:voting(nominees);
             break;
         default:printf("\nwrong choice\n");
                  exit(0);

      }
    }
    else
    {
        printf("\nyou are not a valid voter or your id and name does not match\n ");
        break;
    }

    }

    return 0;
}
