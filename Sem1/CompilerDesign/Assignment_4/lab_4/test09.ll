; ModuleID = 'test09.bc'
target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
target triple = "mips"

; Function Attrs: nounwind
define i32 @fib(i32 signext %n) #0 {
  br label %1

; <label>:1                                       ; preds = %5, %0
  %b.0 = phi i32 [ 1, %0 ], [ %4, %5 ]
  %a.0 = phi i32 [ 0, %0 ], [ %b.0, %5 ]
  %i.0 = phi i32 [ 0, %0 ], [ %6, %5 ]
  %2 = icmp slt i32 %i.0, %n
  br i1 %2, label %3, label %7

; <label>:3                                       ; preds = %1
  %4 = add nsw i32 %a.0, %b.0
  br label %5

; <label>:5                                       ; preds = %3
  %6 = add nsw i32 %i.0, 1
  br label %1

; <label>:7                                       ; preds = %1
  ret i32 %b.0
}

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = call i32 @fib(i32 signext 0)
  call void @print_int(i32 signext %1)
  call void @print_nl()
  %2 = call i32 @fib(i32 signext 1)
  call void @print_int(i32 signext %2)
  call void @print_nl()
  %3 = call i32 @fib(i32 signext 2)
  call void @print_int(i32 signext %3)
  call void @print_nl()
  %4 = call i32 @fib(i32 signext 3)
  call void @print_int(i32 signext %4)
  call void @print_nl()
  %5 = call i32 @fib(i32 signext 4)
  call void @print_int(i32 signext %5)
  call void @print_nl()
  %6 = call i32 @fib(i32 signext 5)
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
