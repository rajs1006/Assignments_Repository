; ModuleID = 'test08.bc'
target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
target triple = "mips"

@.str = private unnamed_addr constant [4 x i8] c"foo\00", align 1

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = call i32 @my_strlen(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0))
  call void @print_int(i32 signext %1)
  ret i32 0
}

declare void @print_int(i32 signext) #1

; Function Attrs: nounwind
define internal i32 @my_strlen(i8* %str) #0 {
  br label %1

; <label>:1                                       ; preds = %5, %0
  %len.0 = phi i32 [ 0, %0 ], [ %7, %5 ]
  %.0 = phi i8* [ %str, %0 ], [ %6, %5 ]
  %2 = load i8* %.0, align 1
  %3 = sext i8 %2 to i32
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %1
  %6 = getelementptr inbounds i8* %.0, i32 1
  %7 = add nsw i32 %len.0, 1
  br label %1

; <label>:8                                       ; preds = %1
  ret i32 %len.0
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.2-3ubuntu1 (tags/RELEASE_352/final) (based on LLVM 3.5.2)"}
