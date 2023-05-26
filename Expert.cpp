// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// // Define a structure to represent a patient
// struct Patient
// {
//     string name;
//     int age;
//     string gender;
//     string symptoms;
// };

// // Function to recommend a medical facility based on patient symptoms
// string recommendMedicalFacility(const Patient &patient)
// {
//     if (patient.symptoms == "Fever" || patient.symptoms == "Cough" || patient.symptoms == "Sore throat")
//     {
//         if (patient.age >= 60)
//         {
//             return "Recommendation: Visit a specialized geriatric hospital.";
//         }
//         else
//         {
//             return "Recommendation: Visit a general hospital.";
//         }
//     }
//     else if (patient.symptoms == "Chest pain" || patient.symptoms == "Shortness of breath")
//     {
//         return "Recommendation: Go to the nearest emergency room immediately!";
//     }
//     else if (patient.symptoms == "Broken bone" || patient.symptoms == "Sprain")
//     {
//         return "Recommendation: Visit an orthopedic clinic or urgent care center.";
//     }
//     else if (patient.symptoms == "Headache" || patient.symptoms == "Migraine")
//     {
//         return "Recommendation: Consult a neurologist.";
//     }
//     else
//     {
//         return "No recommendation available for the given symptoms.";
//     }
// }

// int main()
// {
//     // Ask for patient information
//     Patient patient;
//     cout << "Hospitals and Medical Facilities" << endl;
//     cout << "------------------------------" << endl;
//     cout << "Enter patient name: ";
//     getline(cin, patient.name);
//     cout << "Enter patient age: ";
//     cin >> patient.age;
//     cout << "Enter patient gender: ";
//     cin >> patient.gender;
//     cin.ignore(); // Ignore the newline character in the input buffer
//     cout << "Enter patient symptoms: ";
//     getline(cin, patient.symptoms);

//     // Get the recommendation based on patient symptoms
//     string recommendation = recommendMedicalFacility(patient);

//     // Display the recommendation
//     cout << endl;
//     cout << "Recommendation" << endl;
//     cout << "--------------" << endl;
//     cout << recommendation << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int checkres(string a)
{
    if (a == "y")
    {
        return 1;
    }
    return 0;
}

void flue(string name)
{
    string res;
    // Asking questions for the  flue
    cout << "HI " << name << "re you ready to take flue test:?(y/n) " << endl;
    cin >> res;
    if (res == "y")
    {
        cout << "Good then go then ........" << endl;
        cout << "Loading question............................................." << endl;
    }
    else
    {
        return;
    }
    int prob = 0;
    cout << "1) Do you have cold? (y/n)" << endl;
    cin >> res;
    prob += checkres(res);
    cout << "2) what is your body tempreture ?" << endl;
    int temp = 0;
    cin >> temp;
    if (temp > 100)
    {
        prob++;
    }
    cout << "3)Do you feel weakness in body? (y/n)" << endl;
    cin >> res;
    prob += checkres(res);

    cout << "4)Do you feel headache ? (y/n)" << endl;
    cin >> res;
    prob += checkres(res);

    if (prob > 2)
    {
        cout << "YES, there are high chances that you are wsuffering from flue....\n I will suggest you to do following:==\n"
             << endl;
        cout << "1) Contact the doctor and follow proper medication\n";
        cout << "2) Take rest for few days and dont go outside\n";
        cout << "3) Eat healthy food..\n";
    }
    else if (prob <= 2 && prob != 0)
    {
        cout << "Take rest for few days .....\n";
    }
    else
    {
        cout << "Thank god, Dont worry you are healty....." << endl;
    }
}
void stress(string name)
{
    string res;
    // Asking questions for the  stress
    cout << "HI " << name << " are you ready to take Stress test:?(y/n) " << endl;
    cin >> res;
    if (res == "y")
    {
        cout << "Good then go then ........" << endl;
        cout << "Loading question............................................." << endl;
    }
    else
    {
        return;
    }
    int prob = 0;
    cout << "1) do you feel headache?" << endl;
    cin >> res;
    prob += checkres(res);

    cout << "2) Do you feel depressed ?" << endl;
    cin >> res;
    prob += checkres(res);
    cout << "3) are you specnding ypur day in the overthinking.....?" << endl;
    cin >> res;
    prob += checkres(res);

    if (prob > 2)
    {
        cout << "YES, there are high chances that you have stress....\n I will suggest you to do following:==\n"
             << endl;
        cout << "1) Contact the doctor and follow proper medication\n";
        cout << "2) Do yoga and meditation\n";
        cout << "3) Eat healthy food..\n";
        cout << "4)spend time with friends and travel in the open air...\n";
    }
    else if (prob <= 2 && prob != 0)
    {
        cout << "Do yoga and meditaion .....\n";
    }
    else
    {
        cout << "Thank god, Dont worry you are healty....." << endl;
    }
}
int main()
{

    cout << "Hello Welcome to the Medicure...." << endl;
    string name = "";
    cout << "Enter your good name:" << endl;
    cin >> name;
    cout << "Hi... " << name << " tell me what is your problem, I am here to dolve your problem by identifying the system " << endl;
    cout << "I can  check for the flue and the stress so select option acording to your requirement: " << endl;
    int choice;
menu:
    cout << "1) Flue\n 2) Stress" << endl;
    cout << "Check one of the above:" << endl;
    cin >> choice;

    if (choice == 1)
    {
        flue(name);
    }
    else if (choice == 2)
    {
        stress(name);
    }
    else
    {
        cout << "Wrong choice!!!" << endl;
        goto menu;
    }

    cout << "Thak you so much for using medicure ......." << endl;
    return 0;
}