#include <iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include <string.h>
using namespace std;
class ASSOCIATION;
class member
{
    int id;
    string name;
    string city;
    string email;
    long long int mobile;
    float getamt;
    float amountpaid;
    float amount2paid;
    float intrestamt;
    int month;
public:
    member();
    void getmember();
    void putmember();
    int getid();
    string getname();
    friend ASSOCIATION;
     bool character(char c)
    {
        return ((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z'));
    }
    bool Digit(const char c)
    {
        return (c >= '0' && c <= '9');
    }
    bool is_valid(string email)
    {
        if (!character(email[0]))
        {
            return 0;
        }
        int atSymbol = -1, dotSymbol = -1;
        for (int i = 0;i < email.length(); i++)
        {
            if (email[i] == '@')
            {
                atSymbol = i;
            }
            else if (email[i] == '.')
            {
                dotSymbol = i;
            }
        }
        if (atSymbol == -1 || dotSymbol == -1)
            return 0;

        if (atSymbol > dotSymbol)
          return 0;

        return !(dotSymbol >= (email.length() - 1));
    }


};
struct dnode
{
    dnode *prev;
    member data;
    dnode *next;
};

class ASSOCIATION
{
private:
    dnode* head=NULL;
    dnode *tail=NULL;
    double tresuary;
    int fund;
    float interest;
    int mem;
    float intamt;
    int no_month;
public:
    ASSOCIATION()
    {
        tresuary=0;
        fund=1000;
        interest=2;
        mem=0;
        intamt=0;
    }
    void insert(member a)
    {
        dnode *newnode=new dnode;
        newnode->prev=NULL;
        newnode->next=NULL;
        newnode->data=a;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else{

            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        mem++;


        ofstream file("Members.txt",ios::app);
        file<<endl<<a.name<<"\t\t"<<a.id<<"\t\t"<<a.city<<"\t\t"<<a.mobile<<"\t\t"<<a.email<<"\t\t"<<endl;
        file.close();
        ofstream outfile("Members file.dat",ios::app);
        outfile.write((char*)&a, sizeof(a));
    }
    void display()
    {
        dnode *p=head;
        member a;
        if(p==NULL)
        {
            cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tNO MEMBERS FOUND !!\n";
        }
        else
        {
            int i=1;
            cout<<"\n\n\n\t\t\t\t\t\t\tTOTAL MEMBERS : "<<mem<<endl<<endl;;
            //ifstream in("Members file.dat",ios::in);
            //in.read((char*)&a,sizeof(a));
            //in.close();
            for(p=head;p!=NULL;p=p->next)
            {

                cout<<"\n\t\t\t\tMember "<<i<<endl;
                p->data.putmember();
                i++;
            }



        }


    }
    void modify(int id)
    {
        dnode *p=head;
        for(p=head;p!=NULL;p=p->next)
        {
            if(id==p->data.getid())
            {
                int ch;
                VJ:
                cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tMENU\n";
                cout<<"\n\t\t\t\t1.Name\n\t\t\t\t2.City\n\t\t\t\t3.Mobile\n";
                cout<<"\n\n\t\t\t\tEnter which data to be change :";
                cin>>ch;
                switch(ch)
                {

                    case 1:
                        {
                            cout<<"\n\t\t\t\tEnter your name :";
                            cin.ignore();
                            getline(cin,p->data.name);
                            break;
                        }
                    case 2:
                        {
                            cout<<"\n\t\t\t\tEnter your city :";
                            cin>>p->data.city;
                            break;
                        }
                    case 3:
                        {
                            cout<<"\n\t\t\t\tEnter your mobile number :";
                            cin>>p->data.mobile;
                            break;
                        }
                    default:
                        {
                            char s;
                            cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tDo you want to continue (y/n):";
                            cin>>s;
                            if(s=='y')
                                goto VJ;
                        }


                }
            }
        }
    }


    int setid(int id)
    {
        dnode *p=head;
        for(p=head;p!=NULL;p=p->next)
        {
            if(id==p->data.getid())
            {
                return 1;
            }

        }
        return 0;
    }
    void remove()
    {

            dnode *del;
            if(head==NULL)
            {
                cout<<"NO MEMBER FOUND !!"<<endl;
            }
            else
            {
                del=tail;
                tail=tail->prev;
                tail->next=NULL;

            }

    }
    void remove(char x)
    {
        if(head==NULL)
            cout<<"NO MEMBER FOUND !!"<<endl;
        else
        {
            head=head->next;
            head->prev=NULL;
        }
    }
    void remove(int id)
    {
        dnode *p=head;
        int pos;
        for(p=head;p!=NULL;p=p->next)
            if(p->data.getid()==id)
                pos++;
        if(mem<=1)
        {
            cout<<"\n\n\t\t\t\t\t\tMEMBER CANNOT BE DELETED!!"<<endl;
        }
        else
        {
            dnode *temp=head;
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            cout<<"\n\n\t\t\t\t\t\tMEMBER DELETED!!"<<endl;
        }

    }
    member peek(int pos)
    {
         dnode *temp=head;
            for(int i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            return temp->data;
    }
    void display(int id)
    {
        dnode *p=head;
        for(p=head;p!=NULL;p=p->next)
        {
            if(id==p->data.getid())
            {
                p->data.putmember();
            }
        }
    }
    int search(member a)
    {
        dnode *temp=head;
            for(int i=1;temp!=NULL;i++)
            {
                temp=temp->next;
                if(temp->data.id==a.id)
                    return i;
            }
            return 0;
    }
    /*void del(int id)
    {
        dnode *p=head;
        int i=0;
        for(p=head;p!=NULL;p=p->next)
        {
            i++;
            if(id==p->data.getid())
            {
                remove(i);
            }
        }
    }*/
    int sangam()
    {
        int m,j;
        V:
        system("cls");
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tASSOCIATION MENU\n";
        cout<<"\t\t\t\t\t\t\t----------------\n\n";
        cout<<"\t\t\t\t\t1.fund collection \n\t\t\t\t\t2.Member's id who want to pay due  \n\t\t\t\t\t3.Due collection  \n\t\t\t\t\t4.fund distribute \n\t\t\t\t\t5.Treasury Balance\n\t\t\t\t\t6.Exit\n";
        cout<<"\n\n\t\t\t\t\tEnter your choice :";
        cin>>m;
        switch(m)
        {
        case 1:
            {
                system("cls");
                dnode *p=head;
                if(p==NULL)
                {
                    cout<<"\n\n\t\t\t\t\tNO MEMBERS FOUND !!\n";
                }
                else
                {
                    cout<<"\n\n\t\t\t\t\t\tFUND COLLECTION\n";
                    cout<<"\t\t\t\t\t\t---------------\n";
                    cout<<"\n\n\n\t\t\t\t\tFIXED FUND : 1000\n";

                    for(p=head;p!=NULL;p=p->next)
                    {
                        char s;
                        cout<<"\n\t\t\t\t\tHave "<<p->data.getname()<<" paid fund :(y/n) ";
                        cin>>s;
                        if(s=='y')
                        {
                            tresuary+=fund;
                            p->data.amountpaid+=fund;
                        }
                    }
                }
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tFUND COLLECTED\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
                getch();
                break;
            }

        case 2:
            {
                system("cls");
                int c=0;
                dnode *p=head;
                for(p=head;p!=NULL;p=p->next)
                {
                    if(p->data.getamt!=0)
                    {
                        cout<<"\n\t\t\t\t\tMember's id who want to pay due..."<<endl;
                        cout<<"\n\n\n\t\t\t\t\t  ID\tNAME\n";
                        c=1;
                        break;
                    }

                }

                    for(p=head;p!=NULL;p=p->next)
                    {
                        if(p->data.getamt!=0)
                        {
                            cout<<"\n\t\t\t\t\t"<<p->data.getid()<<"\t"<<p->data.name<<endl;
                        }

                    }


                if(c==0)
                {
                    cout<<"\n\n\t\t\t\t\tNO MEMBERS FOUND !!\n";
                }
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
                getch();
                break;
            }
        case 3:
            {
                system("cls");

                cout<<"\n\n\t\t\t\t\t\tDUE COLLECTION\n";
                cout<<"\t\t\t\t\t\t--------------\n";
                dnode *p=head;
                int id;
                cout<<"\n\t\t\t\t\tEnter the member's id :";
                cin>>id;
                if(setid(id)==0)
                    cout<<"\n\t\t\t\t\tID Doesn't Exist!!"<<endl;
                else
                {
                    for(p=head;p!=NULL;p=p->next)
                    {
                    if(p->data.getid()==id && p->data.month!=0)
                    {
                        char c;
                        cout<<"\n\t\t\t\t\tHave you pay interest (or) due amount (i/d):";
                        cin>>c;
                        if(c=='i')
                        {
                            cout<<"\n\t\t\t\t\tPAY "<<(p->data.getamt*(5+(p->data.month-5))*interest)/500 <<" : "<<endl;
                            p->data.amountpaid+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                            tresuary+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                            p->data.intrestamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                        intamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;

                        }
                        else
                        {
                            cout<<"\n\t\t\t\t\tPAY "<<((p->data.getamt*(5+(p->data.month-5))*interest)/500)+(p->data.getamt/5)<< " : "<<endl;
                            p->data.amountpaid+=((p->data.getamt*(5+(p->data.month-5))*interest)/500)+(p->data.getamt/5);
                            tresuary+=((p->data.getamt*(5+(p->data.month-5))*interest)/500)+(p->data.getamt/5);
                            p->data.intrestamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                            intamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                            p->data.month--;
                        }
                        p->data.intrestamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;
                        intamt+=(p->data.getamt*(5+(p->data.month-5))*interest)/500;

                    }

                }
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
                getch();
                break;

                }

            }
        case 4:
            {
                system("cls");
                cout<<"\n\n\t\t\t\t\t\tFUND DISTRIBUTION\n";
                cout<<"\t\t\t\t\t\t-----------------\n";
                if(tresuary==0)
                    {
                        cout<<"\n\n\n\t\t\t\t\t\ttreasury is empty!!"<<endl;
                        goto V;
                    }

                dnode *p=head;
                int id;
                cout<<"\n\t\t\t\t\tEnter the id who want amount : ";
                cin>>id;
                if(setid(id)==0)
                    cout<<"\n\t\t\t\t\tID Doesn't Exist!!"<<endl;
                else
                {

                    for(p=head;p!=NULL;p=p->next)
                {
                    if(p->data.getid()==id)
                    {
                        if(p->data.getamt!=0)
                        {
                            cout<<"\n\t\t\t\t\tYou have already borrowed the amount "<<p->data.getamt<<" from the association!!"<<endl;
                            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
                            getch();
                            break;
                        }
                        K:
                        cout<<"\n\t\t\t\t\tEnter the amount :";
                        cin>>p->data.getamt;
                        p->data.month=5;
                        if(p->data.getamt>tresuary)
                        {
                            cout<<"\n\t\t\t\t\tLow Balance !!!"<<endl;
                            goto K;
                        }

                        else
                        {

                            tresuary-=p->data.getamt;
                        }
                    }
                }
                }
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
                getch();

                break;

            }
        case 5:
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\tTreasury Balance: "<<tresuary<<endl;
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
            getch();
            break;
        }
        case 6:
        {
            return 7;
        }

        }

        goto V;

    }

};



int main()
{
    ASSOCIATION l;
    int ch;
    system("cls");
    system("color B2");
    cout<<"\n\n\t\t\t\t\t\t\t  AFS";
    cout<<"\n\n\n\n\n\n\n\n\t\t \t\t  \t WELCOME TO ASSOCIATION FINANCE SYSTEM";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
    getch();
    HARI:
    system("cls");
    system("color 01");
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\tMENU\n";
    cout<<"\t\t\t\t\t\t\t----\n\n";
    cout<<"\t\t\t\t\t1.ADD MEMBER \n\t\t\t\t\t2.MODIFY MEMBER \n\t\t\t\t\t3.DELETE MEMBER \n\t\t\t\t\t4.DISPLAY A PERSON \n\t\t\t\t\t5.DISPLAY ALL MEMBERS \n\t\t\t\t\t6.ASSIOCIATION MENU\n\t\t\t\t\t7.EXIT!!\n";
    cout<<"\n\n\t\t\t\tEnter the choice :";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            system("cls");
            cout<<"\n\n\n\n\t\t\t\t\t\tEnter the details \n";
            cout<<"\t\t\t\t\t\t-----------------\n";
            member m;
            m.getmember();
            l.insert(m);
            break;
        }
    case 2:
        {
            system("cls");
            int id;
            cout<<"\n\n\t\t\t\t\t\t\tMODIFY NUMBER ";
            cout<<"\n\n\t\t\t\t\t\tEnter the member id :";
            cin>>id;
            l.modify(id);
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
            break;
        }
    case 3:
        {
            system("cls");
            int id;
            cout<<"\n\n\t\t\t\t\t\t\t\tDELETE NUMBER ";
            cout<<"\n\n\n\n\t\t\t\t\t\tEnter the member's id :";
            cin>>id;
            l.remove(id);
            cin.ignore();
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
            break;
        }
    case 4:
        {
            system("cls");
            int id;
            cout<<"\n\n\t\t\t\t\t\t\tASSIOCIATION MEMBER ";
            cout<<"\n\n\n\n\t\t\t\t\t\tEnter the member's id :";
            cin>>id;
            l.display(id);
            cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
            getch();
            cin.ignore();
            break;
        }
    case 5:
        {
            system("cls");
            cout<<"\n\n\t\t\t\t\t\t\tASSIOCIATION MEMBERS\n ";
            cout<<"\t\t\t\t\t\t\t--------------------\n";
            l.display();
            cin.ignore();
            break;
        }
    case 6:
        {
            system("cls");
            l.sangam();
            break;
        }
    }
    //cin.ignore();
    cin.get();
    //}
    goto HARI;
}

member :: member()
{
    amount2paid=0;
    amountpaid=0;
    intrestamt=0;
    getamt=0;
    month=0;
}
void member::getmember()
{
    cout<<"\n\n\t\t\t\t\tEnter your name :";
    cin.ignore();
    getline(cin,name);
    cout<<"\n\t\t\t\t\tEnter your id :";
    cin>>id;
    cout<<"\n\t\t\t\t\tEnter your city name :";
    cin>>city;
    cout<<"\n\t\t\t\t\tEnter your mobile number :";
    cin>>mobile;
    E:

    cout<<"\n\t\t\t\t\tEnter your email id :";
    cin>>email;
    if(!is_valid(email))
    {
        cout<<"\n\n\t\t\t\tEmail not valid !!!\tTry again \n";
        goto E;
    }
    cout<<"\n\n\t\t\t\t\t\t\tMEMBER CREATED !!!"<<endl;
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress Any Key to Continue...";
    getch();

}
void member::putmember()
{
    cout<<"\n\t\t\t\t\t1.Your name :"<<name<<endl;
    cout<<"\t\t\t\t\t2.Your id : "<<id<<endl;
    cout<<"\t\t\t\t\t3.Your city name :"<<city<<endl;
    cout<<"\t\t\t\t\t4.Your mobile number :"<<mobile<<endl;
    cout<<"\t\t\t\t\t5.Your email id :"<<email<<endl;
    cout<<"\t\t\t\t\t6.Balance amount to be paid :"<<amount2paid<<endl;
    cout<<"\t\t\t\t\t7.Amount paid for ASSOCATION :"<<amountpaid<<endl;
    cout<<"\t\t\t\t\t8.Interest amount paid for association : "<<intrestamt<<endl;

}
int member::getid()
{
    return id;
}

string member :: getname()
{
    return name;
}
