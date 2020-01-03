## And there you have it - In assembly - newline escape versus endl.s
## Matthew C. Bascom
## "2020-01-02 15:22:55 PST"

## Shell calls to inspect the assembly: 
## c++ -S -fverbose-asm Practice\ with\ Pointers_2_4\ -\ Jan\ 2\ 2020.cc -o out_2_4.s
## c++ -S -fverbose-asm Practice\ with\ Pointers_2_5\ -\ Jan\ 2\ 2020.cc -o out_2_5.s

## Summary of executables (note size:)
## ls -lt | grep out
 ## -rwxr-xr-x 1 cloudsat1 cloudsat1 13784 Jan  2 14:44  out_2_5
 ## -rwxr-xr-x 1 cloudsat1 cloudsat1 13728 Jan  2 14:39  out_2_4

## Assembly
# Practice with Pointers_2_4 - Jan 2 2020.cc:112: cout << '\n' << p_str << '\n';
        movl    $10, %esi       #,
        leaq    _ZSt4cout(%rip), %rdi   #,
        call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT       #
        movq    %rax, %rdx      #, _1
        movq    -16(%rbp), %rax # p_str, p_str.0_2
        movq    %rax, %rsi      # p_str.0_2,
        movq    %rdx, %rdi      # _1,
        call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT     #
        movl    $10, %esi       #,
        movq    %rax, %rdi      # _3,
        call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT       #

# Practice with Pointers_2_5 - Jan 2 2020.cc:119: cout << endl << p_str << endl;
        movq    _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax #, tmp95
        movq    %rax, %rsi      # tmp95,
        leaq    _ZSt4cout(%rip), %rdi   #,
        call    _ZNSolsEPFRSoS_E@PLT    #
        movq    %rax, %rdx      #, _1
        movq    -16(%rbp), %rax # p_str, p_str.0_2
        movq    %rax, %rsi      # p_str.0_2,
        movq    %rdx, %rdi      # _1,
        call    _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT     #
        movq    %rax, %rdx      #, _3
        movq    _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax #, tmp96
        movq    %rax, %rsi      # tmp96,
        movq    %rdx, %rdi      # _3,
        call    _ZNSolsEPFRSoS_E@PLT    #