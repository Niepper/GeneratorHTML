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




struct osoba{
string imie;
string nazwisko;
bool plec;//true-kobieta, false-mezczyzna
int wiek;
float waga;
float wzrost;
float BMI;
string opis;
};

osoba kalkulator(osoba a)
{
  a.BMI=(a.waga/(a.wzrost*a.wzrost))*10000;
  return a;
}
osoba opis(osoba a)
{
  if(a.plec==true)
  {
    if (range<0, 13>::contains(wiek))
      {
        if (range<0, 17>::contains(BMI))
          {
            a.opis="Niedowaga";
          }
          else if (range<17, 22>::contains(BMI))
          {
            a.opis="Waga prawidlowa";
          }
          else if (range<22, 27>::contains(BMI))
          {
            a.opis="Nadwaga";
          }
          else if (range<27, 37>::contains(BMI))
          {
            a.opis="Otyłość I stopnia";
          }
          else (range<37, 1000>::contains(BMI))
            a.opis="Otyłość II stopnia";
      }      
    if (range<13, 18>::contains(wiek))
    {
      if (range<0, 18>::contains(BMI))
        {
          a.opis="Niedowaga";
        }
        else if (range<18, 23>::contains(BMI))
        {
          a.opis="Waga prawidlowa";
        }
        else if (range<23, 28>::contains(BMI))
        {
          a.opis="Nadwaga";
        }
        else if (range<28, 38>::contains(BMI))
        {
          a.opis="Otyłość I stopnia";
        }
        else (range<38, 1000>::contains(BMI))
          a.opis="Otyłość II stopnia";
    }
    if (range<18, 25>::contains(wiek))
    {
      if (range<0, 19>::contains(BMI))
        {
          a.opis="Niedowaga";
        }
        else if (range<19, 24>::contains(BMI))
        {
          a.opis="Waga prawidlowa";
        }
        else if (range<24, 29>::contains(BMI))
        {
          a.opis="Nadwaga";
        }
        else if (range<29, 39>::contains(BMI))
        {
          a.opis="Otyłość I stopnia";
        }
        else (range<39, 1000>::contains(BMI))
          a.opis="Otyłość II stopnia";
    }
    if (range<25, 35>::contains(wiek))
    {
      if (range<0, 20>::contains(BMI))
        {
          a.opis="Niedowaga";
        }
        else if (range<20, 25>::contains(BMI))
        {
          a.opis="Waga prawidlowa";
        }
        else if (range<25, 30>::contains(BMI))
        {
          a.opis="Nadwaga";
        }
        else if (range<30, 40>::contains(BMI))
        {
          a.opis="Otyłość I stopnia";
        }
        else (range<40, 1000>::contains(BMI))
          a.opis="Otyłość II stopnia";
    }
    if (range<35, 45>::contains(wiek))
    {
      if (range<0, 21>::contains(BMI))
        {
          a.opis="Niedowaga";
        }
        else if (range<21, 26>::contains(BMI))
        {
          a.opis="Waga prawidlowa";
        }
        else if (range<26, 31>::contains(BMI))
        {
          a.opis="Nadwaga";
        }
        else if (range<31, 41>::contains(BMI))
        {
          a.opis="Otyłość I stopnia";
        }
        else (range<41, 1000>::contains(BMI))
          a.opis="Otyłość II stopnia";
    }
    if (range<45, 55>::contains(wiek))
    {
      if (range<0, 22>::contains(BMI))
        {
          a.opis="Niedowaga";
        }
        else if (range<22, 27>::contains(BMI))
        {
          a.opis="Waga prawidlowa";
        }
        else if (range<27, 32>::contains(BMI))
        {
          a.opis="Nadwaga";
        }
        else if (range<32, 42>::contains(BMI))
        {
          a.opis="Otyłość I stopnia";
        }
        else (range<42, 1000>::contains(BMI))
          a.opis="Otyłość II stopnia";
    }
    if (range<55, 65>::contains(wiek))
    {
      if (range<0, 23>::contains(BMI))
      {
        a.opis="Niedowaga";
      }
      else if (range<23, 28>::contains(BMI))
      {
        a.opis="Waga prawidlowa";
      }
      else if (range<28, 33>::contains(BMI))
      {
        a.opis="Nadwaga";
      }
      else if (range<33, 43>::contains(BMI))
      {
        a.opis="Otyłość I stopnia";
      }
      else (range<43, 1000>::contains(BMI))
        a.opis="Otyłość II stopnia";
    }
    if (range<65, 1000>::contains(wiek))
    {
      if (range<0, 24>::contains(BMI))
      {
        a.opis="Niedowaga";
      }
      else if (range<24, 29>::contains(BMI))
      {
        a.opis="Waga prawidłowa";
      }
      else if (range<29, 34>::contains(BMI))
      {
        a.opis="Nadwaga";
      }
      else if (range<34, 44>::contains(BMI))
      {
        a.opis="Otyłość I stopnia";
      }
      else (range<44, 1000>::contains(BMI))
        a.opis="Otyłość II stopnia";
    }
  }
  else (a.plec==false)
        {
          if (range<0, 13>::contains(wiek))
            {
              if (range<0, 18>::contains(BMI))
                {
                  a.opis="Niedowaga";
                }
                else if (range<18, 23>::contains(BMI))
                {
                  a.opis="Waga prawidlowa";
                }
                else if (range<23, 28>::contains(BMI))
                {
                  a.opis="Nadwaga";
                }
                else if (range<28, 38>::contains(BMI))
                {
                  a.opis="Otyłość I stopnia";
                }
                else (range<38, 1000>::contains(BMI))
                  a.opis="Otyłość II stopnia";
            }      
          if (range<13, 18>::contains(wiek))
          {
            if (range<0, 19>::contains(BMI))
              {
                a.opis="Niedowaga";
              }
              else if (range<19, 24>::contains(BMI))
              {
                a.opis="Waga prawidlowa";
              }
              else if (range<24, 29>::contains(BMI))
              {
                a.opis="Nadwaga";
              }
              else if (range<29, 39>::contains(BMI))
              {
                a.opis="Otyłość I stopnia";
              }
              else (range<39, 1000>::contains(BMI))
                a.opis="Otyłość II stopnia";
          }
          if (range<18, 25>::contains(wiek))
          {
            if (range<0, 20>::contains(BMI))
              {
                a.opis="Niedowaga";
              }
              else if (range<20, 25>::contains(BMI))
              {
                a.opis="Waga prawidlowa";
              }
              else if (range<25, 30>::contains(BMI))
              {
                a.opis="Nadwaga";
              }
              else if (range<30, 40>::contains(BMI))
              {
                a.opis="Otyłość I stopnia";
              }
              else (range<40, 1000>::contains(BMI))
                a.opis="Otyłość II stopnia";
          }
          if (range<25, 35>::contains(wiek))
          {
            if (range<0, 21>::contains(BMI))
              {
                a.opis="Niedowaga";
              }
              else if (range<21, 26>::contains(BMI))
              {
                a.opis="Waga prawidlowa";
              }
              else if (range<26, 31>::contains(BMI))
              {
                a.opis="Nadwaga";
              }
              else if (range<31, 41>::contains(BMI))
              {
                a.opis="Otyłość I stopnia";
              }
              else (range<41, 1000>::contains(BMI))
                a.opis="Otyłość II stopnia";
          }
          if (range<35, 45>::contains(wiek))
          {
            if (range<0, 22>::contains(BMI))
              {
                a.opis="Niedowaga";
              }
              else if (range<22, 27>::contains(BMI))
              {
                a.opis="Waga prawidlowa";
              }
              else if (range<27, 32>::contains(BMI))
              {
                a.opis="Nadwaga";
              }
              else if (range<32, 42>::contains(BMI))
              {
                a.opis="Otyłość I stopnia";
              }
              else (range<42, 1000>::contains(BMI))
                a.opis="Otyłość II stopnia";
          }
          if (range<45, 55>::contains(wiek))
          {
            if (range<0, 23>::contains(BMI))
              {
                a.opis="Niedowaga";
              }
              else if (range<23, 28>::contains(BMI))
              {
                a.opis="Waga prawidlowa";
              }
              else if (range<28, 33>::contains(BMI))
              {
                a.opis="Nadwaga";
              }
              else if (range<33, 43>::contains(BMI))
              {
                a.opis="Otyłość I stopnia";
              }
              else (range<43, 1000>::contains(BMI))
                a.opis="Otyłość II stopnia";
          }
          if (range<55, 65>::contains(wiek))
          {
            if (range<0, 24>::contains(BMI))
            {
              a.opis="Niedowaga";
            }
            else if (range<24, 29>::contains(BMI))
            {
              a.opis="Waga prawidlowa";
            }
            else if (range<29, 34>::contains(BMI))
            {
              a.opis="Nadwaga";
            }
            else if (range<34, 44>::contains(BMI))
            {
              a.opis="Otyłość I stopnia";
            }
            else (range<44, 1000>::contains(BMI))
              a.opis="Otyłość II stopnia";
          }
          if (range<65, 1000>::contains(wiek))
          {
            if (range<0, 25>::contains(BMI))
            {
              a.opis="Niedowaga";
            }
            else if (range<25, 30>::contains(BMI))
            {
              a.opis="Waga prawidłowa";
            }
            else if (range<30, 35>::contains(BMI))
            {
              a.opis="Nadwaga";
            }
            else if (range<35, 45>::contains(BMI))
            {
              a.opis="Otyłość I stopnia";
            }
            else (range<45, 1000>::contains(BMI))
              a.opis="Otyłość II stopnia";
          }
        }
}         

 