; ModuleID = 'test03.bc'
target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
target triple = "mips"

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = and i32 119, 248
  call void @print_int(i32 signext %1)
  call void @print_nl()
  %2 = or i32 119, 248
  call void @print_int(i32 signext %2)
  call void @print_nl()
  %3 = xor i32 119, 248
  call void @print_int(i32 signext %3)
  call void @print_nl()
  %4 = and i32 -16711936, 2004318071
  call void @print_int(i32 signext %4)
  call void @print_nl()
  %5 = or i32 -16711936, 2004318071
  call void @print_int(i32 signext %5)
  call void @print_nl()
  %6 = xor i32 -16711936, 2004318071
  call void @print_int(i32 signext %6)
  call void @print_nl()
  ret i32 0
}

declare void @print_int(i32 signext) #1

declare void @print_nl() #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.2-3ubuntu1 (tags/RELEASE_352/final) (based on LLVM 3.5.2)"}
