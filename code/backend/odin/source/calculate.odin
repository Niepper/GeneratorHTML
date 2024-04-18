package BmiCalc
import "core:c/libc"

@export
calcBmi :: proc "c" (weight, height: libc.complex_float) -> libc.complex_float{
    Mheight:= height/100;
    return (weight / libc.cpowf(Mheight,2))


}