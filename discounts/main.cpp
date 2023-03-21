#include <bits/stdc++.h>
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
    int Menue_id;//here we will connect with the product class
    char Menue_type[20]; //name will be used to displayed on the file
    double charge;
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
        cout<<"  -----Entre discount id-----  "<<endl;
        cin>>d.Discount_id;

        cout<<"  -----Entre discount start date-----  "<<endl;
        cin>>d.start_date;

        cout<<"  -----Entre discount End date-----  "<<endl;
        cin>>d.end_date;

        cout<<"  -----Entre product id-----  "<<endl;
        cin>>d.Menue_id;

        cout<<"  -----Entre product name-----  "<<endl;
        cin>>d.Menue_type;

        cout<<"  -----Entre the original price of the product-----  "<<endl;
        cin>>d.charge;

        cout<<"  -----Entre Amount of Discount-----  "<<endl;
        cin>>d.Discount_amount;

        discounts.write((char*)&d,sizeof(d));

        cout<<"----------Do You Want to Add a new Discount? (Y/N)----------"<<endl;
            cin>>c; //take decision to complete asking for new discounts
    }
    discounts.close();
}
//allowed for customers to show discounts
void display_Product_Discount()
{
    fstream file;
    file.open("product_discounts.txt",ios::in);
    productDiscount d;
    if(file.is_open()){
         file.read((char*)&d,sizeof(d));
        while (!file.eof()){


            cout<<"product:             "<<'\t'<<d.Menue_type<<endl;
            cout<<"Amount of disccount: "<<'\t'<<d.Discount_amount<<"%"<<endl;
            cout<<"from:                "<<'\t'<<d.start_date<<endl;
            cout<<"to:                  "<<'\t'<<d.end_date<<endl;
            cout<<"new Price!:          "<<'\t'<<(d.charge-(d.charge*(d.Discount_amount/100)))<<endl;
            cout<<"---------------------------------------------------------"<<endl;

             file.read((char*)&d,sizeof(d));

        }
    }else {
        cout<<"Ooops!...We Cannot access file"<<endl;
    }

}

void Search_Product(){
    char product[30];
    cout<<"  -----Entre the product to check discount-----  "<<endl;
    cin>>product;

    fstream file;
    file.open("product_discounts.txt",ios::in);
    productDiscount d;
    bool found=false;
    if(file.is_open()){
         file.read((char*)&d,sizeof(d));
        while (!file.eof()){
            if (!strcmp(product,d.Menue_type))
            {
                cout<<"product:             "<<'\t'<<d.Menue_type<<endl;
                cout<<"Amount of disccount: "<<'\t'<<d.Discount_amount<<"%"<<endl;
                cout<<"from:                "<<'\t'<<d.start_date<<endl;
                cout<<"to:                  "<<'\t'<<d.end_date<<endl;
                cout<<"new Price!:          "<<'\t'<<(d.charge-(d.charge*(d.Discount_amount/100)))<<endl;
                cout<<"---------------------------------------------------------"<<endl;

                found=true;
            }

             file.read((char*)&d,sizeof(d));

        }
        if (!found) cout<<"Unfortunately, No discounts Avaliable!\n";
    }
    else {
        cout<<"Ooops!...We Cannot access file"<<endl;
    }



}

void update_discount(){
 char product[30];
 float disc;
    cout<<"  -----Entre the product you want to update-----  "<<endl;
    cin>>product;


    fstream file;
    file.open("product_discounts.txt",ios::in);
    productDiscount d;
    bool found=false;
    if(file.is_open()){
         file.read((char*)&d,sizeof(d));
        while (!file.eof()){
            if (!strcmp(product,d.Menue_type))
            {
                cout<<"  -----Entre the new discount-----  "<<endl;
                cin>>d.Discount_amount;
                int curpos=file.tellg();
                int studsiz=sizeof(d);

                file.seekp(curpos-studsiz,ios::beg);
                file.write((char*)&d,sizeof(d));

                file.seekg(curpos-studsiz,ios::beg);
                file.read((char*)&d,sizeof(d));

                cout<<"product:             "<<'\t'<<d.Menue_type<<endl;
                cout<<"Amount of disccount: "<<'\t'<<d.Discount_amount<<"%"<<endl;
                cout<<"from:                "<<'\t'<<d.start_date<<endl;
                cout<<"to:                  "<<'\t'<<d.end_date<<endl;
                cout<<"new Price!:          "<<'\t'<<(d.charge-(d.charge*(d.Discount_amount/100)))<<endl;
                cout<<"---------------------------------------------------------"<<endl;

        }

        file.read((char*)&d,sizeof(d));
        }
        if (!found) cout<<"There is no discounts on that product to update!";

    }
    else {
        cout<<"Ooops!...We Cannot access file"<<endl;
    }
}

void delete_discount(){
    char product[30];
    cout<<"  -----Entre the discount you want delete-----  "<<endl;
    cin>>product;

    fstream file ("product_discounts.txt",ios::in);
    fstream outfile ("temp.txt",ios::out);



    productDiscount d;
    bool found=false;
    if(file.is_open()){
         file.read((char*)&d,sizeof(d));
        while (!file.eof()){
            if (strcmp(product,d.Menue_type))
            {
                outfile.write((char*)&d,sizeof(d));

                found=true;
            }

             file.read((char*)&d,sizeof(d));

        }
        file.close();
        outfile.close();
        remove("product_discounts.txt");
        rename("temp.txt","product_discounts.txt");

        if (!found) cout<<"There is no disconts on that product!";
    }
    else {
        cout<<"Ooops!...We Cannot access file"<<endl;
    }

}

int main (){

   // add_Product_Discount();
    display_Product_Discount();
    //Search_Product();
    //update_discount();
    //delete_discount();
}



