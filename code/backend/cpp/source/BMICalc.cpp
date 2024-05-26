#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif

//NOTKA DLA MIKOŁAJA: NIE ROBIMY STRUCTA WALISZ SAME ZMIENNE ROBIMY I DO ZWRACANIA BO PIERDOL�� TO WSZYSTKO I SI�� TO PIERDZIELI JAK CHC�� TO JAKOŚ NORMALNIE OGARNĄĆ
#include <string>
#include <cmath>
#include <iostream>


extern "C" {

     def float kalkulator(float waga, float wzrost) {
        float wzrostM = wzrost/100;
        return waga / pow(wzrostM,2);
    }

    def const char* getBMICategory(float BMI, bool plec, int wiek) {
         if (plec) {
              if (wiek < 13) {
                if (BMI < 17) {
                return "NW";
            } else if (17 <= BMI && BMI < 22) {
                return "WP";
            } else if (22 <= BMI && BMI < 27) {
                return "NaW";
            } else if (27 <= BMI && BMI < 37) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 13 && wiek < 18) {
                if (BMI < 18) {
                return "NW";
            } else if (18 <= BMI && BMI < 23) {
                return "WP";
            } else if (23 <= BMI && BMI < 28) {
                return "NaW";
            } else if (28 <= BMI && BMI < 38) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 19) {
                return "NW";
            } else if (19 <= BMI && BMI < 24) {
                return "WP";
            } else if (24 <= BMI && BMI < 29) {
                return "NaW";
            } else if (29 <= BMI && BMI < 39) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 25 && wiek < 35) {
                if (BMI < 20) {
                return "NW";
            } else if (20 <= BMI && BMI < 25) {
                return "WP";
            } else if (25 <= BMI && BMI < 30) {
                return "NaW";
            } else if (30 <= BMI && BMI < 40) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 35 && wiek < 45) {
                if (BMI < 21) {
                return "NW";
            } else if (21 <= BMI && BMI < 26) {
                return "WP";
            } else if (26 <= BMI && BMI < 31) {
                return "NaW";
            } else if (31 <= BMI && BMI < 41) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 22) {
                return "NW";
            } else if (22 <= BMI && BMI < 27) {
                return "WP";
            } else if (27 <= BMI && BMI < 32) {
                return "NaW";
            } else if (32 <= BMI && BMI < 42) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 55 && wiek < 65) {
                if (BMI < 23) {
                return "NW";
            } else if (23 <= BMI && BMI < 28) {
                return "WP";
            } else if (28 <= BMI && BMI < 33) {
                return "NaW";
            } else if (33 <= BMI && BMI < 43) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 65) {
                if (BMI < 24) {
                return "NW";
            } else if (24 <= BMI && BMI < 29) {
                return "WP";
            } else if (29 <= BMI && BMI < 34) {
                return "NaW";
            } else if (34 <= BMI && BMI < 44) {
                return "OIS";
            } else{
                return "OIIS";
            }
            }
        } else {
            if (wiek < 13) {
                if (BMI < 18) {
                return "NW";
            } else if (18 <= BMI && BMI < 23) {
                return "WP";
            } else if (23 <= BMI && BMI < 28) {
                return "NaW";
            } else if (28 <= BMI && BMI < 38) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 13 && wiek < 18) {
                 if (BMI < 19) {
                return "NW";
            } else if (19 <= BMI && BMI < 24) {
                return "WP";
            } else if (24 <= BMI && BMI < 29) {
                return "NaW";
            } else if (29 <= BMI && BMI < 39) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 20) {
                return "NW";
            } else if (20 <= BMI && BMI < 25) {
                return "WP";
            } else if (25 <= BMI && BMI < 30) {
                return "NaW";
            } else if (30 <= BMI && BMI < 40) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 25 && wiek < 35) {
                if (BMI < 21) {
                return "NW";
            } else if (21 <= BMI && BMI < 26) {
                return "WP";
            } else if (26 <= BMI && BMI < 31) {
                return "NaW";
            } else if (31 <= BMI && BMI < 41) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 35 && wiek < 45) {
                if (BMI < 22) {
                return "NW";
            } else if (22 <= BMI && BMI < 27) {
                return "WP";
            } else if (27 <= BMI && BMI < 32) {
                return "NaW";
            } else if (32 <= BMI && BMI < 42) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 23) {
                return "NW";
            } else if (23 <= BMI && BMI < 28) {
                return "WP";
            } else if (28 <= BMI && BMI < 33) {
                return "NaW";
            } else if (33 <= BMI && BMI < 43) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 55 && wiek < 65) {
               if (BMI < 24) {
                return "NW";
            } else if (24 <= BMI && BMI < 29) {
                return "WP";
            } else if (29 <= BMI && BMI < 34) {
                return "NaW";
            } else if (34 <= BMI && BMI < 44) {
                return "OIS";
            } else{
                return "OIIS";
            }
            } else if (wiek >= 65) {
                if (BMI < 25) {
                return "NW";
            } else if (25 <= BMI && BMI < 30) {
                return "WP";
            } else if (30 <= BMI && BMI < 35) {
                return "NaW";
            } else if (35 <= BMI && BMI < 45) {
                return "OIS";
            } else{
                return "OIIS";
            }
            }
        }
        return "NONE";
    }




}


