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

;; p06
(define is-palindrome
  (lambda (p)
    (or (<= (length p) 1)
        (and
         (equal? (car p) (car (reverse (cdr p))))
         (is-palindrome (cdr (reverse (cdr p))))))))

(expect is-palindrome '((a b c d)) #f "is-palindrome (#1)" "Find out whether a list is a palindrome")
(expect is-palindrome '((a b b a)) #t "is-palindrome (#2)" "Find out whether a list is a palindrome")
(expect is-palindrome '((a)) #t "is-palindrome (#3)" "Find out whether a list is a palindrome")
(expect is-palindrome '(()) #t "is-palindrome (#4)" "Find out whether a list is a palindrome")

;; p07
(define my-flatten
  (lambda (x)
    (if (pair? x)
        (append (my-flatten (car x)) (my-flatten (cdr x)))
        (if (null? x) x (list x)))))

(expect my-flatten
        '(((a) (b) (c) (d (e)) (f k (g (x)))))
        '(a b c d e f k g x)
        "my-flatten"
        "Flatten a nested list structure")

;; p08
(define compress
  (lambda (x)
    (letrec ((compress-iter
             (lambda (a c last)
               (if (null? c)
                   a
                   (let ((first (car c)))
                     (compress-iter
                      (if (equal? first last)
                          a
                          (append a (list first)))
                      (cdr c)
                      first))))))
      (compress-iter '() x '()))))

(expect compress '((a a a a b c c a a d e e e e)) '(a b c a d e) "compress" "Eliminate consecutive duplicates of list elements")

;; Recursively iterate over each item in curr, accumulate sublist if same as last item,
;; append sublist if the next item changes.
;; if at the end of curr and acc-sublist is not empty, append it to acc and return
;; otherwise return acc

(define pack
  (lambda (x)
    (letrec ((pack-iter
              (lambda (acc acc-sublist curr last)
                (if (null? curr)
                    (if (null? acc-sublist)
                        acc
                        (append acc (list acc-sublist)))
                    (let ((first (car curr))
                          (rest (cdr curr)))
                      (if (equal? first last)
                          (pack-iter acc (cons last acc-sublist) rest last)
                          (pack-iter
                           (if (null? acc)
                               (if (null? acc-sublist) '() (list acc-sublist))
                               (append acc (list acc-sublist)))
                           (cons first '())
                           rest
                           first)))))))
      (pack-iter '() '() x '()))))

(expect pack '((a a a a b c c a a d e e e e)) '((a a a a) (b) (c c) (a a) (d) (e e e e)) "pack" "Pack consecutive duplicates of list elements into sublists.")

