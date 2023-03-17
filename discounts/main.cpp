#include <iostream>
#include <fstream>
using namespace std;

class productDiscount
{
public:
    int Discount_id;
    char start_date[20]; //20Mar2023
    char end_date[20];
    float Discount_amount;
    //discount on products
    int Product_id;//here we will connect with the product class
    char Product_name[20]; //name will be used to displayed on the file
};
//allowed for IT staff to add discounts
void add_Product_Discount()
{
    fstream discounts;
    discounts.open("product_discounts.txt",ios::out|ios::app);
    productDiscount d;
    char c='Y';
    while (c=='Y')
    {
        cout<<"  -----Entre dicount id-----  "<<endl;
        cin>>d.Discount_id;

        cout<<"  -----Entre dicount start date-----  "<<endl;
        cin>>d.start_date;

        cout<<"  -----Entre dicount End date-----  "<<endl;
        cin>>d.end_date;

        cout<<"  -----Entre product id-----  "<<endl;
        cin>>d.Product_id;

        cout<<"  -----Entre product name-----  "<<endl;
        cin>>d.Product_name;

        discounts.write((char*)&d,sizeof(d));

        cout<<"----------Do You Want to Add a new Discount? (Y/N)----------";
            cin>>c; //take decision to complete asking for new discounts
    }
    discounts.close();
}
//allowed for customers to show discounts
void display_Product_Discount(){
    fstream file;
    file.open("product_discounts.txt",ios::in);
    productDiscount d;
    if(file.is_open()){
        while (!file.eof()){
            file.read((char*)&d,sizeof(d));
            cout<<"product: "<<d.Product_name<<'\t'
            <<"Amount of disccount: "<<d.Discount_amount<<'\t'
            <<"from: "<<d.start_date<<'\t'
            <<"to: "<<d.end_date<<'\t'<<endl;
        }
    }else {
        cout<<"Ooops!...We Cannot access file"<<endl;
    }

}

