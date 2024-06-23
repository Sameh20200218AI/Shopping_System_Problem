#include <iostream>
#include<vector>
#include<string>
using namespace std;
int ID = 0;
struct Item
{
    int id,quantity;
    string name;
    double price;
};
class Seller
{
   private:
       string name,email;
       int maxItem;
       vector<Item> Items;
       double total_money=0;
   public:
    Seller(string n , string em,int num_of_item)
    {
        name =n;
        email = em;
        maxItem = num_of_item;

    }
    string get_name_of_seller()
    {
        return name;
    }
    string get_email_of_seller()
    {
        return email;
    }
    int get_max_item()
    {
        return maxItem;
    }
    double get_total_money_for_user()
    {
        return total_money;
    }
    void add_item_in_list()
    {
        for(int i =0;i<maxItem;i++)
        {
            Item item_ ;
            cout <<"Enter name , price ,quantity for item : "<<endl;
            string n;
            cin >>n;
            int q ;
            int p;
            cin >>p;
            cin >> q;
            ID++;
            item_.id = ID;
            item_.name=n;
            item_.price=p;
            item_.quantity = q;
            Items.push_back(item_);
        }
    }
    void add_new_item_in_list()
    {
        Item item_ ;
            cout <<"Enter name ,id , price ,quantity for item : "<<endl;
            string n;
            cin >>n;
            int id;
            int q ;
            int p;
            cin >>id;
            cin >>p;
            cin >> q;
            while(true)
            {
                if(id <=ID )
                {


                    cout <<"An id must be distinct !!!"<<endl;
                    cout <<"Please enter a value id only : "<<endl;
                    cin >>id;
                }
                else
                break;

            }
            //ID++;
            item_.id = id;
            item_.name=n;
            item_.price=p;
            item_.quantity = q;
            Item * it=search_an_item_by_id(id);
            if(it==nullptr)
            Items.push_back(item_);
            else
            {
              /*for(int i=0;i<Items.size();i++)
              {
                  if(id==Items[i].id)
                  {
                      Items[i].quantity += q;
                      break;
                  }
              }*/
              it ->quantity +=q;
            }
    }
    void print_info_of_seller()
    {
        cout <<"The name of seller is : "<<get_name_of_seller()<<endl;
        cout <<"The email of seller is : "<<get_email_of_seller()<<endl;
        cout <<"The maximum number of items of seller is : "<<get_max_item()<<endl;
    }
    void print_items()
    {
        for(int i=0;i<Items.size();i++)
        {
            cout <<"The name of "<<i+1<<" st is : "<<Items[i].name<<endl;
            cout <<"The id of "<<i+1<<" st is : "<<Items[i].id<<endl;
            cout <<"The quantity of "<<i+1<<" st is : "<<Items[i].quantity<<endl;
            cout <<"The price of "<<i+1<<" st is : "<<Items[i].price<<endl;
        }
    }
    Item* search_an_item_by_id(int id)
    {
        for(int i=0;i<Items.size();i++)
        {
            if(Items[i].id == id )
                return &Items[i];
        }
        return nullptr;

    }
    double get_price_of_an_item(int id)
    {
        for(int i=0;i<Items.size();i++)
              {
                  if(id==Items[i].id)
                  {
                      return Items[i].price;
                  }
              }
              return 0.0;
    }
    void sell_an_items(int id_of_an_item,int quantity)
    {
        if(search_an_item_by_id(id_of_an_item)==nullptr)
        {
            cout << "This item does not exist in items list !!!" <<endl;
        }
        else
        {
            if(search_an_item_by_id(id_of_an_item)->quantity >= quantity)
            {
             total_money = total_money + quantity * get_price_of_an_item(id_of_an_item);
            }
            else
            {
                int min_quantity;
                if(quantity < search_an_item_by_id(id_of_an_item)->quantity)
                    min_quantity = quantity;
                else
                    min_quantity=search_an_item_by_id(id_of_an_item)->quantity;
                total_money = total_money + min_quantity*get_price_of_an_item(id_of_an_item);
            }
        }
    }

};
int main()
{
    string name,email;
    int num_of_item;
    cout <<"Please enter name , email , number of item : "<<endl;
    cin >>name>>email;
    cin >>num_of_item;
     Seller person(name,email,num_of_item);
     person.add_item_in_list();
while(true)
 {


     cout <<"-----------------------------------------------------"<<endl;
     int choice;
     cout <<"1. Print My Information."<<endl;
     cout <<"2. Add An Item."<<endl;
     cout <<"3. Sell An Item."<<endl;
     cout <<"4. Print Items."<<endl;
     cout <<"5. Find an Item by ID"<<endl;
     cout <<"6. Exit"<<endl;
     cout <<"Please enter your choice : "<<endl;
     cin >> choice;
     while(choice <1 || choice >6)
     {
       cout <<"Please enter your choice again : "<<endl;
     cin >> choice;
     }
     if(choice == 1 )
        person.print_info_of_seller();
     else if(choice ==2)
     {

         person.add_new_item_in_list();
     }

     else if(choice==3)
     {
         int id,quantity;
         cout <<"Please enter id , quantity : "<<endl;
         cin >> id>>quantity;
         while(id<1 || quantity <0)
         {
             cout <<"Please enter id , quantity again : "<<endl;
             cin >> id>>quantity;

         }
         person.sell_an_items(id,quantity);
     }
     else if(choice == 4)
        person.print_items();
     else if(choice ==5)
     {
         int id;
         cout <<"Enter id please : "<<endl;
         cin >> id;
         while(id<1)
         {
              cout <<"Enter id please : "<<endl;
              cin >> id;
         }
         Item * it = person.search_an_item_by_id(id);
         if(it == nullptr)
         {
             cout <<"This item does not exist in items !!!"<<endl;
         }
         else
         {
              cout <<"This item does exist in items , then : "<<endl;
              cout <<"The name is : "<<it->name<< endl;
              cout <<"The id is : "<<it->id<< endl;
              cout <<"The price is : "<<it->price<< endl;
              cout <<"The quantity is : "<<it->quantity<< endl;
         }
     }
     else if(choice ==6)
        break;

 }
 cout <<"The total amount of money is :  "<<person.get_total_money_for_user()<<endl;
    return 0;
}
