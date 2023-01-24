#include <iostream>
#include <iomanip>
#include<fstream>

using namespace std;

int daysSpent(int);
void DeptArriv (double&, double&);
double airFare(double);
double carRental(double);
int privateCar(int);
void parking(double&,double&);
void taxi(double&,double&);
double registration(double);
double hotelAmount(double&,double&);
double mealCost(double&,double&);

int main()
{
    int days = 0;
    ofstream outputFile; 		//File stream object
    
    double arrival,departure,// This are for the function DeptArriv
    airfareFee, carRentalFee, privateCarFee,// This are for the functions airFare, carRental, and privateCar
    privateCarMilage = .58,
    parkingFee,//This is for the function parking
    taxiFee,//this is for the function taxi
    registrationFee, //this is for the function registration
    spentTotal,      //the total amount spent
    allowedTotal,    //the total amount allowed
    mealTotal,
    total,
    allowedParking,//amount allowed from the company for parking fees $12 per day.
    allowedTaxiFee,//amount allowed from the company for taxi fees $40 per day
    hotelFee,
    allowedHotelFee,//amount allowed fro the company for Hotel expenses. $90 per night for lodging
    hotelFeeTotal,//Total amount spent on hotel expenses
    allowBfFee, allowLFee, allowDFee,//amount allowed from the company for breakfast($18), luch($12), and dinner($20)
    breakfastFee, lunchFee, dinnerFee,
    TallowedMeal,
    parkingSpent, taxiSpent,
    TspentMeal;
    string employeeFirstName, employeeLastName;
    
	//This is where report begins
	 outputFile.open("expensereport.txt");
    
    cout<<setw(20)<<"Employee Expense Report"<<endl; 
    cout<<setw(20)<<"________________________"<<endl<<endl; 
    
    cout<<"Employee Name: ";
    cin >>employeeFirstName >>employeeLastName;
    cout<<endl;
      
    days = daysSpent(days);  //call of function int daysSpent
    cout<<endl;
    
    DeptArriv (departure,arrival); //call of function void DeptArriv
    cout<<endl;

    airfareFee = airFare(airfareFee); //call of function double airFare
    carRentalFee = carRental(carRentalFee);//call of function double carRental
    privateCar(privateCarFee);//call of function int priateCar
    allowedParking = 12.00 * days;
    parking(parkingFee, allowedParking);//call of function void parking
    taxiSpent = days * taxiFee;
    allowedTaxiFee = 40.00 * days;
    taxi (taxiFee,allowedTaxiFee);//call of function void taxi
    
    hotelAmount(hotelFee,allowedHotelFee);//call of function double hotelAmount
	cout << endl;
    registrationFee= registration(registrationFee);//call of function double registration
    allowedHotelFee = 90.00 * days;
    cout<< endl;
    mealCost (TallowedMeal,TspentMeal);
    allowBfFee = 18.00 * days;
    allowLFee = 12.00 * days;
    allowDFee = 20.00 * days;    
    TallowedMeal = allowBfFee + allowLFee + allowDFee;//set of the the total amount of money allowed from the company for meals (18+12+20=$50 per day)
    mealTotal= breakfastFee + lunchFee + dinnerFee; 

    cout<<endl;

    //calc total
  spentTotal=airfareFee+carRentalFee+privateCarFee+parkingFee+taxiFee+registrationFee+hotelFee+TspentMeal+privateCarMilage;
allowedTotal=airfareFee+carRentalFee+privateCarFee+allowedParking+allowedTaxiFee+registrationFee+allowedHotelFee+TallowedMeal+privateCarMilage;

   //Report
    outputFile<<"Employee Expense Report for "<<employeeFirstName<<" "<<employeeLastName<<endl<<endl;
    outputFile<< "Total Days of trip: "<<days<<endl;
    outputFile<< fixed << setprecision(2);
    outputFile<< "Departure time: "<< departure<<setw(20)<<"Arrival time: " <<arrival<<endl; 
   	outputFile<<setw(8)<<setprecision(2)<<showpoint<<fixed;
    outputFile<<endl;
    outputFile<< setw(29)<<"Spent"<<setw(20)<< "Allowed"<<endl;
    outputFile<< setw(30)<<"_________"<<setw(20)<<"_________"<<endl;
    outputFile<<"Round-trip Airfare"<<setw(9)<<airfareFee<<setw(20)<<airfareFee<<endl;
    outputFile<<"Car Rental"<<setw(17)<<carRentalFee<<setw(20)<<carRentalFee<<endl;
    outputFile<<"Milage"<<setw(21)<<privateCarMilage<<setw(20)<<privateCarMilage<<endl;
    outputFile<<"Parking"<<setw(20)<<parkingFee<<setw(20)<<allowedParking<<endl;
    outputFile<<"Taxi"<<setw(23)<<taxiFee<<setw(20)<<allowedTaxiFee<<endl;
    outputFile<<"Registration"<<setw(15)<<registrationFee<<setw(20)<<registrationFee<<endl;
    outputFile<<"Hotel"<<setw(22)<<hotelFee<<setw(20)<<allowedHotelFee<<endl;
    outputFile<<"Meals"<<setw(23)<<TspentMeal<<setw(20)<<TallowedMeal<<endl;
    outputFile<< setw(30)<<"_________"<<setw(20)<<"_________"<<endl;
    outputFile<<"TOTALS"<<setw(21)<<spentTotal<<setw(20)<<allowedTotal<<endl;
  	outputFile<<endl<<endl;
   
   			
	outputFile.close();

	cout << "\n\nInformation has been successfully written to expensereport.txt \n\n";
   
    system ("pause");
    return 0;
}


int daysSpent(int days) //Function of the total number of days spent on the trip
{
              cout << "Please enter the amount of days spent on the trip. " << endl;
              cin >> days;
              
              while (days < 1) //This loop ensures that the number of days is at least 1.
              {
                    cout << "Please enter a number greater than 1" << endl;
                    cin >> days;
              }
              
              return days;
}


void DeptArriv (double &departure, double &arrival) //This function is for the time of departure on the first day, and the time of arrival back home.
{
           cout << "Please enter the time of departure. " ;
           cin >> departure;
           cout <<endl;
           
           while ( departure <0 || departure > 23.59) // This loop is for the time of departure and the time of arrival to be valid.
           {
                 cout << "Error: Please enter a number between 00.00 and 23.59"<<endl;
                 cin >> departure;
            }
          
           cout << "Please enter the time of arrival." ;
           cin >> arrival;
           
            while ( arrival <0 || arrival > 23.59)
           {
                 cout << "Error: Please enter a number between 00.00 and 23.59"<<endl;
                 cin >> arrival;
            }
            return;
        }

double airFare (double airfareFee)//Function for the amount of any round-trip airfare.
{        
         cout << "Please enter the amount of any round-trip airfare. " << endl;
         cin >> airfareFee;
         
         while (airfareFee < 0)//loop to ensure the program does not accept negative numbers for dollars
         {
               cout << "Error: Please enter a number greater than 0. Try again!" << endl;
               cin >> airfareFee;
         }
         
         return airfareFee;
}

double carRental (double carRentalFee)//Function for the amount of any car rentals.
{
       cout << "Please enter the amount of any car rentals." << endl;
       cin >> carRentalFee;
       
       while (carRentalFee < 0)//loop to ensure the program does not accept negative numbers for dollars
       {
             cout << "Error:Please enter a number greater than 0. Try Again!" << endl;
             cin >> carRentalFee;
       }
       
       return carRentalFee;
}

int privateCar (int privateCarFee)//Function for miles driven if a private vehicle was used
{
       const double RATE = 0.58;
       double miles;
       
       cout << "Please enter the amount of miles driven, if a private vehicle was used." << endl;
       cin >> miles;
       
       while (miles < 0)//loop to ensure the program does not accept negative numbers for miles driven in a private vehicle.
       {
             cout << "Error:Please enter a value greater than 0. Try again!" << endl;
             cin >> miles;
       }
       
       privateCarFee = miles * RATE;
       
       return privateCarFee;
}


void parking(double &parkingFee, double &allowedParking)//Function for Parking fees.
{
    int days;

    
       cout << "Please enter the parking fees." << endl;
       cin >> parkingFee;
       
       
       while (parkingFee < 0)//loop to ensure the program does not accept negative numbers for dollars
       {
             cout << "Error:Please enter a positive number. Try again!" << endl;
             cin >> parkingFee;
       }
       return;
}

void taxi (double &taxiFee, double &allowedTaxiFee)//Function for the taxi fees
{
int days;
       cout << "Please enter the taxi fees." << endl;
       cin >> taxiFee; 
       
        
       while (taxiFee < 0)//Loop to ensure the program does not accept negative numbers for dollars.
       {
             cout << "Error: Enter a positive number. Try again!" << endl;
             cin >> taxiFee;
       }
       return;
}

double registration (double registrationFee)//Function for the conference or seminar registration fees.
{
       cout << "Please enter the amount of conference or registration fees." << endl;
       cin >> registrationFee;
       
       while (registrationFee < 0)//loop to ensure the program does not accept negative numbers for dollars.
       {
             cout << "Error: Enter a positive number. Try again!" << endl;
             cin >> registrationFee;
       }
       
       return registrationFee;
}       

double hotelAmount(double &hotelFee,double &allowedHotelFee)//Function for Hotel expenses.
{
    double hotelFeeTotal;
    int days;
    cout << "Please enter Hotel Expenses." << endl;
    cin >> hotelFee;
      
    
    while (hotelFee < 0)//loop to ensure the program does not accept negative numbers for dollars
       {
             cout << "Error: Enter a positive number. Try again!" << endl;
             cin >> hotelFee;
       }
       hotelFeeTotal = hotelFee;

       return hotelFee;
}     

double mealCost(double &TallowedMeal,double &TspentMeal)   
{ 
    int day;
    int days = 0;
    double breakfast;
    double lunch;
    double dinner;
    double firstDay;
    double lastDay;
    double departureTime = 0;
    double arrivalTime = 0;
    
    
for(int day = 1; day <= days; day++)
        {         
            cout << "Day:" << day <<  endl;
            
    while (day < 2 && departureTime > 00.00 && departureTime<= 7.00)
        {
            cout << "Enter the cost of breakfast: ";
            cin >> breakfast;
            cout << "Enter the cost of lunch: ";
            cin >> lunch;
            cout << "Enter the cost of dinner: ";
            cin >> dinner;
        }
            
    while (day < 2 && departureTime > 7.01 && departureTime <=12.00)
        {
            cout << "Enter the cost of lunch: ";
            cin >> lunch;
            cout << "Enter the cost of dinner: ";
            cin >> dinner;
        }
        
    while (day < 2 && departureTime > 12.01 && departureTime <=18.00)
        {
            cout << "Enter the cost of dinner: ";
            cin >> dinner;
        }
    while (day > 1 && day < days )
       {    
            cout << "Enter the cost of breakfast: ";
            cin >> breakfast;
            cout << "Enter the cost of lunch: ";
            cin >> lunch;
            cout << "Enter the cost of dinner: ";
            cin >> dinner;
       }
    
    while (day == days && arrivalTime > 8.00 && arrivalTime <= 13.00) 
        {
            cout << "Enter the cost of breakfast: ";
            cin >> breakfast;
            
        }
        
    while (day == days && arrivalTime > 13.01 && arrivalTime <= 19.00)
        {
            cout << "Enter the cost of breakfast: ";
            cin >> breakfast;
            cout << "Enter the cost of lunch: ";
            cin >> lunch;  
        }
        
    while (day == days && arrivalTime > 19.01)
        {
            cout << "Enter the cost of breakfast: ";
            cin >> breakfast;
            cout << "Enter the cost of lunch: ";
            cin >> lunch;
            cout << "Enter the cost of dinner: ";
            cin >> dinner;
        }
        cout <<endl;      
        return TspentMeal ;
            
}
}
