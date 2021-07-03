#include<iostream>
#include <math.h>
#include <windows.h>                  // For gotoxy() and Sleep function
#include <ctime>		           	 // For Displaying time
#include <iomanip>
#include <limits>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int a[5][5]={{0,1,0,0,1},{1,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{1,1,0,1,0}};
int q[5], rear=0, front=0;

void enqueue(int data)
{
    if(rear==0)
    {
        front=rear=1;
        q[rear]=data;
        //cout<<"Q:"<< q[rear]<<endl;
    }
    else if(rear<5)
    {
        rear=rear+1;
        q[rear]=data;
        //cout<<"Q:"<< q[rear]<<endl;
    }
    else
    cout<<"Queue Overflown"<<endl;
}

int dequeue()
{
    int item;
    if(front==rear)
    {
        item=q[front];
        front=rear=0;
        //cout<<"D: "<<item<<endl;
        return item;
    }
    else if(front!=0)
    {
        item=q[front];
        front=front+1;
        //cout<<"D: "<<item<<endl;
        return item;
    }
    else
    cout<<"Queue is empty"<<endl;
}

bool qempty()
{
    if(rear==0)
    {
        return true;
    }
    else
    return false;
}

void BFS(int s)
{
    int color[5];
    int d[5];
    int pie[5];
    int u,v;
    for(u=0;u<5;u++)
    {
        if(u!=s)
        {
            color[u]=1;
            d[u]=999;
            pie[u]=NULL;
        }

    }
    color[s]=2;
    d[s]=0;
    pie[s]=NULL;
    enqueue(s);
    while(!qempty())
    {
        u=dequeue();
        cout<<u << endl;

            for(v=0;v<5;v++)
            {
               if(a[u][v]==1)
               {
                   if(color[v]==1)
                   {
                       color[v]=2;
                       d[v]=d[u]+1;
                       pie[v]=u;
                       enqueue(v);
                       //cout<<v << endl;
                   }
               }
            }

        color[u]=3;

    }
}

void LogIn()
{
    system("cls");

	string username = "";
	string password = "";
	char ch,ch2,retry;
	int i = 0, j = 0;
	//gotoxy(55,10);
	cout << "\t\t\t\t\t\tLOGIN"<<endl;
	//gotoxy(20,15);
	cout << "Enter Username: ";
	//gotoxy(36,15);

	ch2=getch();
	while(ch2 != 13){                  // gets input until 'Enter' key is pressed

		if(ch2 == '\b'){
			if(username.size() > 0 )  {
				username.erase(username.begin() + username.size() -1);
				cout << "\b \b";
				j--;
			}
			ch2 = getch();
		}
		else{
			if(j<10)
			{
				cout << ch2;
				username.push_back(ch2);
				ch2 = getch();
				j++;
			}
			else{
				ch2 = getch();
			}
		}
	}

	cout << "\nEnter Password: ";
	//gotoxy(36,16);
	ch=getch();
	while(ch != 13){                  // gets input until 'Enter' key is pressed

		if(ch == '\b'){
			if(password.size() > 0){
				password.erase(password.begin() + password.size() -1);
				cout << "\b \b";
				i--;
			}
			ch = getch();
		}
		else{
			if(i<10)
			{
				password.push_back(ch);
				cout << "*"; 					  // For showing stars instead of actual alphabets
				ch = getch();
				i++;
			}
			else{
				ch = getch();
			}
		}
	}
	if (username == "tanvir_ome" && password == "12345")
	{
		//gotoxy(15,16);
		cout << "\n\n Username & Password Matched !! ";
		cout << "\n\n\t Access Granted...\n\n";
		return;
	}
	else
	{
		system("cls");
		cout << "\n\n You entered Wrong UserName/Password ";
		cout << "\n\n\t Press 'R' or 'r' to Enter Again OR any other key to exit ...\n\n";
		cin >> retry;
			if(retry == 'r' || retry == 'R')
			{
				system("cls");
				LogIn();
			}
			else
			{
				exit(0);
			}
	}
}

int main()
{
    LogIn();

    cout<<"For the graph: "<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"BFS Tree: "<<endl;
    BFS(0);
}

