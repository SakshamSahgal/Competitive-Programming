#include<stdio.h>
#include<string.h>
#include<conio.h>
int last_member_id = 4;
struct Book
{
char name[50];
unsigned int id;
unsigned int rent;
char genre[15];
char writer[30];
char status[4];
}bk[30];

struct Member
{
char name[50];
unsigned int id;
}mb[10];

void Member_input(struct  Member mb[])
{
    for(int i=0;i<6;i++)
        mb[i].name[0] = '\0';

strcpy(mb[0].name,"Saksham_Sahgal");
strcpy(mb[1].name,"Manan_Gandhi");
strcpy(mb[2].name,"Aman_Jain");
strcpy(mb[3].name,"Yatin_Garg");

for(int i=0;i<4;i++)
    mb[i].id = i+1;
}
void book_input(struct Book bk[])
{
    //naming-----------------------------------------------------

    //fiction
   strcpy(bk[0].name,"The Alchemist");
   strcpy(bk[1].name,"Lord of the flies");
   strcpy(bk[2].name,"Alice's Adventures in Wonderland");
   strcpy(bk[3].name,"Harry Potter");
   strcpy(bk[4].name,"Inception");

    //thriller
   strcpy(bk[5].name,"The Silent Patient");
   strcpy(bk[6].name,"Gone Girl");
   strcpy(bk[7].name,"The Girl on the train");
   strcpy(bk[8].name,"The Searcher");
   strcpy(bk[9].name,"The Da Vinci Code");

   //mythology

   strcpy(bk[10].name,"Gita");
   strcpy(bk[11].name,"Mahabharat");
   strcpy(bk[12].name,"Quran");
   strcpy(bk[13].name,"Ramayan");
   strcpy(bk[14].name,"The guru Granth Sahib");

    //biography

   strcpy(bk[15].name,"Steve Jobs");
   strcpy(bk[16].name,"Playing it My way");
   strcpy(bk[17].name,"Einstein: His life and universe");
   strcpy(bk[18].name,"Born a Crime");
   strcpy(bk[19].name,"Calcuttascape : Musings of a GlobeTrotter");


    //MYSTRY

    strcpy(bk[20].name,"The Women In White");
    strcpy(bk[21].name,"A time for mercy");
    strcpy(bk[22].name,"The big sleep");
    strcpy(bk[23].name,"double Cross");
    strcpy(bk[24].name,"Still Life");

    //id-----------------------------------------------------
    for(int i=0;i<25;i++)
        bk[i].id = i+1;
    //price--------------------------------------------------
    for(int i=0;i<25;i++)
        bk[i].rent = 50;
    //genre--------------------------------------------------
    for(int i=0;i<5;i++)
        strcpy(bk[i].genre,"Fiction");
    for(int i=5;i<10;i++)
        strcpy(bk[i].genre,"Thriller");
    for(int i=10;i<15;i++)
        strcpy(bk[i].genre,"Mythology");
    for(int i=15;i<20;i++)
        strcpy(bk[i].genre,"Biography");
    for(int i=20;i<25;i++)
        strcpy(bk[i].genre,"Mystery");
    //WRITER----------------------------------------------------
    //fiction
    strcpy(bk[0].writer,"Paulo Coelho");
   strcpy(bk[1].writer,"William Golding");
   strcpy(bk[2].writer,"Lewis Carroll");
   strcpy(bk[3].writer,"JK rowling");
   strcpy(bk[4].writer,"Christopher Nolan");

    //thriller
   strcpy(bk[5].writer,"Alex Michaelides");
   strcpy(bk[6].writer,"Gillian Flynn");
   strcpy(bk[7].writer,"Paula Hawkins");
   strcpy(bk[8].writer,"Tana French");
   strcpy(bk[9].writer,"Dan Brown");

   //mythology

   strcpy(bk[10].writer,"vyasa");
   strcpy(bk[11].writer,"vyasa");
   strcpy(bk[12].writer,"Muhammad");
   strcpy(bk[13].writer,"valmiki");
   strcpy(bk[14].writer,"Pashaura Singh");

    //biography

   strcpy(bk[15].writer,"Walter Isaacson");
   strcpy(bk[16].writer,"Boria Majumdar");
   strcpy(bk[17].writer,"Walter Isaacson");
   strcpy(bk[18].writer,"Trevor Noah");
   strcpy(bk[19].writer,"sundeep bhutoria");


    //MYSTRY

    strcpy(bk[20].writer,"Wilkie Collins");
    strcpy(bk[21].writer,"John Grisham");
    strcpy(bk[22].writer,"Raymond Chandler");
    strcpy(bk[23].writer,"Ben Macintyre");
    strcpy(bk[24].writer,"Louise Penny");

     //Availability status-----------------------------------------------------
        for(int i=0;i<25;i++)
          strcpy(bk[i].status,"YES");
}

void List_Printer(struct Book bk[])
{
printf(" ID \t\t\t\t BOOK NAME \t\t\t RENT RATE \t GENRE \t\t\t\t WRITER \t\t AVAILABILITY STATUS\n");
printf("\n");
for(int i=0;i<25;i++)
    printf(" %02d \t %50s \t Rs.%d \t %15s\t %30s\t\t %s \n",bk[i].id,bk[i].name,bk[i].rent,bk[i].genre,bk[i].writer,bk[i].status);
}

void Become_Member(struct Member mb[])
{

    printf("\nEnter your name (Firstname_Lastname): \n");
    scanf("%s",mb[last_member_id].name);
    mb[last_member_id].id = last_member_id+1;
    printf("\nyour ID = %d \n",last_member_id+1);
    ++last_member_id;
}

void member_list_Displayer(struct Member mb[])
{
printf("ID         MEMBERS \n");
for(int i=0;i<last_member_id;i++)
    {
        printf("%d         %-5s \n",mb[i].id,mb[i].name);
    }
}


void Choose_Book(struct Book bk[])
{
unsigned int ID;
printf("Enter ID of the Book You Want :");
scanf("%d",&ID);
if(ID>=1 && ID<=25 && bk[ID-1].status[0] == 'Y')
    {
        strcpy(bk[ID-1].status,"NO");
        printf("Thanks for coming\n");
    }
else
    {
    printf("Book not available \n");
    }
}
int main()
{
system("color 30");
unsigned int choice;
unsigned int ID;
book_input(bk);
Member_input(mb);
input_choice_again:
system("cls");
printf("\n\n\n\n\t\t\t------------1.Already a Member\n \t\t\t------------2.Become A Member \n\t\t\t------------3.Display Member List \n\t\t\t------------4.Exit\n");
printf("Your Choice : ");
scanf("%d",&choice);
if(choice == 1)
    {
    input_ID_Again:
    printf("\nEnter ID\n");
    scanf("%d",&ID);

        if(ID>=1 && ID<=last_member_id)
        {
        List_Printer(bk);
        Choose_Book(bk);
        goto input_choice_again;
        }
        else
            {
            printf("YOU ARE NOT A MEMBER\n");
            goto input_choice_again;
            }
    }
else if(choice == 2)
    {
        Become_Member(mb);
        goto input_choice_again;
    }
else if(choice == 3)
    {
    member_list_Displayer(mb);
    goto input_choice_again;
    }
else if(choice == 4)
    return 0;
else
    {
    printf("WRONG CHOICE\n");
    goto input_choice_again;
    }

return 0;
}
