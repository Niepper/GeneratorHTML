package BmiCalc
import "core:c/libc"

BMIFemale:: proc (bmi : f32, plus: f32 = 0) -> string{
    switch bmi{
        case 0 ..< (19 + plus):
            return "Niedowaga"
        case (19 + plus) ..< (24 + plus) :
            return "Prawidłowa"
        case (24 + plus) ..< (29 + plus):
            return "Nadwaga"
        case (29 + plus) ..< (39 + plus):
            return "Otyłość"
        case (39 + plus) ..< 1000:
            return "Skrajna otyłość"
    }
    return "ERROR"
}

BMIMale:: proc (bmi : f32, plus: f32 = 0) -> string{
    switch bmi{
        case 0..< (20 + plus):
            return "Niedowaga"
        case (20 + plus) ..< (25 + plus):
            return "Prawidłowa"
        case (25 + plus) ..< (30 + plus):
            return "Nadwaga"
        case (30 + plus) ..< (40 + plus):
            return "Otyłość"
        case (40 + plus) ..< 1000:
            return "Skrajna otyłość"
    }
    return "ERROR"
}

@export
calcBmi :: proc "c" (weight, height: libc.complex_float) -> libc.complex_float{
    Mheight:= height/100;
    return (weight / libc.cpowf(Mheight,2))
}

@export
describeBMI :: proc "c" (age: int, gender: bool, bmi:f32) -> string{
    //true-kobieta, false-mezczyzna
    if gender == true{
        switch age{
        case 18 ..< 25:
            return BMIFemale(bmi)
        case 25 ..< 35:
           return BMIFemale(bmi,1)        
        case 35 ..< 45:
            return BMIFemale(bmi,2)
        case 45 ..< 55:
            return BMIFemale(bmi,3)
        case 55 ..< 65:
            return BMIFemale(bmi,4)
        case 65 ..< 1000:
            return BMIFemale(bmi,5)
         }
    }
    else{
        switch age{
            case 18..<25:
                return BMIMale(bmi)
            case 25 ..<35:
               return BMIMale(bmi,1)        
            case 35 ..<45:
                return BMIFMale(bmi,2)
            case 45 ..<55:
                return BMIMale(bmi,3)
            case 55 ..<65:
                return BMIMale(bmi,4)
            case 65 ..< 1000:
                return BMIMale(bmi,5)
             }
    }
    return "ERROR"
}


