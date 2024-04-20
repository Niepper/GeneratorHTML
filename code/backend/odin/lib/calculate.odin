package BmiCalc
import "core:c/libc"
import "core:strings"

BMIFemale:: proc "c" (bmi: f32, plus: f32 = 0.0) -> cstring{
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


BMIMale:: proc "c" (bmi: f32, plus: f32 = 0.0) -> cstring{
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
describeBMI :: proc "c" (age: int, gender: bool, bmi:f32, a:^cstring) -> cstring{
    //true-kobieta, false-mezczyzna
    libc.printf("tak")
    a := a
    switch gender{
        case true:
            switch age{
                case 18 ..< 25:
                    a^ = (BMIFemale(bmi));
                case 25 ..< 35:
                    a^ = (BMIFemale(bmi,1));     
                case 35 ..< 45:;
                    a^ = (BMIFemale(bmi,2));
                case 45 ..< 55:
                    a^ = (BMIFemale(bmi,3));
                case 55 ..< 65:
                    a^ = (BMIFemale(bmi,4));
                case 65 ..< 1000:
                    a^ = (BMIFemale(bmi,5));
            }
        case false:
            switch age{
                case 18..<25:
                    a^ = (BMIMale(bmi));
                case 25 ..<35:
                    a^ = (BMIMale(bmi,1));
                case 35 ..<45:
                    a^ = (BMIMale(bmi,2));
                case 45 ..<55:
                    a^ = (BMIMale(bmi,3));
                case 55 ..<65:
                    a^ = (BMIMale(bmi,4));
                case 65 ..< 1000:
                    a^ = (BMIMale(bmi,5));
                }
    }
    return a^
}


