/*
****************************************************************************
*                        FCI – Programming 1 – 2017                        *
** Project Name: Inventory Management System                               *
** Last Modification Date: 08/10/2017                                      *
** Author: Mahmoud Ahmed Tawfik                                            *
****************************************************************************
*/

#include <iostream>
using namespace std;

int main()
{
	int user,pass,status1=1,status2=1,choice,logout,productId1=0,productCount1,productChechOut1,productId2,productCount2,productChechOut2;
	double profit=0,productCost1,productCost2;
	const int adminUser   = 123 ;
	const int adminPass   = 123 ;
	const int adminUser1   = 12345 ;
	const int adminPass1   = 12345 ;
	const int cashierUser = 987 ;
	const int cashierPass = 987 ;
	while(status1)
	{
		cout<<"Please enter your username:"<<endl;
		cin>>user;
		cout<<"Please enter your password:"<<endl;
		cin>>pass;
		if((adminUser == user && adminPass ==  pass) || (adminUser1 == user && adminPass1 ==  pass) )
		{
			status1 = 0;
			status2 = 1;
			while(status2)
			{
				cout<<"Please select an action:"<<endl;
				cout<<"1-Insert products’ details."<<endl;
				cout<<"2-Display how many items of each product are remaining."<<endl;
				cout<<"3-Display profit."<<endl;
				cout<<"4-Log out."<<endl;
				cin>>choice;
				if(choice == 1)
				{
					//------ Details product #1 ------
					cout<<"Pleas enter product one name:"<<endl;
					cin>>productId1;
					cout<<"Please enter how many items of product "<<productId1<<" exist:"<<endl;
					cin>>productCount1;
					cout<<"Please enter the cost of each item of product "<<productId1<<endl;
					cin>>productCost1;
					//------ Details product #2 ------
					cout<<"Pleas enter product two name:"<<endl;
					cin>>productId2;
					cout<<"Please enter how many items of product "<<productId2<<" exist:"<<endl;
					cin>>productCount2;
					cout<<"Please enter the cost of each item of product "<<productId2<<endl;
					cin>>productCost2;
			
				}
				else if (choice == 2)
				{
					if(productId1 != 0 )
					{
						cout<<"Product "<<productId1<<":"<<productCount1<<", Product "<<productId2<<":"<<productCount2; //If products are registered.
					}
					else
					{
						cout<<"No products yet."; //If products are not registered.
					}
					cout<<endl;
				}
				else if (choice == 3)
				{
					cout<<"Profit = "<<profit<<endl; //Display profit.
				}
				else if (choice == 4)
				{
					cout<<"Please select an action:"<<endl;
					cout<<"1-Login."<<endl;
					cout<<"2-Terminate the program."<<endl;
				    cin>>logout;
					if(logout == 1)
					{
						 status1  = 1 ;
						 status2  = 0 ;
					}
					else if(logout == 2)
					{
					    status2  = 0 ;
						status1  = 0 ;
						break;
					}
					else
					{
						cout<<"sorry, But your choice isn't correct"<<endl;
					}
				}
				else
				{
					cout<<"sorry, But your choice isn't correct"<<endl;
				}
			
			}
		}
		else if(cashierUser == user && cashierPass ==  pass)
		{
			status1 = 0;
			status2 = 1;
			while(status2)
			{
				cout<<"Please select an action:"<<endl;
				cout<<"1-Check out items."<<endl;
				cout<<"4-Log out."<<endl;
				cin>>choice;
				if(choice == 1)
				{
					cout<<"Please enter how many items of product "<<productId1<<" would you like to check out"<<endl;
					cin>>productChechOut1;
					if(productChechOut1 > productCount1)
					{
						cout<<"Sorry, we don’t have enough items of product "<<productId1<<" to check out."<<endl;
					}
					else
					{
					    profit += (productChechOut1 * productCost1);
				    	productCount1 -= productChechOut1;
					}
					cout<<"Please enter how many items of product "<<productId2<<" would you like to check out"<<endl;
					cin>>productChechOut2;
					if(productChechOut2 > productCount2)
					{
						cout<<"Sorry, we don’t have enough items of product "<<productId2<<" to check out."<<endl;
					}
					else
					{
					    profit += (productChechOut2 * productCost2);
				    	productCount2 -= productChechOut2;
					}
				}
				else if (choice == 4)
				{
					cout<<"Please select an action:"<<endl;
					cout<<"1-Login."<<endl;
					cout<<"2-Terminate the program."<<endl;
				    cin>>logout;
					if(logout == 1)
					{
						status1  = 1 ;
						status2  = 0 ;
					}
					else if(logout == 2)
					{
						status2  = 0 ;
						status1  = 0 ;
						break;
					}
					else
					{
						cout<<"sorry, But your choice isn't correct"<<endl;
					}
			
				}
				else
				{
					cout<<"sorry, But your choice isn't correct"<<endl;
				}

			}
		}
		else
		{
			cout<<"Log in Failed"<<endl;
		}
		
	}

return 0;
}