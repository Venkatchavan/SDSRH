#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#define num_of_vaccine 200
#define datafile "covid19.txt"
#define indexfile "covid19index.txt"
#define sindexfile "covid19sindex.txt"
#define datafile1 "vaccine.txt"
#define indexfile1 "vaccineindex.txt"
#define sindexfile1 "vaccinesindex.txt"

using namespace std;
fstream dfile,ifile,sifile;
int i,indsize,sindsize;
char buffer[100],skey[20];
void menu();
void show();
fstream dfile1,ifile1,sifile1;
int j,indsize1,sindsize1;
int slots();int nodes;
void number();
int count = 0;

//function to open 
void fopen(fstream &file, char *fn,std::_Ios_Openmode mode)
{
	file.open(fn,mode);
	if(!file)
	{
		cout<<"\n\t\t\t Unable to open a file";
		exit(1);
	}
}

//covid class
class covid
{
	char dbuno[15],name[20],age[5],phone[11],hospital[20];
	public:
		void patient_details();
		void pack();
	    int search(char *);
		void remove_patients();
		void display();
		void unpack();
}s;

//index class for covid
class index
{
	public:
		char ibuno[15],addr[5];
		void initial();
		void write();
}id[50],in;

//sindex class for covid
class sindex
{
	public :
		  char sname[20],sbuno[15];
		  void sinitial();
		  void swrite();
}sid[50],sin;


// function to copy index file to array structure
void index::initial()
{
	ifile.open(indexfile,ios::in);
	if(!ifile)
	{
		   indsize=0;
		   return;
	}
   for(indsize=0;;indsize++)
   {
		ifile.getline(id[indsize].ibuno,15,'|');
		ifile.getline(id[indsize].addr,5,'\n');
		if(ifile.eof())
			break;
   }
   ifile.close();
}

//function to copy sindex file to array structure
 void sindex::sinitial()
{
	sifile.open(sindexfile,ios::in);
	if(!sifile)
	{
		   sindsize=0;
		   return;
	}
   for(sindsize=0;;sindsize++)
   {
		sifile.getline(sid[sindsize].sname,20,'|');
		sifile.getline(sid[sindsize].sbuno,15,'\n');
		if(sifile.eof())
			break;
   }
   sifile.close();
}

// function to update the index file
void index::write()
{
	fopen(ifile,indexfile,ios::out);
	for(i=0;i<indsize;i++)
		ifile<<id[i].ibuno<<"|"<<id[i].addr<<"\n";
}

//function to upadate the secondary file
void sindex::swrite()
{
	fopen(sifile,sindexfile,ios::out);
	for(i=0;i<sindsize;i++)
		sifile<<sid[i].sname<<"|"<<sid[i].sbuno<<"\n";
}


// function to read the patient record
void covid::patient_details()
{	

		int k;
		cout<<"\n**************************************************************************************************************************\n";
		cout<<"\n\t\t\t\t ENTERING PATIENT DETAILS \t\t\t"<<endl;
		cout<<"\n**************************************************************************************************************************\n";
		cout<<" \n\t\t\t Enter the buno number=";  
		cin>>dbuno;
		if(search(dbuno)>=0)
		{
		  cout<<"\n\t\t\t BU Number is already present we can't add to index file\n";
		  return;
		}
		for(i=indsize;i>0;i--)
		{
	   		if(strcmp(dbuno,id[i-1].ibuno)<0)
				id[i]=id[i-1];
	   		else
				break;
		}
		fopen(dfile,datafile,ios::app);
		cout<<"\n\t\t\t Enter the name=";    	cin>>name;
		cout<<"\n\t\t\t Enter the age=";     	cin>>age;
		cout<<"\n\t\t\t Enter the phone num=";  	cin>>phone;
		cout<<"\n\t\t\t Enter the hospital=";   	cin>>hospital;
		pack();
		dfile.seekg(0,ios::end);
		k=dfile.tellg();
		dfile<<buffer<<"\n";
		strcpy(id[i].ibuno,dbuno);
		sprintf(id[i].addr, "%d",k);
		indsize++;
		for(i=sindsize;i>0;i--)
		{
			if(strcmp(name,sid[i-1].sname)<0)
				sid[i]=sid[i-1];
			else if((strcmp(name,sid[i-1].sname)==0) && (strcmp(dbuno,sid[i-1].sbuno)<0))
				sid[i]=sid[i-1];
			else
				break;
		}
		strcpy(sid[i].sname,name);
		strcpy(sid[i].sbuno,dbuno);
		sindsize++; 
	
}
	

//function to pack 
void covid::pack()
{
		strcpy(buffer,dbuno);	strcat(buffer,"|");
		strcat(buffer,name);	strcat(buffer,"|");
		strcat(buffer,age);	strcat(buffer,"|");
		strcat(buffer,phone);	strcat(buffer,"|");
		strcat(buffer,hospital);	strcat(buffer,"|");
}



//function to search based on name (secondary key)
int covid::search(char * fbuno)
{
	int low=0,high=indsize-1,mid;
	while(low <=high)
	{
		mid = (low+high)/2;
		if(strcmp(fbuno,id[mid].ibuno)==0)
			return mid;
		if(strcmp(fbuno,id[mid].ibuno)>0)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

//function to search based on secondary key
int sec_search()
{	
	int pos,j,flag=-1;
	cout<<"\n*******************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t SEARCHING PATIENT DETAILS \t\t\t"<<endl;
	cout<<"\n********************************************************************************************************************************\n";
	cout<<"\n\t\t\t Enter the name to search(sec key):";
	cin>>skey;
	cout<<"\n\t\t\t The searched record details are :"<<endl;
	cout<<setiosflags(ios::left);
	cout<<"\t\t\t BU NO:"<<"\t\t\t Name:"<<endl;
	fopen(dfile,datafile,ios::in|ios::out);
	for(j=0;j<sindsize;j++)
			 if(strcmp(skey,sid[j].sname)==0)
		  {
			cout<<"\t\t\t"<<sid[j].sbuno<<"\t\t\t"<<sid[j].sname<<endl;
			flag=j;
		  }
	return flag;
	system("cls");
}

// function to remove the patient record
void covid::remove_patients()
{	
	char rbuno[10];
	int pos,spos;
	cout<<"\n****************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t REMOVING PATIENT DETAILS \t\t\t"<<endl;
	cout<<"\n****************************************************************************************************************************\n";
	cout<<"\n\t\t\t Enter the BU number above listed to delete:";
	cin>>rbuno;
	for(i=0;i<sindsize;i++)
	{
		  if(strcmp(sid[i].sbuno,rbuno)==0)
		   {
			  spos=i;
			  break;
		   }
	}

	if(strcmp(sid[spos].sname,skey)==0)
	{
		pos=search(rbuno);
		dfile.seekp(atoi(id[pos].addr),ios::beg);
		dfile.put('$');
		for(i=pos;i<indsize;i++)
			id[i]=id[i+1];
		indsize--;
		for(i=spos;i<sindsize;i++)
			sid[i]=sid[i+1];
		sindsize--;
		cout<<"\n\t\t\t The patient record with BU number "<<rbuno<<"is deleted"<<endl;
	}
	else
		cout<<"\n\t\t\t BU number and name doesnot match";
}

//function to display the datafile
void covid::display()
{	
	cout<<"*****************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t DISPLAYING DETAILS \t\t\t"<<endl;
	cout<<"\n***************************************************************************************************************************\n";
	cout<<setiosflags(ios::left);
	cout<<setw(20)<<"buno"<<setw(20)<<"name"<<setw(16)<<"age"<<setw(20)<<"phone"<<setw(20)<<"hospital\n";
	cout<<"\n";
	while(1)
	{
		unpack();
		if(dfile.eof()) 	
  		break;
	}
	cout<<endl<<"The index file details are :- "<<endl;
	cout<<setw(10)<<"Buno"<<setw(10)<<"address";
	for(i=0;i<indsize;i++)
		 cout<<endl<<setw(10)<<id[i].ibuno<<setw(10)<<id[i].addr;
	cout<<endl<<"\n The secondary file details are :- " <<endl;
	cout<<setw(20)<<"Name"<<setw(15)<<"primary reference";
	for(i=0;i<sindsize;i++)
		  cout<<endl<<setw(20)<<sid[i].sname<<setw(15)<<sid[i].sbuno;
}

//function to unpack the data file
void covid::unpack()
{
	dfile.getline(buffer,100,'\n');
	i=0;
	if(buffer[i]!='$')
		 while(buffer[i]!='\0')
		{
			if(buffer[i]=='|')
				cout<<"\t\t";
			else
				cout<<buffer[i];
			i++;
		}
		cout<<"\n";
}

//main program of covid menu
int covid_menu()
{
	int ch,flag;
	sin.sinitial();
	B:
	for(;;)
	{
				cout<<"\n********************************************************************************************************************\n";
				cout<<"\t\t\t\t Welcome to Covid-19 Menu\t\t"<<endl;
				cout<<"\n********************************************************************************************************************\n";
				int ch;
				cout<<"\n\t\t\t 1.Patient Entry Details"<<endl;
				cout<<"\n\t\t\t 2.Display Patients"<<endl;
				cout<<"\n\t\t\t 3.Search Patients"<<endl;
				cout<<"\n\t\t\t 4.Delete Patient details"<<endl;
				cout<<"\n\t\t\t 5.Exit to main menu"<<endl;
				cout<<"\n\t\t\t Enter the choice : ";
				cin>>ch;
				switch(ch)
            	{
					case 1: 
							char symptoms,Y,N;
							cout<<"\n\t\t\t Enter the health status"<<endl; 
							cout<<"\n\t\t\t ******symptoms like FEVER,COLD,ACHES,COUGH,LOW OXYGEN LEVEL,SORE THROAT****** \n\t if all present choose Y(yes)|N(no) :\t ";
							cin>>symptoms;
							switch(symptoms)
							{
								case 'Y':
										s.patient_details();
										in.write();
										sin.swrite();
										break;
								case 'N':cout<<"\n\t\t\t No Symptoms of covid consult the doctor"<<endl;
										break;
										
							}
					break;
						
					case 2: 
							fopen(dfile,datafile,ios::in);
			   				
			   				s.display();
			   				break;
					case 3:
						
							flag=sec_search();
							if(flag==-1)
							cout<<"\n\t\t\t No data record ";	
							break;
					case 4: 
							flag=sec_search();
							if(flag==-1)
							cout<<"\n\t\t\t No data record found";
							else
							{
					   			s.remove_patients();
					   			in.write();
					   			sin.swrite();
				 			}
							break;
					case 5: system("cls");
							return 0;
					default :  exit(0);
	   			}
	   			dfile.close();
	   			ifile.close();	
	   			sifile.close();
	}
}

//function to open
void fopen1(fstream &file, char *fn,std::_Ios_Openmode mode)
{
	file.open(fn,mode);
	if(!file)
	{
		cout<<"\n\t\t\t Unable to open a file";
		exit(1);
	}
}

//vaccine class
class vaccine
{
	char name[15],daadaar[20],age[5],phone[11],gender[2],address[25];
	public:
		void read();
		void pack();
	    int search(char *);
		void datadisp();
		void unpack();
		void view_vaccine();
		int book_menu();
}v;

//index class for vaccination
class index1
{
	public:
		char iaadaar[15],addr[5];
		void initial();
		void write();
}idv[50],inv;

//sindex class for vaccination
class sindex1
{
	public :
		  char sname[20],saadaar[15];
		  void sinitial();
		  void swrite();
}sidv[50],sinv;

// function to copy index file to array structure
void index1::initial()
{
	ifile1.open(indexfile1,ios::in);
	if(!ifile1)
	{
		   indsize1=0;
		   return;
	}
   for(indsize1=0;;indsize1++)
   {
		ifile1.getline(idv[indsize1].iaadaar,15,'|');
		ifile1.getline(idv[indsize1].addr,5,'\n');
		if(ifile1.eof())
			break;
   }
   ifile1.close();
}

//function to copy sindex file to array structure
 void sindex1::sinitial()
{
	sifile1.open(sindexfile1,ios::in);
	if(!sifile1)
	{
		   sindsize1=0;
		   return;
	}
   for(sindsize1=0;;sindsize1++)
   {
		sifile1.getline(sidv[sindsize1].sname,20,'|');
		sifile1.getline(sidv[sindsize1].saadaar,15,'\n');
		if(sifile1.eof())
			break;
   }
   sifile1.close();
}

// function to update the index file
void index1::write()
{
	fopen1(ifile1,indexfile1,ios::out);
	for(j=0;j<indsize1;j++)
		ifile1<<idv[j].iaadaar<<"|"<<idv[j].addr<<"\n";
}

//function to upadate the secondary file
void sindex1::swrite()
{
	fopen1(sifile1,sindexfile1,ios::out);
	for(j=0;j<sindsize1;j++)
		sifile1<<sidv[j].sname<<"|"<<sidv[j].saadaar<<"\n";
}

// function to read the details of people
void vaccine::read()
{	
	cout<<"\n**********************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t DETAILS FOR VACCINATION \t\t\t"<<endl;
	cout<<"\n**********************************************************************************************************************************\n";
	int k;
	cout<<"\n\t\t Enter the Aadaar number="; 
	cin>>daadaar;
	if(search(daadaar)>=0)
	{
		  cout<<"\n\t\t\t Aadaar Number is already present we can't add to index file\n";
		  return;
	}
	for(j=indsize1;j>0;j--)
	{
	   if(strcmp(daadaar,idv[j-1].iaadaar)<0)
			idv[j]=idv[j-1];
	   else
			break;
	}
	fopen1(dfile1,datafile1,ios::app);
		cout<<"\n\t\t Enter your name :-  ";
        cin>>name;
        cout<<"\n\t\t Enter your gender (M|F) :-  ";
        cin>>gender;
        cout<<"\n\t\t Enter your age:- ";
        cin>>age;
        cout<<"\n\t\t Enter your permanent address :-  ";
        cin>>address;
        cout<<"\n\t\t Enter your Mobile number :- ";
        cin>>phone;
	pack();
	dfile1.seekg(0,ios::end);
	k=dfile1.tellg();
	dfile1<<buffer<<"\n";
	strcpy(idv[j].iaadaar,daadaar);
	sprintf(idv[j].addr, "%d",k);
	indsize1++;
	for(j=sindsize1;j>0;j--)
	{
		if(strcmp(name,sidv[j-1].sname)<0)
			sidv[j]=sidv[j-1];
		else if((strcmp(name,sidv[j-1].sname)==0) && (strcmp(daadaar,sidv[j-1].saadaar)<0))
				sidv[j]=sidv[j-1];
		else
				break;
	}
	strcpy(sidv[j].sname,name);
	strcpy(sidv[j].saadaar,daadaar);
	sindsize1++; 
}

//function to pack
void vaccine::pack()
{
		strcpy(buffer,daadaar);	strcat(buffer,"|");
		strcat(buffer,name);	strcat(buffer,"|");
		strcat(buffer,age);	strcat(buffer,"|");
		strcat(buffer,gender);	strcat(buffer,"|");
		strcat(buffer,phone);	strcat(buffer,"|");
		strcat(buffer,address);	strcat(buffer,"|");
}

//function to search based on name (secondary key)
int vaccine::search(char * faadaar)
{
	int low=0,high=indsize1-1,mid;
	while(low <=high)
	{
		mid = (low+high)/2;
		if(strcmp(faadaar,idv[mid].iaadaar)==0)
			return mid;
		if(strcmp(faadaar,idv[mid].iaadaar)>0)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

//function to search based on name secondary key
int sec_search1()
{
	int pos,i,flag=-1;
	cout<<"\n**************************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t SEARCHING DETAILS \t\t\t"<<endl;
	cout<<"\n**************************************************************************************************************************************\n";
	cout<<"\n\t\t\t Enter the Name to search(sec key):";
	cin>>skey;
	cout<<"\n\t\t\t The searched record details are :"<<endl;
	cout<<setiosflags(ios::left);
	cout<<"\t\t\tAadaar:"<<"\t\t\tName:"<<endl;
	fopen1(dfile1,datafile1,ios::in|ios::out);
	for(i=0;i<sindsize1;i++)
		 if(strcmp(skey,sidv[i].sname)==0)
		  {
			cout<<"\t\t\t"<<sidv[i].saadaar<<"\t\t\t"<<sidv[i].sname<<endl;
			flag=i;
		  }
	return flag;
}

//function to book slots
void vaccine ::view_vaccine()
{
	slots();
}
int slots()
{	
	cout<<"\n************************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t VACCINATION DRIVE COUNT \t\t\t"<<endl;
	cout<<"\n************************************************************************************************************************************\n";
    string line;
    ifstream file("vaccineindex.txt");
    if(file.is_open())
  {
        while(!file.eof())
    {
            getline(file,line);
            //cout<< line << endl;
            count++;
        }
        file.close();
    }
    number();
}
void number()
{
		
  	count--;
    cout<<"\n\t\t\t Number of people vaccinated : " << count << endl;
    cout<<"\n\t\t\t Vaccinatinons left : "<<num_of_vaccine - count<<endl;
}

//function to display the datafile
void vaccine::datadisp()
{	
	cout<<"\n*************************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t VACCINATION DRIVE DETAILS \t\t\t"<<endl;
	cout<<"\n*************************************************************************************************************************************\n";
	cout<<setiosflags(ios::left);
	cout<<setw(16)<<"Aadaar"<<setw(16)<<"Name"<<setw(16)<<"Age"<<setw(16)<<"Gender"<<setw(16)<<"Phone"<<setw(2)<<"Address\n";
	cout<<"\n";
	while(1)
	{
		unpack();
		if(dfile1.eof()) 	
  		break;
	}
	
	cout<<endl<<"\n\t\t\t The index file details are "<<endl;
	cout<<setw(10)<<"Aadaar"<<setw(10)<<"address";
	for(j=0;j<indsize1;j++)
		 cout<<endl<<setw(10)<<idv[j].iaadaar<<setw(10)<<idv[j].addr;
	cout<<endl<<"\n The secondary file details are " <<endl;
	cout<<setw(20)<<"Name"<<setw(15)<<"primary reference";
	for(j=0;j<sindsize1;j++)
		  cout<<endl<<setw(20)<<sidv[j].sname<<setw(15)<<sidv[j].saadaar;
}

//Inherited class booking
class book_appointments :public vaccine
{
	struct appoint
	{
 		int status;
 		char start[10];
 		char end[10];
		char max[10];
		char min[10];
 		struct appoint *Next;
	}*head;

void create_app()
{
    int i ;
    appoint *temp, *p;
 	
    head = NULL;
 	cout<<"\n*********************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t VACCINATION DRIVE APPOINTMENTS \t\t\t"<<endl;
	cout<<"\n*********************************************************************************************************************************\n";
    cout<<"\n\t How many Appointments : ";
    cin>>nodes;
 
    for(i=0; i<nodes; i++)
    { 
    	 cout<<"\n\t NEW APPOINTMENT FOR VACCINATION ";
      	 temp = new(struct appoint);  //Step 1: Allocate Memory
   		temp->status=0;
       	cout<<"\n\t\t\t Enter Start Time: "; //Step 2: Store data and address
       	cin>>temp->start;
       	cout<<" \n\t\t\tEnter End Time: "; //Step 2: Store data and address
       	cin>>temp->end;
       	cout<<"\n\t\t\t Enter min Time: "; //Step 2: Store data and address
       	cin>>temp->min;
       	cout<<"\n\t\t\t Enter max Time: "; //Step 2: Store data and address
       	cin>>temp->max;
     
       temp->Next = NULL;
 
       if(head == NULL)   //Step 3: Attach node in linked List
       {
          head = temp;
          p = head;
       }
       else
       {
          p->Next = temp;
          p = p->Next;
       }
 
    } 

}
void display_SLL()
{
  appoint *p;
 	cout<<"\n************************************************************************************************************************************\n";
	cout<<"\n\t\t\t\t VACCINATION BOOKINGSLOTS \t\t\t"<<endl;
	cout<<"\n************************************************************************************************************************************\n";
    p = head;
    cout<<"Status\tStart Timet\tEnd Time\tMin Time\tMax Time\n";
    while(p != NULL)
    {
    if(p->status==0)
    {
    cout<<"\n\t\t\t Free";
    }
    else
    {
     cout<<"\n\t\t\t Booked"; 
 }
       cout<<"\t\t"<<p->start<<"\t\t"<<p->end<<"\t\t"<<p->min<<"\t\t"<<p->max<<"\t\t";
       p = p->Next;
    }
 
}
void book_app()
{
char time[10];
struct appoint *p;
cout<<"\n\t\t\t Enter The Time Slot to book appointment";
cin>>time;
p=head;
 while(p!=NULL)
 {
  if(strcmp(time,p->start) == 0)
  {
    if(p->status == 0)
    {
     p->status=1;
     cout<<"\n\t\t\t Your Appointment Is Booked\n\n";
    }
    else
    cout<<"\n\t\t\t Appointment slot is Busy\n\n";
    break;
  }
  else
   p=p->Next;
 }
 
 if(p==NULL)
 cout<<"\n\t\t\t Appointment slot is Not available\n\n";
 display_SLL();

}

void sort_app()
{
char str[10];
struct appoint *p;
int i;
for(i=0;i<nodes-1;i++)
 {
  p = head;
  while(p->Next!=NULL)
  {
   if(strcmp(p->start,p->Next->start)>0)
   {
    int tmp=p->status;
    p->status=p->Next->status;
    p->Next->status=tmp;
    
    strcpy(str,p->start);
    strcpy(p->start,p->Next->start);
    strcpy(p->Next->start,str);
   
    strcpy(str,p->end);
    strcpy(p->end,p->Next->end);
    strcpy(p->Next->end,str);
   
    strcpy(str,p->min);
    strcpy(p->min,p->Next->min);
    strcpy(p->Next->min,str);
   
    strcpy(str,p->max);
    strcpy(p->max,p->Next->max);
    strcpy(p->Next->max,str);   
   }
   p=p->Next;
  }
 }
  cout<<"\n\t\t\t SORTED\n";
  display_SLL();
}
public:
int book_menu()
{
	create_app();

display_SLL();

book_app();

sort_app();

return 0;
}
};

//close inerited class


//function to unpack the data file
void vaccine::unpack()
{
	 dfile1.getline(buffer,100,'\n');
	 j=0;
	 if(buffer[j]!='$')
		 while(buffer[j]!='\0')
		{
			if(buffer[j]=='|')
				cout<<"\t\t";
			else
				cout<<buffer[j];
			j++;
		}
		cout<<"\n";
}

//main program for vaccination_menu
int vaccination_menu()
{
	int ch,flag;
	book_appointments bookapp;
	inv.initial();
	sinv.sinitial();
	for(;;)
	{
		cout<<"\n********************************************************************************************************************************\n";
		cout<<"\n\t\t\t\t Welcome to Vaccination Menu"<<endl;
		cout<<"\n********************************************************************************************************************************\n";
   		cout<<" \n\t\t\t 1: Add NEW Record"<<endl;
		cout<<" \n\t\t\t 2: View VACCINE DATA"<<endl;
    	cout<<" \n\t\t\t 3: Search"<<endl;
    	cout<<" \n\t\t\t 4: Statistics"<<endl;
    	cout<<" \n\t\t\t 5:Slot booking"<<endl;
    	cout<<" \n\t\t\t 6.Exit"<<endl;
		cout<<"\n\t\t\t Enter the choice:";
		cin>>ch;
		switch(ch)
		{	
			case 1:		char status,P,N;
						cout<<"\n\t\t\t Enter the health status Positive(P) Negative(N):-";
						cin>>status;
						switch(status)
						{
						case 'P':cout<<"\n\t\t\t Cannot be vaccinated"<<endl;
								break;
						case 'N':cout<<endl<<" \n\t\t\tEnter the details : " <<endl;
								v.read();
								inv.write();
								sinv.swrite();
								break;
						}
					break;
			case 2: 
					fopen1(dfile1,datafile1,ios::in);
			   		cout<<"\n\t\t\t the datafile,indexfile and secondary file" <<endl;
			   		v.datadisp();
			   		break;
			case 3:
					cout<<"\n\t\t\t To search based on (Name) sec key ";
					flag=sec_search1();
					if(flag==-1)
					cout<<"\n\t\t\t No data record ";
					break;
			case 4: 
					v.view_vaccine();
					break;
			case 5:
					bookapp.book_menu();
					break;
			default : return 0;
	   }
	   dfile1.close();
	   ifile1.close();	
	   sifile1.close();
	}
}

//main program 
int main()
{
	int choice,c;
	for(;;)
	{
		cout<<"\n\t\t\t***************************************************************************"<<endl;
		cout<<"\n\t\t\t\t\t\t MAIN MENU"<<endl;
		cout<<"\n\t\t\t\t\t\t 1.COVID MENU"<<endl;
		cout<<"\n\t\t\t\t\t\t 2.VACCINATION"<<endl;
		cout<<"\n\t\t\t\t\t\t 3.EXIT"<<endl;	
		cout<<"\n\t\t\t*****************************************************************************"<<endl;
		cout<<"\n\t\t\t Enter the Choice 1,2,3 :";
		cin>>choice;
		switch(choice)
		{	
			case 1: cout<<"\n\t\t\t Covid"<<endl;
					covid_menu();
					break;
			case 2: cout<<"\n\t\t\t Vaccination"<<endl;
			 		vaccination_menu();
			 		break;
			case 3: exit(0);
			default:exit(0);
		}
	}
}
