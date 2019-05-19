Total expense:
>round trip airfare
>car rental (default=0)
>private car cost (if a private car is used) (should ask milage)
>parking fee (maximum 6 per day)
>taxi fee
>conference/seminar fee
>hotel expenses (up to $90 per night)


Variables:
1. Global variable
	num_days_total //to store the total number of days of travel

2. Global constant
	CAR_EXPENSE=0.27; //price per mile if private cars are used
	PARKING_MAX=6; //the maximum parking fee per day
	TAXI_MAX=10; //maximum taxi fee per days
	HOTEL_EXPENSE=90; //maximun allowed hotel expense per day
	BREAKFAST_EXPENSE=9; //maximum allowed breakfast expense per day
	LUNCH_EXPENSE=12; //maximum allowed lunch expense per day
	DINNER_EXPENSE=16; //maximum allowed dinner expense per day

3. Function list

	1) create_report()
	This function can copy other file into one final file, in this way a report 
	can be created
	
	2) transportation_expense()
	This function calculates the expenses related to the transportation
	> round trip expense
	> car rental and usage expense
	> parking expense
	> taxi expense
	This function should create a txt report about transportation expense.
	Use reference variable to return transportation_total, transportation_allowed and transportation_saved
	
	3) conference_expense()
	This function asks for the expense related to registration fee
	return total registration fee
	
	4) hotel_expense()
	This function asks for the expense related to hotel.
	Use reference variable to return hotel_total, hotel_allowed and hotel_fee_saved;
	
	5) food_expense()
	This function calculates the expense related to food.
	> fisrt day food expense
	> 2 ~ (n-1) day food expense
	> last day food expense
	
	Use reference variable to return food_total, food_allowed and food_saved
4. Variable list
	
	//Overview
	int hour_depart; //this is the hour when the employee left
	int min_depart; //this is the min when the employee left
	int hour_arrive; //this is the hour when the employee back
	int min_arrive; //this is the min when the employee back
	
	
	//Transportation
	double round_trip_air_expense; //airline expense
	double car_rental; //rental expense. User should decide using rental car or private car
	double miles_driven; //if private car is used, ask for milage traveled and calculate cost
	double car_private; //calculate the expense of private car
	double parking_days; //ask for how many days parking is used
	double parking_allowed; //parking_days*PARKING_MAX, holds the amount allowed maximum
	double parking_fee; //maximum $6 per day. use an iteration to calculate total (use parking_days). Store (6-parking_fee) into parking_fee_saved
	double parking_total; //calculate the parking total, initiate with 0
	double parking_fee_saved; //to record how much parking fee is saved by employee. If it is negative, the employee must reimburse it
	double taxi_days; //ask for howmany days taxi is used
	double taxi_allowed; //taxi_days*TAXI_MAX, holds the amount allowed maximum for taxi expense
	double taxi_fee; //maximum $10 per day. use an iteration to calculate total (use taxi_days). Store (10-taxi_fee) into taxi_fee_saved
	double taxi_total; //calculate the taxi total
	double taxi_fee_saved; //to record how much taxi fee is saved by employee. If it is negative, the employee must reimburse it
	double transportation_total; //holds the total expense in transportation
	double transportation_allowed; //total allowed expense of transportation: round_trip_air_expense+car_rental+car_private+parking_allowed+taxi_allowed
	double transportation_saved; //total saved expense of transportation: parking_fee_saved+taxi_fee_saved
	reference variable:
	transportation_allowed, transportation_saved
	
	//conference expense
	double conference_fee;
	double seminar_fee;
	
	//Hotel expense
	double hotel_total; //total hotel fee.
	double hotel_fee; //maximum $90 per day. Use an iteration to ask hotel expense each day, and store into total. Also, store (90-hotel_fee) into hotel_fee_saved
	double hotel_fee_saved=0; //to record how much hotel fee is saved by employee. If it is negative, the employee must reimburse it
	double hotel_allowed; //num_days_total*HOTEL_EXPENSE
	
	//food expense
	double breakfast_fee;
	double lunch_fee;
	double dinner_fee; //to input food cost. Use iteration. First day (use if to determine how many meals to be inputed), 2 ~ (n-1) day, last day.
	double food_total; //total food expense
	double food_allowed; //allowed food expense
	double food_saved; //saved or (if it is negative) reimbursed food expense
	
	
	