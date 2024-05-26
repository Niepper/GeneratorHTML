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
        static std::string opis;
         if (plec) {
              if (wiek < 13) {
                if (BMI < 17) {
                opis = "NW";
            } else if (17 <= BMI && BMI < 22) {
                opis = "WP";
            } else if (22 <= BMI && BMI < 27) {
                opis = "NaW";
            } else if (27 <= BMI && BMI < 37) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 13 && wiek < 18) {
                if (BMI < 18) {
                opis = "NW";
            } else if (18 <= BMI && BMI < 23) {
                opis = "WP";
            } else if (23 <= BMI && BMI < 28) {
                opis = "NaW";
            } else if (28 <= BMI && BMI < 38) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 19) {
                opis = "NW";
            } else if (19 <= BMI && BMI < 24) {
                opis = "WP";
            } else if (24 <= BMI && BMI < 29) {
                opis = "NaW";
            } else if (29 <= BMI && BMI < 39) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 25 && wiek < 35) {
                if (BMI < 20) {
                opis = "NW";
            } else if (20 <= BMI && BMI < 25) {
                opis = "WP";
            } else if (25 <= BMI && BMI < 30) {
                opis = "NaW";
            } else if (30 <= BMI && BMI < 40) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 35 && wiek < 45) {
                if (BMI < 21) {
                opis = "NW";
            } else if (21 <= BMI && BMI < 26) {
                opis = "WP";
            } else if (26 <= BMI && BMI < 31) {
                opis = "NaW";
            } else if (31 <= BMI && BMI < 41) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 22) {
                opis = "NW";
            } else if (22 <= BMI && BMI < 27) {
                opis = "WP";
            } else if (27 <= BMI && BMI < 32) {
                opis = "NaW";
            } else if (32 <= BMI && BMI < 42) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 55 && wiek < 65) {
                if (BMI < 23) {
                opis = "NW";
            } else if (23 <= BMI && BMI < 28) {
                opis = "WP";
            } else if (28 <= BMI && BMI < 33) {
                opis = "NaW";
            } else if (33 <= BMI && BMI < 43) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 65) {
                if (BMI < 24) {
                opis = "NW";
            } else if (24 <= BMI && BMI < 29) {
                opis = "WP";
            } else if (29 <= BMI && BMI < 34) {
                opis = "NaW";
            } else if (34 <= BMI && BMI < 44) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            }
        } else {
            if (wiek < 13) {
                if (BMI < 18) {
                opis = "NW";
            } else if (18 <= BMI && BMI < 23) {
                opis = "WP";
            } else if (23 <= BMI && BMI < 28) {
                opis = "NaW";
            } else if (28 <= BMI && BMI < 38) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 13 && wiek < 18) {
                 if (BMI < 19) {
                opis = "NW";
            } else if (19 <= BMI && BMI < 24) {
                opis = "WP";
            } else if (24 <= BMI && BMI < 29) {
                opis = "NaW";
            } else if (29 <= BMI && BMI < 39) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 18 && wiek < 25) {
                if (BMI < 20) {
                opis = "NW";
            } else if (20 <= BMI && BMI < 25) {
                opis = "WP";
            } else if (25 <= BMI && BMI < 30) {
                opis = "NaW";
            } else if (30 <= BMI && BMI < 40) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 25 && wiek < 35) {
                if (BMI < 21) {
                opis = "NW";
            } else if (21 <= BMI && BMI < 26) {
                opis = "WP";
            } else if (26 <= BMI && BMI < 31) {
                opis = "NaW";
            } else if (31 <= BMI && BMI < 41) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 35 && wiek < 45) {
                if (BMI < 22) {
                opis = "NW";
            } else if (22 <= BMI && BMI < 27) {
                opis = "WP";
            } else if (27 <= BMI && BMI < 32) {
                opis = "NaW";
            } else if (32 <= BMI && BMI < 42) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 45 && wiek < 55) {
                if (BMI < 23) {
                opis = "NW";
            } else if (23 <= BMI && BMI < 28) {
                opis = "WP";
            } else if (28 <= BMI && BMI < 33) {
                opis = "NaW";
            } else if (33 <= BMI && BMI < 43) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 55 && wiek < 65) {
               if (BMI < 24) {
                opis = "NW";
            } else if (24 <= BMI && BMI < 29) {
                opis = "WP";
            } else if (29 <= BMI && BMI < 34) {
                opis = "NaW";
            } else if (34 <= BMI && BMI < 44) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            } else if (wiek >= 65) {
                if (BMI < 25) {
                opis = "NW";
            } else if (25 <= BMI && BMI < 30) {
                opis = "WP";
            } else if (30 <= BMI && BMI < 35) {
                opis = "NaW";
            } else if (35 <= BMI && BMI < 45) {
                opis = "OIS";
            } else{
                opis = "OIIS";
            }
            }
        }
        return opis.c_str();
    }




}



/*


Person opis(Person a)
{
  if(a.plec==true)
  {
    if(a.wiek>=25&&a.wiek<=34)
    {
      if(a.BMI>20)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=20&&a.BMI<25)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=25&&a.BMI<30)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=30&&a.BMI<40)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=40)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=35&&a.wiek<=44)
    {
      if(a.BMI>21)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=21&&a.BMI<26)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=26&&a.BMI<31)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=31&&a.BMI<41)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=41)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=45&&a.wiek<=54)
    {
      if(a.BMI>22)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=22&&a.BMI<27)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=27&&a.BMI<32)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=32&&a.BMI<42)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=42)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=55&&a.wiek<=64)
    {
      if(a.BMI>23)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=23&&a.BMI<28)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=28&&a.BMI<33)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=33&&a.BMI<43)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=43)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=65)
    {
      if(a.BMI>24)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=24&&a.BMI<29)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=29&&a.BMI<34)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=34&&a.BMI<44)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=44)
      {
        a.opis="otyłość skrajna";
      }
    }
  }
    return a;
}
*/