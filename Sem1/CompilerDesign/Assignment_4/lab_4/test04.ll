; ModuleID = 'test04.bc'
target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
target triple = "mips"

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = mul nsw i32 42, 5
  call void @print_int(i32 signext %1)
  call void @print_nl()
  %2 = sdiv i32 42, 5
  call void @print_int(i32 signext %2)
  call void @print_nl()
  %3 = srem i32 42, 5
  call void @print_int(i32 signext %3)
  ret i32 0
}

declare void @print_int(i32 signext) #1

declare void @print_nl() #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.2-3ubuntu1 (tags/RELEASE_352/final) (based on LLVM 3.5.2)"}
