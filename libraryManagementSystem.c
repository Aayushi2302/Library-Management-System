#include<stdio.h>
#include<string.h>
int n1=10,n2=20;
struct book
{
	char book_id[10];
	char book_name[50];
	char author[50];
	int no_of_pages;
	float price;
};
struct student
{
	char student_id[10];
	char student_name[30];
	char branch[10];
	int year;
};
struct issue
{
	char stud_id[10];
	char book_id[10];
	int status;
};
int main()
{
	struct student s[50]={
								{"S1","Aadish Jain","CSE",1},
								{"S2","Aradhya Shukla","AI",1},
								{"S3","Bhavya Sharma","ME",2},
								{"S4","Chaitra Mishra","CSE",3},
								{"S5","Divyanshu Kothari","ME",4},
								{"S6","Falguni Samar","AI",2},
								{"S7","Himani Shah","AI",3},
								{"S8","Kanak Kolhi","ME",3},
								{"S9","Rehan Khanna","ME",4},
								{"S10","Tanish Verma","ME",3}									
							};
	struct book b[50]={
						{"B1","Wings of Fire","Dr.A.P.J.Abdul Kalam",400,250},
						{"B2","Learning How to Fly","Dr.A.P.J.Abdul Kalam",200,110},
						{"B3","A Secular Agenda","Arun Shourie",600,450},
						{"B4","A Suitable Boy","Vikram Seth",300,200},
						{"B5","A Revolutionary Life","Laxmi Sehgal",250,199},
						{"B6","Area of Darkness","V.S.Naipul",195,120},
						{"B7","Broken Wings","Sarojini Naidu",435,350},
						{"B8","Chandalika","Rabindranath Tagore",625,449},
						{"B9","Godan","Munshi Premchand",429,300},
						{"B10","Court Dancer","Rabindranath Tagore",247,185},
						{"B11","Eternal India","Indira Gandhi",325,250},
						{"B12","Fall of a Sparrow","Salim Ali",339,247},
						{"B13","It is Always Possible","Kiran Bedi",328,199},
						{"B14","Tarkash","Javed Akhtar",224,185},
						{"B15","Vendor of Sweets","R.K.Narayan",415,339},
						{"B16","A Promised Land","Barack Obama",800,1103},
						{"B17","Timeless Laxman","Narendra Modi",247,120},
						{"B18","My Experiments with Truth","Mahatma Gandhi",400,300},
						{"B19","Raja Yoga","Swami Vivekananda",112,80},
						{"B20","Powers of The Mind","Swami Vivekananda",125,99}
					  };
	struct issue iss={0};
	struct issue fissue[10];
	int c1=0,c2=0,count=0,c=0,choice,ch;
	char dum,ch1,bname[50],aname[20];
	printf("********************Welcome to The Library Managemnet Software*******************\n\n");
	do
	{
		printf("The list of tasks that can be performed are:-\n");
		printf("1.Print Student Details\n");
		printf("2.Print Book Details\n");
		printf("3.Issue a Book\n");
		printf("4.Deposit a Book\n");
		printf("5.Print list of Issued Books\n");
		printf("6.Search a book by its Name or Author's Name\n");
		printf("7.Add Student or Book Details\n");
		printf("8.Quit\n");
		printf("Enter your choice(1/2/3/4/5/6/7/8):-");
		scanf("%d",&choice);
		printf("\n");
		if(choice==1)
		{
			for(int i=0;i<n1;i++)
			{
				printf("\nDetails of Student %d:-\n",i+1);
				printf("Student Id :- %s\n",s[i].student_id);
				printf("Student Name :- %s\n",s[i].student_name);
				printf("Branch :- %s\n",s[i].branch);
				printf("Year :- %d\n",s[i].year);
			}
		}
		if(choice==2)
		{
			for(int i=0;i<n2;i++)
			{
				printf("\nDetails of Book %d:-\n",i+1);
				printf("Book Id :- %s\n",b[i].book_id);
				printf("Book Name :- %s\n",b[i].book_name);
				printf("Author's Name :- %s\n",b[i].author);
				printf("Number of Pages :- %d\n",b[i].no_of_pages);
				printf("Price :- %.2f\n",b[i].price);
			}
		}
		if(choice==3)
		{
			do
			{
				printf("Enter the Student Id of the student for which you want to issue the book:-");
				scanf("%s",&iss.stud_id);
				for(int i=0;i<n1;i++)
				{
					if(strcmp(s[i].student_id,iss.stud_id)==0)
					{
						c1++;
						printf("Student Details:-\n");
						printf("Student Id :- %s\n",s[i].student_id);
						printf("Student Name :- %s\n",s[i].student_name);
						printf("Branch :- %s\n",s[i].branch);
						printf("Year :- %d\n",s[i].year);
					}
				}
				if(c1==0)
				printf("\nStudent Id :- %s does not exist!!",iss.stud_id);
				else
				{
					printf("Enter the Book Id of the book that you want to issue:-");
					scanf("%s",&iss.book_id);
					for(int i=0;i<n2;i++)
					{
						if(strcmp(b[i].book_id,iss.book_id)==0)
						{
							c2++;
							printf("Book Details:-\n");
							printf("Book Id :- %s\n",b[i].book_id);
							printf("Book Name :- %s\n",b[i].book_name);
							printf("Author's Name :- %s\n",b[i].author);
							printf("Number of Pages :- %d\n",b[i].no_of_pages);
							printf("Price :- %.2f\n",b[i].price);
						}
					}
					if(c2==0)
						printf("\nBook Id :- %s does not exist!!\n",iss.book_id);
					else
					{
						printf("\nBook Issued Successfully!!\n");
						strcpy(fissue[count].stud_id,iss.stud_id);
						strcpy(fissue[count].book_id,iss.book_id);
						fissue[count].status=1;
						count++;
					}	
				}
				printf("\nNumber of issued books :- %d\n",count);
				for(int i=0;i<count;i++)
				{
					for(int j=0;j<n2;j++)
					{
						if(strcmp(fissue[i].book_id,b[j].book_id)==0)
						{
							printf("Book :- %s(Book Id :- %s) has been issued by",b[j].book_name,b[j].book_id);
							break;
						}	
					}
					for(int j=0;j<n1;j++)
					{
						if(strcmp(fissue[i].stud_id,s[j].student_id)==0)
						{
							printf(" %s(Student Id :- %s)\n",s[j].student_name,s[j].student_id);
							break;
						}
					}
				}
				scanf("%c",&dum);
				printf("\nDo you want to issue more books?(Y/N) :-");
				scanf("%c",&ch1);
			}while(ch1=='Y'||ch1=='y');
		}
		if(choice==4)
		{
			c1=0,c2=0;
			do
			{
				printf("Enter the Student Id for the student for which you want to submit the book:-");
				scanf("%s",&iss.stud_id);
				for(int i=0;i<count;i++)
				{
					if(strcmp(iss.stud_id,fissue[i].stud_id)==0)
					{
						c1++;
						for(int j=0;j<n1;j++)
						{
							if(strcmp(iss.stud_id,s[j].student_id)==0)
							{
								printf("Student Details:-\n");
								printf("Student Id :- %s\n",s[j].student_id);
								printf("Student Name :- %s\n",s[j].student_name);
								printf("Branch :- %s\n",s[j].branch);
								printf("Year :- %d\n",s[j].year);
								break;
							}
						}
					}
				}
				if(c1==0)
					printf("\nStudent with Student Id :- %s has not issued any book!!\n",iss.stud_id);
				else
				{
					printf("\nEnter Book Id of the book that you want to submit:-");
					scanf("%s",&iss.book_id);
					for(int i=0;i<count;i++)
					{
						if(strcmp(iss.stud_id,fissue[i].stud_id)==0)
						{
							c++;
							if(strcmp(iss.book_id,fissue[i].book_id)==0)
							{
								c2++;
								for(int j=0;j<n2;j++)
								{
									if(strcmp(iss.book_id,b[j].book_id)==0)
									{
										printf("Book Details:-\n");
										printf("Book Id :- %s\n",b[j].book_id);
										printf("Book Name :- %s\n",b[j].book_name);
										printf("Author's Name :- %s\n",b[j].author);
										printf("Number of Pages :- %d\n",b[j].no_of_pages);
										printf("Price :- %.2f",b[j].price);
										break;
									}
								}
							}
						}
					}
					if(c!=0&&c2==0)
						printf("\nStudent with Student Id :- %s has not issued Book with Book Id :- %s",iss.stud_id,iss.book_id);
					else
					{
						printf("\nBook with Book Id :- %s is Submitted Successfully!!",iss.book_id);
						for(int i=0;i<count;i++)
						{
							if(strcmp(fissue[i].book_id,iss.book_id)==0)
							{
								for(int j=i;j<count;j++)
								{
									strcpy(fissue[j].book_id,fissue[j+1].book_id);
									strcpy(fissue[j].stud_id,fissue[j+1].stud_id);
									fissue[j].status=fissue[j+1].status;
								}
								count--;
							}
						}
					}
				}
					
			scanf("%c",&dum);
			printf("\nDo you want to submit more books?(Y/N) :-");
			scanf("%c",&ch1);
			}while(ch1=='Y'||ch1=='y');
			printf("\nNumber of books issued currently:-%d\n",count);
			if(count!=0)
			{
				printf("Issued Books are:-\n");
				for(int i=0;i<count;i++)
				{
					for(int j=0;j<n2;j++)
					{
						if(strcmp(fissue[i].book_id,b[j].book_id)==0)
							printf("%s with Book Id :- %s\n",b[j].book_name,fissue[i].book_id);
					}
				}
			}
		}
		if(choice==5)
		{
			printf("The list of issued books are:-\n");
			printf("	Book Id				Book Name\n");
			for(int i=0;i<count;i++)
			{
				for(int j=0;j<n2;j++)
				{
					if(strcmp(fissue[i].book_id,b[j].book_id)==0)
						printf("	%s		-		%s\n",fissue[i].book_id,b[j].book_name);
				}
			}
		}
		if(choice==6)
		{
			c1=0,c2=0;
			printf("Want to search the book and know its details by:-\n");
			printf("1.Book's Name\n");
			printf("2.Author's Name\n");
			printf("Enter your choice(1/2):-");
			scanf("%d",&ch);
			if(ch==1)
			{
				c=0;
				fflush(stdin);
				printf("\nEnter the book name of the book for which you want to print the details:-\n");
				gets(bname);
				for(int i=0;i<n2;i++)
				{
					if(strcmp(bname,b[i].book_name)==0)
					{
						c++;
						printf("\nBook Details:-\n");
						printf("Book Id :- %s\n",b[i].book_id);
						printf("Author's Name :- %s\n",b[i].author);
						printf("Number of Pages :- %d\n",b[i].no_of_pages);
						printf("Price :- %.2f\n",b[i].price);
						for(int j=0;j<count;j++)
						{
							if(strcmp(b[i].book_id,fissue[j].book_id)==0)
							{
								c1++;
								printf("\nBook is already issued!!\n");
							}
						}
						if(c1==0)
							printf("\nBook is not issued!!\n");
					}
				}
				if(c==0)
					printf("\nBook does not exist!!\n");
			}
			if(ch==2)
			{
				c=0;
				fflush(stdin);
				printf("\nEnter the author's name of the book for which you want to print the details:-\n");
				gets(aname);
				for(int i=0;i<n2;i++)
				{
					if(strcmp(aname,b[i].author)==0)
					{
						printf("\nBook Details:-\n");
						printf("Book Id :- %s\n",b[i].book_id);
						printf("Book Name :- %s\n",b[i].book_name);
						printf("Number of Pages :- %d\n",b[i].no_of_pages);
						printf("Price :- %.2f\n",b[i].price);
						for(int j=0;j<count;j++)
						{
							if(strcmp(b[i].book_id,fissue[j].book_id)==0)
							{
								c2++;
								printf("\nBook is already issued!!\n");
								break;
							}
						}
						if(c2==0)
							printf("\nBook is not issued!!\n");
					}
				}
				if(c==0)
					printf("\nBook does not exist!!\n");
			}
		}
		if(choice==7)
		{
			printf("\nSelect whose details you want to add:-\n");
			printf("1.Student\n");
			printf("2.Book\n");
			printf("Enter your choice(1/2):-");
			scanf("%d",&ch);
			if(ch==1)
			{
				do
				{
					n1+=1;
					printf("Enter details of student %d:-\n",n1);
					for(int i=n1-1;i<n1;i++)
					{
						printf("Enter Student Id :-");
						scanf("%s",&s[i].student_id);
						fflush(stdin);
						printf("\nEnter Student Name :-");
						gets(s[i].student_id);
						printf("\nEnter Student Branch :-");
						scanf("%s",&s[i].branch);
						printf("\nEnter Student Year :-");
						scanf("%d",&s[i].year);
					}
					fflush(stdin);
					printf("\nWant to add more student details(Y/N):-");
					scanf("%c",&ch1);
				}while(ch1=='Y'||ch1=='y');
			}
			if(ch==2)
			{
				do
				{
					n2+=1;
					printf("Enter details of book %d:-\n",n2);
					for(int i=n2-1;i<n2;i++)
					{
						printf("Enter Book Id :-");
						scanf("%s",&b[i].book_id);
						fflush(stdin);
						printf("\nEnter Book Name :-");
						gets(b[i].book_name);
						fflush(stdin);
						printf("\nEnter Author's Name :-");
						gets(b[i].author);
						printf("\nEnter number of pages of book :-");
						scanf("%d",&b[i].no_of_pages);
						printf("\nEnter Price of the book :-");
						scanf("%.2f",&b[i].price);
					}
					fflush(stdin);
					printf("\nWant to add more book details(Y/N):-");
					scanf("%c",&ch1);
				}while(ch1=='Y'||ch1=='y');
			}
		}
		if(choice==8)
			break;
		fflush(stdin);
		printf("\nDo you want to anything else?(Y/N):-");
		scanf("%c",&ch1);
		printf("\n");
	}while(ch1=='Y'||ch1=='y');
	return 0;
}
