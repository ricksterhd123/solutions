(define (double x) (* x 2))

(define (abs x)
  (if (< x 0)
      (- x)
      x))

(define (square a)
  (* a a))

(define (sum-of-squares a b)
  (+ (square a) (square b)))

(define (max a b)
  (if (> a b)
      a
      b))

;; Exercise 1.3
;; Define a procedure that takes three numbers as arguments and returns the sum
;; of the squares of the two larger numbers
(define (sum-of-two-largest a b c)
  (max
   (max (sum-of-squares a b) (sum-of-squares a c))
   (sum-of-squares b c)))

;; 1.1.7 example square roots
(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x)
                 x)))

(define (sqrt x)
  (sqrt-iter 1.0 x))

;; Exercise 1.6
;; new-if is a function and it's operands get evaluated first 

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(define (new-if-sqrt-iter guess x)
  (new-if (good-enough? guess x)
      guess
      (new-if-sqrt-iter (improve guess x)
                 x)))

(define (new-if-sqrt x)
  (new-if-sqrt-iter 1.0 x))

;; Exercise 1.7
(define (good-enough2.0? guess last-guess)
  (< (abs (- guess last-guess)) 0.00000001))

(define (good2-sqrt-iter guess last-guess x)
  (if (good-enough2.0? guess last-guess)
      guess
      (good2-sqrt-iter (improve guess x)
                       guess)))

(define (good2-sqrt x)
  (good2-sqrt-iter 1.0 0 x))

;; Test cases
(display (equal? (sum-of-squares 3 4) 25))
(display (equal? (sum-of-two-largest 3 4 1) 25))
(display (equal? (sum-of-two-largest 4 1 3) 25))
(display (equal? (sum-of-two-largest 1 3 4) 25))
(display (equal? (double 2) 4))
(display (equal? (abs 2) 2))
(display (equal? (abs 0) 0))
(display (equal? (abs -2) 2))
(display "\n")
