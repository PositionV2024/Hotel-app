#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct Customer_info {
    string first_name {""};
    string last_name {""};
    int age {0};
};

struct Cost {
    const double per_night {80.0};
    const double per_room {50.0};
    const double sales_tax {0.06};
    const int percent_converter {100};
};
    const vector <string> options
    {
        "(1) Learn more about various facilities.", 
        "(2) Learn more about breakfast, lunch and dinner.",
        "(3) Learn more about the pricing.",
        "(4) Book your stay!!",
    };
    
    const vector <string> descriptions
    {
      "Hotel guest are allowed in the gym during their stay for physical exercises, attend classes, and etc. The gym opens at 08:30 to 23:00 daily.",
      "Hotel guest are allowed to stay or extend their stay duration. It will cost $80/day, $50/room, and there is a tax of 6%.",
    };
    
    const string error_message {"Ending program..."};
    
    const char prefix {'$'};
    
double Calculate_final_cost(double arg1, double arg2, double arg3, double arg4, double arg5) {
        struct Cost cost;
        double result {0};
        result = (arg1 * arg2) + (arg3 * arg4) + arg5 * cost.percent_converter;
        return result;
}
int main() {
    SetConsoleTitle("Clarence's hotel booking app");
    
    cout << "Welcome to Clarence's hotel booking app. Please select one of the options below to get started." << endl;
    
    cout << endl;
    
    for (auto ops: options) {
        cout << ops << endl;
    }
    cout << endl;
    
    int option_input {0};
    cout << "Enter an option: ";
    cin >> option_input;
    cout << endl;
    
        switch (option_input) {
            default:
                cout << error_message << endl;
                break;
            case 1:
                cout << descriptions.at(0) << endl;
                break;
            case 2:
                cout << "All about breakfast, lunch and dinner." << endl;
                break;
            case 3:
                cout << descriptions.at(1) << endl;
                break;
            case 4:
            {
                int stay_duration {0};
                cout << "How many days will you be staying: ";
                cin >> stay_duration;
                int number_of_rooms {0};
                cout << "How many rooms will it be: ";
                cin >> number_of_rooms;
                
                bool is_number_valid {false};
                is_number_valid = ((stay_duration != 0 && number_of_rooms != 0 ? true : false));
                
                switch (is_number_valid)
                {
                    case true:
                    {
                        cout << endl << "========== " << "Final order ==========" << endl;
                        cout << "Duration: " << stay_duration << " days." << endl;
                        cout << "Rooms: " << number_of_rooms << " rooms" << endl;
                        struct Cost cost;
                        int grand_total {0};
                        grand_total += Calculate_final_cost(cost.per_night, stay_duration, cost.per_room, number_of_rooms, cost.sales_tax);
                        cout << "Grand total: " << prefix << grand_total << " (included tax)" << "." << endl;
                        cout << endl << "========== Pricing breakdown (Per day) ==========" << endl;
                        cout << "A night will cost: " << prefix << cost.per_night << endl;
                        cout << "You want to stay for: " << stay_duration << " days." << endl;
                        double result_1 {0};
                        result_1 = Calculate_final_cost(cost.per_night, stay_duration, 0, 0, 0);
                        cout << "So it will be:" << prefix << cost.per_night << "x" << stay_duration << " which it will be " << prefix << result_1 << "." << endl;
                        cout << endl << "========== Pricing breakdown (Per room) ==========" << endl;
                        cout << "A room will cost: " << prefix << cost.per_room << endl;
                        cout << "You want to book : " << number_of_rooms << " rooms" << endl;
                        double result_2 {0};
                        result_2 = Calculate_final_cost(cost.per_room, number_of_rooms, 0, 0, 0);
                        cout << "So it will be:" << prefix << cost.per_room << "x" << number_of_rooms << " which it will be " << prefix << result_2 << "." << endl;
                        cout << endl;
                        
                        struct Customer_info customer_info;
                        
                        cout << "May I get your first name for the order?: ";
                        cin >> customer_info.first_name;
                        cout << "May I get your last name for the order?: ";
                        cin >> customer_info.last_name;
                        cout << "May I get your age for the order? (Note: you must be 18 or over in order to book a stay): ";
                        cin >> customer_info.age;
                        
                        const int age_legal {18};
                        
                        bool is_age {false};
                        is_age = ((customer_info.age >= age_legal ? true : false));
                        
                        switch (is_age)
                        {
                            case true:
                                break;
                            case false:
                                cout << error_message;
                                break;
                        }
                        break;
                    }
                    case false:
                        cout << error_message << endl;
                        break;
                }
            }
        }
    return 0;
}
