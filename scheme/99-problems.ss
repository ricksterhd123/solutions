#!/usr/bin/chezscheme --script

(define print
  (lambda args
    (if (null? args)
        (display "")
        (begin
          (display (car args))
          (apply print (cdr args))))))

(define expect
  (lambda (fn args equals name desc)
    (let ((result (apply fn args)))
      (if (equal? result equals)
          (print "Test: " name ", Description: " desc " - PASSED\n")
          (print "Test: " name ", Description: " desc " - FAILED\n")))))

;; p01
(define my-last
  (lambda (list)
    (if (null? (cdr list))
        list
        (my-last (cdr list)))))

(expect my-last '((a b c d)) '(d) "my-last" "Find the last box of a list")

;; p02
(define my-but-last
  (lambda (list)
    (if (null? (cddr list))
        list
        (my-but-last (cdr list)))))

(expect my-but-last '((a b c d)) '(c d) "my-but-last" "Find the last but one box of a list")

;; p03
(define element-at
  (lambda (list n)
    (if (<= n 1)
        (car list)
        (element-at (cdr list) (- n 1)))))

(expect element-at '((a b c d) 3) 'c "element-at" "Find the K'th element of a list")

;; p04
(define my-length
  (lambda (list)
    (if (null? list)
        0
        (+ (my-length (cdr list)) 1))))

(expect my-length '((a b c d)) 4 "my-length" "Find the number of elements in a list")

;; p05
(define my-reverse
  (lambda (x)
    (if (null? x)
        '()
        (append (my-reverse (cdr x)) (list (car x))))))

(expect my-reverse '((a b c d)) '(d c b a) "my-reverse" "Reverse a list.")

