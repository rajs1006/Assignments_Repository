; ModuleID = 'test06.bc'
target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
target triple = "mips"

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = icmp sgt i32 1, 2
  br i1 %1, label %2, label %3

; <label>:2                                       ; preds = %0
  br label %4

; <label>:3                                       ; preds = %0
  br label %4

; <label>:4                                       ; preds = %3, %2
  %c.0 = phi i32 [ 1, %2 ], [ 2, %3 ]
  call void @print_int(i32 signext %c.0)
  call void @print_nl()
  %5 = icmp ult i32 -1, 1
  br i1 %5, label %6, label %7

; <label>:6                                       ; preds = %4
  br label %8

; <label>:7                                       ; preds = %4
  br label %8

; <label>:8                                       ; preds = %7, %6
  %9 = phi i32 [ -1, %6 ], [ 1, %7 ]
  call void @print_int(i32 signext %9)
  call void @print_nl()
  ret i32 0
}

declare void @print_int(i32 signext) #1

declare void @print_nl() #1

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.2-3ubuntu1 (tags/RELEASE_352/final) (based on LLVM 3.5.2)"}
