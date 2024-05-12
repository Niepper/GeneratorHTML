#include <iostream>
/* Dodaje flagę wymaganą do kompilacji jako plik .dll dla rodziny systemów Windows*/
#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif


extern "C"
{

  def int add(int a, int b)
  {
    return (a + b);
  }

  def void subtractArrays(int* a, int* b, int size)
  {
    for(int i = 0; i < size; i++)
    {
      a[i] -= b[i];
    }
  }

}



template <int min, int max> class range { static bool contains(int i) { return min <= i && i < max; }}

osoba kalkulator(osoba a)
{
   BMI=( waga/( wzrost* wzrost))*10000;
  return a;
}

string name;
string surname = surname;
bool sex;
int age;
float weight;
float height;
float BMI = 0;
string desc = "None";


const char* opis(bool sex, int age, float BMI)
{
  char* desc = malloc(100);
  {
    if(sex==true)
    {
      if (range<0, 13>::contains(age))
        {
          if (range<0, 17>::contains(BMI))
            {
              desc="Niedowaga";
              return desc;
            }
            else if (range<17, 22>::contains(BMI))
            {
              desc="Waga prawidlowa";
              return desc;
            }
            else if (range<22, 27>::contains(BMI))
            {
              desc="Nadwaga";
              return desc;
            }
            else if (range<27, 37>::contains(BMI))
            {
              desc="Otyłość I stopnia";
              return desc;
            }
            else (range<37, 1000>::contains(BMI))
            {
              desc="Otyłość II stopnia";
              return desc;
            }
        }      
      if (range<13, 18>::contains(age))
        {
          if (range<0, 18>::contains(BMI))
          {
            desc="Niedowaga";
            return desc;
          }
          else if (range<18, 23>::contains(BMI))
          {
            desc="Waga prawidlowa";
            return desc;
          }
          else if (range<23, 28>::contains(BMI))
          {
            desc="Nadwaga";
            return desc;
          }
          else if (range<28, 38>::contains(BMI))
          {
            desc="Otyłość I stopnia";
            return desc;
          }
          else (range<38, 1000>::contains(BMI))
          {
            desc="Otyłość II stopnia";
            return desc;
          }
        }
      if (range<18, 25>::contains(age))
        {
          if (range<0, 19>::contains(BMI))
          {
            desc="Niedowaga";
            return desc;
          }
          else if (range<19, 24>::contains(BMI))
          {
            desc="Waga prawidlowa";
            return desc;
          }
          else if (range<24, 29>::contains(BMI))
          {
            desc="Nadwaga";
            return desc;
          }
          else if (range<29, 39>::contains(BMI))
          {
            desc="Otyłość I stopnia";
            return desc;
          }
          else (range<39, 1000>::contains(BMI))
          {
            desc="Otyłość II stopnia";
            return desc;
          }
        }
      if (range<25, 35>::contains(age))
        {
          if (range<0, 20>::contains(BMI))
          {
            desc="Niedowaga";
            return desc;
          }
          else if (range<20, 25>::contains(BMI))
          {
            desc="Waga prawidlowa";
            return desc;
          }
          else if (range<25, 30>::contains(BMI))
          {
            desc="Nadwaga";
            return desc;
          }
          else if (range<30, 40>::contains(BMI))
          {
            desc="Otyłość I stopnia";
            return desc;
          }
          else (range<40, 1000>::contains(BMI))
          {
            desc="Otyłość II stopnia";
            return desc;
          }
      }
      if (range<35, 45>::contains(age))
        {
          if (range<0, 21>::contains(BMI))
          {
            desc="Niedowaga";
            return desc;
          }
          else if (range<21, 26>::contains(BMI))
          {
            desc="Waga prawidlowa";
            return desc;
          }
          else if (range<26, 31>::contains(BMI))
          {
            desc="Nadwaga";
            return desc;
          }
          else if (range<31, 41>::contains(BMI))
          {
            desc="Otyłość I stopnia";
            return desc;
          }
          else (range<41, 1000>::contains(BMI))
          {
            desc="Otyłość II stopnia";
            return desc;
          }
      }
      if (range<45, 55>::contains(age))
        {
          if (range<0, 22>::contains(BMI))
          {
            desc="Niedowaga";
            return desc;
          }
          else if (range<22, 27>::contains(BMI))
          {
            desc="Waga prawidlowa";
            return desc;
          }
          else if (range<27, 32>::contains(BMI))
          {
            desc="Nadwaga";
            return desc;
          }
          else if (range<32, 42>::contains(BMI))
          {
            desc="Otyłość I stopnia";
            return desc;
          }
          else (range<42, 1000>::contains(BMI))
          {
            desc="Otyłość II stopnia";
            return desc;
          }
      }
      if (range<55, 65>::contains(age))
      {
        if (range<0, 23>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<23, 28>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<28, 33>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<33, 43>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<43, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<65, 1000>::contains(age))
      {
        if (range<0, 24>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<24, 29>::contains(BMI))
        {
          desc="Waga prawidłowa";
          return desc;
        }
        else if (range<29, 34>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<34, 44>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<44, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
    }
    else
    {
      if (range<0, 13>::contains(age))
      {
        if (range<0, 18>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<18, 23>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<23, 28>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<28, 38>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<38, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
    }      
      if (range<13, 18>::contains(age))
      {
        if (range<0, 19>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<19, 24>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<24, 29>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<29, 39>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<39, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<18, 25>::contains(age))
      {
        if (range<0, 20>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<20, 25>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<25, 30>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<30, 40>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<40, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<25, 35>::contains(age))
      {
        if (range<0, 21>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<21, 26>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<26, 31>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<31, 41>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<41, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<35, 45>::contains(age))
      {
        if (range<0, 22>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<22, 27>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<27, 32>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<32, 42>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<42, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<45, 55>::contains(age))
      {
        if (range<0, 23>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<23, 28>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<28, 33>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<33, 43>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<43, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<55, 65>::contains(age))
      {
          if (range<0, 24>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<24, 29>::contains(BMI))
        {
          desc="Waga prawidlowa";
          return desc;
        }
        else if (range<29, 34>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<34, 44>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<44, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
      }
      if (range<65, 1000>::contains(age))
      {
        if (range<0, 25>::contains(BMI))
        {
          desc="Niedowaga";
          return desc;
        }
        else if (range<25, 30>::contains(BMI))
        {
          desc="Waga prawidłowa";
          return desc;
        }
        else if (range<30, 35>::contains(BMI))
        {
          desc="Nadwaga";
          return desc;
        }
        else if (range<35, 45>::contains(BMI))
        {
          desc="Otyłość I stopnia";
          return desc;
        }
        else (range<45, 1000>::contains(BMI))
        {
          desc="Otyłość II stopnia";
          return desc;
        }
    }
    }       
  }
}
        

 