#include <iostream>
/* Dodaje flagę wymaganą do kompilacji jako plik .dll dla rodziny systemów Windows*/
#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif


struct osoba{
    std::string imie;
    std::string nazwisko;
    bool plec; //true-kobieta, false-mezczyzna
    int wiek;
    float waga;
    float wzrost;
    float BMI;
    std::string opis;
};
extern "C"
{

    def int add(int a, int b){
        return (a + b);
    }

    def void subtractArrays(int* a, int* b, int size){
        for(int i = 0; i < size; i++){
            a[i] -= b[i];
        }
    }

}
osoba kalkulator(osoba a)
{
  a.BMI=(a.waga/(a.wzrost*a.wzrost))*10000;
  return a;
}
extern "C" {
     const char* getBMICategory(float BMI, bool plec, int wiek) {
        std::string opis;
         if (plec) {
              if (wiek < 13) {
                if (BMI < 17) {
                opis = "Niedowaga";
            } else if (17 <= BMI && BMI < 22) {
                opis = "Waga prawidlowa";
            } else if (22 <= BMI && BMI < 27) {
                opis = "Nadwaga";
            } else if (27 <= BMI && BMI < 37) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 13 && wiek < 18) {  
                if (BMI < 18) {
                opis = "Niedowaga";
            } else if (18 <= BMI && BMI < 23) {
                opis = "Waga prawidlowa";
            } else if (23 <= BMI && BMI < 28) {
                opis = "Nadwaga";
            } else if (28 <= BMI && BMI < 38) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 19) {
                opis = "Niedowaga";
            } else if (19 <= BMI && BMI < 24) {
                opis = "Waga prawidlowa";
            } else if (24 <= BMI && BMI < 29) {
                opis = "Nadwaga";
            } else if (29 <= BMI && BMI < 39) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 25 && wiek < 35) { 
                if (BMI < 20) {
                opis = "Niedowaga";
            } else if (20 <= BMI && BMI < 25) {
                opis = "Waga prawidlowa";
            } else if (25 <= BMI && BMI < 30) {
                opis = "Nadwaga";
            } else if (30 <= BMI && BMI < 40) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 35 && wiek < 45) { 
                if (BMI < 21) {
                opis = "Niedowaga";
            } else if (21 <= BMI && BMI < 26) {
                opis = "Waga prawidlowa";
            } else if (26 <= BMI && BMI < 31) {
                opis = "Nadwaga";
            } else if (31 <= BMI && BMI < 41) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 22) {
                opis = "Niedowaga";
            } else if (22 <= BMI && BMI < 27) {
                opis = "Waga prawidlowa";
            } else if (27 <= BMI && BMI < 32) {
                opis = "Nadwaga";
            } else if (32 <= BMI && BMI < 42) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 55 && wiek < 65) {   
                if (BMI < 23) {
                opis = "Niedowaga";
            } else if (23 <= BMI && BMI < 28) {
                opis = "Waga prawidlowa";
            } else if (28 <= BMI && BMI < 33) {
                opis = "Nadwaga";
            } else if (33 <= BMI && BMI < 43) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }           
            } else if (wiek >= 65) {  
                if (BMI < 24) {
                opis = "Niedowaga";
            } else if (24 <= BMI && BMI < 29) {
                opis = "Waga prawidlowa";
            } else if (29 <= BMI && BMI < 34) {
                opis = "Nadwaga";
            } else if (34 <= BMI && BMI < 44) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            }
        } else {
            if (wiek < 13) {
                if (BMI < 18) {
                opis = "Niedowaga";
            } else if (18 <= BMI && BMI < 23) {
                opis = "Waga prawidlowa";
            } else if (23 <= BMI && BMI < 28) {
                opis = "Nadwaga";
            } else if (28 <= BMI && BMI < 38) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 13 && wiek < 18) {  
                 if (BMI < 19) {
                opis = "Niedowaga";
            } else if (19 <= BMI && BMI < 24) {
                opis = "Waga prawidlowa";
            } else if (24 <= BMI && BMI < 29) {
                opis = "Nadwaga";
            } else if (29 <= BMI && BMI < 39) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 20) {
                opis = "Niedowaga";
            } else if (20 <= BMI && BMI < 25) {
                opis = "Waga prawidlowa";
            } else if (25 <= BMI && BMI < 30) {
                opis = "Nadwaga";
            } else if (30 <= BMI && BMI < 40) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }
            } else if (wiek >= 25 && wiek < 35) { 
                if (BMI < 21) {
                opis = "Niedowaga";
            } else if (21 <= BMI && BMI < 26) {
                opis = "Waga prawidlowa";
            } else if (26 <= BMI && BMI < 31) {
                opis = "Nadwaga";
            } else if (31 <= BMI && BMI < 41) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 35 && wiek < 45) { 
                if (BMI < 22) {
                opis = "Niedowaga";
            } else if (22 <= BMI && BMI < 27) {
                opis = "Waga prawidlowa";
            } else if (27 <= BMI && BMI < 32) {
                opis = "Nadwaga";
            } else if (32 <= BMI && BMI < 42) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 23) {
                opis = "Niedowaga";
            } else if (23 <= BMI && BMI < 28) {
                opis = "Waga prawidlowa";
            } else if (28 <= BMI && BMI < 33) {
                opis = "Nadwaga";
            } else if (33 <= BMI && BMI < 43) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 55 && wiek < 65) {   
               if (BMI < 24) {
                opis = "Niedowaga";
            } else if (24 <= BMI && BMI < 29) {
                opis = "Waga prawidlowa";
            } else if (29 <= BMI && BMI < 34) {
                opis = "Nadwaga";
            } else if (34 <= BMI && BMI < 44) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            } else if (wiek >= 65) {  
                if (BMI < 25) {
                opis = "Niedowaga";
            } else if (25 <= BMI && BMI < 30) {
                opis = "Waga prawidlowa";
            } else if (30 <= BMI && BMI < 35) {
                opis = "Nadwaga";
            } else if (35 <= BMI && BMI < 45) {
                opis = "Otylosc I stopnia";    
            } else{
                opis = "Otylosc II stopnia";
            }            
            }
        }         
        return opis.c_str();
    }
}
