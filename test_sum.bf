take first digit into cell 0:
, 

generate 48 (the ascii value for '0') in cell 4 by starting with 4 and multiplying by 12
>>> ++++ [->++++++++++++<] >

subtract cell 4 (which has 48) from cell 0
[-<<<<->>>>]

take second digit into cell 1:
<<< ,

generate 48 again into cell 4 using cell 3:
>> ++++ [->++++++++++++<] 

subtract cell 4 from cell 1
[-<<<->>>]

add first digit to second digit:
<<< [->+<]

select second digit:
>

output it:
.

>>>>> [
    expected input/output:
    input: 34
    output 7
    (only works on single digits and the result cannot be greater than 9)
]