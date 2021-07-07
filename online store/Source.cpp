#include<iostream>
#include<string>
#include <vector>
#include <cstdlib>
#include<fstream>
using namespace std;
const int shopCartsize = 10;
int shopCart[shopCartsize] = { 0,0,0,0,0,0,0,0,0,0 };//array to hold the bought item 
int shopcartIndex = 0;//current index of the shop cart array
void GiftCards();
char pathInput;//char that is used in the switch in the menu function to decide the case of the switch  
int discountpercent = 0;//global variable that the discountCodeVerifier function set to the actual discount percent
string discount_Codes[5]{ "wet34rg","eqw213l","qer123f","qwr124s","dgh23nk" };// array that have ALL THE DISCOUNT CODES
class item
{
public:
    string Item_Name;
    float price;
    int  Item_code;
    int item_quantity;
    item();
    item(string name, float Price, int code, int Quantity);
    ~item();

private:

};
void viewitemsPrices(item arryofObjects[]);
void discountCodeVerifier(item arry[]);
void showCart();
item::item()
{
}
item::~item()
{
}
item::item(string name, float Price, int code, int Quantity)
{
    Item_Name = name;
    price = Price;
    Item_code = code;
    item_quantity = Quantity;
}
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, temp[50];//the temp array will hold the valus after sorting , 
    i = low;//i is the first index of first  subarray the unsorted array
    k = low;//k is the index of the empty array
    j = mid + 1;//j is the first index of the  second subarray of the unsorted array
    while (i <= mid && j <= high) {
        if (arr[i] > arr[j]) {
            temp[k] = arr[i];//filling the temp array with greater value
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];//filling the temp array with greater value
            k++;
            j++;
        }
    }
    while (i <= mid) {//if j array is empty , this while loop will fill the temp the  remaining values
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {//if i array is empty , this while loop will fill the temp the  remaining values
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {//filling the main array after being sorted
        arr[i] = temp[i];
    }
}
void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        //divide the array into two subarrays 
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        //merge and sorted arrays
        merge(arr, low, high, mid);
    }
}
void menu(item arry[]) {
    cout << "PRESS 1 TO BUY ITEM" << endl;
    cout << "PRESS 2 TO to View Cart" << endl;
    cout << "PRESS 3 TO Add discount Code" << endl;
    cout << "PRESS 4 TO buy gift Cards" << endl;
    cout << "PRESS 5 TO view all items prices descendingly" << endl;
    cout << "PRESS 6 TO exit" << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "press 1 if you want to add " << arry[0].Item_Name << " to your cart" << endl;
        cout << "press 2 if you want to add " << arry[1].Item_Name << " to your cart" << endl;
        cout << "press 3 if you want to add " << arry[2].Item_Name << " to your cart" << endl;
        cout << "press 4 if you want to add " << arry[3].Item_Name << " to your cart" << endl;
        cout << "press 5 if you want to add " << arry[4].Item_Name << " to your cart" << endl;
        cout << "press 6 if you want to add " << arry[5].Item_Name << " to your cart" << endl;

        int buy;
        cin >> buy;
        switch (buy)
        {
        case 1:
            shopCart[shopcartIndex] = arry[0].Item_code;
            shopcartIndex++;
            menu(arry);
            break;
        case 2:
            shopCart[shopcartIndex] = arry[1].Item_code;
            shopcartIndex++;
            menu(arry);
            break;
        case 3:
            shopCart[shopcartIndex] = arry[2].Item_code;
            shopcartIndex++;
            menu(arry);
            break;
        case 4:
            shopCart[shopcartIndex] = arry[3].Item_code;
            shopcartIndex++;
            menu(arry);
            break;
        case 5:
            shopCart[shopcartIndex] = arry[4].Item_code;
            shopcartIndex++;
            menu(arry);
            break;
        case 6:
            shopCart[shopcartIndex] = arry[5].Item_code;
            shopcartIndex++;
            menu(arry);
            break;

        default:
            break;
        }
        break;
    case 2:

        showCart();
        cout << "press any button to return to menu " << endl;
        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        break;
    case 3:
        discountCodeVerifier(arry);
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        break;

    case 4:
        GiftCards();
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        break;
    case 5:
        viewitemsPrices(arry);
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        break;

    case 6:
        exit(0);
        break;

    case 7:

        break;

    default:cout << " erorr: wrong input";
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        break;
    }
}
void discountCodeVerifier(item arry[]) {//function the verfiy the discount , the function uses#brute force paradigm#
    int count = 0;
    bool match = false;
    if (discountpercent == 20) {//this if condition is made to deny the user access  to  the discount function if he allready aplied a code"user cant used two discount codes"
        cout << " you already applied 20 percent discont code" << endl;
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }
        ;
    }
    else if (discountpercent == 30) {
        cout << " you allready applied 30 percent discont code" << endl; //this if condition is made to deny the user access  to  the discount function if he allready aplied a code"user cant used two discount codes"
        cout << "press any button to return to menu " << endl;

        cin >> pathInput;
        switch (pathInput)
        {
        default:menu(arry);
            break;
        }


    }
    else {

        cout << "please enter your discount code";//the user must enter the discount code he got
        string DisCountCODE;
        cin >> DisCountCODE;

        for (int i = 0; i < sizeof(discount_Codes) / sizeof(DisCountCODE); i++) {// for loop that loops on every index of the discount_Codes array 
            if (discount_Codes[i].length() == DisCountCODE.length() && discount_Codes[i] == DisCountCODE) {//if statment to match between the user input and the indexies of he discount_Codes array
                for (int j = 0; j < DisCountCODE.length(); j++) {// for loop to loop on each char of the discount code  
                    if (DisCountCODE.at(j) >= 48 && DisCountCODE.at(j) <= 57) {// the if condition  to calculat how much numbers in the discount code"if the discount code have 2 numbers then the discount code is 20 percent,if the discount code have 3 numbers then the discount code is 30 percent  "

                        count++;// count is the number of numbers in the discount code
                    }


                }
                match = true;// this boolen check if the discount code match the codes stored in the system
                break;

            }
        }

        if (match == true && count == 3) {
            discountpercent = 30;
            cout << "your discount percent is : 30" << endl;

        }
        else if (match == true && count == 2) {
            discountpercent = 20;
            cout << "your discount percent is : 20" << endl;

        }
        else {
            cout << "your discount code is wrong" << endl;
            discountpercent = 0;
        }
    }
}
void GiftCards() {//if the user wanted to but gift cards with a certain amount of money,this function calculate how much and what is the gift cards the system should return to the user#greedy paradigm cashier algorithm#
    int arryofGiftCards[7] = { 50,5,200,100,500,20,250 };//array that has all the gift cards values 
    int total = 0;
    int j = 0;
    merge_sort(arryofGiftCards, 0, 6);//the array should be sorted descendingly
    vector<int> givenGiftCards;// a vector that holds the givin giftcards from the system to the user

    cout << "please enter the amount of money do you want to buy gift cards with" << endl;
    int money;//the amount of money that the user want to buy gift cards with
    cin >> money;
    for (int i = 0; i < 7; i++) {//for loop on the array of giftcards
        while ((total + arryofGiftCards[i]) <= money * 10) {//if the money value is less than the total"total" + the array of gift cards indexs, the indexs of the giftcards array will be incremented  by one ,which is a smaller value 
            total = total + arryofGiftCards[i];
            givenGiftCards.push_back(arryofGiftCards[i]);//filling the array of gifted cardes "bought gift cards" with the gifted cards

        }
    }
    for (int x = 0; x < givenGiftCards.size(); x++) {//display the giftcard that user bought
        cout << "card :" << givenGiftCards[x] << endl;
    }
}
void mergeArrayofObjrcts(item arry[], int low, int high, int mid)//this function is the same as "merge" mentiond above but it uses array of object and sort acording to item price ascendingly 
{
    int i, j, k;
    item temp[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arry[i].price > arry[j].price) {
            temp[k] = arry[i];
            k++;
            i++;
        }
        else {
            temp[k] = arry[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = arry[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = arry[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arry[i] = temp[i];
    }
}
void merge_sortarray_of_objects(item arry[], int low, int high)//the function is same as "merge and sort" mentioned with comments above
{
    int mid;
    if (low < high) {
        //divide the array into two subarrays
        mid = (low + high) / 2;
        merge_sortarray_of_objects(arry, low, mid);
        merge_sortarray_of_objects(arry, mid + 1, high);
        //merge and sort the arrays
        mergeArrayofObjrcts(arry, low, high, mid);
    }
}
void viewitemsPrices(item arryofObjects[]) {

    merge_sortarray_of_objects(arryofObjects, 0, 5);//sorting the array of objects by the price values #merge-and-sort dvide and conquer#
    for (int i = 0; i < 5; i++)// displaying the array content
    {
        cout << "product name : " << arryofObjects[i].Item_Name;
        cout << "           product price :" << arryofObjects[i].price << endl;
    }
}
void showCart() {//this function display the shop cart of the user it uses#transfer and conqure paradigm#
    merge_sort(shopCart, 0, shopCartsize - 1);//SORTING THE ARRAY because the reptitive items will be beneath each other
    int shopcartItem[shopCartsize];// AN ARRAY TO HOLD THE ITEM CODE
    int shopcartQuntity[shopCartsize];// AN ARRAY TO HOLD ITEM QOUANTITY IN THE SHOP CART
    for (int i = 0; i < shopCartsize; i++) {// for loop for the shop cart size
        int s = 1; int v = shopCart[i];
        shopcartItem[i] = v;
        shopcartQuntity[i] = s;
        while (i + s <= shopCartsize && shopCart[i + s] == v)//TO CHECK HOW MUCH ONE ITEM GOT RPEATED IN THE SHOP CART ARRAY
        {
            s++;
            shopcartItem[i] = v;
            shopcartQuntity[i] = s;
        }
        s = s + i;
    }
    for (int i = 0; i < 9; i++) { //TO DISPLAY EACH ITEM WITH HOW MUCH IT GOT RPEATED IN THE SHOP CART"HOW MUCH THE USER BOUGHT  THE SAME ITEM"
        if (shopcartItem[i] == 0)break;
        cout << "Item :" << shopcartItem[i] << "   " << "Quantity :" << shopcartQuntity[i] << endl;

    }

};
void main() {
    item q;
    q.item::item("PS4 controller", 50, 123, 13);
    item x;
    x.item::item("ps4 Device ", 500, 133, 13);
    item e;
    e.item::item("headset", 120, 134, 13);
    item r;
    r.item::item("charger", 10, 135, 13);
    item f;
    f.item::item("ps5 device", 600, 136, 13);
    item w;
    w.item::item("ps5 controller", 70, 136, 13);
    //creating objects from class item
    item array[6] = { q,x,e,r,f,w };
    //saving all the objects in one array of obejects 
    ofstream file;
    file.open("DataFile.txt", ios::out);//creating file to save the array of objects  mentioned before  
    file.write((char*)&array, sizeof(array));//writing the array of objects to the file
    file.close();//closing the file
    item arry[6];// creating another array to hold the objects that has been save in the file
    ifstream files;
    files.open("DataFile.txt", ios::in);//opening the file that has the arry of objects
    while (!files.eof())//filling the new array with the saved objects  
    {
        files.read((char*)&arry, sizeof(arry));

    }
    files.close();

    menu(arry);


}