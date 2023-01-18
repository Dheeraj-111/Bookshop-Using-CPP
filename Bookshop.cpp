//Om Namah Shivay
//Bookshop Management System...
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class book{
    private:
        char *author,*pulisher,*title;
        int *stock;
        float *price;
    public:
        book()
        {
            author=new char[20]; 
            pulisher=new char[20];
            title=new char[20];
            price=new float;
            stock=new int;
        }
        void feeddata();
        void editdata();
        void showdata();
        int search(char[],char[]);
        void buy();
};
void book::feeddata()
{
    cin.ignore();
    cout<<"\nEnter Author Name:- ";
    cin.getline(author,20);
    cout<<"\nEnter Title Name:- ";
    cin.getline(title,20);
    cout<<"\nEnter Pulisher Name:- ";
    cin.getline(pulisher,20);
    cout<<"\nEnter Price of Book:- ";
    cin>>*price;
    cout<<"\nEnter Stock:- ";
    cin>>*stock;
}
void book::editdata()
{
    cin.ignore();
    cout<<"\nEnter Author Name:- ";
    cin.getline(author,20);
    cout<<"\nEnter Title Name:- ";
    cin.getline(title,20);
    cout<<"\nEnter Pulisher Name:- ";
    cin.getline(pulisher,20);
    cout<<"\nEnter Price of Book:- ";
    cin>>*price;
    cout<<"\nEnter Stock:- ";
    cin>>*stock;
}
void book::showdata()
{
    cout<<"\nAuthor Name:- "<<author;
    cout<<"\nTitile Name:- "<<title;
    cout<<"\nPublisher Name:- "<<pulisher;
    cout<<"\nPrice:- "<<*price<<"/-";
    cout<<"\nStock:- "<<*stock;
}
int book::search(char title_to_buy[20],char author_to_buy[]){
    if(strcmp(title_to_buy,title)==0 && strcmp(author_to_buy,author)==0)
        return 1;
    else
        return 0;
}
void book::buy()
{
    int count;
    cout<<"\nEnter number of book you want to buy:- ";
    cin>>count;
    if(count<=*stock)
    {
        *stock=*stock-count;
        cout<<"\nBooks bought Successfully...";
        cout<<"\nAmount:- Rs."<<(*price)*count<<"/-";
    }
    else
    {
        cout<<"\nRequired copies not in stock...";
    }
}
int main()
{
    book *B[20];
    int i=0,r,t,choice;
    char titlebuy[20],authorbuy[20];
    while(1)
    {
        cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		switch(choice){
		    case 1: B[i]=new book;
		            B[i]->feeddata();
		            i++;
		            break;
		    case 2:cin.ignore();
		            cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				    cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				    for(t=0;t<i;t++)
				    {
				        if(B[t]->search(titlebuy,authorbuy))
				        {
				            B[t]->buy();
				            break;
				        }
				    }
				    if(t==i)
				    {
				        cout<<"\nThis Book is not in stock...";
				    }
				    break;
			case 3:cin.ignore();
			        cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				    cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				    for(t=0;t<i;t++)
				    {
				        if(B[t]->search(titlebuy,authorbuy))
				        {
				            cout<<"\nBook Found Successfully";
						    B[t]->showdata();
				            break;
				        }
				    }
				    if(t==i)
				    {
				        cout<<"\nThis Book is not in stock...";
				    }
				    break;
			case 4:cin.ignore();
			        cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				    cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				     for(t=0;t<i;t++)
				    {
				        if(B[t]->search(titlebuy,authorbuy))
				        {
				            cout<<"\nBook Found Successfully....";
				            B[t]->editdata();
				            break;
				        }
				    }
				    if(t==i)
				    {
				        cout<<"\nThis Book is not in stock...";
				    }
				    break;
			case 5:exit(0);
			default: cout<<"\n Invalid Choice Entered....";
		}
    }
    return 0;
}






