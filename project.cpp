/*** Key for Employee Login ***/
/*** SECRET KEY :-  "sQfw1D"  ***/
#include<iostream>
//#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include<vector>
using namespace std;
vector <string>item_names;
vector <int>item_quantity;
vector <int>item_price;
vector <int>total_price;
int bill=0;
string SECRET_KEY="sQfw1D";


/*** Forward Declaration of Classes ***/
class Login;
class FileHandling;
class CouponCode;
class foodjoint;
class pizza;
class burger;
class sandwich;
class shakes;


/******** CODE FOR Login CLASS**********/
class Login {
    string username;
    string password;
public:
    Login(void);
    void createAcount();
    int loginAcount();
};


/******** CODE FOR FileHandling CLASS**********/
class FileHandling {
public:
    void addToMyCoupon(string s);
    void deleteFromMyCoupon(string deleteCoupon);
    void printCouponCodes();

};

/******** CODE FOR CouponCode CLASS**********/
class CouponCode {
public:
    void addCouponCode(void);
    void deleteCouponCode(void);
    void printCouponCode(void);
};

/******** CODE FOR foodjoint CLASS**********/
class foodjoint {
public:
    void welcome();
    virtual void display_menu();
};

/******** CODE FOR pizza CLASS**********/
class pizza:public foodjoint {
public:
    void display_menu();
};

/******** CODE FOR burger CLASS**********/
class burger:public foodjoint {
public:
    int cost_arr[4]= {75,110,85,120};
    void display_menu();
};

/******** CODE FOR sandwich CLASS**********/
class sandwich:public foodjoint {
public:
    int cost_arr[3]= {35,45,50};
    void display_menu();
};

/******** CODE FOR shakes CLASS**********/
class shakes:public foodjoint {
public:
    int cost_arr[4]= {40,50,60,85};
    void display_menu();
};


/*** Declaration of member functions of (Class Login) class STARTED ***/
Login :: Login(void) {
    ofstream fout,gout;
    fout.open("usersData.txt",ios::app);
    gout.open("myCoupon.txt",ios::app);
    fout.close();
    gout.close();

}
void Login:: createAcount() {
    while(true) {
        cout<<"Enter UserName:";
        cin>>username;
        /************** Below you Need To Add STL To Convert username ToLOwerCase ***************/
        transform(username.begin(), username.end(), username.begin(), ::tolower);
        /************** Above you Need To Add STL To Convert username ToLOwerCase ***************/
        /* Code to check username STARTED... */
        string checkUsername,tempPassword;
        int usernameStatus=1;
        ifstream fin;
        fin.open("usersData.txt");
        while(!fin.eof()) {
            fin>>checkUsername>>tempPassword;
            if(username.compare(checkUsername)==0) {
                cout<<"{{ '"<<username<<"' is taken. "<<"Please try other username. }}"<<endl;
                usernameStatus=0;
                break;
            }
        }
        if(usernameStatus==0) {
            fin.close();
            usernameStatus=1;
            continue;
        } else if(usernameStatus==1) {
            break;
        }
        /* Code to check username ENDED... */
    }
    cout<<"Enter Password:";
    cin>>password;
    /* Code to insert Code in file STARTED...*/
    ofstream fout;
    fout.open("usersData.txt",ios::app);
    fout<<username<<" "<<password<<endl;
    /* Code to insert Code in file ENDED...*/
    cout<<"Account Created successfully."<<endl<<endl;
}

int Login:: loginAcount() {
    string checkUsername,tempPassword,lpassword;
    while(true) {
        cout<<"Enter UserName:";
        cin>>username;
        /************** Below you Need To Add STL To Convert username ToLOwerCase ***************/
        transform(username.begin(), username.end(), username.begin(), ::tolower);
        /************** Above you Need To Add STL To Convert username ToLOwerCase ***************/
        /* Code to check username STARTED... */
        int usernameStatus=0;
        ifstream fin;
        fin.open("usersData.txt");
        while(!fin.eof()) {
            fin>>checkUsername>>tempPassword;
            if(username.compare(checkUsername)==0) {
                usernameStatus=1;
                break;
            }
        }

        if(usernameStatus==1) {
            fin.close();
            break;
        } else if(usernameStatus==0) {
            int localUserName;
            cout<<"{{ User is not present.}}"<<endl;
            while(true) {
                cout<<"1.Create Account"<<endl<<"2.Try Other User name"<<endl<<":";
                cin>>localUserName;
                switch(localUserName) {
                case 1:
                    createAcount();
                    break;
                case 2:
                    break;
                default:
                    cout<<"Wrong Input";
                }
                if(localUserName==2 || localUserName==1 ) {
                    break;
                }
            }
            if(localUserName==2) {
                continue;
            }
        }
        /* Code to check username ENDED... */
    }

    /* Code to check password CorrectNess */
    do {
        int localPassword;
        cout<<"Enter Password:";
        cin>>lpassword;
        if(tempPassword.compare(lpassword)) {
            do {
                cout<<"\nWrong password!!\n1.Try again"<<endl<<"2.exit"<<endl<<":";
                cin>>localPassword;
                switch(localPassword) {
                case 1:
                    break;
                case 2:
                    exit(1);
                    break;
                default:
                    cout<<"Wrong Input"<<endl;
                }
            } while(!(localPassword>=1 && localPassword<=2));
        } else {
            break;
        }
    } while(true);
    /* Code to check password CorrectNess */
    cout<<"Logged In successfully."<<endl;
    return 1;
}
/*** Declaration of member functions of (Class Login) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class FileHandling) class STARTED ***/
void FileHandling :: addToMyCoupon(string s) {
    ofstream fout;
    fout.open("myCoupon.txt",ios::app);
    fout<<s<<endl;
    fout.close();
}
void FileHandling :: deleteFromMyCoupon(string deleteCoupon) {
    string tempCouponCode;
    ofstream fout;
    ifstream fin;
    fout.open("nf.txt");
    fin.open("myCoupon.txt");
    fin>>tempCouponCode;
    while(!fin.eof()) {
        if(tempCouponCode.compare(deleteCoupon)==0) {
            fin>>tempCouponCode;
            continue;
        }
        fout<<tempCouponCode<<endl;
        fin>>tempCouponCode;
    }
    fout.close();
    fin.close();
    remove("myCoupon.txt");
    rename("nf.txt","myCoupon.txt");
}
void FileHandling::printCouponCodes() {
    int checkNumber=0;
    ifstream fin;
    fin.open("myCoupon.txt");
    while(fin.eof()==0) {
        string tempCouponString;
        fin>>tempCouponString;
        if(tempCouponString.empty() && checkNumber==0) {
            cout<<"  No Active Coupon Codes"<<endl;
        } else if(!tempCouponString.empty()) {
            checkNumber=1;
            cout<<"  ->"<<tempCouponString<<endl;
        }
    }
    fin.close();
}
/*** Declaration of member functions of (Class FileHandling) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class CouponCode) class STARTED ***/
void CouponCode:: addCouponCode() {
    string coupon_code;
    cout<<"Enter COUPON CODE\n( NOTE: Coupon code should contain two digits either at the begining or at the end )"<<endl<<"=>";
    cin>>coupon_code;
    FileHandling f;
    f.addToMyCoupon(coupon_code);
}

void CouponCode:: deleteCouponCode() {
    string deleteCoupon,tempCouponCode;
    cout<<endl<<"Enter Coupon Code To Be Deleted"<<endl;
    cin>>deleteCoupon;
    FileHandling f;
    f.deleteFromMyCoupon(deleteCoupon);
}

void CouponCode:: printCouponCode(void) {
    cout<<endl<<"**Active Coupon Codes**\n";
    FileHandling f;
    f.printCouponCodes();
}
/*** Declaration of member functions of (Class CouponCode) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class foodjoint) class STARTED ***/
void foodjoint:: welcome() {
    cout<<"\t\t\t\t=====================\n";
    cout<<"\t\t\t\t|Welcome to Two Guys|\n";
    cout<<"\t\t\t\t=====================\n";

    cout<<"\n\nPlease provide your details:\n";
    cout<<"---------------------------\n\n";

    Login user;
    int loginChoice,checkLogin=0,loginPrompt;
    do {
        cout<<"1.Customer Login"<<endl<<"2.Employee Login"<<endl<<"=>";
        cin>>loginPrompt;
        if(loginPrompt==2) {
            string secret_key;
            cout<<"Enter SECRET KEY"<<endl<<"=>";
            cin>>secret_key;
            if(secret_key.compare(SECRET_KEY)==0) {
                CouponCode c;
                c.printCouponCode();
                cout<<endl<<"1.Add Coupon Code\n2.Delete Coupon Code\n3.Main Menu"<<endl<<"=>";
                int choiceCoupon;
                cin>>choiceCoupon;

                if(choiceCoupon==1) {
                    CouponCode c;
                    c.addCouponCode();
                }

                else if(choiceCoupon==2) {
                    CouponCode c;
                    c.deleteCouponCode();
                }

                else {
                    continue;
                }

            } else {
                cout<<"\nInvalid SECRET KEY!!\n\n";
            }
        }

        else if(loginPrompt==1) {
            do {
                cout<<"1.Create Account"<<endl<<"2.Login"<<endl<<"=>";
                cin>>loginChoice;
                switch(loginChoice) {
                case 1:
                    user.createAcount();
                    break;
                case 2:
                    checkLogin=user.loginAcount();
                    break;
                default:
                    cout<<"Try again..."<<endl;
                }
            } while(!checkLogin);
        }

    } while(loginPrompt!=1);
    cout<<"\n\nWhat would you like to order today!!\n";
}

void foodjoint:: display_menu() {
    cout<<"\t\t----------Our Menu----------\n\n";
    cout<<"1.Pizza\n2.Burgers\n3.Sandwiches\n4.Milkhakes\n";
}
/*** Declaration of member functions of (Class foodjoint) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class pizza) class STARTED ***/
void pizza:: display_menu() {
    cout<<"\t\t----------Pizza Menu----------\n\n";
    cout<<"1.Classic Margharita\n2.Chicken Fazita\n3.Chicken Creamy Max\n4.Peppy Paneer Pizza\n5.Back to Main Menu\n";
}
/*** Declaration of member functions of (Class pizza) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class burger) class STARTED ***/

void burger:: display_menu() {
    cout<<"\t\t----------Burger Menu----------\n\n";
    cout<<"\n1.Zinger Burger        - Rs.75\n2.Chicken Burger       - Rs.110\n3.Veg. Tandoori Burger - Rs.85\n4.Chicken Kebab Burger - Rs.120\n5.Back to Main Menu\n";
}

/*** Declaration of member functions of (Class pizza) class STARTED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class sandwich) class STARTED ***/



void sandwich:: display_menu() {
    cout<<"\t\t----------Sandwich Menu----------\n\n";
    cout<<"\n1.Grilled Cheese Sandwich - Rs.35\n2.Chilli Cheese Sandwich  - Rs.45\n3.Golden Corn Sandwich    - Rs.55\n4.Back to Main Menu\n";
}

/*** Declaration of member functions of (Class sandwich) class ENDED ***/

/***---------------------------------------------------------------------***/

/*** Declaration of member functions of (Class shakes) class STARTED ***/


void shakes:: display_menu() {
    cout<<"\t\t----------Milkshakes Menu----------\n\n";
    cout<<"\n1.Vanilla/Butterscotch Milkshake - Rs.40\n2.Chocolate Milkshake            - Rs.50\n3.Strawberry Milkshake           - Rs.60\n4.Kitkat/Oreo Milkshake          - Rs.85\n5.Back to Main Menu\n";
}
/*** Declaration of member functions of (Class shakes) class ENDED ***/

/***---------------------------------------------------------------------***/


void add_bill(int &size,int &quantity) {
    switch(size) {
    case 1:
        bill+=250*quantity;
        break;
    case 2:
        bill+=550*quantity;
        break;
    case 3:
        bill+=900*quantity;
        break;
    }
}
template<class X>void add_bill(X &o,int &ch,int &quantity) {
    switch(ch) {
    case 1:
        bill+=o.cost_arr[0]*quantity;
        break;
    case 2:
        bill+=o.cost_arr[1]*quantity;
        break;
    case 3:
        bill+=o.cost_arr[2]*quantity;
        break;
    case 4:
        bill+=o.cost_arr[3]*quantity;
        break;
    }
}

int main() {
    vector <string>pizzaS_vec= {"Classic Margharita - Small","Chicken Fazita - Small","Chicken Creamy Max - Small","Peppy Paneer Pizza - Small"};
    vector <string>pizzaM_vec= {"Classic Margharita - Medium","Chicken Fazita - Medium","Chicken Creamy Max - Medium","Peppy Paneer Pizza - Medium"};
    vector <string>pizzaL_vec= {"Classic Margharita - Large","Chicken Fazita - Large","Chicken Creamy Max - Large","Peppy Paneer Pizza - Large"};
    vector <string>burger_vec= {"Zinger Burger","Chicken Burger","Veg. Tandoori Burger","Chicken Kebab Burger"};
    vector <string>sandwich_vec= {"Grilled Cheese Sandwich","Chilli Cheese Sandwich","Golden Corn Sandwich"};
    vector <string>shakes_vec= {"Vanilla/Butterscotch Milkshake","Chocolate Milkshake","Strawberry Milkshake","Kitkat/Oreo Milkshake"};
    foodjoint order;
    int ch,choice,quantity;
    char opt;
    order.welcome();
    do {
main_menu:
        order.display_menu();
        cout<<"Enter your choice:";
        cin>>ch;
        if(ch==1) {
            pizza pobj;
            pobj.display_menu();
            int p_choice;
            cout<<"\nEnter your choice:";
            cin>>p_choice;
            if(p_choice==5)
                goto main_menu;
            cout<<"\n1.Small  - Rs.250\n2.Medium - Rs.550\n3.Large  - Rs.900\n";
            cout<<"\nEnter you choice:";
            cin>>choice;
            cout<<"\nEnter quantity:";
            cin>>quantity;
            switch(choice) {
            case 1:
                item_names.push_back(pizzaS_vec[p_choice-1]);
                item_price.push_back(250);
                total_price.push_back(250*quantity);
                break;
            case 2:
                item_names.push_back(pizzaM_vec[p_choice-1]);
                item_price.push_back(550);
                total_price.push_back(550*quantity);
                break;
            case 3:
                item_names.push_back(pizzaL_vec[p_choice-1]);
                item_price.push_back(900);
                total_price.push_back(900*quantity);
                break;
            }
            item_quantity.push_back(quantity);
            add_bill(choice,quantity);
        } else if(ch==2) {
            burger bobj;
            bobj.display_menu();
            cout<<"\nEnter your choice:";
            cin>>choice;
            if(choice==5)
                goto main_menu;
            item_names.push_back(burger_vec[choice-1]);
            item_price.push_back(bobj.cost_arr[choice-1]);
            cout<<"\nEnter quantity:";
            cin>>quantity;
            item_quantity.push_back(quantity);
            total_price.push_back(bobj.cost_arr[choice-1]*quantity);
            add_bill(bobj,choice,quantity);
        } else if(ch==3) {
            sandwich sobj;
            sobj.display_menu();
            cout<<"\nEnter your choice:";
            cin>>choice;
            if(choice==4)
                goto main_menu;
            item_names.push_back(sandwich_vec[choice-1]);
            item_price.push_back(sobj.cost_arr[choice-1]);
            cout<<"\nEnter quantity:";
            cin>>quantity;
            item_quantity.push_back(quantity);
            total_price.push_back(sobj.cost_arr[choice-1]*quantity);
            add_bill(sobj,choice,quantity);
        } else if(ch==4) {
            shakes skobj;
            skobj.display_menu();
            cout<<"\nEnter your choice:";
            cin>>choice;
            if(choice==5)
                goto main_menu;
            item_names.push_back(shakes_vec[choice-1]);
            item_price.push_back(skobj.cost_arr[choice-1]);
            cout<<"\nEnter quantity:";
            cin>>quantity;
            item_quantity.push_back(quantity);
            total_price.push_back(skobj.cost_arr[choice-1]*quantity);
            add_bill(skobj,choice,quantity);
        }

        cout<<"\n*If you want to add more items press (Y/y)\n*To exit please press (N/n)\n=>";
        cin>>opt;
        cout<<endl;
    } while(opt=='Y'||opt=='y');
    char couponCodeInp;
    int discountPercentage=-1;
    cout<<"Do you have COUPON CODE(y/n)\n=>"<<endl;
    cin>>couponCodeInp;
    string EnteredCouponCode,RealCouponCode;
    if(couponCodeInp=='y' || couponCodeInp=='Y') {
        cout<<"Enter COUPON CODE\n=>"<<endl;
        cin>>EnteredCouponCode;
        ifstream fin;
        fin.open("myCoupon.txt");
        while(fin.eof()==0) {
            fin>>RealCouponCode;

            if(EnteredCouponCode.compare(RealCouponCode)==0) {
                cout<<"\nCoupon discount applied!!\n";
                if(EnteredCouponCode[0]>='0' && EnteredCouponCode[0]<='9') {
                    discountPercentage = (EnteredCouponCode[0]-'0')*10+(EnteredCouponCode[1]-'0');
                } else {
                    discountPercentage = (EnteredCouponCode[EnteredCouponCode.length()-2]-'0')*10+(EnteredCouponCode[EnteredCouponCode.length()-1]-'0');
                }
                break;
            }
        }
        fin.close();
    }
    cout<<"\t\t\t\t\t===========\n";
    cout<<"\t\t\t\t\t|Your Bill|\n";
    cout<<"\t\t\t\t\t===========\n";
    cout<<setw(8)<<"ITEM NO."<<setw(35)<<"ITEM        "<<setw(8)<<"PRICE"<<setw(12)<<"QUANTITY"<<setw(17)<<"TOTAL PRICE"<<endl;
    cout<<setw(8)<<"========"<<setw(35)<<"====        "<<setw(8)<<"====="<<setw(12)<<"========"<<setw(17)<<"==========="<<endl;
    int j=0;
    for(auto it=item_names.begin(); it!=item_names.end(); it++) {
        cout<<setw(5)<<j+1<<setw(35)<<item_names[j]<<setw(10)<<item_price[j]<<setw(10)<<item_quantity[j]<<setw(15)<<total_price[j]<<endl;
        j++;
    }
    if(discountPercentage<0) {
        cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
        cout<<setw(71)<<"Total Bill:-  "<<(bill);
        cout<<"\n\n\t\t\t\t****Kindly pay Rs."<<bill<<"****"<<endl;
    } else {
        cout<<endl<<setw(48)<<"Coupon('"<<setw(EnteredCouponCode.length())<<EnteredCouponCode<<setw(15)<<"') Discount:-  -"<<setw(5)<<(bill*discountPercentage/100.0)<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout<<setw(71)<<"Total Bill:-  "<<(bill-(bill*discountPercentage/100.0))<<endl;
        cout<<"\n\n\t\t\t\t****Please pay Rs."<<(bill-(bill*discountPercentage/100.0))<<"****"<<endl;
    }
    cout<<"\n\nThank you\nVisit Again!!\n\n";
}
