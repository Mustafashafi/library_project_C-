#include<iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>


struct book{
    string name;
    string author;
    int id;
	book *next;
};

struct student{
    string name;
    string email;
    string book;
    int id;
     student *next,*prev;
};
 book *start_lib=NULL;
 student *start=NULL;
 void Available_books(book*);
 void Search_book(book*);
 void Search_byBookName(book*);
 void Search_byBookId(book*);
 void Search_byBookAuthor(book*);
 book *initialize_lib( book *);
 student *book_issue( student *);
 student *book_return( student *);
void display( student *);

void STRING(){
    cout<<"\n\n";
    cout<<"\t\t\t     ****************************************\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *     ----------------------------     *\n";
    cout<<"\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n";
    cout<<"\t\t\t     *     ----------------------------     *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     ****************************************\n";
    cout<<"\n\n";
    cout<<"\t\t\t     ****************************************\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *       ------------------------       *\n";
    cout<<"\t\t\t     *           STUDENT LIBRARY            *\n";
    cout<<"\t\t\t     *       ------------------------       *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *         *********************        *\n";
    cout<<"\t\t\t     *         *  USAMA SARDAR     *        *\n";
    cout<<"\t\t\t     *         *   M.MUSTAFA       *        *\n";
    cout<<"\t\t\t     *         *   SHAHEER KHAN    *        *\n";
    cout<<"\t\t\t     *         *********************        *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *                                      *\n";
    cout<<"\t\t\t     *     PROJECT FOR LIBRARY MANAGMENT    *\n";
   
    cout<<"\t\t\t     ****************************************\n";
    
}

int main(){
	
	start_lib= initialize_lib(start_lib);	
    STRING();

    int choice;
    do{
        
        cout<<"\n\t\t\t\t      MAIN FUNCTION: ";
        cout<<"\n\t\t\t\t     1.BOOKS available in library ";
        cout<<"\n\t\t\t\t     2.Search a book in libraray ";
        cout<<"\n\t\t\t\t     3.ISSUE OF BOOKS ";
        cout<<"\n\t\t\t\t     4.RETURN OF BOOKS ";
        cout<<"\n\t\t\t\t     5.DISPLAY STUDENT DETAILS ";
        cout<<"\n\t\t\t\t     6.EXIT\n ";
        cout<<"\t\t\t     ****************************************\n";
       cout<<"\n\t\t\t\t      Enter your choice: ";
        cin>>choice;
        switch(choice){
        	case 1:{
                Available_books(start_lib);
                break;
            }
        	case 2:{
                Search_book(start_lib);
                break;
            }
            case 3:{
                start=book_issue(start);
                break;
            }
            case 4:{
                start=book_return(start);
                break;
            }
            case 5:{
                display(start);
                break;
            }
            case 6:{
                exit(1);
            }
            default:{
                cout<<"\n\t\t\t\t      ...Invalid Option!...\n";
                cout<<"\n\t\t\t\t      Press any key to try again: ";
          
            }
        }
    }while(choice!=6);
    
    
    return 0;
}


void Search_book(book* start_lib){
	int choice;
	
	do{
		
		cout<<"\n\t\t\t\t  Enter your choice , By which you wanna search the book : ";
    	cout<<"\n\t\t\t\t     1.Search book by name ";
    	cout<<"\n\t\t\t\t     2.Search book by his id ";
        cout<<"\n\t\t\t\t     3.Search book by author name ";
        cout<<"\n\t\t\t\t     4.Return to main ";
        cout<<"\n\t\t\t\t     5.Exit "<<endl;
	    cin>>choice; 
        switch(choice){
        	case 1:{
                Search_byBookName(start_lib);
                break;
            }
            case 2:{
                Search_byBookId(start_lib);
                break;
            }
            case 3:{
                Search_byBookAuthor(start_lib);
                break;
            }
            case 4:{
                main();
            }
             case 5:{
                exit(1);
            }
            default:{
                cout<<"\n\t\t\t\t      ...Invalid Option!...\n";
                cout<<"\n\t\t\t\t      Press any key to try again: ";
          
            }
        }
    }while(choice!=5);
    
}

void Search_byBookName(book* start_lib){
	book* ptr=start_lib;
	int flag;
	string book_name;
	cout<<"Enter book name , on which  you wanna search book : "<<endl;
	cin>>book_name;
while(ptr!=NULL){
            if(ptr->name==book_name){
                flag=1;
            cout<<"Book is Available : ";   
            cout<<"\n\t_________________________________________________\n";    
            cout<<"\n\t Book Title:"<<ptr->name;
            cout<<"\n\t Name of Author:"<<ptr->author;
            cout<<"\n\t Book ID:"<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
                break;
            }
            ptr=ptr->next;
        }
            if(flag!=1){
            	cout<<"Book is not available on that book name:";
			}		
	
	

}
void Search_byBookId(book* start_lib){
	book* ptr=start_lib;
	int book_id,flag=0;
	cout<<"Enter book id , on which you wanna search book : "<<endl;
	cin>>book_id;
	 while(ptr!=NULL){
            if(ptr->id==book_id){
            flag=1;
            cout<<"Book is Available : ";   
            cout<<"\n\t_________________________________________________\n";    
            cout<<"\n\t Book Title:"<<ptr->name;
            cout<<"\n\t Name of Author:"<<ptr->author;
            cout<<"\n\t Book ID:"<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
                break;
            }
            ptr=ptr->next;
        }
            if(flag!=1){
            	cout<<"Book is not available on that ID:";
			}
}

void Search_byBookAuthor(book* start_lib){
	book* ptr=start_lib;
	string book_author_name;
	int flag;
	cout<<"Enter author name , on which  you wanna search book : "<<endl;
	cin>>book_author_name;
		 while(ptr!=NULL){
            if(ptr->author==book_author_name){
                flag=1;
            cout<<"Book is Available : ";   
            cout<<"\n\t_________________________________________________\n";    
            cout<<"\n\t Book Title:"<<ptr->name;
            cout<<"\n\t Name of Author:"<<ptr->author;
            cout<<"\n\t Book ID:"<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
            break;
            }
            ptr=ptr->next;
        }
            if(flag!=1){
            	cout<<"Book is not available on that author name :";
			}
}
book* initialize_lib( book *start_lib){
     book *ptr,*new_book1,*new_book2,*new_book3,*new_book4,*new_book5,*new_book6,*new_book7,*new_book8,*new_book9,*new_book10;

    new_book1=new book;
    new_book1->next=NULL;
    start_lib=new_book1;
    new_book1->name="COA";
	new_book1->author="SadatSir";
    new_book1->id=101;
    ptr=new_book1;

    new_book2=new book;
    new_book2->next=NULL;
    new_book2->name="DifferentialEquation";
    new_book2->author="MushtaqSir";
    new_book2->id=102;
    ptr->next=new_book2;
    ptr=new_book2;

    new_book3=new book;
    new_book3->next=NULL;
    new_book3->name="DataStructure";
    new_book3->author="ShamsSir";
    new_book3->id=103;
    ptr->next=new_book3;
    ptr=new_book3;

    new_book4=new book;
    new_book4->next=NULL;
    new_book4->name="ProfessionalEthics";
    new_book4->author="ColJaveed";
    new_book4->id=104;
    ptr->next=new_book4;
    ptr=new_book4;

    new_book5=new book;
    new_book5->next=NULL;
    new_book5->name="DiscreteStructure";
    new_book5->author="HamidullahSir";
    new_book5->id=105;
    ptr->next=new_book5;
	ptr=new_book5;
	
	new_book6=new book;
    new_book6->next=NULL;
    new_book6->name="DataScience";
    new_book6->author="HammadSir";
    new_book6->id=106;
    ptr->next=new_book6;
	ptr=new_book6;
	
	 new_book7=new book;
    new_book7->next=NULL;
    new_book7->name="Islamyat";
    new_book7->author="AdnanSir";
    new_book7->id=107;
    ptr->next=new_book7;
	ptr=new_book7;
	
	 new_book8=new book;
    new_book8->next=NULL;
    new_book8->name="ProgrammingFundamentals";
    new_book8->author="FaisalSir";
    new_book8->id=108;
    ptr->next=new_book8;
	ptr=new_book8;
	
	 new_book9=new book;
    new_book9->next=NULL;
    new_book9->name="Statistics";
    new_book9->author="IrfanSir";
    new_book9->id=109;
    ptr->next=new_book9;
	ptr=new_book9;
	
	 new_book10=new book;
    new_book10->next=NULL;
    new_book10->name="ArtificialIntelligance";
    new_book10->author="OsmanSir";
    new_book10->id=110;
    ptr->next=new_book10;
	ptr=new_book10;	
	
	  
    return start_lib;
}
void Available_books(book* start_lib){
	int i=1;
	 cout<<"\n\t******** Books Available: *************\n";
        for(book *ptr=start_lib;ptr!=NULL;ptr=ptr->next){
           cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Book :"<<i;
            cout<<"\n\t Book Title:"<<ptr->name;
            cout<<"\n\t Name of Author:"<<ptr->author;
            cout<<"\n\t Book ID:"<<ptr->id;
            cout<<"\n\t_________________________________________________\n";
            i++;
    }
}
student* book_issue( student *start ){
     book *ptr;
     student *ptr2,*new_student;
    int id,flag=0;
    if(start_lib==NULL){
        cout<<"\n\t\t\t\t No books left in the library to issue!\n\t\t\t Sorry for the inconvenience!\n";
    }else{
        cout<<"\n\n\t Enter the Book ID: ";
        cin>>id;
        ptr=start_lib;
        while(ptr!=NULL){
            if(ptr->id==id){
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==1){
            new_student=new student;
            cout<<"\n\t Enter Student Details:\n ";
            cout<<"\n\t Enter your Name: ";
            cin>>new_student->name;
            cout<<"\n\t Enter your Email: ";
            cin>>new_student->email;
    		new_student->book=ptr->name;
            new_student->id=ptr->id;
            new_student->next=NULL;
           	cout<<"\n\t Issue of Book ID  done successfully!\n";
            cout<<"\n\n\t************************************\n";
            
            if(start==NULL){
                start=new_student;
            }else{
                ptr2=start;
                while(ptr2->next!=NULL){
                    ptr2=ptr2->next;
                }
                ptr2->next=new_student;
            }
        }
		else{
           cout<<"\n\t\t      ...Invalid Option!...\n";
          cout<<"\n\t\t      Press any key to try again: ";
        }
    }
    
	return start;
}

student* book_return( student *start){
	student *prev=start;
	
    int flag=0,identity;
    string name;
    cout<<"\n\n\t*************** Books Submission: ****************\n";
    cout<<"\n\n\t Enter your Book ID: ";
    cin>>identity;
    cout<<"\n\n\t Enter student name: ";
    cin>>name;
    
    if(start->id==identity && start->name==name)
	   {
	   	flag=1;
	   	cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Student Name:"<<start->name;
            cout<<"\n\t Student Email:"<<start->email;
            cout<<"\n\t Name of Book Issued:"<<start->book;
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\n\t Return of Book ID done successfully! "<<identity;
            cout<<"\n\n\t*************************************************\n";
	   start=start->next;
	   delete(prev);
	   }

	student *ptr;
    for(ptr=prev->next; ptr!=NULL; ptr=ptr->next){
	if(ptr->id==identity && ptr->name==name)
	   {
	   	flag=1;
	   	cout<<"\n\t_________________________________________________\n";
            cout<<"\n\t Student Name:"<<ptr->name;
            cout<<"\n\t Student Email:"<<ptr->email;
            cout<<"\n\t Name of Book Issued:"<<ptr->book;
            cout<<"\n\t_________________________________________________\n";
            cout<<"\n\n\t Return of Book ID done successfully! "<<identity;
            cout<<"\n\n\t*************************************************\n";
            prev->next=ptr->next;
	   delete(ptr);
		break;
	   }
	   prev=prev->next;
	}
	if(flag!=1){
	cout<<"\n\t Sorry the book doesn't exist in record ! Please recheck the entered ID and Name";	 	      
	}
	
	
    return start;
}

void display( student *start){
     student *ptr;
    ptr=start;
    int flag;
    	cout<<"\n\n\t************* Details of Students: **************\n";
    while(ptr!=NULL){
	flag=1;    
        cout<<"\n\t_________________________________________________\n";
        cout<<"\n\t\t Student Name:"<<ptr->name;
        cout<<"\n\t\t Student Email:"<<ptr->email;
        cout<<"\n\t\t Name of Book Issued:"<<ptr->book;
        cout<<"\n\t\t Book ID:"<<ptr->id;
        cout<<"\n\t_________________________________________________\n";
        cout<<"\n\n\t********************************************\n";
        ptr=ptr->next;
    }
    if(flag!=1){
    	cout<<"\n\n\t      ********* NO BOOK ISSUE YET : *********    \n\n";
	}
    
}


